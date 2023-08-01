#pragma once 

namespace modules::dump_xassets
{
    const std::string XAssetType[] // representation of game::structs::XAssetType
    {
        "xmodelpieces",
        "physpreset",
        "xanimparts",
        "xmodel",
        "material",
        "pixelshader",
        "technique_set",
        "image",
        "sound",
        "sound_curve",
        "clipmap",
        "clipmap_pvs",
        "comworld",
        "gameworld_sp",
        "gameworld_mp",
        "map_ents",
        "gfxworld",
        "light_def",
        "ui_map",
        "font",
        "menulist",
        "menu",
        "localize_entry",
        "weapon",
        "snddriver_globals",
        "fx",
        "impact_fx",
        "aitype",
        "mptype",
        "character",
        "xmodelalias",
        "rawfile",
        "stringtable",
        "count",
        "string",
        "assetlist"
    };

    bool GetXAssetTypeFromStr(const std::string xasset_type_str, game::structs::XAssetType* xasset_type )
    {
        for (size_t i = 0; i < sizeof(XAssetType) / sizeof(XAssetType[0]); ++i)
        {
            if (xasset_type_str == XAssetType[i])
            {
                *xasset_type = static_cast<game::structs::XAssetType>(i);
                return true;
            }
        }
        return false;
    }

    void listassets_f(const char** argv, const size_t argc)
    {       
        game::structs::XAssetType xasset_type;
        if (GetXAssetTypeFromStr(argv[1], &xasset_type))
        {
            game::functions::DB_EnumXAssets(xasset_type, game::functions::DB_PrintAssetName, &xasset_type, 1);
        }
    }

	const game::structs::cmd_function_s* listassets = game::commands::Register("listassets", &listassets_f);
	
}