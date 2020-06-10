RustboroCity_Flat1_1F_MapScripts:: @ 82150CD
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man:: @ 82150CE
	msgbox RustboroCity_Flat1_1F_Text_Man, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman:: @ 82150D7
	msgbox RustboroCity_Flat1_1F_Text_Woman, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_Man: @ 82150E0
	.string "What's for dinner today?\n"
	.string "My specialty, Seaweed Stew!$"

RustboroCity_Flat1_1F_Text_Woman: @ 8215115
	.string "My husband likes to cook.\p"
	.string "I don't dare to tell him the truth.$"
