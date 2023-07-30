#pragma once

namespace game::globals
{
	const int* cg_maxPlayers = reinterpret_cast<int*>(0x74AA48);
	const int* cg_currentPlayer = reinterpret_cast<int*>(0x74E338);
	const game::structs::entity_t* cg_Entities = reinterpret_cast<game::structs::entity_t*>(0x84F2D8); // array of cg_maxPlayers
	const game::structs::clientInfo_t* clientInfo = reinterpret_cast<game::structs::clientInfo_t*>(0x839270);
	const game::structs::r_globals_t* rg = reinterpret_cast<game::structs::r_globals_t*>(0xCC9D150);
	const game::structs::r_global_permanent_t* rgp = reinterpret_cast<game::structs::r_global_permanent_t*>(0xCC98280);
	game::structs::CmdArgs* cmd_args = reinterpret_cast<game::structs::CmdArgs*>(0x1410B40);
	game::structs::cmd_function_s** cmd_ptr = reinterpret_cast< game::structs::cmd_function_s**>(0x1410B3C);
}