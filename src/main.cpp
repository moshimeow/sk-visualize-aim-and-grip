#include "stereokit.h"
#include "stereokit_ui.h"
#include "randoviz.hpp"
using namespace sk;


#include <stdio.h>

#include <unistd.h>

void disp_controller(handed_ hand, const char *name) {
  const controller_t *controller = input_controller(hand);
  sk::log_diagf("Exists %d tracked %d tracked_pos %d tracked_rot %d", controller->exists, controller->tracked, controller->tracked_pos, controller->tracked_rot);
  if (!controller->tracked_pos || !controller->tracked_rot) {
    return;
  }
  // log_diagf("%s is %d", name, controller->tracked);
  // return;
  draw_axis(controller->pose, 1.0f, 0.01);
  draw_axis(controller->aim, 1.0f, 0.01);

  char blarb[128];
  snprintf(blarb, 128, "%s-grip", name);


  text_from_vec3(controller->pose.position, blarb);
  snprintf(blarb, 128, "%s-aim", name);
  text_from_vec3(controller->aim.position, blarb);

}

void update() {
  disp_controller(sk::handed_left, "left");
  disp_controller(sk::handed_right, "right");
}

int main() {
  sk_settings_t settings = {};
  settings.app_name = "StereoKit C";
  settings.assets_folder = "/2/XR/skNotes/Assets";
  settings.display_preference = display_mode_mixedreality;
  settings.overlay_app = true;
  settings.overlay_priority = 1;
  if (!sk_init(settings))
    return 1;

  while (sk_step(update)) {
    // Don't do anything here
  };

  sk_shutdown();
  return 0;
}
