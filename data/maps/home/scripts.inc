# 1 "data/maps/home/scripts.pory"

# 2 "data/maps/home/scripts.pory"
home_MapScripts::
# 3 "data/maps/home/scripts.pory"
	.byte 0
# 4 "data/maps/home/scripts.pory"

# 5 "data/maps/home/scripts.pory"
home_EventScript_GiveStarter::
# 6 "data/maps/home/scripts.pory"
	lockall
# 7 "data/maps/home/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 8 "data/maps/home/scripts.pory"
	givemon SPECIES_FENNEKIN, 5
# 9 "data/maps/home/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
# 10 "data/maps/home/scripts.pory"
	goto_if_eq home_EventScript_MonInParty
# 11 "data/maps/home/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
# 12 "data/maps/home/scripts.pory"
	goto_if_eq home_EventScript_MonInPC
# 13 "data/maps/home/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 14 "data/maps/home/scripts.pory"
	releaseall
# 15 "data/maps/home/scripts.pory"
	end
# 16 "data/maps/home/scripts.pory"

# 17 "data/maps/home/scripts.pory"
home_EventScript_MonInParty::
# 18 "data/maps/home/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 19 "data/maps/home/scripts.pory"
	msgbox home_Text_ReceivedMon, MSGBOX_DEFAULT
# 20 "data/maps/home/scripts.pory"
	waitfanfare
# 21 "data/maps/home/scripts.pory"
	waitmessage
# 22 "data/maps/home/scripts.pory"
	setvar VAR_TEMP_0, 1
# 23 "data/maps/home/scripts.pory"
	releaseall
# 24 "data/maps/home/scripts.pory"
	end
# 25 "data/maps/home/scripts.pory"

# 26 "data/maps/home/scripts.pory"
home_EventScript_MonInPC::
# 27 "data/maps/home/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 28 "data/maps/home/scripts.pory"
	msgbox home_Text_ReceivedMonPC, MSGBOX_DEFAULT
# 29 "data/maps/home/scripts.pory"
	waitfanfare
# 30 "data/maps/home/scripts.pory"
	waitmessage
# 31 "data/maps/home/scripts.pory"
	setvar VAR_TEMP_0, 1
# 32 "data/maps/home/scripts.pory"
	releaseall
# 33 "data/maps/home/scripts.pory"
	end
# 34 "data/maps/home/scripts.pory"

# 35 "data/maps/home/scripts.pory"
home_Text_ReceivedMon:
# 36 "data/maps/home/scripts.pory"
	.string "{PLAYER} received a FENNEKIN!$"
# 37 "data/maps/home/scripts.pory"

# 38 "data/maps/home/scripts.pory"
home_Text_ReceivedMonPC:
# 39 "data/maps/home/scripts.pory"
	.string "FENNEKIN was sent to someone's PC.$"
