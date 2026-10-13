#pragma once
#include <EASTL/string.h>

namespace DefaultConfig {

// Desktop target default configurations (windows/linux/mac)
#if DESKTOP

inline const ea::string core_dir_name = "core/";
inline const ea::string user_dir_name = "user/";
inline const ea::string down_dir_name = "down/";
inline const ea::string temp_dir_name = "temp/";

inline const ea::string default_user_config_json = R"({
    "game.first_run": true,
    "audio.master_volume": 1.0,
    "window.full_screen": false,
    "window.maximized": false,
    "window.resizable": false,
    "window.width": 1280,
    "window.height": 720
})";

inline const short game_version_major = 0;
inline const short game_version_medium = 0;
inline const short game_version_minor = 1;

inline const ea::string manifest_extension = "_manifest.json";

inline const ea::string expected_manifest_json = R"({
    "game.name": "ulexite"
    "game.version": "0.0.1",
    "game.build_date": "september_17_2026",
    "game.platform": "desktop"
})";

#endif

} // namespace DefaultConfig