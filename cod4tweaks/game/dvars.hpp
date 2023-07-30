#pragma once

namespace game::dvars
{
	const game::structs::dvar_s* r_world_material = game::functions::Dvar_RegisterString_Wrapped
	(
		"r_world_material",
		"Change world rendering material",
		"none",
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
		"TECHNIQUE_COUNT"
	};
	const game::structs::dvar_s* r_world_techtype = game::functions::Dvar_RegisterEnum_Wrapped
	(
		"r_world_techtype",
		"Change world rendering technique", 
		0, 
		r_techtype_enum.size(),
		r_techtype_enum.data(), 
		game::structs::dvar_flags::none
	);

	const game::structs::dvar_s* r_player_material = game::functions::Dvar_RegisterString_Wrapped
	(
		"r_player_material",
		"Change player rendering material",
		"none",
		game::structs::dvar_flags::none
	);

	const game::structs::dvar_s* r_player_techtype = game::functions::Dvar_RegisterEnum_Wrapped
	(
		"r_player_techtype",
		"Change player rendering technique",
		0,
		r_techtype_enum.size(),
		r_techtype_enum.data(),
		game::structs::dvar_flags::none
	);

	const game::structs::dvar_s* com_redirect = game::functions::Dvar_RegisterBool_Wrapped
	(
		"com_redirect",
		"Redirect Com_PrintMessage to the console window",
		0,
		game::structs::dvar_flags::none
	);
}