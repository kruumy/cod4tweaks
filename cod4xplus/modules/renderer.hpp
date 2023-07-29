#pragma once

#include "../game/functions.hpp"
#include "../utils/MinHookObject.hpp"
#include <iostream>

namespace modules::renderer
{
	int R_SetMaterial();
	
	utils::MinHookObject<game::functions::R_SetMaterial_t> hook(game::functions::R_SetMaterial,&R_SetMaterial, true);

	int R_SetMaterial()
	{

		return hook.GetOriginalFunc()();
	}
}