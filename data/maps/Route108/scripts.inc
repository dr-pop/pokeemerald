Route108_MapScripts:: @ 81EE689
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Test_OnFrame
	.byte 0

Test_OnFrame: @ 81DCD12
	map_script_2 VAR_EVER_GRANDE_CITY_STATE, 1, Test_EventScript_IntroTest_Simple
	map_script_2 VAR_EVER_GRANDE_CITY_STATE, 0, Test_EventScript_IntroTest_Simple
	.2byte 0

// === Simple version ===

Test_EventScript_IntroTest_Simple::
	lock
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Simple_EnterPlayer // move camera up
	waitmovement 0
	applymovement 1, Simple_EnterSub // move camera up
	//playse SE_MIZU           // Puddle
	//waitse
	waitmovement 0
	applymovement 5, Simple_WingullGlide1
	applymovement 4, Simple_WingullGlide2
	applymovement 2, Simple_WingullGlide3
	applymovement 1, Simple_PlayerSub1
	applymovement OBJ_EVENT_ID_PLAYER, Simple_PlayerSub1
	delay 60
	delay 60
	delay 60
	delay 60
	playmoncry SPECIES_WINGULL, 0
	delay 60
	delay 60
	playmoncry SPECIES_WINGULL, 0
	delay 60
	delay 60
	delay 30
	playmoncry SPECIES_WINGULL, 0
	waitmovement 0
	setvar VAR_EVER_GRANDE_CITY_STATE, 2
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ABANDONED_SHIP_CAPTAINS_OFFICE, 255, 5, 4
	waitstate
	release
	end

Simple_EnterPlayer:
	set_invisible
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

Simple_EnterSub:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end
	
Simple_PlayerSub1: // 38 steps
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	step_end

Simple_WingullGlide1:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	step_end

Simple_WingullGlide2:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	step_end

Simple_WingullGlide3:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	step_end

/*

// === New debug attempts ===

Test_EventScript_IntroTest_Debug::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Debug_Enter // move camera to the right
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Debug_Player // move camera and wingull and sub up
	applymovement 1, Debug_Player // Debug_Sub
	applymovement 2, Debug_Player
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Debug_All // move camera and wingull and sub right
	applymovement 1, Debug_All
	applymovement 2, Debug_All
	waitmovement 0
	warp MAP_ABANDONED_SHIP_CAPTAINS_OFFICE, 255, 5, 4
	waitstate
	release
	end
	
	
Debug_Enter: // 16 steps
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Debug_Player: // 4 (part 2) + 5 (part 3) steps + 5 steps up (part 4)
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Debug_Sub: // 4 steps up (new part 2) + in position (part 3) + 8 steps right (part 4)
	walk_up
	walk_up
	walk_up
	walk_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_right
	
Debug_All:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end


// === Original attempt ===

Test_EventScript_IntroTest::
	lock
	delay 60
	//applymovement 1, Test_Movement_SubMove1 //move sub in position
	applymovement OBJ_EVENT_ID_PLAYER, Test_Movement_PlayerMove1 //move player/camera to rocks
	waitmovement 0
	//msgbox Debug_Ocean1, MSGBOX_DEFAULT 
	// play water sound
	// azumarill emote ?
	// azumarill movement
	// play water sound again
	// azumarill movement face up
	// azumarill emote !
	delay 120
	playse SE_W127 // bubblebeam sound
	//waitfanfare
	delay 16
	applymovement 3, Test_Movement_Azu1
	waitmovement 0
	delay 30
	playse SE_PIN
	applymovement 3, Test_Movement_Azu2
	waitmovement 0
	delay 120
	playse SE_W127 // bubble sound
	//waitfanfare
	delay 16
	applymovement 3, Test_Movement_Azu3
	waitmovement 0
	delay 30
	playse SE_PIN
	applymovement 3, Test_Movement_Azu4
	waitmovement 0
	// wingull face up
	// wingull emote !
	delay 60
	//applymovement 1, Test_Movement_SubMove2
	//applymovement 2, Test_Movement_WingullMove1_1
	//applymovement 4, Test_Movement_WingullMove2_1
	//applymovement 5, Test_Movement_WingullMove3_1
	applymovement 2, Test_Movement_PlayerMove2
	applymovement 4, Test_Movement_PlayerMove2
	//applymovement 5, Test_Movement_PlayerMove2
	applymovement OBJ_EVENT_ID_PLAYER, Test_Movement_PlayerMove2
	//waitmovement 2
	//waitmovement 4
	//waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement 0
	//msgbox Debug_Ocean2, MSGBOX_DEFAULT 
	applymovement 1, Test_Movement_SubMove3
	//applymovement 2, Test_Movement_WingullMove1_2
	//applymovement 4, Test_Movement_WingullMove2_2
	//applymovement 5, Test_Movement_WingullMove3_2
	applymovement OBJ_EVENT_ID_PLAYER, Test_Movement_PlayerMove3
	applymovement 2, Test_Movement_PlayerMove3
	applymovement 4, Test_Movement_PlayerMove3
	//applymovement 5, Test_Movement_PlayerMove3
	//waitmovement 1
	//waitmovement 2
	//waitmovement 4
	//waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement 0
	//msgbox Debug_Ocean3, MSGBOX_DEFAULT 
	applymovement OBJ_EVENT_ID_PLAYER, Test_Movement_PlayerMove4
	//applymovement 2, Test_Movement_WingullMove1_3
	//applymovement 4, Test_Movement_WingullMove2_3
	//applymovement 5, Test_Movement_WingullMove3_3
	//applymovement 2, Test_Movement_PlayerMove4
	//applymovement 4, Test_Movement_PlayerMove4
	applymovement 1, Test_Movement_SubMove4
	//applymovement 5, Test_Movement_PlayerMove4
	waitmovement 0
	//waitmovement OBJ_EVENT_ID_PLAYER
	//waitmovement 1
	//waitmovement 2
	//waitmovement 4
	//msgbox Debug_Ocean4, MSGBOX_DEFAULT 
//	applymovement OBJ_EVENT_ID_PLAYER, Test_Movement_PlayerMoveX
//	applymovement 1, Test_Movement_SubMoveX
//	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Test_Movement_PlayerSubMove
	//applymovement 2, Test_Movement_WingullMove_4
	//applymovement 4, Test_Movement_WingullMove_4
	//applymovement 5, Test_Movement_WingullMove_4
	applymovement 2, Test_Movement_PlayerSubMove
	applymovement 4, Test_Movement_PlayerSubMove
	//applymovement 5, Test_Movement_PlayerSubMove
	applymovement 1, Test_Movement_PlayerSubMove
	waitmovement 1
	waitmovement 2
	waitmovement 4
	waitmovement OBJ_EVENT_ID_PLAYER
	//msgbox Debug_Ocean5, MSGBOX_DEFAULT 
	//delay 60
	applymovement 1, Test_Movement_SubIdle
	waitmovement 0
	setvar VAR_EVER_GRANDE_CITY_STATE, 0
	warp MAP_ABANDONED_SHIP_CAPTAINS_OFFICE, 255, 5, 4
	waitstate
	release
	end

Test_Movement_PlayerMove1: //16 steps right // longer
	set_invisible
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

Test_Movement_SubMove1: //10 right
	set_invisible
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

Test_Movement_Azu1:
	jump_in_place_down
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_down
	step_end

Test_Movement_Azu2:	
	emote_question_mark
	step_end

Test_Movement_Azu3:
	jump_in_place_down
	delay_8
	jump_in_place_down
	delay_16
	delay_16
	face_left
	delay_16
	delay_8
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	delay_8
	step_end
	
Test_Movement_Azu4:
	emote_exclamation_mark
	delay_16
	delay_16
	walk_up
	walk_up
	step_end
	
Test_Movement_PlayerMove2: // 4 steps up
	set_visible
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up //
	step_end

Test_Movement_SubMove2: // 4 steps up // equally long
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

Test_Movement_WingullMove1_1: // too far
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_diag_northwest
	walk_diag_northwest
	walk_up
	walk_up
	//walk_up
	//walk_diag_northeast
	//walk_diag_northeast
	//walk_up
	step_end

Test_Movement_WingullMove2_1: // too far
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_up
	walk_up
	walk_up
	walk_up
	//walk_up
	//walk_up
	//walk_diag_northeast
	//walk_diag_northeast
	step_end
	
Test_Movement_WingullMove3_1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	//walk_diag_northwest
	//walk_diag_northwest
	walk_up
	walk_up
	step_end
	
Test_Movement_PlayerMove3: // 4 up //not clear which one longer
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up //
	walk_slow_up
	step_end

Test_Movement_SubMove3:	
	set_invisible
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_right
	set_visible
	step_end

Test_Movement_WingullMove1_2:
	walk_up
	walk_up
	walk_up
	walk_up
	//walk_diag_northwest
	//walk_diag_northwest
	walk_up
	walk_up
	walk_up
	step_end

Test_Movement_WingullMove2_2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	//walk_diag_northeast
	//walk_diag_northeast
	walk_up
	walk_up
	step_end

Test_Movement_WingullMove3_2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	//walk_diag_northeast
	walk_up
	step_end

Test_Movement_PlayerMove4:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up //
	step_end
	
Test_Movement_SubMove4:	// longer
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	//walk_slow_right
	//walk_slow_right
	step_end	

Test_Movement_WingullMove1_3:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_up
	walk_up
	step_end
	
Test_Movement_WingullMove2_3:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_up
	walk_up
	step_end
	
Test_Movement_WingullMove3_3:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

Test_Movement_PlayerSubMove:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right //10
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right //20
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right //30
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right //34
	step_end	

Test_Movement_WingullMove_4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Test_Movement_SubIdle:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	step_end

Debug_Ocean1:
	.string "Phase 1 done.$"
	
Debug_Ocean2:
	.string "Phase 2 done.$"
	
Debug_Ocean3:
	.string "Phase 3 done.$"
	
Debug_Ocean4:
	.string "Phase 4 done.$"
	
Debug_Ocean5:
	.string "Phase 5 done.$"

Test_Movement_PlayerMoveX:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end
	
Test_Movement_SubMoveX:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

//=========

*/

Route108_EventScript_Jerome:: @ 81EE68A
	trainerbattle_single TRAINER_JEROME, Route108_Text_JeromeIntro, Route108_Text_JeromeDefeated
	msgbox Route108_Text_JeromePostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Matthew:: @ 81EE6A1
	trainerbattle_single TRAINER_MATTHEW, Route108_Text_MatthewIntro, Route108_Text_MatthewDefeated
	msgbox Route108_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Tara:: @ 81EE6B8
	trainerbattle_single TRAINER_TARA, Route108_Text_TaraIntro, Route108_Text_TaraDefeated
	msgbox Route108_Text_TaraPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Missy:: @ 81EE6CF
	trainerbattle_single TRAINER_MISSY, Route108_Text_MissyIntro, Route108_Text_MissyDefeated
	msgbox Route108_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Carolina:: @ 81EE6E6
	trainerbattle_single TRAINER_CAROLINA, Route108_Text_CarolinaIntro, Route108_Text_CarolinaDefeated
	msgbox Route108_Text_CarolinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Cory:: @ 81EE6FD
	trainerbattle_single TRAINER_CORY_1, Route108_Text_CoryIntro, Route108_Text_CoryDefeated, Route108_EventScript_CoryRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route108_EventScript_CoryRematch
	msgbox Route108_Text_CoryPostBattle, MSGBOX_DEFAULT
	release
	end

Route108_EventScript_CoryRegisterMatchCallAfterBattle:: @ 81EE729
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route108_Text_CoryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CORY_1
	release
	end

Route108_EventScript_CoryRematch:: @ 81EE748
	trainerbattle_rematch TRAINER_CORY_1, Route108_Text_CoryRematchIntro, Route108_Text_CoryRematchDefeated
	msgbox Route108_Text_CoryRematchPostBattle, MSGBOX_AUTOCLOSE
	end

