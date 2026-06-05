{Skeleton
	{animation
		{blend "pose_from_idle"{pose "idle" end}}
		{blend "pose_to_stun"{pose "stun" begin}}
		{binary "stun"{speed 0.6}}
		{blend "pose_to_mass_damage_fly"{pose "mass_damage_fly" begin}}
		{binary "mass_damage_fly"{speed 0.6}}
		{binary "massive_stand_up"{speed 0.6}}
		{binary "death"{speed 0.6}}
		{blend "pose_from_death"{pose "death" end}}
		{blend "pose_to_walk"{pose "walk" begin}}
		{binary "walk"{speed 0.6}}
		{blend "pose_to_idle"{pose "idle" begin}}
		{binary "idle"{speed 0.6}}
		{blend "pose_to_blow01"{pose "blow01" begin}}
		{binary "blow01"{speed 0.6}}
		{binary "blow02"{speed 0.6}}
	}
}