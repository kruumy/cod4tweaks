#pragma once

namespace modules::iw3mvm_binds
{
	__declspec(naked) void OnKeyEvent_stub(int a1, char key, int a3, int a4)
	{
		const static uint32_t continuer = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x1CA;
		const static uint32_t switch_K = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0xDD;
		const static uint32_t switch_J = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x5C;
		const static uint32_t switch_L = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x104;
		const static uint32_t switch_C8 = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x1DE;
		const static uint32_t switch_CD = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x14A;
		const static uint32_t switch_CE = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x1A3;
		const static uint32_t switch_default = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x1F0;

		if (game::dvars::mvm_bind_playdolly && key == game::dvars::mvm_bind_playdolly->current.string[0])
		{
			__asm jmp	switch_J // Play Campath
		}
		else if (game::dvars::mvm_bind_addnode && key == game::dvars::mvm_bind_addnode->current.string[0])
		{
			__asm jmp	switch_K // Add Node
		}
		else if (game::dvars::mvm_bind_clearnodes && key == game::dvars::mvm_bind_clearnodes->current.string[0])
		{
			__asm jmp	switch_L // Clear Nodes
		}
		else if (key == 0xC8)
		{
			__asm jmp	switch_C8
		}
		else if (key == 0xCD)
		{
			__asm jmp	switch_CD
		}
		else if (key == 0xCE)
		{
			__asm jmp	switch_CE
		}
		else
		{
			__asm jmp	switch_default
		}
		__asm jmp	continuer
	}
	utils::MinHookObject<LPVOID> hook(reinterpret_cast<LPVOID>(game::functions::iw3mvm_OnKeyEvent ? reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x42 : NULL), &OnKeyEvent_stub, true);

	
}