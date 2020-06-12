RustboroCity_DevonCorp_1F_MapScripts:: @ 8211245
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition: @ 821124B
	//call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs:: @ 8211255
	setobjectxyperm 2, 14, 2
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_CrowdBurglar:: @ 821127F
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_1F_Text_CrowdBurglar, MSGBOX_DEFAULT
	closemessage
	applymovement 14, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_1F_EventScript_CrowdGirl:: @ 821127F
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_1F_Text_CrowdGirl, MSGBOX_DEFAULT
	closemessage
	applymovement 12, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_1F_EventScript_CrowdKarateGirl:: @ 821127F
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_1F_Text_CrowdKarateGirl, MSGBOX_DEFAULT
	closemessage
	applymovement 13, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Prof1::
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Prof5, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Mayor1::
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Mayor4, MSGBOX_NPC
	end

RustboroCity_DevonCorp_1F_EventScript_CrowdExpertF:: @ 821127F
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_1F_Text_CrowdExpertF, MSGBOX_DEFAULT
	closemessage
	applymovement 8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_1F_EventScript_CrowdMan:: @ 821127F
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_1F_Text_CrowdMan, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_1F_EventScript_CrowdPicknicker:: @ 821127F
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_1F_Text_CrowdPicknicker, MSGBOX_DEFAULT
	closemessage
	applymovement 10, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_1F_EventScript_CrowdOldMan:: @ 821127F
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_1F_Text_CrowdOldMan, MSGBOX_DEFAULT
	closemessage
	applymovement 9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_1F_EventScript_CrowdRangerM:: @ 821127F
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_1F_Text_CrowdRangerM, MSGBOX_DEFAULT
	closemessage
	applymovement 6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
RustboroCity_DevonCorp_1F_EventScript_CrowdHiker:: @ 821127F
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_1F_Text_CrowdHiker, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Cutscene1:: @ 8211289
	lockall
	delay 30
	//work in progress
	applymovement 2, RustboroCity_DevonCorp_1F_Movement_WalkInPlace
	waitmovement 0
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Mayor1, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	applymovement 4, Common_Movement_FaceRight
	waitmovement 0
	delay 16
	applymovement 4, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	applymovement 4, Common_Movement_FaceDown
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	applymovement 4, RustboroCity_DevonCorp_1F_Movement_WalkInPlace
	waitmovement 0
	delay 16
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Prof1, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Prof2, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Prof3, MSGBOX_DEFAULT
	closemessage
	delay 16
	playbgm MUS_RG_AJITO, 0
	delay 16
	applymovement 14, RustboroCity_DevonCorp_1F_Movement_Burglar1
	waitmovement 0
	playse SE_PIN
	delay 6
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Burglar1, MSGBOX_DEFAULT
	closemessage
	removeobject 5
	delay 30
	applymovement 14, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Burglar2, MSGBOX_DEFAULT
	closemessage
	applymovement 14, RustboroCity_DevonCorp_1F_Movement_Burglar2
	waitmovement 0
	removeobject 14
	applymovement 10, Common_Movement_FaceRight
	applymovement 13, Common_Movement_FaceRight
	applymovement 7, Common_Movement_FaceLeft
	applymovement 8, Common_Movement_FaceLeft
	applymovement 2, Common_Movement_FaceRight
	applymovement 4, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	applymovement 10, Common_Movement_FaceLeft
	applymovement 13, Common_Movement_FaceLeft
	applymovement 7, Common_Movement_FaceRight
	applymovement 8, Common_Movement_FaceRight
	waitmovement 0
	delay 16
	applymovement 9, Common_Movement_FaceLeft	
	applymovement 11, Common_Movement_FaceLeft
	applymovement 12, Common_Movement_FaceRight
	applymovement 6, Common_Movement_FaceRight
	waitmovement 0
	delay 16
	applymovement 9, Common_Movement_FaceRight	
	applymovement 11, Common_Movement_FaceRight
	applymovement 12, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	applymovement 6, Common_Movement_FaceLeft
	applymovement 2, Common_Movement_FaceDown
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	applymovement 7, Common_Movement_FaceUp
	applymovement 8, Common_Movement_FaceUp
	applymovement 13, Common_Movement_FaceUp
	applymovement 10, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	applymovement 6, Common_Movement_FaceUp
	applymovement 9, Common_Movement_FaceUp
	applymovement 11, Common_Movement_FaceUp
	applymovement 12, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	applymovement 2, RustboroCity_DevonCorp_1F_Movement_Mayor1
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Mayor2, MSGBOX_DEFAULT	
	waitmovement 0
	waitmessage
	closemessage
	applymovement 8, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Crowd1, MSGBOX_DEFAULT	
	waitmessage
	closemessage
	applymovement 8, RustboroCity_DevonCorp_1F_Movement_Crowd1
	waitmovement 0
	removeobject 8
	applymovement 12, RustboroCity_DevonCorp_1F_Movement_Crowd3
	applymovement 11, RustboroCity_DevonCorp_1F_Movement_Crowd4
	applymovement 7, RustboroCity_DevonCorp_1F_Movement_Crowd2
	waitmovement 0
	removeobject 7
	removeobject 12
	removeobject 11
	applymovement 6, RustboroCity_DevonCorp_1F_Movement_WalkInPlace
	waitmovement 0
	delay 30
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Crowd3, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 6, RustboroCity_DevonCorp_1F_Movement_Crowd5
	waitmovement 0
	applymovement 13, RustboroCity_DevonCorp_1F_Movement_WalkInPlace
	waitmovement 0
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Crowd4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 13, RustboroCity_DevonCorp_1F_Movement_Crowd6
	waitmovement 0
	removeobject 6
	removeobject 13
	delay 30
	applymovement 9, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Crowd2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 9, RustboroCity_DevonCorp_1F_Movement_Crowd7
	waitmovement 0
	removeobject 9
	applymovement 10, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	delay 30
	playse SE_PIN
	delay 6
	playse SE_PIN
	applymovement 10, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	delay 30
	applymovement 10, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	delay 30
	applymovement 2, RustboroCity_DevonCorp_1F_Movement_WalkInPlace
	waitmovement 0
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Mayor3, MSGBOX_DEFAULT
	closemessage
	applymovement 4, RustboroCity_DevonCorp_1F_Movement_Prof1
	waitmovement 0
	delay 16
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Prof4, MSGBOX_DEFAULT
	closemessage
	delay 16
	fadescreen FADE_TO_BLACK
	delay 16
	special ChooseStarter
	waitstate
	delay 8
	playfanfare MUS_FANFA4
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Fanfare1, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 16
	applymovement 10, Common_Movement_WalkUp
	waitmovement 0
	applymovement 10, Common_Movement_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_FaceLeft
	waitmovement 0
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Rival1, MSGBOX_DEFAULT
	closemessage
	delay 16
	playfanfare MUS_FANFA4
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Fanfare2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	applymovement 10, Common_Movement_FaceUp
	waitmovement 0
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Rival2, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_1F_Movement_Player1
	applymovement 10, RustboroCity_DevonCorp_1F_Movement_Rival1
	waitmovement 0
	removeobject 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Prof5, MSGBOX_DEFAULT
	closemessage
	applymovement 4, RustboroCity_DevonCorp_1F_Movement_Prof2
	waitmovement 0
	fadedefaultbgm
	setflag FLAG_DEVON_GOODS_STOLEN
	setvar VAR_SLATEPORT_CITY_STATE, 1
	clearflag FLAG_HIDE_SLATEPORT_CITY_SCOTT
	clearflag FLAG_HIDE_ROUTE_101_BIRCH
	releaseall
	end

RustboroCity_DevonCorp_1F_EventScript_ChooseStarterDebug::
	lockall
	faceplayer
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Prof4, MSGBOX_DEFAULT
	closemessage
	delay 16
	special ChooseStarter
	waitstate
	lockall
	delay 30
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Rival1, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_FANFA4
	msgbox RustboroCity_DevonCorp_1F_Text_Cutscene1Fanfare1, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	releaseall
	end

RustboroCity_DevonCorp_1F_Movement_Burglar1:: @ 821127F
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	face_up
	step_end

RustboroCity_DevonCorp_1F_Movement_Burglar2:: @ 821127F
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RustboroCity_DevonCorp_1F_Movement_WalkInPlace:: @ 821127F
	walk_in_place_down
	walk_in_place_down
	step_end

RustboroCity_DevonCorp_1F_Movement_Mayor1:: @ 821127F
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

RustboroCity_DevonCorp_1F_Movement_Crowd1:: @ 821127F
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RustboroCity_DevonCorp_1F_Movement_Crowd2:: @ 821127F
	walk_slow_down
	walk_slow_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
RustboroCity_DevonCorp_1F_Movement_Crowd3:: @ 821127F
	face_right
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
RustboroCity_DevonCorp_1F_Movement_Crowd4:: @ 821127F
	face_left
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RustboroCity_DevonCorp_1F_Movement_Crowd5:: @ 821127F
	face_up
	delay_16
	walk_right
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RustboroCity_DevonCorp_1F_Movement_Crowd6:: @ 821127F
	walk_left
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RustboroCity_DevonCorp_1F_Movement_Crowd7:: @ 821127F
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RustboroCity_DevonCorp_1F_Movement_Prof1:: @ 821127F
	walk_down
	walk_left
	face_down
	step_end

RustboroCity_DevonCorp_1F_Movement_Rival1:: @ 821127F
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RustboroCity_DevonCorp_1F_Movement_Player1:: @ 821127F
	delay_16
	face_down
	step_end

RustboroCity_DevonCorp_1F_Movement_Prof2:: @ 821127F
	walk_right
	walk_up
	face_down
	step_end

RustboroCity_DevonCorp_1F_EventScript_Employee:: @ 8211261
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright:: @ 821127F
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered:: @ 8211289
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard:: @ 8211293
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome:: @ 82112BA
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed:: @ 82112C4
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter:: @ 82112CE
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp:: @ 82112F5
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed:: @ 82112FF
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay:: @ 8211309
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay:: @ 8211312
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_CrowdHiker:
	.string "I hiked all the way from Mt. Snow to\n"
	.string "see this reveal.$"

RustboroCity_DevonCorp_1F_Text_CrowdRangerM:
	.string "I'm curious to know what Prof. Buxus\n"
	.string "found this time around!$"

RustboroCity_DevonCorp_1F_Text_CrowdKarateGirl:
	.string "What a crowd!\p"
	.string "I can hardly see anything from here.$"

RustboroCity_DevonCorp_1F_Text_CrowdMan:
	.string "The Mayor is about to make an\n"
	.string "announcement. Find a spot!$"

RustboroCity_DevonCorp_1F_Text_CrowdGirl:
	.string "Prof. Buxus often goes on expedition.\n"
	.string "He doesn't like sitting in his lab.$"

RustboroCity_DevonCorp_1F_Text_CrowdExpertF:
	.string "Science uncovers the secrets of\n"
	.string "nature, one discovery at a time.$"

RustboroCity_DevonCorp_1F_Text_CrowdPicknicker:
	.string "Is that a fossil?\p"
	.string "Oh no, it's the Mayor!$"

RustboroCity_DevonCorp_1F_Text_CrowdOldMan:
	.string "That Buxus fellow is an adventurous\n"
	.string "type.\p"
	.string "I used to be like him, back in the days.$"

RustboroCity_DevonCorp_1F_Text_CrowdBurglar:
	.string "What do you want, kid?\n"
	.string "I'm not doing anything illegal!$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Mayor1:
	.string "Mayor: Welcome, dear Islanders and\n"
	.string "strangers from afar.\p"
	.string "My name is Bertha,\n"
	.string "Mayor of Willystad City.\p"
	.string "When Willy the Great, founder of this\n"
	.string "city, first set foot on this Island,\p"
	.string "he immediately recognized the beauty\n"
	.string "and power its nature had to offer.\p" 
	.string "To this day, we continue to learn more\n"
	.string "about the secrets of this Island.\p"
	.string "Because the scientists of today are\n"
	.string "like the explorers of yesteryear!\p"
	.string "And so, I am happy to announce a new\n"
	.string "discovery, which will bring pride and\l"
	.string "power to our glorious city!\p"
	.string "It is my pleasure to give the word\n"
	.string "to the renowned Prof. Buxus.$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Prof1:
	.string "Huh, oh, yes. Yes, alright.\p"
	.string "Well, my name is Buxus. I study the\n"
	.string "science of flora and Pokémon.\p"
	.string "Flora, that is flowers and plants.\p"
	.string "And Pokémon, well, you know what\n"
	.string "that is.$"
	
RustboroCity_DevonCorp_1F_Text_Cutscene1Prof2:
	.string "In a recent expedition, our team\n"
	.string "found this artefact.\p"
	.string "It is a fossil of a flower. One that\n"
	.string "I have never seen before.$"
	
RustboroCity_DevonCorp_1F_Text_Cutscene1Prof3:
	.string "We know that some plants can give\n"
	.string "humans and Pokémon strength.\p"
	.string "Other plants have healing properties.\p"
	.string "But this fossil… It shows traces\n"
	.string "of an unknown kind of energy.\p"
	.string "We need to study it further. But it\n"
	.string "truly is one of its kind.\p"
	.string "That also makes it one of the rarest\n"
	.string "and most valuable fossils in the world!$"
	//.string "We need to study it further. But it seems this\n"
	//.string "is the rarest and most valuable fossil on this Island.\p"
	//.string "We need to study it further. But either\n"
	//.string "way, this is a thrilling time for science!\p"
	//.string "When we're done, the fossil will be donated to \n"
	//.string "new species of plants.\p"
	//.string "It is my honour to give the word to the\n"
	//.string "renowned Prof. Buxus.$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Burglar1:
	.string "???: Well, doc. Sounds like this will\n"
	.string "sell for a good buck!\p"
	.string "I'll take it from here, then.$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Burglar2:
	.string "???: This city got rich by trading goods\n"
	.string "that were stolen from others!\l"
	.string "And now I will do the same!\p"
	.string "So long, Slowpokes!$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Mayor2:
	.string "Mayor: We cannot let this happen!\p"
	.string "I need a brave trainer to pursue\n"
	.string "this heinous thief!$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Crowd1:
	.string "Old Lady: Oh my! Look at the time!$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Crowd2:
	.string "Old Man: Good luck, kiddos.\n"
	.string "You've got this!$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Crowd3:
	.string "Young Man: Shoot! I forgot to\n"
	.string "water my Berries.$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Crowd4:
	.string "Young Woman: Uhh… Me too!$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Mayor3:
	.string "Mayor: Very well. It seems we've\n"
	.string "got ourselves two volunteers.$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Prof4:
	.string "Prof. Buxus: {PLAYER}, this is\n"
	.string "very noble of you.\p"
	.string "Here, please take one of these\n"
	.string "Pokémon to keep you safe.$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Rival1:
	.string "???: Alright, then. I will take\n"
	.string "the other one.$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Fanfare1:
	.string "{PLAYER} obtained the Pokémon.$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Fanfare2:
	.string "??? obtained the Pokémon.$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Rival2:
	.string "???: Don't worry, Mayor. We will\n"
	.string "catch this bandit right away!$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Prof5:
	.string "Prof. Buxus: Good luck, {PLAYER}!\p"
	.string "We'll be waiting.$"

RustboroCity_DevonCorp_1F_Text_Cutscene1Mayor4:
	.string "Mayor: Godspeed, young trainer.\p"
	.string "Please catch that thief.$"
	
RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp: @ 821131B
	.string "Hello and welcome to the DEVON\n"
	.string "CORPORATION.\p"
	.string "We're proud producers of items and\n"
	.string "medicine that enhance your life.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed: @ 821138B
	.string "One of our research staff stupidly\n"
	.string "got robbed of an important parcel.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct: @ 82113D1
	.string "Hey, those RUNNING SHOES!\n"
	.string "They're one of our products!\p"
	.string "It makes me happy when I see someone\n"
	.string "using something we made.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright: @ 8211446
	.string "That stolen parcel…\p"
	.string "Well, sure it's important, but it's not\n"
	.string "anything that anyone can use.\p"
	.string "In my estimation, that robber must not\n"
	.string "have been very bright.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered: @ 82114DE
	.string "It sounds like they've recovered\n"
	.string "the ripped-off DEVON GOODS.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter: @ 821151B
	.string "I'm sorry, only authorized people\n"
	.string "are allowed to enter here.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed: @ 8211558
	.string "It's beyond stupid.\n"
	.string "How could we get robbed?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere: @ 8211585
	.string "Hi, there!\n"
	.string "You're always welcome here!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay: @ 82115AC
	.string "Samples of rocks and metal are\n"
	.string "displayed in the glass case.\p"
	.string "There's a panel with some writing\n"
	.string "on it…\p"
	.string "“DEVON CORPORATION got its start as\n"
	.string "a producer of stones from quarries.\p"
	.string "“The company also produced iron from\n"
	.string "filings in the sand.\p"
	.string "“From that humble start as a producer\n"
	.string "of raw materials, DEVON developed.\p"
	.string "“DEVON is now a manufacturer of a wide\n"
	.string "range of industrial products.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay: @ 8211722
	.string "Prototypes and test products fill\n"
	.string "the glass display case.\p"
	.string "There's a panel with a description…\p"
	.string "“In addition to industrial products,\n"
	.string "DEVON now markets sundries and\l"
	.string "pharmaceuticals for better lifestyles.\p"
	.string "“Recently, DEVON has begun marketing\n"
	.string "tools for POKéMON TRAINERS, including\l"
	.string "POKé BALLS and POKéNAV systems.”$"

