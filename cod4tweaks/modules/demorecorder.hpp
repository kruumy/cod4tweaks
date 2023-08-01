#pragma once
#include <sstream>
#include <unordered_map>

namespace modules::demorecorder
{
	std::string ParseOutputTemplate(const std::string raw)
	{
		const char enter_variable_token = '<';
		const char exit_variable_token = '>';
		std::unordered_map<std::string, std::string> variable_map
		{
			{"map", std::string(game::globals::cgs->visionNameNaked) },
			{"time", std::to_string(game::globals::cgs->time) },
			{"clientNum", std::to_string(game::globals::cgs->clientNum) },
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
	void AppendNumberIfFileExists(std::string& name)
	{
		
		
	}

	void Record()
	{
		//std::string demoname = ParseOutputTemplate("demo_<map>");
		//AppendNumberIfFileExists(demoname);
		//game::functions::Cbuf_AddText(("record " + demoname + '\n').c_str(), 0);
		game::functions::Cbuf_AddText("record\n", 0);
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
	
	__declspec(naked) void CG_SetNextSnap_stub()
	{
		const static uint32_t LABEL_63 = reinterpret_cast<uint32_t>(game::functions::CG_SetNextSnap) + 0x62E;
		__asm
		{
			call	OnPlayerSpawn
			jmp		LABEL_63
		}
	}
	utils::MinHookObject<LPVOID> hook(reinterpret_cast<LPVOID>(reinterpret_cast<uint32_t>(game::functions::CG_SetNextSnap) + 0x5A8), &CG_SetNextSnap_stub, true);
}