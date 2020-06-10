SlateportCity_PokemonCenter_1F_MapScripts:: @ 820DABF
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition: @ 820DACA
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

@ VAR_0x800B is the Nurse's object event id
SlateportCity_PokemonCenter_1F_EventScript_Nurse:: @ 820DAD3
	setvar VAR_0x800B, 1
	getpartysize
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_PokemonCenter_1F_EventScript_PlayerHasNoPokemon
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_PlayerHasNoPokemon::
	msgbox SlateportCity_PokemonCenter_1F_Text_PlayerHasNoPokemon, MSGBOX_DEFAULT
	release
	end
	
SlateportCity_PokemonCenter_1F_EventScript_Sailor:: @ 820DAE1
	msgbox SlateportCity_PokemonCenter_1F_Text_WillyTheGreat, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman:: @ 820DAEA
	msgbox SlateportCity_PokemonCenter_1F_Text_IntoTheWild, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_WillyTheGreat: @ 820DAF3
	.string "This city is named after its founder,\n"
	.string "Willy the Great.\p"
	.string "I wish I had a city named after myself.$"

SlateportCity_PokemonCenter_1F_Text_IntoTheWild: @ 820DBBC
	.string "I'm mustering up courage to go out\n"
	.string "into the wild with my Pokémon.\p"
	.string "My mom tells me I'm strong enough,\n"
	.string "but I don't feel ready yet.$"

SlateportCity_PokemonCenter_1F_Text_PlayerHasNoPokemon:
	.string "Hello, and welcome to the Pokémon Center.\n"
	.string "We restore your tired Pokémon to full health.\p"
	.string "You don't seem to have any Pokémon yet. Feel\n"
	.string "free to come back later.$"
