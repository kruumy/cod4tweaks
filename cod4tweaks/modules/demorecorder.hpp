#pragma once
#include <sstream>
#include <unordered_map>

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
			std::sprintf(Destination, (baseDemoName + "%04i").c_str(), i);
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
		std::string demoname = GetNonConflictingDemoNumber(ParseOutputTemplate("demo_<map>_<clientNum>"));
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