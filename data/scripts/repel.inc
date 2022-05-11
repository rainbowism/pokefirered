EventScript_RepelWoreOff:: @ 81BFB65
	lockall
	compare VAR_REPEL_TYPE_USED, ITEM_REPEL
	goto_if_eq EventScript_UseRepel
	compare VAR_REPEL_TYPE_USED, ITEM_SUPER_REPEL
	goto_if_eq EventScript_UseSuperRepel
	compare VAR_REPEL_TYPE_USED, ITEM_MAX_REPEL
	goto_if_eq EventScript_UseMaxRepel
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	releaseall
	end

EventScript_UseRepel::
	checkitem ITEM_REPEL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_UseAnotherRepel
	setvar VAR_REPEL_TYPE_USED, 0
	goto EventScript_RepelWoreOff
	end

EventScript_UseSuperRepel::
	checkitem ITEM_SUPER_REPEL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_UseAnotherRepel
	setvar VAR_REPEL_TYPE_USED, 0
	goto EventScript_RepelWoreOff
	end

EventScript_UseMaxRepel::
	checkitem ITEM_MAX_REPEL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_UseAnotherRepel
	setvar VAR_REPEL_TYPE_USED, 0
	goto EventScript_RepelWoreOff
	end

EventScript_UseAnotherRepel::
	msgbox Text_UseAnotherRepel, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_RepelExit
	copyvar VAR_REPEL_STEP_COUNT, VAR_REPEL_STEP_USED
	playse SE_REPEL
	waitse
	compare VAR_REPEL_TYPE_USED, ITEM_REPEL
	goto_if_eq EventScript_UsedRepel
	compare VAR_REPEL_TYPE_USED, ITEM_SUPER_REPEL
	goto_if_eq EventScript_UsedSuperRepel
	compare VAR_REPEL_TYPE_USED, ITEM_MAX_REPEL
	goto_if_eq EventScript_UsedMaxRepel
	end

EventScript_UsedRepel::
	removeitem ITEM_REPEL
	msgbox Text_UsedRepel, MSGBOX_SIGN
	releaseall
	end

EventScript_UsedSuperRepel::
	removeitem ITEM_SUPER_REPEL
	msgbox Text_UsedSuperRepel, MSGBOX_SIGN
	releaseall
	end

EventScript_UsedMaxRepel::
	removeitem ITEM_MAX_REPEL
	msgbox Text_UsedMaxRepel, MSGBOX_SIGN
	releaseall
	end

EventScript_RepelExit::
	releaseall
	end

Text_RepelWoreOff:: @ 81BFB6E
	.string "REPEL's effect wore off…$"

Text_UseAnotherRepel::
	.string "REPEL's effect wore off…\n"
	.string "Use another?$"

Text_UsedRepel::
	.string "{PLAYER} used a Repel.$"

Text_UsedSuperRepel::
	.string "{PLAYER} used a Super Repel.$"

Text_UsedMaxRepel::
	.string "{PLAYER} used a Max Repel.$"
