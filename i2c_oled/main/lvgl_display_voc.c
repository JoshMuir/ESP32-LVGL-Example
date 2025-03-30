#include "lvgl.h"
#include <stdio.h>


void example_lvgl_display_voc(lv_disp_t *disp)
{
    lv_obj_t *scr = lv_disp_get_scr_act(disp);
    lv_obj_t *label = lv_label_create(scr);
    lv_label_set_text(label, "Hello Espressif, Hello LVGL.");

}

// function that takes a temperature value and displays it on the screen 
void display_temperature(lv_disp_t *disp, float temperature)
{
    lv_obj_t *scr = lv_disp_get_scr_act(disp);
    lv_obj_t *label = lv_label_create(scr);
    char temp_str[20];
    snprintf(temp_str, sizeof(temp_str), "Temp: %.2f C", temperature);
    lv_label_set_text(label, temp_str);
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 0);
    // screen is blue/yellow 
    lv_obj_set_width(label, lv_pct(90));         /* Separate... */
}


static void set_angle(void * obj, int32_t v)
{
    lv_arc_set_value((lv_obj_t *)obj, v);
}

/**
 * Create an arc which acts as a loader.
 */
void lv_example_arc_2(lv_disp_t *disp)
{
    /*Create an Arc*/
    lv_obj_t * arc = lv_arc_create(lv_disp_get_scr_act(disp));
    lv_arc_set_rotation(arc, 270);
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_center(arc);
    // scale the arc
    lv_obj_set_size(arc, 40, 40);
    lv_arc_set_value(arc, 50);



}



