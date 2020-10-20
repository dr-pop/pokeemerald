RustboroCity_Flat2_2F_MapScripts:: @ 8215FD7
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan:: @ 8215FD8
	msgbox RustboroCity_Flat2_2F_Text_MayorFounder, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_Grandchild:: @ 8215FE1
	msgbox RustboroCity_Flat2_2F_Text_Grandchild, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall:: @ 8216010
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_MayorFounder: @ 821601A
	.string "The Mayor of Willystad descends from\n"
	.string "the founder of the city.\p"
	.string "Do you think that's a coincidence?$"

RustboroCity_Flat2_2F_Text_Grandchild: @ 821605A
	.string "Grandpa is amazing!\p"
	.string "He knows so much history!$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo: @ 82160BD
	.string "My daddy's working at the CORPORATION.\p"
	.string "When I grow up, I'm going to work for\n"
	.string "DEVON, too.$"

