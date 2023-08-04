#pragma once

namespace modules::customfov
{
	double GetCalculatedFOV();
	utils::MinHookObject<game::functions::GetCalculatedFOV_t> hook(game::functions::GetCalculatedFOV, &GetCalculatedFOV, true);
	double GetCalculatedFOV()
	{
		double fov = hook.GetOriginalFunc()();
		if (game::dvars::cg_lockfov && game::dvars::cg_lockfov->current.integer)
		{
			fov = static_cast<float>(game::dvars::cg_lockfov->current.integer);
		}
		return fov;
	}
}
