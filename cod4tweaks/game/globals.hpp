#pragma once

namespace game::globals
{
	const int* cg_maxPlayers = reinterpret_cast<int*>(0x74AA48);
	const int* cg_currentPlayer = reinterpret_cast<int*>(0x74E338);
	const game::structs::centity_t* cg_Entities = reinterpret_cast<game::structs::centity_t*>(0x84F2D8);
	const game::structs::clientInfo_t* clientInfo = reinterpret_cast<game::structs::clientInfo_t*>(0x839270);
	const game::structs::r_globals_t* rg = reinterpret_cast<game::structs::r_globals_t*>(0xCC9D150);
	const game::structs::r_global_permanent_t* rgp = reinterpret_cast<game::structs::r_global_permanent_t*>(0xCC98280);
	game::structs::CmdArgs* cmd_args = reinterpret_cast<game::structs::CmdArgs*>(0x1410B40);
	game::structs::cmd_function_s** cmd_ptr = reinterpret_cast<game::structs::cmd_function_s**>(0x1410B3C);
	const char* current_server_ip = reinterpret_cast<char*>(0x00956D88);
	const game::structs::gentity_s* g_entities = reinterpret_cast<game::structs::gentity_s*>(0x12885C4);
	const game::structs::gclient_s* g_clients = reinterpret_cast<game::structs::gclient_s*>(0x13255A8);
	const game::structs::gentity_s* scr_g_entities = reinterpret_cast<game::structs::gentity_s*>(0x1288500);
	const game::structs::level_locals_t* level_locals = reinterpret_cast<game::structs::level_locals_t*>(0x13EB6A8);
	const game::structs::WeaponDef** BG_WeaponNames = reinterpret_cast<const game::structs::WeaponDef**>(0x736DB8);
	const game::structs::XZone* g_zones = reinterpret_cast<game::structs::XZone*>(0xFFEFD0);
	const game::structs::XAssetEntry* g_assetEntryPool = reinterpret_cast<game::structs::XAssetEntry*>(0xF0D640);
	const game::structs::playerState_s* ps_loc = reinterpret_cast<game::structs::playerState_s*>(0x13255A8);
	const game::structs::Console* con = reinterpret_cast<game::structs::Console*>(0x8DC8C0);
	const bool* is_recording = reinterpret_cast<bool*>(0x00934E70);
	const game::structs::cg_s* cgs = reinterpret_cast<game::structs::cg_s*>(0x74E338);
	const IDirect3DDevice9* D3DDevice = *reinterpret_cast<IDirect3DDevice9**>(0xCC9A408);
	const char* fs_gamedir = reinterpret_cast<const char*>(0xCB19898);
	const game::structs::searchpath_s* fs_searchpaths = reinterpret_cast<game::structs::searchpath_s*>(0xD5EC4DC);
	game::structs::WeaponDef** bg_weaponDefs = reinterpret_cast<game::structs::WeaponDef**>(0x00736DB8);
	const game::structs::pmove_t* pmove = reinterpret_cast<game::structs::pmove_t*>(0x8C9C90);
	const uint32_t hiw3mvm = reinterpret_cast<uint32_t>(GetModuleHandle(L"iw3mvm.dll"));
	bool* iw3mvm_isInDolly = reinterpret_cast<bool*>(game::globals::hiw3mvm ? game::globals::hiw3mvm + 0x661EC : NULL);
}
