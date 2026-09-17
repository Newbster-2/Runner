#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/EngineDefs.h>
#include <Urho3D/Input/Input.h>

using namespace Urho3D;

class MyRbfxGame : public Application {
  URHO3D_OBJECT(MyRbfxGame, Application);

public:
  explicit MyRbfxGame(Context *context) : Application(context) {}

  void Setup() override {
    // Configure engine settings (like window title)
    engineParameters_[EP_WINDOW_TITLE] = "rbfx Light Skeleton";
    engineParameters_[EP_FULL_SCREEN] = false;
    engineParameters_[EP_WINDOW_WIDTH] = 1280;
    engineParameters_[EP_WINDOW_HEIGHT] = 720;
  }

  void Start() override {
    // Put your game initialization logic here (scenes, cameras, etc.)

    // Subscribe to per-frame update event instead of overriding a virtual
    // Update()
    SubscribeToEvent(E_UPDATE, [this](StringHash, VariantMap &eventData) {
      using namespace Update;
      float timeStep = eventData[P_TIMESTEP].GetFloat();

      auto *input = GetSubsystem<Input>();
      if (input->GetKeyDown(KEY_ESCAPE))
        engine_->Exit();
    });
  }
};

// This macro generates the actual main entry point for Linux
URHO3D_DEFINE_APPLICATION_MAIN(MyRbfxGame);
