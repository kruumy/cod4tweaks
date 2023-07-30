#pragma once


namespace modules::testclient
{
	const game::structs::cmd_function_s* addtestclient = game::commands::Register("addtestclient", (game::commands::cmd_callback_t)game::functions::SV_AddTestClient);
}

