{"FSM.AnimationsFSM"

;********************************************************************
; Requests
;********************************************************************
	{AnimRequest "idle" {System "PRE_IDLE"}}

	{AnimRequest "move" {System "PRE_MOVE"}}

	{AnimRequest "rotate" {System "PRE_ROTATE_LEFT"}}

	{AnimRequest "rotate" {System "PRE_ROTATE_RIGHT"}}

	{AnimRequest "attack" {System "PRE_MELEE_ATTACK"}}

	{AnimRequest "death" {System "PRE_DEATH"}}

;********************************************************************
; States
;********************************************************************
{State "freeze"
	;transations
	{from "stun"}
	{from "pose_to_stun"}
	{from "pose_to_move_default"}
	{from "move_default"}
	{from "pose_to_idle_default"}
	{from "idle_default"}
	{from "pose_to_attack_fight"}
	{from "attack_fight"}
	{from "pose_to_move_fight"}
	{from "move_fight"}
	{from "pose_to_idle_fight"}
	{from "idle_fight"}
	{from "from_default"}
	{from "from_fight"}
	;tags
	{tag "freeze"}
}
{StateWork "freeze"
	{pose}
	{AnimName "pose_from_idle" {speed 0.1} }
}

{State "pose_to_stun"
	;transations
	{from "freeze"}
	{from "pose_to_move_default"}
	{from "move_default"}
	{from "pose_to_idle_default"}
	{from "idle_default"}
	{from "pose_to_attack_fight"}
	{from "attack_fight"}
	{from "pose_to_move_fight"}
	{from "move_fight"}
	{from "pose_to_idle_fight"}
	{from "idle_fight"}
	{from "from_default"}
	{from "from_fight"}
}
{StateWork "pose_to_stun"
	{pose}
	{AnimName "pose_to_stun" {speed 0.1} }
}

{State "stun"
	;transations
	{from "pose_to_stun"}
	;tags
	{tag "stun"}
}
{StateWork "stun"
	{looped}
	{AnimName "stun" {speed 1} }
}

{State "from_unmoved_1"
	;transations
	{from "freeze"}
	{from "stun"}
	{from "stand_up"}
	{from "pose_to_stun"}
}
{StateWork "from_unmoved_1"
}

{State "from_unmoved_2"
	;transations
	{from "from_unmoved_1"}
}
{StateWork "from_unmoved_2"
}

{State "pose_to_mass_damage"
	;transations
	{from "from_stun_1"}
	{from "pose_to_move_default"}
	{from "move_default"}
	{from "pose_to_idle_default"}
	{from "idle_default"}
	{from "pose_to_attack_fight"}
	{from "attack_fight"}
	{from "pose_to_move_fight"}
	{from "move_fight"}
	{from "pose_to_idle_fight"}
	{from "idle_fight"}
	{from "from_default"}
	{from "from_fight"}
}
{StateWork "pose_to_mass_damage"
	{pose}
	{AnimName "pose_to_mass_damage_fly" {speed 0.001} }
}

{State "mass_damage"
	;transations
	{from "pose_to_mass_damage"}
	;tags
	{tag "mass_damage"}
}
{StateWork "mass_damage"
	{SyncNotifyStart "MASS_FLY"}
	{looped}
	{AnimName "mass_damage_fly" {speed 1.2} }
}

{State "stand_up"
	;transations
	{from "mass_damage"}
	{from "pose_to_mass_damage"}
	;tags
	{tag "stand_up"}
}
{StateWork "stand_up"
	{SyncNotifyFinish "STAND_READY"}
	{AnimName "massive_stand_up" {speed 1.2} }
}

{State "from_unmoved_3"
	;transations
	{from "mass_damage"}
	{from "pose_to_mass_damage"}
}
{StateWork "from_unmoved_3"
}

{State "from_unmoved_4"
	;transations
	{from "from_unmoved_3"}
}
{StateWork "from_unmoved_4"
}

{State "from_unmoved_5"
	;transations
	{from "from_unmoved_4"}
}
{StateWork "from_unmoved_5"
}

{State "from_stun_2"
	;transations
	{from "from_stun_3"}
}
{StateWork "from_stun_2"
}

{State "from_stun_3"
	;transations
	{from "freeze"}
	{from "stun"}
	{from "pose_to_stun"}
}
{StateWork "from_stun_3"
}

{State "from_stun_1"
	;transations
	{from "from_stun_2"}
}
{StateWork "from_stun_1"
}

{State "to_death"
	;transations
	{from "blank01"}
}
{StateWork "to_death"
}

{State "death_anim"
	;transations
	{from "to_death"}
	;tags
	{tag "death_anim"}
}
{StateWork "death_anim"
	{AnimName "death" {speed 1.3} {frame 1 "SPIDER_DEATH_SND"} }
}

{State "blank01"
	;transations
	{from "pose_to_move_default"}
	{from "move_default"}
	{from "pose_to_idle_default"}
	{from "idle_default"}
	{from "pose_to_attack_fight"}
	{from "attack_fight"}
	{from "pose_to_move_fight"}
	{from "move_fight"}
	{from "pose_to_idle_fight"}
	{from "idle_fight"}
	{from "from_default"}
	{from "from_fight"}
}
{StateWork "blank01"
}

{State "death"
	;transations
	{from "death_anim"}
	{from "from_unmoved_5"}
	;tags
	{tag "death"}
}
{StateWork "death"
	{SyncNotifyStart "FINAL_DEATH"}
	{pose}
	{AnimName "pose_from_death" {speed 0.5} }
}

{State "pose_to_move_default"
	;transations
	{from "from_default"}
	{from "idle_default"}
	{from "pose_to_idle_default"}
}
{StateWork "pose_to_move_default"
	{pose}
	{AnimName "pose_to_walk" {speed 0.25} }
}

{State "move_default"
	;transations
	{from "pose_to_move_default"}
	;tags
	{tag "move"}
	{tag "default"}
}
{StateWork "move_default"
	{SyncNotifyStart "MOVE_RESUME"}
	{SyncNotifyFinish "MOVE_PAUSE"}
	{looped}
	{AnimName "walk" {speed 1.4} }
}

{State "pose_to_idle_default"
	;transations
	{from "move_default"}
	{from "from_default"}
	{from "pose_to_move_default"}
}
{StateWork "pose_to_idle_default"
	{pose}
	{AnimName "pose_to_idle" {speed 0.25} }
}

{State "idle_default"
	;transations
	{from "pose_to_idle_default"}
	;tags
	{tag "idle"}
	{tag "default"}
}
{StateWork "idle_default"
	{SyncNotifyStart "MOVE_PAUSE"}
	{looped}
	{AnimName "idle" {speed 1} }
}

{State "pose_to_attack_fight"
	;transations
	{from "idle_fight"}
	{from "move_fight"}
	{from "from_fight"}
	{from "pose_to_move_fight"}
	{from "pose_to_idle_fight"}
}
{StateWork "pose_to_attack_fight"
	{pose}
	{AnimName "pose_to_blow01" {speed 0.1} }
}

{State "attack_fight"
	;transations
	{from "pose_to_attack_fight"}
	;tags
	{tag "attack"}
	{tag "fight"}
}
{StateWork "attack_fight"
	{SyncNotifyStart "ATTACK"}
	{SyncNotifyFinish "ATTACK"}
	{random}
	{AnimName "blow01" {speed 1.2} {frame 2 "SPIDER_SOUND_SND"} {frame 10 "IMP_SWISH_SND"} {frame 11 "SPIDER_ATTACK_SND"} {frame 12 "ATTACK"} {frame -1 "ATTACK"} }
	{AnimName "blow02" {speed 1.2} {frame 2 "SPIDER_SOUND_SND"} {frame 11 "WHOOSH_FAST_LOW_SND"} {frame 15 "SPIDER_ATTACK_SND"} {frame 18 "ATTACK"} {frame -1 "ATTACK"} }
}

{State "pose_to_move_fight"
	;transations
	{from "idle_fight"}
	{from "attack_fight"}
	{from "from_fight"}
	{from "pose_to_attack_fight"}
	{from "pose_to_idle_fight"}
}
{StateWork "pose_to_move_fight"
	{pose}
	{AnimName "pose_to_walk" {speed 0.25} }
}

{State "move_fight"
	;transations
	{from "pose_to_move_fight"}
	;tags
	{tag "move"}
	{tag "fight"}
}
{StateWork "move_fight"
	{SyncNotifyStart "MOVE_RESUME"}
	{SyncNotifyFinish "MOVE_PAUSE"}
	{looped}
	{AnimName "walk" {speed 1.4} }
}

{State "pose_to_idle_fight"
	;transations
	{from "move_fight"}
	{from "attack_fight"}
	{from "from_fight"}
	{from "pose_to_attack_fight"}
	{from "pose_to_move_fight"}
}
{StateWork "pose_to_idle_fight"
	{pose}
	{AnimName "pose_to_idle" {speed 0.25} }
}

{State "idle_fight"
	;transations
	{from "pose_to_idle_fight"}
	;tags
	{tag "idle"}
	{tag "fight"}
}
{StateWork "idle_fight"
	{SyncNotifyStart "MOVE_PAUSE"}
	{looped}
	{AnimName "idle" {speed 1.1} }
}

{State "from_default"
	;transations
	{from "move_default"}
	{from "idle_default"}
	{from "from_fight"}
	{from "death"}
	{from "from_unmoved_2"}
	{from "pose_to_move_default"}
	{from "pose_to_idle_default"}
}
{StateWork "from_default"
	{SyncNotifyStart "MOVE_PAUSE"}
}

{State "from_fight"
	;transations
	{from "from_default"}
	{from "idle_fight"}
	{from "attack_fight"}
	{from "move_fight"}
	{from "death"}
	{from "from_unmoved_2"}
	{from "pose_to_attack_fight"}
	{from "pose_to_move_fight"}
	{from "pose_to_idle_fight"}
}
{StateWork "from_fight"
	{SyncNotifyStart "MOVE_PAUSE"}
}

;********************************************************************
; Subsets
;********************************************************************
{subset "default"
	{enable "default"}
	{disable "fight"}
}

{subset "fight"
	{disable "default"}
	{enable "fight"}
}

;********************************************************************
; Start state \ subset
;********************************************************************
	{Start "idle_default"}

	{WorkSubset "default"}

}
