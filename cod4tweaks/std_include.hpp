#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <vector>
#include <string>
#include <format>
#include <iostream>
#include <d3d9.h>
#include <map>
#include <unordered_map>
#include <sstream>


#include "utils/logger.hpp"
#include "utils/clipboard.hpp"

#include "deps/MinHook.h"
#include "utils/MinHookObject.hpp"

#include "game/structs.hpp"
#include "game/globals.hpp"
#include "game/functions.hpp"
#include "game/dvars.hpp"
#include "game/commands.hpp"

#include "modules/_renderer.hpp"
#include "modules/com_redirect.hpp"
#include "modules/dump_xassets.hpp"
#include "modules/testclient.hpp"
#include "modules/copyip.hpp"
#include "modules/demorecorder.hpp"
#include "modules/windowed_fullscreen.hpp"
