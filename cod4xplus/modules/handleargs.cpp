#include "handleargs.hpp"
#include "windowed_fullscreen.hpp"
#include "../game/functions.hpp"
#include <iostream>

void modules::handleargs::ApplyArgs(const utils::cmdparser& args)
{
	if(args.contains("-windowedfullscreen"))
	{
		game::functions::Cbuf_AddText("r_fullscreen 0\n",0);
		windowed_fullscreen::WindowFullscreen();
	}
}
