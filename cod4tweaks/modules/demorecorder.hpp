#pragma once
#include <sstream>

namespace modules::demorecorder
{
	std::string GetCustomDemoName()
	{
		if (game::globals::cgs)
		{
			std::stringstream ret;
			ret << game::globals::cgs->visionNameNaked << '_';
			ret << game::globals::cgs->clientNum << '_';
			ret << game::globals::cgs->time;
			return ret.str();
		}
		else
		{
			return "";
		}
	}

	void Record()
	{
		//std::string recordCommand = "record " + GetCustomDemoName() + '\n';
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