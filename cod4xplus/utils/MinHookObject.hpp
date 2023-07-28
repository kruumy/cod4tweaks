#pragma once
#include <MinHook.h>

namespace utils
{
	template<typename T>
	class MinHookObject
	{
	public:
		MinHookObject(LPVOID pTarget, LPVOID pDetour, bool enable = true)
		{
			this->pTarget = pTarget;
			this->pDetour = pDetour;
			this->isEnabled = false;
			if (!isInitialized)
			{
				MH_Initialize();
				isInitialized = true;
			}
			MH_CreateHook(pTarget, pDetour, reinterpret_cast<LPVOID*>(&ppOriginal));
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
				MH_EnableHook(pTarget);
				isEnabled = true;
			}
		}

		void DisableHook()
		{
			if (isEnabled)
			{
				MH_DisableHook(pTarget);
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
		LPVOID pTarget;
		LPVOID pDetour;
		T ppOriginal;
		bool isEnabled;
		static inline bool isInitialized = false;
	};
}
