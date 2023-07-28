#pragma once
#include "structs.hpp"
namespace game::globals
{
	const game::structs::clientActive_t* clients = reinterpret_cast<game::structs::clientActive_t*>(0xC5F930);
	const game::structs::clientStatic_t* cls = reinterpret_cast<game::structs::clientStatic_t*>(0x956D80);
	const game::structs::clientConnection_t& clc = *reinterpret_cast<game::structs::clientConnection_t*>(0x8F4CE0);
	const game::structs::cg_s* cgs = reinterpret_cast<game::structs::cg_s*>(0x74E338);
	const game::structs::serverStatic_t* svs = reinterpret_cast<game::structs::serverStatic_t*>(0x185C480);

	const game::structs::Console* con = reinterpret_cast<game::structs::Console*>(0x8DC8C0);
	const game::structs::field_t* g_consoleField = reinterpret_cast<game::structs::field_t*>(0x8F1B88);
}