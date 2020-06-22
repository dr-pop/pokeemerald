SlateportCity_MapScripts:: @ 81DCC61
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition: @ 81DCC6C
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	//compare VAR_WILLYSTAD_CITY_STATE, 1
	//call_if_eq SlateportCity_EventScript_LocateRival
	//compare VAR_WILLYSTAD_CITY_STATE, 1
	//call_if_eq SlateportCity_EventScript_RivalIntroduction
	//call_if_eq SlateportCity_EventScript_MovePeopleForSternInterview
	//compare VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	//call_if_eq SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport:: @ 81DCC8D
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_LocateRival::
	//setobjectxy 2, 21, 15
	//setobjectxy 19, 17, 13
	addobject 2
	//addobject 19
	end

SlateportCity_OnWarp:
	compare VAR_WILLYSTAD_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_LocateRival
	end

SlateportCity_OnFrame: @ 81DCD12
	//map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	map_script_2 VAR_WILLYSTAD_CITY_STATE, 1, SlateportCity_EventScript_RivalIntroduction
	.2byte 0

// ============================================================
// DEBUGGING AND TESTING SCRIPTS.
// ============================================================

Script_GivePokemonDemo::
	lock
	faceplayer
	setflag FLAG_SYS_B_DASH
	msgbox Text_TakeCharizard, MSGBOX_DEFAULT
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq Script_PlayerHasFullParty
	givemon SPECIES_CHARIZARD, 50, ITEM_DRAGON_FANG
	playfanfare MUS_FANFA4
	msgbox Text_ReceivedCharizard, MSGBOX_DEFAULT
	waitfanfare
	release
	end

Script_PlayerHasFullParty::
	msgbox Text_PlayerHasFullParty, MSGBOX_DEFAULT
	release
	end

Text_TakeCharizard:
	.string "Please, take this Charizard.$"

Text_ReceivedCharizard:
	.string "{PLAYER} received a Charizard!$"

Text_PlayerHasFullParty:
	.string "Ah, your party is full.$"

// SlateportCity_EventScript_Man3:: @ 81DD365
//	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
//	end

// “”

Script_DebugKecleonNew::
	lock
	faceplayer
	message Text_DebugHello
	waitmessage
	//multichoice 1, 1, MULTI_DEBUG_KECLEON, 0
	scrollingmultichoice 0, 2, 2, 5, TRUE
	switch VAR_RESULT
	case 0, Script_DebugKecleonNew_1
	case 1, Script_DebugKecleonNew_2
	case 2, Script_DebugKecleonNew_3
	case 3, Script_DebugKecleonNew_4
	case 4, Script_DebugKecleonNew_5
	case 5, Script_DebugKecleonNew_6a
	case 6, Script_DebugKecleonNew_6b
	case 7, Script_DebugKecleonNew_7
	case MULTI_B_PRESSED, Script_DebugKecleonNew_Cancel

Text_DebugHello:
	.string "Hello, I'm Debug Kecleon.\p"
	.string "To which game state do you\n"
	.string "wish to go?$"
	
Script_DebugKecleonNew_1::
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_SPRITES
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	setflag FLAG_HIDE_WILLYSTAD_LAB_PROF
	clearflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	clearflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	clearflag FLAG_MAYOR_OFFICE_LOCKED
	setvar VAR_WILLYSTAD_CITY_STATE, 0
	msgbox Text_Debug_Option1, MSGBOX_DEFAULT
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	closemessage
	warp MAP_SLATEPORT_CITY, 255, 37, 41
	waitstate
	releaseall
	end

Text_Debug_Option1:
	.string "You chose Option 1:\n"
	.string "“Start of new game”$"

Script_DebugKecleonNew_2::
	clearflag FLAG_HIDE_WILLYSTAD_RIVAL_SPRITES
	clearflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	setflag FLAG_HIDE_WILLYSTAD_LAB_PROF
	clearflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	setflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	clearflag FLAG_MAYOR_OFFICE_LOCKED
	setvar VAR_WILLYSTAD_CITY_STATE, 1
	msgbox Text_Debug_Option2, MSGBOX_DEFAULT
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUSTBORO_CITY_DEVON_CORP_1F, 255, 8, 13
	waitstate
	releaseall
	end

Text_Debug_Option2:
	.string "You chose Option 2:\n"
	.string "“Fossil stolen!”$"
	
Script_DebugKecleonNew_3::
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_SPRITES
	clearflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	setflag FLAG_HIDE_WILLYSTAD_LAB_PROF
	clearflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	setflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	clearflag FLAG_MAYOR_OFFICE_LOCKED
	setvar VAR_WILLYSTAD_CITY_STATE, 2
	msgbox Text_Debug_Option3, MSGBOX_DEFAULT
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	closemessage
	warp MAP_SLATEPORT_CITY, 255, 18, 17
	waitstate
	releaseall
	end

Text_Debug_Option3:
	.string "You chose Option 3:\n"
	.string "“Met your Rival”$"
	
Script_DebugKecleonNew_4::
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_SPRITES
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	setflag FLAG_HIDE_WILLYSTAD_LAB_PROF
	clearflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	setflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	clearflag FLAG_MAYOR_OFFICE_LOCKED
	setvar VAR_WILLYSTAD_CITY_STATE, 3
	msgbox Text_Debug_Option4, MSGBOX_DEFAULT
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUSTBORO_CITY_DEVON_CORP_1F, 255, 9, 13
	waitstate
	releaseall
	end

Text_Debug_Option4:
	.string "You chose Option 4:\n"
	.string "“Defeated the Thief”$"

Script_DebugKecleonNew_5::
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_SPRITES
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	clearflag FLAG_HIDE_WILLYSTAD_LAB_PROF
	setflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	setflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	clearflag FLAG_MAYOR_OFFICE_LOCKED
	setvar VAR_WILLYSTAD_CITY_STATE, 4
	msgbox Text_Debug_Option5, MSGBOX_DEFAULT
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUSTBORO_CITY_DEVON_CORP_1F, 255, 8, 11
	waitstate
	releaseall
	end

Text_Debug_Option5:
	.string "You chose Option 5:\n"
	.string "“Fossil returned!”$"

Script_DebugKecleonNew_6a::
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_SPRITES
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	setflag FLAG_HIDE_WILLYSTAD_LAB_PROF
	setflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	setflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	clearflag FLAG_MAYOR_OFFICE_LOCKED
	setvar VAR_WILLYSTAD_CITY_STATE, 4
	msgbox Text_Debug_Option6a, MSGBOX_DEFAULT
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUSTBORO_CITY_POKEMON_SCHOOL, 255, 6, 8
	waitstate
	releaseall
	end

Text_Debug_Option6a:
	.string "You chose Option 6a:\n"
	.string "“Met the Prof”$"
	
Script_DebugKecleonNew_6b::
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_SPRITES
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	clearflag FLAG_HIDE_WILLYSTAD_LAB_PROF
	setflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	setflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	clearflag FLAG_MAYOR_OFFICE_LOCKED
	setvar VAR_WILLYSTAD_CITY_STATE, 5
	msgbox Text_Debug_Option6b, MSGBOX_DEFAULT
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUSTBORO_CITY_DEVON_CORP_2F, 255, 8, 9
	waitstate
	releaseall
	end

Text_Debug_Option6b:
	.string "You chose Option 6b:\n"
	.string "“Met the Mayor”$"
	
Script_DebugKecleonNew_7::
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_SPRITES
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	setflag FLAG_HIDE_WILLYSTAD_LAB_PROF
	setflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	setflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	clearflag FLAG_MAYOR_OFFICE_LOCKED
	setvar VAR_WILLYSTAD_CITY_STATE, 6
	msgbox Text_Debug_Option7, MSGBOX_DEFAULT
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUSTBORO_CITY_DEVON_CORP_1F, 255, 8, 5
	waitstate
	releaseall
	end

Text_Debug_Option7:
	.string "You chose Option 7:\n"
	.string "“Met Prof and Mayor”$"

Script_DebugKecleonNew_Cancel::
	msgbox Text_DebugBye, MSGBOX_DEFAULT
	closemessage
	release
	end

Text_DebugDone:
	.string "All done. See ya!$"

Text_DebugBye:
	.string "OK then. Bye!$"

// ==== ANIMATION TEST RUN: ===

Script_AnimationTest::
	lock
	faceplayer
	msgbox Text_AnimationTest1, MSGBOX_DEFAULT
	closemessage
	addobject 17
	applymovement 17, Movement_Test1
	waitmovement 0
	removeobject 17
	addobject 20
	applymovement 20, Movement_Test1
	waitmovement 0
	removeobject 20
	addobject 5
	applymovement 5, Movement_Test1
	waitmovement 0
	release
	end

Text_AnimationTest1:
	.string "Starting test animation.$"

Movement_Test1:
	walk_right
	walk_right
	walk_right
	step_end

// ==== OLD DEBUG: ===

Script_DebugKecleon::
	lock
	faceplayer
	msgbox Text_Debug1, MSGBOX_YESNO //restore "fossil stolen"
	compare VAR_RESULT, YES
	goto_if_eq Script_DebugKecleonYes1
	msgbox Text_Debug2, MSGBOX_YESNO //toggle "fossil stolen"
	compare VAR_RESULT, YES
	goto_if_eq Script_DebugKecleonYes2
	msgbox Text_Debug3, MSGBOX_YESNO //toggle "thief caught"
	compare VAR_RESULT, YES
	goto_if_eq Script_DebugKecleonYes3
	msgbox Text_Debug4, MSGBOX_YESNO //toggle "open door office"
	compare VAR_RESULT, YES
	goto_if_eq Script_DebugKecleonYes4
	goto Script_DebugKecleonNo4
	//goto_if_set FLAG_HIDE_SLATEPORT_CITY_SCOTT, Script_DebugKecleonScottHidden
	//goto_if_unset FLAG_HIDE_SLATEPORT_CITY_SCOTT, Script_DebugKecleonScottUnhidden
	release
	end

Text_Debug1:
	.string "Hello, I'm Debug Kecleon.\p"
	.string "Do you wish to reset this:\n"
	.string "“Fossil Stolen (C.S. 1)”$"

Script_DebugKecleonYes1::
	clearflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	//clearflag FLAG_DELIVERED_DEVON_GOODS
	//setflag FLAG_HIDE_SLATEPORT_CITY_SCOTT
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	clearflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	setvar VAR_WILLYSTAD_CITY_STATE, 0
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	release
	end

Text_Debug2:
	.string "Do you wish to toggle this:\n"
	.string "“Fossil Stolen (C.S. 1)”$"

Script_DebugKecleonYes2::
	setflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	//setflag FLAG_DELIVERED_DEVON_GOODS
	//clearflag FLAG_HIDE_SLATEPORT_CITY_SCOTT
	clearflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	clearflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	setvar VAR_WILLYSTAD_CITY_STATE, 1
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	release
	end

Text_Debug3:
	.string "Do you wish to toggle this:\n"
	.string "“Thief Caught (C.S. 2)”$"

Script_DebugKecleonYes3::
	setflag FLAG_HIDE_WILLYSTAD_CROWD_FOSSIL
	//clearflag FLAG_DELIVERED_DEVON_GOODS
	//clearflag FLAG_HIDE_SLATEPORT_CITY_SCOTT
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF
	clearflag FLAG_HIDE_WILLYSTAD_CITYHALL_MAYOR_PROF
	setvar VAR_WILLYSTAD_CITY_STATE, 3
	giveitem ITEM_PLUME_FOSSIL
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUSTBORO_CITY_DEVON_CORP_1F, 255, 9, 13
	waitstate
	releaseall
	end

Text_Debug4:
	.string "Do you wish the door to the\n"
	.string "Mayor's Office to be open?”$"

Script_DebugKecleonYes4::
	clearflag FLAG_USED_STORAGE_KEY
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	release
	end

Script_DebugKecleonNo4::
	setflag FLAG_USED_STORAGE_KEY
	msgbox Text_DebugDone, MSGBOX_DEFAULT
	release
	end

Script_DebugKecleonScottHidden::
	msgbox Text_ScottHidden, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF, Script_DebugKecleonBirchHidden
	goto_if_unset FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF, Script_DebugKecleonBirchUnhidden
	release
	end

Script_DebugKecleonScottUnhidden::
	msgbox Text_ScottUnhidden, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF, Script_DebugKecleonBirchHidden
	goto_if_unset FLAG_HIDE_WILLYSTAD_RIVAL_AND_THIEF, Script_DebugKecleonBirchUnhidden
	release
	end
	
Script_DebugKecleonBirchHidden::
	msgbox Text_BirchHidden, MSGBOX_DEFAULT
	closemessage
	msgbox Text_DebugBye, MSGBOX_DEFAULT
	release
	end
	
Script_DebugKecleonBirchUnhidden::
	msgbox Text_BirchUnhidden, MSGBOX_DEFAULT
	closemessage
	msgbox Text_DebugBye, MSGBOX_DEFAULT
	release
	end

Text_ScottHidden:
	.string "FLAG: HIDE SCOTT is set.\n"
	.string "Pikachu invisible.$"
	
Text_ScottUnhidden:
	.string "FLAG: HIDE SCOTT is unset.\n"
	.string "Pikachu visible.$"
	
Text_BirchHidden:
	.string "FLAG: HIDE BIRCH is set.\n"
	.string "Kirla invisible.$"
	
Text_BirchUnhidden:
	.string "FLAG: HIDE BIRCH is unset.\n"
	.string "Kirlia visible.$"


// ============================================================
// NPC INTERACTIONS. WILLYSTAD CITIZENS.
// ============================================================

SlateportCity_EventScript_OceanicMuseumSign:: @ 81DCF79
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_BattleTentSign:: @ 81DCF36
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign:: @ 81DCF82
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign:: @ 81DCF8B
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign:: @ 81DCF94
	msgbox SlateportCity_Text_CityHallSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OldWoman:: @ 81DCE63
	lock
	msgbox SlateportCity_Text_PeerHorizon, MSGBOX_NPC
	closemessage
	applymovement 6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_Girl:: @ 81DCE84
	msgbox SlateportCity_Text_MarketAndMart, MSGBOX_NPC
	end

SlateportCity_EventScript_FatMan:: @ 81DCED9
	//compare VAR_WILLYSTAD_CITY_STATE, 1
	//goto_if_eq SlateportCity_EventScript_FatManSternInterview
	lock
	faceplayer
	msgbox SlateportCity_Text_MarketBlockedTourist, MSGBOX_NPC
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_Man1:: @ 81DCEF6
	lock
	faceplayer
	compare VAR_WILLYSTAD_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1:: @ 81DCF17
	msgbox SlateportCity_Text_HotOutside, MSGBOX_NPC
	end

SlateportCity_EventScript_Maniac:: @ 81DCFBB
	msgbox SlateportCity_Text_BigCityLife, MSGBOX_NPC
	end

SlateportCity_EventScript_LittleGirl:: @ 81DCFBB
	msgbox SlateportCity_Text_LittleGirl, MSGBOX_NPC
	end

SlateportCity_EventScript_OldMan:: @ 81DCFDC
	lock
	faceplayer
	compare VAR_WILLYSTAD_CITY_STATE, 2
	goto_if_eq SlateportCity_EventScript_OldMan2
	msgbox SlateportCity_Text_OldMan, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldMan2::
	msgbox SlateportCity_Text_OldMan2, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Sailor1:: @ 81DCFE5
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2:: @ 81DCFEE
	msgbox SlateportCity_Text_MarketBlockedSailor, MSGBOX_NPC //edited
	end

SlateportCity_EventScript_Man2:: @ 81DD000
	msgbox SlateportCity_Text_RecentArrival, MSGBOX_NPC
	end

SlateportCity_EventScript_BlackBelt:: @ 81DD009
	msgbox SlateportCity_Text_Jungle, MSGBOX_NPC
	end

SlateportCity_EventScript_Pikachu:: @ 8215F80
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, 0
	msgbox SlateportCity_EventScript_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_EventScript_Text_Pikachu:
	.string "Pikachu: Piikaa!$"

SlateportCity_EventScript_Ty:: @ 81DD353
	lock
	msgbox SlateportCity_Text_CameraMan1, MSGBOX_SIGN
	release
	end

SlateportCity_EventScript_Gabby:: @ 81DD35C
	lock
	compare VAR_WILLYSTAD_CITY_STATE, 2
	goto_if_ge SlateportCity_EventScript_Gabby2
	msgbox SlateportCity_Text_Reporter1, MSGBOX_SIGN
	release
	end

SlateportCity_EventScript_Gabby2::
	compare VAR_WILLYSTAD_CITY_STATE, 4
	goto_if_ge SlateportCity_EventScript_Gabby3
	msgbox SlateportCity_Text_Reporter2, MSGBOX_SIGN
	release
	end

SlateportCity_EventScript_Gabby3::
	msgbox SlateportCity_Text_Reporter3, MSGBOX_SIGN
	release
	end

SlateportCity_EventScript_InMyShotScene:: @ 81DD5DC
	lockall
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox SlateportCity_Text_CameraMan2, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	waitmovement 0
//	opendoor 10, 12
//	waitdooranim
//	addobject 35
//	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
//	applymovement 35, SlateportCity_Movement_ScottExitBattleTent
//	waitmovement 0
//	closedoor 10, 12
//	waitdooranim
//	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
//	closemessage
//	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
//	applymovement 35, SlateportCity_Movement_ScottExitAfterBattleTent
//	waitmovement 0
//	removeobject 35
//	addvar VAR_SCOTT_STATE, 1
//	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown: @ 81DD630
	walk_down
	step_end

SlateportCity_Text_PeerHorizon: @ 81DD8A6
	.string "I love to stand on the docks and peer\n"
	.string "over the horizon.\p"
	.string "I wonder what is beyond it.$"

SlateportCity_Text_MarketAndMart: @ 81DD93D
	.string "The Willystad Market sells products\n"
	.string "from all across the Island.\p"
	.string "But the Pokémon Mart sells products\n"
	.string "from all across the world!$"

SlateportCity_Text_HotOutside: @ 81DDBAC
	.string "Whenever it's too hot outside, I like\n"
	.string "to go to a Pokémon Center.\p"
	.string "They're airconditioned!$"

SlateportCity_Text_Jungle: @ 81DDC4F
	.string "I just spent one month in the jungle\n"
	.string "with my Pokémon.\p"	
	.string "It was tough, but I can't wait to go\n"	
	.string "back again!$"

SlateportCity_Text_MarketBlockedSailor: @ 81DE04B //edited
	.string "Sorry kid! I'm unloading fresh goods\n"
	.string "to be sold at the Willystad Market.\p"
	.string "But first, let me take a break.$"

SlateportCity_Text_BigCityLife: @ 81DE10E
	.string "Whew! This city is big!\p"
	.string "I think I'm lost…$"

SlateportCity_Text_LittleGirl: @ 81DE16C
	.string "My father is a sailor!\l"
	.string "And my grandpa too!\p"
	.string "When I grow up, I want to be a\n"
	.string "sailor myself!$"

SlateportCity_Text_OldMan: @ 81DE16C
	.string "They say the towns on this Island were\n"
	.string "founded by six families, long ago.\p"
	.string "They arrived by boat from faraway\n"
	.string "lands.$"

SlateportCity_Text_OldMan2:
	.string "A strange chap just ran out of\n"
	.string "the City Hall.\p"
	.string "It looked like he was carrying\n"
	.string "something heavy.$"

SlateportCity_Text_RecentArrival: @ 81DE1EC
	.string "Hey, are you new in town as well?\p"
	.string "I came from overseas to study the\n"
	.string "unique Pokémon that live here!$"

SlateportCity_Text_CameraMan1: @ 81DE491
	.string "Shush, kid. Can't you see I'm working?$"

SlateportCity_Text_CameraMan2: @ 81DE491
	.string "Hey kid! You're in my shot!$"

SlateportCity_Text_Reporter1: @ 81DE4C4
	.string "We are standing here in front of the\n"
	.string "Willystad City Hall.\p"
	.string "In a few moments, the Mayor will reveal\n"
	.string "a new scientific discovery…\p"
	.string "Rumour has it that Prof. Buxus found\n"
	.string "something on one of his expeditions!$"

SlateportCity_Text_Reporter2: @ 81DE4C4
	.string "Breaking news from Willystad City!\p"
	.string "There has been a heist in the City\n"
	.string "Hall. A precious item was stolen.\p"
	.string "The thief was spotted fleeing the\n"
	.string "city in a haste.\l"
	.string "Will he be found?\l"
	.string "Stay tuned for more!$"

SlateportCity_Text_Reporter3:
	.string "Our latest information!\p"
	.string "The Fossil may have been returned,\n"
	.string "but questions remain…\l"
	.string "Who was the strange robber?\l"
	.string "How could this have happened?\l"
	.string "Is anyone still safe now?\l"
	.string "Should we all be afraid?\p"
	.string "This, and more, after the break.\n"
	.string "Back to the studio.$"

SlateportCity_Text_BattleTentSign: @ 81DE8BC
	.string "Prof. Buxus Laboratory\p"
	.string "“Studying the plants and Pokémon\n"
	.string "of Sigma Island.”$"

SlateportCity_Text_OceanicMuseumSign: @ 81DEA3B
	.string "Island Warehouse\n"
	.string "“Buy and sell your goods in bulk!”$"

SlateportCity_Text_CitySign: @ 81DEA6F
	.string "Willystad City\p"
	.string "“The Island's bustling trading\n"
	.string "port for over 300 years.”$"

SlateportCity_Text_MarketSign: @ 81DEAAF
	.string "Willystad Market\n"
	.string "“For local and exotic goods!”$"

SlateportCity_EventScript_Wingull::
	//lock
	applymovement 12, SlateportCity_Movement_WingullFlyEast
	waitmovement 0
	release
	end

SlateportCity_Movement_WingullFlyEast:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

// =======================================
// CUTSCENE: RIVAL INTRODUCTION, AUTO-PLAY
// =======================================

SlateportCity_EventScript_RivalIntroduction::
	//setobjectxy 2, 21, 15
	//addobject 2
	//setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	lockall
	//delay 30
	//applymovement 2, Common_Movement_FaceLeft
	//waitmovement 0
	//delay 30
	//applymovement 2, Common_Movement_FaceRight
	//waitmovement 0
	delay 30
	applymovement 2, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	playbgm MUS_RG_RIVAL1, 0
	delay 16
	msgbox SlateportCity_Text_Rival1, MSGBOX_DEFAULT
	closemessage
	delay 16
	fadescreen FADE_TO_BLACK
	special RivalNameChange
	fadescreen FADE_FROM_BLACK
	//waitstate
	delay 16
	msgbox SlateportCity_Text_Rival2, MSGBOX_DEFAULT
	closemessage
	applymovement 2, SlateportCity_Movement_RivalExit
	waitmovement 0
	//playse SE_PIN
	setflag FLAG_HIDE_WILLYSTAD_RIVAL_SPRITES
	removeobject 2
	//playse SE_PIN
	//setobjectxy 2, 40, 18
	//addobject 2
	//setobjectmovementtype 2, MOVEMENT_TYPE_LOOK_AROUND
	//delay 30
	//playse SE_PIN
	//showobjectat 2, MAP_SLATEPORT_CITY
	//delay 30
	//playse SE_PIN
	setvar VAR_WILLYSTAD_CITY_STATE, 2
	fadedefaultbgm
	releaseall
	end

//SlateportCity_EventScript_RivalNameChange::
	//lock
	//faceplayer
	//special RivalNameChange
	//release
	//end

SlateportCity_Text_Rival1:
	.string "???: Oh, hey there!\p"
	.string "Let's find this thief, shall\n"
	.string "we?\p"
	.string "By the way, what's your name?\n"
	.string "Wait, let me guess…\p"
	.string "It's {PLAYER}, am I right?\p"
	.string "Now you guess mine.$"

SlateportCity_Text_Rival2:
	.string "Wow, you guessed it right, too!\n"
	.string "My name is {RIVAL}!\p"
	.string "Now, let's not waste any more\n"
	.string "time on niceties, {PLAYER}.\p"
	.string "I will look for the thief\n"
	.string "in the Market.\l"
	.string "You go the other way!$"

SlateportCity_Movement_RivalExit:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right	
	walk_right
	walk_right
	walk_right
	step_end

// ===============================
// POST-CUTSCENE RIVAL INTERACTION
// ===============================

SlateportCity_EventScript_RivalSearching::
	msgbox SlateportCity_Text_Rival3, MSGBOX_NPC
	end

SlateportCity_Text_Rival3:
	.string "{RIVAL}: Hey, {PLAYER}!\n"
	.string "Found anything yet?\p"
	.string "I got this area covered.\n"
	.string "Check out the rest of town.$"

// =============================================
// REMAINING SCRIPTS FROM ORIGINAL GAME, UNUSED:
// =============================================
	
SlateportCity_EventScript_MovePeopleForSternInterview:: @ 81DCC99
	setobjectxyperm 11, 28, 13
	setobjectxyperm 7, 25, 13
	setobjectxyperm 3, 25, 14
	setobjectxyperm 6, 27, 16
	setobjectxyperm 8, 28, 16
	setobjectxyperm 1, 29, 16
	setobjectxyperm 2, 31, 14
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene:: @ 81DCCE7
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 30
	goto_if_eq SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm 35, 23, 27
	setobjectmovementtype 35, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft:: @ 81DCD06
	setobjectxyperm 35, 22, 27
	setobjectmovementtype 35, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_ScottScene:: @ 81DCD1C
	lockall
	addobject 35
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement 35, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement 35, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement 35, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement 35, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject 35
	setobjectxyperm 35, 10, 12
	setobjectmovementtype 35, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott: @ 81DCDA8
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

SlateportCity_Movement_ScottApproachPlayer: @ 81DCDAC
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit: @ 81DCDB4
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru:: @ 81DCDBD
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_Pokemart_EnergyGuru: @ 81DCDD4
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_EffortRibbonWoman:: @ 81DCDE4
	lock
	faceplayer
	bufferleadmonspeciesname 0
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	compare VAR_RESULT, FALSE
	call_if_eq SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed:: @ 81DCE2E
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon:: @ 81DCE38
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook:: @ 81DCE42
	lock
	faceplayer
	compare VAR_WILLYSTAD_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview:: @ 81DCE59
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview:: @ 81DCE7A
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview:: @ 81DCEA4
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase:: @ 81DCEAE
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy:: @ 81DCEB8
	lock
	faceplayer
	compare VAR_WILLYSTAD_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview:: @ 81DCECF
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatManSternInterview:: @ 81DCEED
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1SternInterview:: @ 81DCF0D
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone:: @ 81DCF2C
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end


SlateportCity_EventScript_SternsShipyardSign:: @ 81DCF3F
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion:: @ 81DCF5C
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete:: @ 81DCF66
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign:: @ 81DCF70
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSignFerryComplete:: @ 81DCFA8
	msgbox SlateportCity_Text_CityHallSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign:: @ 81DCFB2
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview:: @ 81DCFD2
	msgbox SlateportCity_Text_BigCityLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_PokefanF:: @ 81DCFF7
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt2:: @ 81DD020
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement 18, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3:: @ 81DD037
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement 19, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4:: @ 81DD04E
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement 26, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5:: @ 81DD065
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement 27, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6:: @ 81DD07C
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement 28, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7:: @ 81DD093
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement 29, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8:: @ 81DD0AA
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement 30, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9:: @ 81DD0C1
	lock
	faceplayer
	playse SE_PIN
	applymovement 31, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 31, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement 31, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement 31, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement 31, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement 31, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement 31, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement 31, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 31, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement 31, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt: @ 81DD147
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10:: @ 81DD14A
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11:: @ 81DD153
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement 33, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk:: @ 81DD16A
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls: @ 81DD184
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_ComeBackWithSecretPower:: @ 81DD18E
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk:: @ 81DD198
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemartDecor: @ 81DD1B8
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerk:: @ 81DD1D8
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs: @ 81DD1F0
	.2byte ITEM_TM10  @ Hidden Power
	.2byte ITEM_TM43  @ Secret Power
	.2byte ITEM_NONE
	release
	end

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern:: @ 81DD1F8
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement 10, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 10
	applymovement 9, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 25
	applymovement 11, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement 10, SlateportCity_Movement_GabbyExit
	applymovement 9, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject 10
	removeobject 9
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement 11, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_AQA_0, 0
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	applymovement 7, SlateportCity_Movement_OldWomanConcern
	applymovement 3, Common_Movement_QuestionMark
	applymovement 2, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement 11, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 11, Common_Movement_Delay48
	waitmovement 0
	applymovement 11, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement 11, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject 11
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_WILLYSTAD_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern: @ 81DD309
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

SlateportCity_Movement_ManConcern: @ 81DD311
	emote_question_mark
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

SlateportCity_Movement_GabbyExit: @ 81DD319
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit: @ 81DD326
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused: @ 81DD334
	walk_down
	walk_in_place_fastest_up
	step_end

SlateportCity_Movement_SternEnterHarbor: @ 81DD337
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit: @ 81DD33C
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor: @ 81DD344
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern: @ 81DD34A
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end


SlateportCity_EventScript_BerryPowderClerk:: @ 81DD36E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar:: @ 81DD39A
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder:: @ 81DD3C0
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem:: @ 81DD3CA
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder:: @ 81DD46E
	bufferitemname 0, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot:: @ 81DD482
	bufferitemname 0, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder:: @ 81DD496
	bufferitemname 0, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb:: @ 81DD4AA
	bufferitemname 0, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein:: @ 81DD4BE
	bufferitemname 0, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron:: @ 81DD4D2
	bufferitemname 0, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos:: @ 81DD4E6
	bufferitemname 0, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium:: @ 81DD4FA
	bufferitemname 0, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc:: @ 81DD50E
	bufferitemname 0, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp:: @ 81DD522
	bufferitemname 0, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp:: @ 81DD536
	bufferitemname 0, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect:: @ 81DD54A
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem:: @ 81DD557
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem:: @ 81DD5C1
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder:: @ 81DD5CE
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_Movement_PlayerWatchScottExit: @ 81DD634
	delay_16
	walk_in_place_fastest_right
	step_end

SlateportCity_Movement_ScottExitBattleTent: @ 81DD637
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent: @ 81DD63A
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign:: @ 81DD643
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed: @ 81DD64A
	.string "I'm the ENERGY GURU! I'll go for it and\n"
	.string "sell you what you need!$"

SlateportCity_Text_OhYourPokemon: @ 81DD68A
	.string "Oh?\n"
	.string "Your {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon: @ 81DD697
	.string "Went for it stupendously!\p"
	.string "As its reward, please give it this\n"
	.string "EFFORT RIBBON.$"

SlateportCity_Text_ReceivedEffortRibbon: @ 81DD6E3
	.string "{PLAYER} received the EFFORT RIBBON.$"

SlateportCity_Text_PutEffortRibbonOnMon: @ 81DD702
	.string "{PLAYER} put the EFFORT RIBBON\n"
	.string "on {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder: @ 81DD722
	.string "You have to go for it a little harder.\p"
	.string "If you do, I'll give your POKéMON\n"
	.string "something nice.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt: @ 81DD77B
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
	.string "RIBBON looks good on it!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon: @ 81DD7AD
	.string "The light of the lighthouse reaches\n"
	.string "dozens of miles away.\p"
	.string "I wonder if it doesn't startle POKéMON\n"
	.string "in the sea.$"

SlateportCity_Text_SeaweedFullOfLife: @ 81DD81A
	.string "Ooh, look at this!\p"
	.string "The seaweed you can get around these\n"
	.string "parts is fresh and full of life.\p"
	.string "Why, it looks like it can even rear up\n"
	.string "and attack!$"


SlateportCity_Text_BuyBricksSoDecorWontGetDirty: @ 81DD999
	.string "If you put DOLLS or CUSHIONS on\n"
	.string "the floor, they'll get dirty.\p"
	.string "I'm going to buy some BRICKS so my\n"
	.string "DOLLS and CUSHIONS won't get dirty\l"
	.string "when I leave them out.$"

SlateportCity_Text_GoingToCompeteInBattleTent: @ 81DDA34
	.string "Wroooar! I'm going to compete in\n"
	.string "the BATTLE TENT, too!\p"
	.string "But before that, I need to catch\n"
	.string "some POKéMON!$"

SlateportCity_Text_MarketBlockedTourist: @ 81DDA9A
	.string "Whoop-de-doo! I can't wait for the\n"
	.string "Willystad Market to open up.\p"
	.string "It is a must-visit for tourists like\n"
	.string "myself, or so I've heard.$"

SlateportCity_Text_EveryoneCallsHimCaptStern: @ 81DDB21
	.string "STERN, the fellow who built the\n"
	.string "MUSEUM, also happens to be the leader\l"
	.string "of an undersea exploration team.\p"
	.string "So, everyone calls him CAPT. STERN.$"

SlateportCity_Text_VisitedMuseumOften: @ 81DDBD5
	.string "When I was a child, I visited\n"
	.string "the MUSEUM often.\p"
	.string "I used to dream about the mysteries of\n"
	.string "the sea after seeing the exhibits.$"
	
SlateportCity_Text_AquaHasPolicy: @ 81DDC8A
	.string "TEAM AQUA has a policy of\n"
	.string "assembling and dispersing at\l"
	.string "the operation site.$"

SlateportCity_Text_BossIsBrilliant: @ 81DDCD5
	.string "Our BOSS is brilliant.\p"
	.string "What would he want to do with\n"
	.string "a MUSEUM now?$"

SlateportCity_Text_WhatsNewSchemeIWonder: @ 81DDD18
	.string "What's the new scheme, I wonder?\p"
	.string "Our BOSS is scary when he's mad, so\n"
	.string "I'd better not screw things up…$"

SlateportCity_Text_ShouldTakeItAll: @ 81DDD7D
	.string "If there's something we need in\n"
	.string "the MUSEUM, we should take it all!$"

SlateportCity_Text_DontButtIn: @ 81DDDC0
	.string "Hey, you there!\n"
	.string "Don't butt in!$"

SlateportCity_Text_RemindsMeOfLongLineForGames: @ 81DDDDF
	.string "A long line, huh?\p"
	.string "It reminds me of the times I lined up to\n"
	.string "buy smash-hit games…$"

SlateportCity_Text_WhyAreWeLiningUp: @ 81DDE2F
	.string "Why are we even lining up and paying?\n"
	.string "We should just march in!$"

SlateportCity_Text_WhatDoYouWant: @ 81DDE6E
	.string "What?\n"
	.string "What do you want?$"

SlateportCity_Text_IllReadSignForYou: @ 81DDE86
	.string "You want to read this sign?\n"
	.string "I'll read it for you!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless: @ 81DDEB8
	.string "Let's see…\p"
	.string "Um… I think it says something like\n"
	.string "“the life in the sea is endless.”\p"
	.string "Yup, I'm pretty sure that's what\n"
	.string "it says.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy: @ 81DDF32
	.string "Grumble…\p"
	.string "I should've brought my Game Boy\n"
	.string "Advance so I wouldn't get bored in line…\p"
	.string "Grumble…$"

SlateportCity_Text_HotSpringsAfterOperation: @ 81DDF8D
	.string "When this operation's over, I'll take\n"
	.string "you to a hot spring spa!\p"
	.string "That's what our leader said.\n"
	.string "I can't wait!$"

SlateportCity_Text_SeaIsSoWet: @ 81DDFF7
	.string "The sea is just so vast…\p"
	.string "Could the sea have been made by\n"
	.string "the tears shed by POKéMON?$"

SlateportCity_Text_BuyTooMuch: @ 81DE0D2
	.string "Whenever I visit here, I get carried\n"
	.string "away and buy too much.$"

SlateportCity_Text_CaptSternBeingInterviewed: @ 81DE28E
	.string "I was hoping that it was a famous star\n"
	.string "so I could get an autograph.\p"
	.string "But who's that being interviewed?\n"
	.string "Isn't that CAPT. STERN?$"

SlateportCity_Text_InterviewerSoCool: @ 81DE30C
	.string "That lady interviewer is so cool\n"
	.string "and pretty.\p"
	.string "When I grow up, I'm going to be\n"
	.string "an international journalist!$"

SlateportCity_Text_SternSaysDiscoveredSomething: @ 81DE376
	.string "CAPT. STERN says they discovered\n"
	.string "something at the bottom of the sea.\p"
	.string "I wonder what it is?\n"
	.string "What could it be?$"

SlateportCity_Text_CaptainComeBackWithBigFish: @ 81DE3E2
	.string "What's going on here?\p"
	.string "Did the good CAPTAIN come back with\n"
	.string "a big fish from the ocean floor?$"

SlateportCity_Text_AmIOnTV: @ 81DE43D
	.string "Hey! Are you watching?\n"
	.string "Am I on TV?$"

SlateportCity_Text_CaptainsACelebrity: @ 81DE460
	.string "A TV interview! Here!\n"
	.string "The CAPTAIN's a celebrity!$"

SlateportCity_Text_SternMoveAheadWithExploration: @ 81DE502
	.string "CAPT. STERN: Yes, indeed. We intend to\n"
	.string "move ahead with our exploration.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview: @ 81DE54A
	.string "GABBY: That's wonderful, CAPT. STERN!\n"
	.string "Thank you for taking the time from\l"
	.string "your busy schedule to talk to us.\p"
	.string "We hope we can interview you again\n"
	.string "with news of more discoveries!$"

SlateportCity_Text_SternWhewFirstInterview: @ 81DE5F7
	.string "CAPT. STERN: Whew…\p"
	.string "That was my first time to be filmed for\n"
	.string "TV. That was nerve-wracking.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery: @ 81DE64F
	.string "Oh! {PLAYER}{KUN}!\n"
	.string "You're looking great!\p"
	.string "We made a huge discovery on our last\n"
	.string "seafloor exploration.\p"
	.string "We found an underwater cavern on\n"
	.string "ROUTE 128.\p"
	.string "We think it's the habitat of a POKéMON\n"
	.string "that's said to have been long extinct.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine: @ 81DE724
	.string "Fufufu…\n"
	.string "CAPT. STERN, I presume.\p"
	.string "We of TEAM AQUA will assume\n"
	.string "control of your submarine!\p"
	.string "Your objections are meaningless!\n"
	.string "We expect your total cooperation!\p"
	.string "Fufufu…\n"
	.string "Just watch and learn what TEAM\l"
	.string "AQUA has planned!$"

SlateportCity_Text_SternWhatWasAllThat: @ 81DE7F7
	.string "CAPT. STERN: What was that all about?\p"
	.string "It sounded like someone using\n"
	.string "a megaphone…\p"
	.string "Where did it come from?$"

SlateportCity_Text_FromHarborTryingToTakeSub: @ 81DE860
	.string "It's from the HARBOR!\p"
	.string "The submarine!\n"
	.string "They're trying to take it!$"

SlateportCity_Text_PleaseComeWithMe: @ 81DE8A0
	.string "{PLAYER}{KUN}!\n"
	.string "Please, come with me!$"


SlateportCity_Text_SternsShipyardWantedSign: @ 81DE8F8
	.string "STERN'S SHIPYARD\p"
	.string "“Wanted: A sailor capable of sailing\n"
	.string "in all currents.”$"

SlateportCity_Text_SternsShipyardNearsCompletion: @ 81DE940
	.string "STERN'S SHIPYARD\p"
	.string "“The ferry S.S. TIDAL nears\n"
	.string "completion for serving the ports of\l"
	.string "SLATEPORT and LILYCOVE.”$"

SlateportCity_Text_SternsShipyardFerryComplete: @ 81DE9AA
	.string "STERN'S SHIPYARD\p"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
	.string "ferry S.S. TIDAL is handled at the\l"
	.string "HARBOR.”$"

SlateportCity_Text_PokemonFanClubSign: @ 81DEA0B
	.string "POKéMON FAN CLUB\n"
	.string "“Calling all fans of POKéMON!”$"

SlateportCity_Text_HarborFerryUnderConstruction: @ 81DEAE3
	.string "SLATEPORT HARBOR\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in the SHIPYARD.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"

SlateportCity_Text_CityHallSign: @ 81DEB5A
	.string "Willystad City Hall\p"
	.string "“Home to the Island Library\n"
	.string "and the Mayor's Office.”$"

SlateportCity_Text_NameRatersHouseSign: @ 81DEBA0
	.string "-----\n"
	.string "-----$"

SlateportCity_Text_ExplainBerries: @ 81DEBCE
	.string "If a wild POKéMON gets hurt, it heals\n"
	.string "itself by chewing on BERRIES.\p"
	.string "Did you know that?\p"
	.string "Somebody saw that and got the idea\n"
	.string "of making medicine from BERRIES.\p"
	.string "Did you know that?\p"
	.string "To turn BERRIES into medicine,\n"
	.string "they must be crushed into powder.\p"
	.string "Did you know that?\p"
	.string "You seem to have an interest\n"
	.string "in BERRIES!\p"
	.string "I've got something good for someone\n"
	.string "like you.$"

SlateportCity_Text_ExplainBerryPowder: @ 81DED27
	.string "I recently had machines installed at\n"
	.string "POKéMON CENTERS for crushing BERRIES.\p"
	.string "The BERRY CRUSH machines are at\n"
	.string "the DIRECT CORNER upstairs.\p"
	.string "Did you know?\p"
	.string "Could you make BERRY POWDER for\n"
	.string "me using those machines?\p"
	.string "I can make you all sorts of medicine\n"
	.string "if you bring me lots of BERRY POWDER.$"

SlateportCity_Text_BroughtMeSomeBerryPowder: @ 81DEE40
	.string "Have you brought me some\n"
	.string "BERRY POWDER?$"

SlateportCity_Text_ExchangeWhatWithIt: @ 81DEE67
	.string "What would you like to exchange\n"
	.string "it with?$"

SlateportCity_Text_ExchangeBerryPowderForItem: @ 81DEE90
	.string "Okay, you want to exchange your\n"
	.string "BERRY POWDER for one {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder: @ 81DEEC9
	.string "Oh, dear. You don't have enough\n"
	.string "BERRY POWDER.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse: @ 81DEEF7
	.string "This is fine BERRY POWDER.\n"
	.string "It will make excellent medicine.\p"
	.string "Would you like to trade more of your\n"
	.string "BERRY POWDER for something else?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe: @ 81DEF79
	.string "Okay! When you get some more\n"
	.string "BERRY POWDER, bring it to me, please!$"

SlateportCity_Text_ComeBackToTradeBerryPowder: @ 81DEFBC
	.string "Come back if you'd like to trade your\n"
	.string "BERRY POWDER for some medicine.\p"
	.string "I'm always running a bazaar here.\p"
	.string "Did you know?$"

SlateportCity_Text_YouDroveTeamAquaAway: @ 81DF032
	.string "SCOTT: Huh?\n"
	.string "I'm sure I met you somewhere before.\p"
	.string "Have I introduced myself to you?\n"
	.string "If not, my name's SCOTT.\p"
	.string "I just saw TEAM AQUA run away from\n"
	.string "here like they were stung.\p"
	.string "Let me guess--you drove them away?$"

SlateportCity_Text_MaybeThisTrainer: @ 81DF0FE
	.string "SCOTT: Hmm…\n"
	.string "Maybe, just maybe, this TRAINER…$"

SlateportCity_Text_LetsRegisterEachOther: @ 81DF12B
	.string "SCOTT: All right! I think you're going\n"
	.string "to become a good friend.\p"
	.string "So, let's register each other in our\n"
	.string "POKéNAVS.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott: @ 81DF1A6
	.string "Registered this SCOTT person\n"
	.string "in the POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou: @ 81DF1D3
	.string "SCOTT: What I'd like to do is tag along\n"
	.string "with you, but I do want to keep an eye\l"
	.string "on the talents of other people, too.\p"
	.string "So, I'll be off to roam other towns\n"
	.string "a bit more.\p"
	.string "Be seeing you, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge: @ 81DF28C
	.string "SCOTT: Oh, hey!\n"
	.string "If it isn't {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, let me guess--you're going\n"
	.string "to take the BATTLE TENT challenge?\p"
	.string "Yeah! That's a good idea!\n"
	.string "That's a really great idea!\p"
	.string "After all, a tough TRAINER is\n"
	.string "the perfect fit for the BATTLE TENT!\p"
	.string "Give it your best effort!$"
