#pragma once

namespace game::dvars
{
	constexpr const char* r_material_default = "none";
	const game::structs::dvar_s* r_world_material = game::functions::Dvar_RegisterString
	(
		"r_world_material",
		"Change world rendering material",
		r_material_default,
		game::structs::dvar_flags::none
	);

	static std::vector<const char*> r_techtype_enum =
	{
		"DEFAULT",
		"TECHNIQUE_DEPTH_PREPASS",
		"TECHNIQUE_BUILD_FLOAT_Z",
		"TECHNIQUE_BUILD_SHADOWMAP_DEPTH",
		"TECHNIQUE_BUILD_SHADOWMAP_COLOR",
		"TECHNIQUE_UNLIT",
		"TECHNIQUE_EMISSIVE",
		"TECHNIQUE_EMISSIVE_SHADOW",
		"TECHNIQUE_LIT",
		"TECHNIQUE_LIT_SUN",
		"TECHNIQUE_LIT_SUN_SHADOW",
		"TECHNIQUE_LIT_SPOT",
		"TECHNIQUE_LIT_SPOT_SHADOW",
		"TECHNIQUE_LIT_OMNI",
		"TECHNIQUE_LIT_OMNI_SHADOW",
		"TECHNIQUE_LIT_INSTANCED",
		"TECHNIQUE_LIT_INSTANCED_SUN",
		"TECHNIQUE_LIT_INSTANCED_SUN_SHADOW",
		"TECHNIQUE_LIT_INSTANCED_SPOT",
		"TECHNIQUE_LIT_INSTANCED_SPOT_SHADOW",
		"TECHNIQUE_LIT_INSTANCED_OMNI",
		"TECHNIQUE_LIT_INSTANCED_OMNI_SHADOW",
		"TECHNIQUE_LIGHT_SPOT",
		"TECHNIQUE_LIGHT_OMNI",
		"TECHNIQUE_LIGHT_SPOT_SHADOW",
		"TECHNIQUE_FAKELIGHT_NORMAL",
		"TECHNIQUE_FAKELIGHT_VIEW",
		"TECHNIQUE_SUNLIGHT_PREVIEW",
		"TECHNIQUE_CASE_TEXTURE",
		"TECHNIQUE_WIREFRAME_SOLID",
		"TECHNIQUE_WIREFRAME_SHADED",
		"TECHNIQUE_SHADOWCOOKIE_CASTER",
		"TECHNIQUE_SHADOWCOOKIE_RECEIVER",
		"TECHNIQUE_DEBUG_BUMPMAP",
		"TECHNIQUE_DEBUG_BUMPMAP_INSTANCED",
		"TECHNIQUE_COUNT",
		"TECHNIQUE_TOTAL_COUNT",
		"TECHNIQUE_NONE"
	};
	const game::structs::dvar_s* r_world_techtype = game::functions::Dvar_RegisterEnum
	(
		"r_world_techtype",
		"Change world rendering technique", 
		0, 
		r_techtype_enum.size(),
		r_techtype_enum.data(), 
		game::structs::dvar_flags::none
	);

	const game::structs::dvar_s* r_player_material = game::functions::Dvar_RegisterString
	(
		"r_player_material",
		"Change player rendering material",
		r_material_default,
		game::structs::dvar_flags::none
	);

	const game::structs::dvar_s* r_player_techtype = game::functions::Dvar_RegisterEnum
	(
		"r_player_techtype",
		"Change player rendering technique",
		0,
		r_techtype_enum.size(),
		r_techtype_enum.data(),
		game::structs::dvar_flags::none
	);

	const game::structs::dvar_s* com_redirect = game::functions::Dvar_RegisterBool
	(
		"com_redirect",
		"Redirect Com_PrintMessage to the console window",
		0,
		game::structs::dvar_flags::none
	);

	const game::structs::dvar_s* cl_autorecord = game::functions::Dvar_RegisterBool
	(
		"cl_autorecord",
		"Auto record a demo by spawn",
		0,
		game::structs::dvar_flags::none
	);

	const game::structs::dvar_s* cl_autorecord_output = game::functions::Dvar_RegisterString
	(
		"cl_autorecord_output",
		"Change the autorecord output template",
		"<name>_<map>_",
		game::structs::dvar_flags::none
	);

	game::structs::dvar_s* r_windowedfullscreen = game::functions::Dvar_RegisterBool
	(
		"r_windowedfullscreen",
		"Set Windowed Fullscreen",
		0,
		game::structs::dvar_flags::latched
	);

	game::structs::dvar_s* mvm_usedefaultbinds = game::functions::Dvar_RegisterBool
	(
		"mvm_usedefaultbinds",
		"Whether to use the default mvm binds. ( J, K, L )",
		true,
		game::structs::dvar_flags::none
	);

	game::structs::dvar_s* cg_fovlock = game::functions::Dvar_RegisterInt
	(
		"cg_fovlock",
		"Custom field of view to lock to. 0 = default/unlocked.",
		0,
		0,
		180,
		game::structs::dvar_flags::none
	);

	game::structs::dvar_s* cg_fovscope = game::functions::Dvar_RegisterInt // TODO use registerfloat instead
	(
		"cg_fovscope",
		"Custom field of view to for sniper scopes.",
		game::structs::SCOPE_FOV,
		0,
		180,
		game::structs::dvar_flags::none
	);
}