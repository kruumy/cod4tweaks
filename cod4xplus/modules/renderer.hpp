#pragma once

#include "../game/functions.hpp"
#include "../utils/MinHookObject.hpp"
#include <iostream>

namespace modules::renderer
{
	int R_SetMaterial(game::structs::GfxCmdBufContext* context, game::structs::GfxDrawSurf* drawSurf, game::structs::MaterialTechniqueType techType);
	
	utils::MinHookObject<game::functions::R_SetMaterial_t> hook(game::functions::R_SetMaterial,&R_SetMaterial, true);

	int R_SetMaterial(game::structs::GfxCmdBufContext* context, game::structs::GfxDrawSurf* drawSurf, game::structs::MaterialTechniqueType techType)
	{

		return hook.GetOriginalFunc()(context, drawSurf, techType);
	}
}