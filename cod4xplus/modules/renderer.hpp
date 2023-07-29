#pragma once
#include "../utils/MinHookObject.hpp"
#include "../game/structs.hpp"

namespace modules::renderer
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

	inline bool is_valid_technique_for_type(const game::structs::Material* mat, const game::structs::MaterialTechniqueType type);
	void switch_technique(switch_material_t* swm, game::structs::Material* material);
	inline void switch_technique(switch_material_t* swm, const char* material_name);
	void switch_material(switch_material_t* swm, game::structs::Material* material);
	inline void switch_material(switch_material_t* swm, const char* material_name);
	inline bool is_material_for_xmodel(game::structs::Material* material);
	inline bool is_material_for_skybox(game::structs::Material* material);
	bool is_material_not_players(game::structs::Material* material);

	void R_SetMaterial_stub();
	utils::MinHookObject<LPVOID> hook(reinterpret_cast<LPVOID>(0x648F86), &R_SetMaterial_stub, true);
}