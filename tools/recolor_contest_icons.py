#!/usr/bin/env python3
"""
Rewrite graphics/types/contest_*.png so every pixel uses only the colors from
the matching move_types_*.pal palette.

Mapping (from src/contest.c and src/data/types_info.h):
    contest_cool   -> move_types_1.pal   (palette 13)
    contest_beauty -> move_types_2.pal   (palette 14)
    contest_cute   -> move_types_2.pal   (palette 14)
    contest_smart  -> move_types_3.pal   (palette 15)
    contest_tough  -> move_types_1.pal   (palette 13)

The script preserves the original alpha channel and the indexed PNG format,
which is what gbagfx expects.
"""

from pathlib import Path
from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
TYPES_DIR = ROOT / "graphics" / "types"

# (contest png, palette png) pairs
PLAN = [
    ("contest_cool.png",   "move_types_1.pal"),
    ("contest_beauty.png", "move_types_2.pal"),
    ("contest_cute.png",   "move_types_2.pal"),
    ("contest_smart.png",  "move_types_3.pal"),
    ("contest_tough.png",  "move_types_1.pal"),
]


def load_jasc_pal(path: Path) -> list[tuple[int, int, int]]:
    """Parse a JASC-PAL file into a list of (R, G, B) tuples."""
    lines = path.read_text(encoding="utf-8").splitlines()
    if lines[0].strip() != "JASC-PAL":
        raise ValueError(f"{path} is not a JASC-PAL file")
    count = int(lines[2].strip())
    colors = []
    for i in range(count):
        r, g, b = (int(x) for x in lines[3 + i].split())
        colors.append((r, g, b))
    return colors


def make_palette_image(colors: list[tuple[int, int, int]]) -> Image.Image:
    """Build a tiny pal_p-style image containing the palette colors."""
    pal = Image.new("P", (len(colors), 1))
    flat = []
    for r, g, b in colors:
        flat.extend([r, g, b])
    # Pad to 256 RGB triplets (Pillow's quantize expects a full 256-color table).
    flat.extend([0] * (256 * 3 - len(flat)))
    pal.putpalette(flat)
    return pal


def recolor(src_png: Path, pal_pal: Path) -> None:
    pal_colors = load_jasc_pal(pal_pal)
    print(f"{src_png.name}: palette {pal_pal.name} "
          f"({len(pal_colors)} colors)")

    img = Image.open(src_png)
    was_indexed = img.mode == "P"
    rgba = img.convert("RGBA")

    # Save original alpha; quantize RGB only so transparency is untouched.
    alpha = rgba.split()[3]

    rgb = rgba.convert("RGB")
    pal_img = make_palette_image(pal_colors)
    indexed = rgb.quantize(palette=pal_img, dither=Image.Dither.NONE)

    # Re-apply the original alpha. Pillow's quantize drops alpha.
    rgba_out = indexed.convert("RGBA")
    rgba_out.putalpha(alpha)

    if was_indexed:
        # Keep the indexed format gbagfx expects. The PNG palette gets
        # rewritten to exactly match the .pal file.
        out = rgba_out.convert("P", palette=Image.Palette.ADAPTIVE, colors=256)
        # Overwrite the embedded palette with the exact JASC-PAL colors.
        flat = []
        for r, g, b in pal_colors:
            flat.extend([r, g, b])
        flat.extend([0] * (256 * 3 - len(flat)))
        out.putpalette(flat)
    else:
        out = rgba_out

    out.save(src_png, optimize=True)
    print(f"  -> wrote {src_png}")


def main() -> None:
    for png_name, pal_name in PLAN:
        recolor(TYPES_DIR / png_name, TYPES_DIR / pal_name)


if __name__ == "__main__":
    main()