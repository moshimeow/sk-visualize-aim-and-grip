#include "stereokit.h"
#include "stereokit_ui.h"
using namespace sk;


#include <stdio.h>

#include <unistd.h>


int main() {
  sk_settings_t settings = {};
  settings.app_name = "StereoKit C";
  settings.assets_folder = "/2/XR/skNotes/Assets";
  settings.display_preference = display_mode_mixedreality;
  settings.overlay_app = true;
  settings.overlay_priority = 1;
  if (!sk_init(settings))
    return 1;

  while (sk_step([]() {
  })) {
  };

  sk_shutdown();
  return 0;
}
