/*
MIT License

Copyright (c) 2019 Kunwar Sahni

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// This code has been modified in order to suit our needs

#include "autons.hpp"


int auton;
int autonCount;
const char *btnmMap[] = {"","","","","","","","","","",""}; // up to 10 autons

lv_obj_t *tabview;
lv_obj_t *offensiveBtnm;
lv_obj_t *defensiveBtnm;

lv_res_t offensiveBtnmAction(lv_obj_t *btnm, const char *txt){
    //printf("offensive button: %s released\n", txt);

    for(int i = 0; i < autonCount; i++){
        if(strcmp(txt, btnmMap[i]) == 0){
            auton = i+1;
        }
    }

    return LV_RES_OK; // return OK because the button matrix is not deleted
}

lv_res_t defensiveBtnmAction(lv_obj_t *btnm, const char *txt)
{
    //printf("defensive button: %s released\n", txt);

    for(int i = 0; i < autonCount; i++){
        if(strcmp(txt, btnmMap[i]) == 0){
            auton = -(i+1);
        }
    }

    return LV_RES_OK; // return OK because the button matrix is not deleted
}

lv_res_t skillsBtnAction(lv_obj_t *btn){
    //printf("skills pressed");
    auton = 0;
    return LV_RES_OK;
}

int tabWatcher() {
    int activeTab = lv_tabview_get_tab_act(tabview);
    while(1){
        int currentTab = lv_tabview_get_tab_act(tabview);

        if(currentTab != activeTab){
            activeTab = currentTab;
            if(activeTab == 0){
                if(auton == 0) auton = 1;
                auton = abs(auton);
                lv_btnm_set_toggle(offensiveBtnm, true, abs(auton)-1);
            }else if(activeTab == 1){
                if(auton == 0) auton = -1;
                auton = -abs(auton);
                lv_btnm_set_toggle(defensiveBtnm, true, abs(auton)-1);
            }else{
                auton = 0;
            }
        }

        pros::delay(20);
    }
}

void init(int hue, int default_auton, const char **autons){

    int i = 0;
    do{
        memcpy(&btnmMap[i], &autons[i], sizeof(&autons));
        i++;
    }while(strcmp(autons[i], "") != 0);

    autonCount = i;
    auton = default_auton;

    // lvgl theme
    lv_theme_t *th = lv_theme_alien_init(hue, NULL); //Set a HUE value and keep font default offensive
    lv_theme_set_current(th);

    // create a tab view object
    tabview = lv_tabview_create(lv_scr_act(), NULL);

    // add 3 tabs (the tabs are page (lv_page) and can be scrolled
    lv_obj_t *offensiveTab = lv_tabview_add_tab(tabview, "Offensive");
    lv_obj_t *defensiveTab = lv_tabview_add_tab(tabview, "Defensive");
    lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");

    //set default tab
    if(auton < 0){
        lv_tabview_set_tab_act(tabview, 1, LV_ANIM_NONE);
    }else if(auton == 0){
        lv_tabview_set_tab_act(tabview, 2, LV_ANIM_NONE);
    }

    // add content to the tabs
    // button matrix
    offensiveBtnm = lv_btnm_create(offensiveTab, NULL);
    lv_btnm_set_map(offensiveBtnm, btnmMap);
    lv_btnm_set_action(offensiveBtnm, offensiveBtnmAction);
    lv_btnm_set_toggle(offensiveBtnm, true, abs(auton)-1);//3
    lv_obj_set_size(offensiveBtnm, 450, 50);
    lv_obj_set_pos(offensiveBtnm, 0, 100);
    lv_obj_align(offensiveBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

    // defensive tab
    defensiveBtnm = lv_btnm_create(defensiveTab, NULL);
    lv_btnm_set_map(defensiveBtnm, btnmMap);
    lv_btnm_set_action(defensiveBtnm, *defensiveBtnmAction);
    lv_btnm_set_toggle(defensiveBtnm, true, abs(auton)-1);
    lv_obj_set_size(defensiveBtnm, 450, 50);
    lv_obj_set_pos(defensiveBtnm, 0, 100);
    lv_obj_align(defensiveBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

    // skills tab
    lv_obj_t *skillsBtn = lv_btn_create(skillsTab, NULL);
    lv_obj_t *label = lv_label_create(skillsBtn, NULL);
    lv_label_set_text(label, "Skills");
    lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, *skillsBtnAction);
    // lv_btn_set_state(skillsBtn, LV_BTN_STATE_TGL_REL);
    lv_obj_set_size(skillsBtn, 450, 50);
    lv_obj_set_pos(skillsBtn, 0, 100);
    lv_obj_align(skillsBtn, NULL, LV_ALIGN_CENTER, 0, 0);

    // start tab watcher
    pros::Task tabWatcher_task(tabWatcher);
}
