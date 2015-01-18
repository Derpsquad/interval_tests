#include <pebble.h>
#include "schedules.h"
static Window *s_main_window;
static TextLayer *s_time_layer;

  
static void main_window_load(Window *window) {
  /*//do my testing stuff
  interval econ_class;
  econ_class.day = MONDAY;
  econ_class.duration = 115;
  econ_class.repeat = true;
  econ_class.begin_time_mins = 695; //11:35am
  
  int econ_id = interval_write(econ_class);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "attempted write with persistent id: %d", econ_id);
  
  interval art_class;
  art_class.day = WEDNESDAY;
  art_class.duration = 115;
  art_class.repeat = true;
  art_class.begin_time_mins = 695; //11:35am
  
  int art_id = interval_write(art_class);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "attempted write with persistent id: %d", art_id);
  
  schedule_all();
  */
  clear_all();
  
  //APP_LOG(APP_LOG_LEVEL_DEBUG, "m: %d tu: %d wed: %d fri: %d sat: %d sun: %d today: %d", MONDAY, TUESDAY, WEDNESDAY, FRIDAY, SATURDAY, SUNDAY, TODAY);
  // Create time TextLayer
  s_time_layer = text_layer_create(GRect(0, 55, 144, 50));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_text(s_time_layer, "hithere");

  // Improve the layout to be more like a watchface
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
}

static void main_window_unload(Window *window) {
    // Destroy TextLayer
    text_layer_destroy(s_time_layer);
}

static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
}

static void deinit() {
    // Destroy Window
    window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}