#pragma once
#include <sstream>

namespace modules::demorecorder
{
	std::string ParseOutputTemplate(const std::string raw)
	{
		const char enter_variable_token = '<';
		const char exit_variable_token = '>';
		const std::vector<std::pair<std::string, std::string>> variable_map
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
				i++;
				for (size_t j = 0; j < variable_map.size(); j++)
				{
					if (raw.substr(i, variable_map[j].first.length()) == variable_map[j].first)
					{
						ret << variable_map[j].second;
						break;
					}
				}
				while (raw[i] != exit_variable_token)
				{
					i++;
				}
				continue;
			}
			ret << raw[i];
		}

		return ret.str();
	}


	void Record()
	{
		std::string recordCommand = "record " + ParseOutputTemplate("demo_<map>_<time>") + '\n';
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