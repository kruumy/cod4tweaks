#pragma once

// owe a lot of this to https://github.com/xoxor4d/iw3xo-dev/blob/develop/src/components/modules/_renderer.cpp
namespace modules::_renderer
{
	struct switch_material_t
	{
		bool switch_material;
		bool switch_technique;
		bool switch_technique_type;
		game::structs::Material* current_material;
		game::structs::MaterialTechnique* current_technique;
		game::structs::Material* material;
		game::structs::MaterialTechnique* technique;
		game::structs::MaterialTechniqueType technique_type;
	};

	inline bool is_valid_technique_for_type(const game::structs::Material* mat, const game::structs::MaterialTechniqueType type)
	{
		return mat && mat->techniqueSet && mat->techniqueSet->remappedTechniqueSet && mat->techniqueSet->remappedTechniqueSet->techniques && mat->techniqueSet->remappedTechniqueSet->techniques[type];
	}
	void switch_technique(switch_material_t* swm, game::structs::Material* material) 
	{
		if (material)
		{
			swm->technique = nullptr;

			if (is_valid_technique_for_type(material, swm->technique_type))
			{
				swm->technique = material->techniqueSet->remappedTechniqueSet->techniques[swm->technique_type];
			}

			swm->switch_technique = true;
			return;
		}
		else
		{
			swm->technique = swm->current_technique;
		}
	}
	inline void switch_technique(switch_material_t* swm, const char* material_name) 
	{
		switch_technique(swm, game::functions::Material_RegisterHandle(material_name, 3));
	}
	void switch_material(switch_material_t* swm, game::structs::Material* material) 
	{
		if (material)
		{
			swm->material = material;
			swm->technique = nullptr;

			if (is_valid_technique_for_type(material, swm->technique_type))
			{
				swm->technique = material->techniqueSet->remappedTechniqueSet->techniques[swm->technique_type];
			}

			swm->switch_material = true;
			return;
		}
		else
		{
			swm->material = swm->current_material;
		}
	}
	inline void switch_material(switch_material_t* swm, const char* material_name)
	{
		switch_material(swm, game::functions::Material_RegisterHandle(material_name, 3));
	}

	inline bool is_material_for_xmodel(game::structs::Material* material)
	{
		return utils::cstring::starts_with(material->info.name, "mc/");
	}

	inline bool is_material_for_skybox(game::structs::Material* material)
	{
		return utils::cstring::starts_with(material->info.name, "wc/sky");
	}

	bool is_material_not_players(game::structs::Material* material) 
	{
		const char* forbiddenSubstrings[] = 
		{
			"weapon", "wpn", "viewmodel", "gmz", "scope_overlay",
			"mc/mtl_usmc", "mc/mtl_arab", "mc/mtl_opforce", "mc/mtl_op_force",
			"mc/mtl_sas", "mc/mtl_desert_", "mc/mtl_viewhands", "mc/mtl_viewsleeves",
			"mc/mtl_marine", "mc/mtl_wpn", "mc/mtl_ghillie", "mc/mtl_head", "mc/mtl_bodies"
		};
		constexpr size_t forbiddenSubstringsCount = sizeof(forbiddenSubstrings) / sizeof(forbiddenSubstrings[0]);
		return !utils::cstring::contains_any(material->info.name, forbiddenSubstrings, forbiddenSubstringsCount);
	}

	int R_SetMaterial(game::structs::MaterialTechniqueType techType, game::structs::GfxCmdBufSourceState* src, game::structs::GfxCmdBufState* state, game::structs::GfxDrawSurf drawSurf)
	{
		switch_material_t mat = {};
		mat.current_material = game::globals::rgp->sortedMaterials[(drawSurf.packed >> 29) & 0x7FF];
		mat.current_technique = mat.current_material->techniqueSet->remappedTechniqueSet->techniques[techType];
		mat.material = mat.current_material;
		mat.technique = mat.current_technique;
		mat.technique_type = techType;

		if (mat.current_material)
		{
			//world
			if (game::dvars::r_world_material && game::dvars::r_world_material->current.string)
			{
				if (strcmp(game::dvars::r_world_material->current.string, game::dvars::r_material_default) != 0)
				{
					if (is_material_not_players(mat.current_material))
					{
						mat.technique_type = game::structs::TECHNIQUE_UNLIT;
						switch_material(&mat, game::dvars::r_world_material->current.string);
					}
				}
			}

			if (game::dvars::r_world_techtype && game::dvars::r_world_techtype->current.integer)
			{
				if (is_material_not_players(mat.current_material))
				{
					int value = game::dvars::r_world_techtype->current.integer;
					value--;
					mat.technique_type = (game::structs::MaterialTechniqueType)value;
					mat.switch_technique_type = true;
				}
			}

			//player
			if (game::dvars::r_player_material && game::dvars::r_player_material->current.string)
			{
				if (strcmp(game::dvars::r_player_material->current.string, game::dvars::r_material_default) != 0)
				{
					if (!is_material_not_players(mat.current_material))
					{
						mat.technique_type = game::structs::TECHNIQUE_UNLIT;
						switch_material(&mat, game::dvars::r_player_material->current.string);
					}
				}
			}

			if (game::dvars::r_player_techtype && game::dvars::r_player_techtype->current.integer)
			{
				if (!is_material_not_players(mat.current_material))
				{
					int value = game::dvars::r_player_techtype->current.integer;
					value--;
					mat.technique_type = (game::structs::MaterialTechniqueType)value;
					mat.switch_technique_type = true;
				}
			}


			if (!mat.switch_material && !mat.switch_technique && !mat.switch_technique_type)
			{
				if (state->origMaterial)
				{
					state->material = state->origMaterial;
				}
				if (state->origTechType)
				{
					state->techType = state->origTechType;
				}
			}
		}
		// save the original material
		state->origMaterial = state->material;

		// only switch to a different technique_type
		if (mat.switch_technique_type)
		{
			if (is_valid_technique_for_type(mat.current_material, mat.technique_type))
			{
				switch_technique(&mat, mat.current_material);
			}
		}

		// set stock or new material & technique
		state->material = mat.material;
		state->technique = mat.technique;


		if (!state->technique || (state->technique->flags & 1) != 0 && !game::globals::rg->distortion)
		{
			return 0;
		}

		if (!mat.switch_material && !mat.switch_technique && !mat.switch_technique_type)
		{
			if ((mat.technique_type == game::structs::TECHNIQUE_EMISSIVE || mat.technique_type == game::structs::TECHNIQUE_UNLIT) && (state->technique->flags & 0x10) != 0 && !src->constVersions[4])
			{
				return 0;
			}
		}

		state->origTechType = state->techType;
		state->techType = mat.technique_type;

		return 1;
	}
	__declspec(naked) void R_SetMaterial_stub()
	{
		const static uint32_t rtn_to_set_shadowable_light = reinterpret_cast<uint32_t>(game::functions::R_SetMaterial) + 0x82;
		const static uint32_t retn_to_retn = reinterpret_cast<uint32_t>(game::functions::R_SetMaterial) + 0x38;
		__asm
		{
			push	esi;		// techType
			call	R_SetMaterial;
			pop		esi;
			add     esp, 10h;

			test    eax, eax;
			jz      memes;
			jmp		rtn_to_set_shadowable_light;

		memes:
			jmp		retn_to_retn;
		}
	}
	utils::MinHookObject<LPVOID> hook(reinterpret_cast<LPVOID>(reinterpret_cast<uint32_t>(game::functions::R_SetMaterial) + 0x76), &R_SetMaterial_stub, true);
}