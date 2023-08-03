#pragma once

namespace modules::iw3mvm_binds
{
	__declspec(naked) void OnKeyEvent_stub(int a1, int key, int a3, int a4)
	{
		const static uint32_t switch_K = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0xDD;
		const static uint32_t switch_J = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x5C;
		const static uint32_t switch_L = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x104;
		const static uint32_t switch_C8 = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x1DE;
		const static uint32_t switch_CD = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x14A;
		const static uint32_t switch_CE = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x1A3;
		const static uint32_t switch_default = reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x1F0;
		if ( game::dvars::mvm_usedefaultbinds && game::dvars::mvm_usedefaultbinds->current.enabled )
		{
			if (key == 'j')
			{
				__asm jmp	switch_J // Play Campath
			}
			else if (key == 'k')
			{
				__asm jmp	switch_K // Add Node
			}
			else if (key == 'l')
			{
				__asm jmp	switch_L // Clear Nodes
			}
		}
		if (key == 0xC8)
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
		__asm jmp	switch_default
	}
	utils::MinHookObject<LPVOID> hook(reinterpret_cast<LPVOID>(game::functions::iw3mvm_OnKeyEvent ? reinterpret_cast<uint32_t>(game::functions::iw3mvm_OnKeyEvent) + 0x42 : NULL), &OnKeyEvent_stub, true);

	const game::structs::cmd_function_s* mvm_addnode = game::commands::Register("mvm_addnode", (game::commands::cmd_callback_t)game::functions::iw3mvm_AddNode);

	const game::structs::cmd_function_s* mvm_playdolly = game::commands::Register("mvm_playdolly", (game::commands::cmd_callback_t)game::functions::iw3mvm_PlayDolly_Wrapped);

	const game::structs::cmd_function_s* mvm_clearnodes = game::commands::Register("mvm_clearnodes", (game::commands::cmd_callback_t)game::functions::iw3mvm_ClearNodes_Wrapped);

	
}