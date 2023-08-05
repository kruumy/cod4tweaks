#pragma once

namespace modules::customfov
{
	double GetCalculatedFOV();
	utils::MinHookObject<game::functions::GetCalculatedFOV_t> replacement_hook(game::functions::GetCalculatedFOV, &GetCalculatedFOV, true);
	double GetCalculatedFOV()
	{
		if (game::dvars::cg_fovlock && game::dvars::cg_fovlock->current.integer)
		{
			return game::dvars::cg_fovlock->current.integer;
		}
		else
		{
			return replacement_hook.GetOriginalFunc()();
		}
	}


	__declspec(naked) void GetCalculatedFOV_ads_stub()
	{
		const static uint32_t retn_to_set_fov = reinterpret_cast<uint32_t>(game::functions::GetCalculatedFOV) + 0x79;
		static float weaponadsfov;
		__asm
		{
			fld		dword ptr[esp + 0Ch - 4]
			fstp	dword ptr[weaponadsfov]
		}
		if (weaponadsfov == game::structs::SCOPE_FOV)
		{
			weaponadsfov = game::dvars::cg_fovscope->current.integer;
		}
		__asm
		{
			fstp st
			fld     dword ptr[weaponadsfov]
			jmp		retn_to_set_fov
		}
	}
	utils::MinHookObject<LPVOID> ads_hook((LPVOID)0x00450413, (LPVOID)GetCalculatedFOV_ads_stub, true);
}
