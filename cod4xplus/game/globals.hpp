#pragma once
#include "structs.hpp"
namespace game::globals
{
	const int* cg_maxPlayers = reinterpret_cast<int*>(0x74AA48);
	const int* cg_currentPlayer = reinterpret_cast<int*>(0x74E338);
	const game::structs::entity_t* cg_Entities = reinterpret_cast<game::structs::entity_t*>(0x84F2D8); // array of cg_maxPlayers
	const game::structs::clientInfo_t* clientInfo = reinterpret_cast<game::structs::clientInfo_t*>(0x839270);
}