#pragma once

namespace modules::demorecorder
{
	// recreation of 0x468A3A
	std::string GetNonConflictingDemoNumber(std::string baseDemoName)
	{
		const int maxdemos = 0x270F;
		char Destination[64];
		char ArgList[MAX_OSPATH];
		uint32_t sub_55B190 = 0x55B190;
		int doesFileExist;
		for (int i = 0; i <= maxdemos; ++i)
		{
			std::sprintf(Destination, (baseDemoName + "%i").c_str(), i);
			std::sprintf(ArgList, "demos/%s.dm_%d", Destination, 1);
			__asm
			{
				lea     eax, [ArgList]
				call    sub_55B190
				mov     doesFileExist, eax
			}
			if (!doesFileExist) break;
		}
		return std::string(Destination);
	}

	std::string ParseOutputTemplate(const std::string raw)
	{
		const char enter_variable_token = '<';
		const char exit_variable_token = '>';
		std::unordered_map<std::string, std::string> variable_map
		{
			{"map", std::string(game::globals::cgs->visionNameNaked) }, // TODO use map not vision name
			{"time", std::to_string(game::globals::cgs->time) },
			{"clientNum", std::to_string(game::globals::cgs->clientNum) },
			{"killcam", game::globals::cgs->inKillCam != 0 ? "KILLCAM" : ""},
			{"ip", game::globals::current_server_ip },
			{"team", game::globals::clientInfo[game::globals::cgs->clientNum].team == game::structs::team_t::TEAM_RED ? "axis" : game::globals::clientInfo[game::globals::cgs->clientNum].team == game::structs::team_t::TEAM_BLUE ? "allies" : game::globals::clientInfo[game::globals::cgs->clientNum].team == game::structs::team_t::TEAM_SPECTATOR ? "spectator" : ""},
			{"name", game::functions::Dvar_FindMalleableVar("name")->current.string}
		};
		std::stringstream ret;

		for (size_t i = 0; i < raw.length(); i++)
		{
			if (raw[i] == enter_variable_token)
			{
				int j = i; 
				do 
				{
					j++;
				} while (raw[j] != exit_variable_token);
				std::string query = raw.substr(i + 1, j - i - 1);
				if (variable_map.contains(query))
				{
					ret << variable_map[ query ];
				}
				i = j;
				continue;
			}
			ret << raw[i];
		}

		return ret.str();
	}

	void Record()
	{
		
		std::string demoname = ParseOutputTemplate(game::dvars::cl_autorecord_output->current.string);
		demoname = demoname.replace(demoname.begin(), demoname.end(), ' ', '_');
		demoname = GetNonConflictingDemoNumber(demoname);
		game::functions::Cbuf_AddText(("record " + demoname + '\n').c_str(), 0);
	}

	void StopRecord()
	{
		game::functions::Cbuf_AddText("stoprecord\n", 0);
	}

	void OnPlayerSpawn()
	{
		if (game::dvars::cl_autorecord && game::dvars::cl_autorecord->current.enabled)
		{
			if (game::globals::is_recording)
			{
				StopRecord();
			}
			Record();
		}
	}
	
	

	bool snap_is_respawn = false;
	__declspec(naked) void CG_SetNextSnap_InRespawn_stub()
	{
		const static uint32_t CG_Respawn = reinterpret_cast<uint32_t>(game::functions::CG_Respawn);
		const static uint32_t continuer = reinterpret_cast<uint32_t>(game::functions::CG_SetNextSnap) + 0x636;
		snap_is_respawn = true;
		__asm
		{
			call    CG_Respawn
			jmp		continuer
		}
	}

	__declspec(naked) void CG_SetNextSnap_End_stub()
	{
		if (snap_is_respawn)
		{
			snap_is_respawn = false;
			OnPlayerSpawn();
		}
		__asm
		{
			add     esp, 0ACh
			retn
		}
	}

	utils::MinHookObject<LPVOID> hook_InRespawn(reinterpret_cast<LPVOID>(reinterpret_cast<uint32_t>(game::functions::CG_SetNextSnap) + 0x631), &CG_SetNextSnap_InRespawn_stub, true);
	utils::MinHookObject<LPVOID> hook_End(reinterpret_cast<LPVOID>(reinterpret_cast<uint32_t>(game::functions::CG_SetNextSnap) + 0xA45), &CG_SetNextSnap_End_stub, true);
	
}