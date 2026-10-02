# 1 "data/maps/EventTest/scripts.pory"

# 2 "data/maps/EventTest/scripts.pory"
EventTest_MapScripts::
# 3 "data/maps/EventTest/scripts.pory"
	.byte 0
# 4 "data/maps/EventTest/scripts.pory"

# 5 "data/maps/EventTest/scripts.pory"
EventTest_EventScript_GiveStarter::
# 6 "data/maps/EventTest/scripts.pory"
	lockall
# 7 "data/maps/EventTest/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 8 "data/maps/EventTest/scripts.pory"
	givemon SPECIES_FENNEKIN, 5
# 9 "data/maps/EventTest/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
# 10 "data/maps/EventTest/scripts.pory"
	goto_if_eq EventTest_EventScript_MonInParty
# 11 "data/maps/EventTest/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
# 12 "data/maps/EventTest/scripts.pory"
	goto_if_eq EventTest_EventScript_MonInPC
# 13 "data/maps/EventTest/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 14 "data/maps/EventTest/scripts.pory"
	releaseall
# 15 "data/maps/EventTest/scripts.pory"
	end
# 16 "data/maps/EventTest/scripts.pory"

# 17 "data/maps/EventTest/scripts.pory"
EventTest_EventScript_MonInParty::
# 18 "data/maps/EventTest/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 19 "data/maps/EventTest/scripts.pory"
	msgbox EventTest_Text_ReceivedMon, MSGBOX_DEFAULT
# 20 "data/maps/EventTest/scripts.pory"
	waitfanfare
# 21 "data/maps/EventTest/scripts.pory"
	waitmessage
# 22 "data/maps/EventTest/scripts.pory"
	setvar VAR_TEMP_0, 1
# 23 "data/maps/EventTest/scripts.pory"
	releaseall
# 24 "data/maps/EventTest/scripts.pory"
	end
# 25 "data/maps/EventTest/scripts.pory"

# 26 "data/maps/EventTest/scripts.pory"
EventTest_EventScript_MonInPC::
# 27 "data/maps/EventTest/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 28 "data/maps/EventTest/scripts.pory"
	msgbox EventTest_Text_ReceivedMonPC, MSGBOX_DEFAULT
# 29 "data/maps/EventTest/scripts.pory"
	waitfanfare
# 30 "data/maps/EventTest/scripts.pory"
	waitmessage
# 31 "data/maps/EventTest/scripts.pory"
	setvar VAR_TEMP_0, 1
# 32 "data/maps/EventTest/scripts.pory"
	releaseall
# 33 "data/maps/EventTest/scripts.pory"
	end
# 34 "data/maps/EventTest/scripts.pory"

# 35 "data/maps/EventTest/scripts.pory"
EventTest_Text_ReceivedMon:
# 36 "data/maps/EventTest/scripts.pory"
	.string "{PLAYER} received a FENNEKIN!$"
# 37 "data/maps/EventTest/scripts.pory"

# 38 "data/maps/EventTest/scripts.pory"
EventTest_Text_ReceivedMonPC:
# 39 "data/maps/EventTest/scripts.pory"
	.string "FENNEKIN was sent to someone's PC.$"
