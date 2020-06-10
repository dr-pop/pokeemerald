RustboroCity_Flat2_1F_MapScripts:: @ 8215F76
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman:: @ 8215F77
	msgbox RustboroCity_Flat2_1F_Text_RichCity, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty:: @ 8215F80
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_RichCity: @ 8215F93
	.string "Our city has become rich through trade,\n"
	.string "but we don't produce anything.\p"
	.string "Without the other towns on the Island,\n"
	.string "we would be nothing.$"

RustboroCity_Flat2_1F_Text_Skitty: @ 8215FC6
	.string "Skitty: Gyaaaah!$"

