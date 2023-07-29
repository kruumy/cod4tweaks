#pragma once
#include "functions.hpp"


namespace game::dvars
{
	const game::structs::dvar_s* r_world_material = game::functions::Dvar_RegisterString_Wrapped("r_world_material", "Change world rendering material", "none",game::structs::dvar_flags::none);
}