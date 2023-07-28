#pragma once
#include "structs.hpp"
namespace game::globals
{
	const game::structs::clientActive_t* clients = reinterpret_cast<game::structs::clientActive_t*>(0xC5F930);
	const game::structs::clientStatic_t* cls = reinterpret_cast<game::structs::clientStatic_t*>(0x956D80);
	const game::structs::clientConnection_t& clc = *reinterpret_cast<game::structs::clientConnection_t*>(0x8F4CE0);
	const game::structs::cg_s* cgs = reinterpret_cast<game::structs::cg_s*>(0x74E338);
}