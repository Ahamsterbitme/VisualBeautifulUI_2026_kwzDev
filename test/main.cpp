#include "../src/LayoutComponentController/LayoutBlockComponentController.h"
#include "../src/LayoutComponentController/LayoutFlexComponentController.h"
#include "../src/ApplicationController/Application.h"
#include "../src/ButtonComponentController/Button.h"
#include "../src/TextComponent/HtmlText.h"
#include "../src/TextComponent/Text.h"
#include "gtkmm/widget.h"
#include <iostream>

using namespace VisualUI;
using namespace Gtk;
using namespace std;

Widget* Userbutton(){
    auto blockLayout = BlockLayoutColumns();
    auto NewButton = ButtonComponent();
    return blockLayout.CreateBlockLayout({
    NewButton.SettingButtonMargin(1)
        .SettingButtonAlign(BUTTON_ALIGN_CENTER)
        .SettingButtonAdaption(BUTTON_ADAPTION_WIDTH_TRUE, BUTTON_ADAPTION_HEIGHT_TRUE)
        .SettingButtonLabel("hai cliek me")
        .UserClick(true)
        .Click([](){
            cout << "hai" << endl;
        })
        .addComponent()
    });
}

int main () {
    VisualUI::Application()
        .SettingAppID("com.app.kwzdev")
        .SettingAppName("Visual Beautiful UI 2026 KwzDev")
        .SettingAppTitle("Visual Beautiful UI")
        .SettingWindowSize(500, 300)
        .CreateContent([]() -> Widget*{
            auto blockLayout = BlockLayoutColumns();
            auto flexLayout = FlexLayoutRow();
            auto text = StaticComponentText();
            return blockLayout
                .SettingLayoutChildrenSpacingNumber(2)
                .SettingLayoutMargin(2)
                .SettingLayoutStyle("block-css")
                .SettingLayoutWidth(200)
                .SettingLayoutHeight(200)
                .CreateBlockLayout({
                    text.SettingText("hai developer!")
                        .SettingStyleName("text-css")
                        .addComponent(),
                });
        }).start();
}