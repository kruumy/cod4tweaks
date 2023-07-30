#pragma once


namespace game::commands
{
	typedef void(__cdecl* cmd_callback)(const char** argv, const size_t argc);
	std::map<std::string, cmd_callback> function_map;

	void callback_prefix()
	{
		const char** argv = game::globals::cmd_args->argv[game::globals::cmd_args->nesting];
		const size_t argc = game::globals::cmd_args->argc[game::globals::cmd_args->nesting];
		const std::string command_name = argv[0];
		if (function_map.contains(command_name))
		{
			function_map[command_name](argv, argc);
		}
	}

	game::structs::cmd_function_s* Register(const char* name, cmd_callback callback)
	{
		const auto cmd = new game::structs::cmd_function_s;
		function_map[name] = callback;
		game::functions::Cmd_AddCommand(name, &callback_prefix, cmd);
		utils::logger::info("Registered Command %s", name);
		return cmd;
	}

	game::structs::cmd_function_s* Register(const char* name, const char* args, const char* desc, cmd_callback callback)
	{
		const auto cmd = new game::structs::cmd_function_s;
		function_map[name] = callback;
		game::functions::Cmd_AddCommand(name, args,desc, &callback_prefix, cmd);
		utils::logger::info("Registered Command %s", name);
		return cmd;
	}
}