#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/EngineDefs.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Input/Input.h>

using namespace Urho3D;

#include "main_defaults.h"

using namespace DefaultConfig;

class UlexliteGame : public Application {
  URHO3D_OBJECT(UlexliteGame, Application);

public:
  explicit UlexliteGame(Context *context) : Application(context) {}

  void Setup() override {

    // singleton file system
    auto *file_sys = GetSubsystem<FileSystem>();

    // application path and name
    const ea::string app_path = file_sys->GetProgramFileName();
    const ea::string app_name = GetFileName(app_path);

    // operating folders
    const ea::string core_dir = file_sys->GetCurrentDir() + core_dir_name;
    const ea::string user_dir = file_sys->GetCurrentDir() + user_dir_name;
    const ea::string down_dir = file_sys->GetCurrentDir() + down_dir_name;
    const ea::string temp_dir = file_sys->GetCurrentDir() + temp_dir_name;

    // core data must exist
    if (!file_sys->DirExists(core_dir)) {
      ErrorExit("Core data directory missing: " + core_dir);
      return;
    }

    // manifest file name
    const ea::string manifest_name = app_name + manifest_extension;

    // we want the manifest to exist, but if it doesn't, create it and log error
    /// if (!file_sys->FileExists(manifest_name)) {
    ///   URHO3D_LOGERROR("Manifest file not in game folder! '{}'",
    ///   manifest_name);
    ///
    /// }

    engineParameters_[EP_WINDOW_TITLE] = "rbfx Light Skeleton";
    engineParameters_[EP_FULL_SCREEN] = false;
    engineParameters_[EP_WINDOW_MAXIMIZE] = false;
    engineParameters_[EP_WINDOW_RESIZABLE] = true;
    engineParameters_[EP_WINDOW_WIDTH] = 1280;
    engineParameters_[EP_WINDOW_HEIGHT] = 720;
  }

  void Start() override {
    auto *input = GetSubsystem<Input>();
    input->SetMouseMode(Urho3D::MM_FREE);
    input->SetMouseVisible(true);

    SubscribeToEvent(
        E_UPDATE, [this, input](StringHash, VariantMap &eventData) {
          using namespace Update;
          float timeStep = eventData[P_TIMESTEP].GetFloat();

          if (input->GetKeyDown(KEY_ESCAPE))
            engine_->Exit();
        });
  }
};

// This macro generates the actual main entry point for Linux
URHO3D_DEFINE_APPLICATION_MAIN(UlexliteGame);
