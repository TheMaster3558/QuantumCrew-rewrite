#include "auton_selector.hpp"


auton_selector::Auton::Auton(std::string name, const std::function<void()>& callback) : name(name), callback(callback) {}
auton_selector::Category::Category(std::string name, const std::vector <Auton>& autons) : name(name), autons(autons) {}


std::vector<auton_selector::Category> auton_categories;
void auton_selector::set_autons(const std::vector<auton_selector::Category> &categories) {
    auton_categories = categories;
}


auton_selector::Auton selected_auton = auton_categories[0].autons[0];
void auton_selector::call_selected_auton() {
    selected_auton.callback();
}


typedef struct {
    lv_obj_t *category_button_matrix;
    auton_selector::Category *category;
} CategoryButtonMatrixPair;
// Map the button matrix to the category so the category can be retrieved during the callback
std::vector<CategoryButtonMatrixPair> button_matrix_to_category;


lv_res_t button_action(lv_obj_t *button_matrix, const char *text) {
    for (CategoryButtonMatrixPair pair : button_matrix_to_category) {
        bool should_break = false;

        if (pair.category_button_matrix == button_matrix) {
            // auton is in this category
            for (auton_selector::Auton auton : pair.category->autons) {
                if (strcmp(auton.name.c_str(), text) == 0) {
                    selected_auton = auton;
                    should_break = true;
                    break;
                }
            }
        }

        if (should_break) break;
    }

    return LV_RES_OK;
}


void auton_selector::initialize(int autons_per_row) {
    button_matrix_to_category = {};

    lv_obj_t* tabview = lv_tabview_create(lv_scr_act(), NULL);

    for (auton_selector::Category category : auton_categories) {
        lv_obj_t* category_tab = lv_tabview_add_tab(tabview, category.name.c_str());
        lv_obj_t* category_button_matrix = lv_btnm_create(category_tab, NULL);

        size_t num_autons = category.autons.size();
        size_t auton_buttons_size = num_autons + num_autons / autons_per_row + 1;
        const char** auton_buttons = new const char *[auton_buttons_size];

        size_t i;
        int autonIndex = 0;
        for (i = 0; i < auton_buttons_size; i++) {
            // i != 0 so there's no empty row at the start
            if (i != 0 && i % autons_per_row == 0) {
                auton_buttons[i] = "\n";
            }
            else {
                auton_buttons[i] = category.autons[autonIndex++].name.c_str();
            }
        }
        auton_buttons[i] = "";  // empty string at end

        lv_btnm_set_map(category_button_matrix, auton_buttons);
        lv_btnm_set_action(category_button_matrix, *button_action);
        lv_obj_set_pos(category_button_matrix, 0, 100);
        lv_obj_align(category_button_matrix, NULL, LV_ALIGN_CENTER, 0, 0);

        CategoryButtonMatrixPair pair;
        pair.category_button_matrix = category_button_matrix;
        pair.category = &category;
    }
}
