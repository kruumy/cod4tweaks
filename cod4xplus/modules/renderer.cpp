#include "renderer.hpp"
#include "../game/globals.hpp"
#include "../game/functions.hpp"
#include <cstdint>

// A lot of this comes from https://github.com/xoxor4d/iw3xo-dev/blob/develop/src/components/modules/_renderer.cpp

bool modules::renderer::is_valid_technique_for_type(const game::structs::Material* mat, const game::structs::MaterialTechniqueType type)
{
	return mat && mat->techniqueSet && mat->techniqueSet->remappedTechniqueSet && mat->techniqueSet->remappedTechniqueSet->techniques && mat->techniqueSet->remappedTechniqueSet->techniques[type];
}

void modules::renderer::switch_technique(switch_material_t* swm, game::structs::Material* material)
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

void modules::renderer::switch_technique(switch_material_t* swm, const char* material_name)
{
	switch_technique(swm, game::functions::Material_RegisterHandle(material_name, 3));
}

void modules::renderer::switch_material(modules::renderer::switch_material_t* swm, game::structs::Material* material)
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

void modules::renderer::switch_material(modules::renderer::switch_material_t* swm, const char* material_name)
{
	switch_material(swm, game::functions::Material_RegisterHandle(material_name, 3));
}

int R_SetMaterial(game::structs::MaterialTechniqueType techType, game::structs::GfxCmdBufSourceState* src, game::structs::GfxCmdBufState* state, game::structs::GfxDrawSurf drawSurf)
{
	modules::renderer::switch_material_t mat = {};
	mat.current_material = game::globals::rgp->sortedMaterials[(drawSurf.packed >> 29) & 0x7FF];
	mat.current_technique = mat.current_material->techniqueSet->remappedTechniqueSet->techniques[techType];
	mat.material = mat.current_material;
	mat.technique = mat.current_technique;
	mat.technique_type = techType;

	if (mat.current_material)
	{
		mat.technique_type = game::structs::TECHNIQUE_WIREFRAME_SOLID;
		mat.switch_technique_type = true;


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
		if (modules::renderer::is_valid_technique_for_type(mat.current_material, mat.technique_type))
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

__declspec(naked) void modules::renderer::R_SetMaterial_stub()
{
	const static uint32_t rtn_to_set_shadowable_light = 0x648F92;
	const static uint32_t retn_to_retn = 0x648F48;
	__asm
	{
		push	esi;		// techType
		call	R_SetMaterial;
		pop		esi;
		add     esp, 10h;

		test    eax, eax;	// do not return BOOL if you test 4 byte sized registers :>
		jz      memes;
		jmp		rtn_to_set_shadowable_light;

	memes:
		jmp		retn_to_retn;
	}
}