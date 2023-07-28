#pragma once
#include <MinHook.h>

namespace utils
{
	template<typename T>
	class MinHookObject
	{
	public:
		MinHookObject(T pTarget, T pDetour, bool enable = true)
		{
			this->pTarget = pTarget;
			this->pDetour = pDetour;
			this->isEnabled = false;
			if (!isInitialized)
			{
				MH_Initialize();
				isInitialized = true;
			}
			MH_CreateHook((LPVOID)pTarget, (LPVOID)pDetour, reinterpret_cast<LPVOID*>(&ppOriginal));
			if (enable)
			{
				EnableHook();
			}
		}
		~MinHookObject()
		{
			DisableHook();
		}
		void EnableHook()
		{
			if (!isEnabled)
			{
				MH_EnableHook((LPVOID)pTarget);
				isEnabled = true;
			}
		}

		void DisableHook()
		{
			if (isEnabled)
			{
				MH_DisableHook((LPVOID)pTarget);
				isEnabled = false;
			}

		}
		T GetOriginalFunc()
		{
			return ppOriginal;
		}
		bool IsEnabled()
		{
			return isEnabled;
		}

	private:
		T pTarget;
		T pDetour;
		T ppOriginal;
		bool isEnabled;
		static inline bool isInitialized = false;
	};
}
