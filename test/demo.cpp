#include "../src/LayoutComponentController/LayoutBlockComponentController.h"
#include "../src/LayoutComponentController/LayoutFlexComponentController.h"
#include "../src/ApplicationController/Application.h"
#include "../src/ButtonComponentController/Button.h"
#include "../src/TextComponent/HtmlText.h"
#include "../src/TextComponent/Text.h"
#include <iostream>

using namespace VisualUI;
using namespace std;
using namespace Gtk;

int main () {
    VisualUI::Application()
    .SettingAppName("myapp")
    .SettingAppID("com.app.test")
    .SettingAppTitle("myapp")
    .SettingWindowStyleName("class")
    .SettingWindowSize(100, 100)
    .CreateContent([]() -> Widget*{
        static auto newButton = ButtonComponent();
        static auto newHtmlText = HtmlText();
        static auto newFlexRow = FlexLayoutRow(); 
        static auto newText = StaticComponentText();
        static auto newBlockColumns = BlockLayoutColumns();
        return newFlexRow
            .SettingLayoutStyle("default")
            .SettingLayoutMargin(20)
            .SettingLayoutChildrenSpacingNumber(1)
            .SettingLayoutWidth(200)
            .SettingLayoutHeight(200)
            .CreateFlexLayout({
                newText.SettingText("hello,word")
                    .SettingStyleName("defaul-dark-txt")
                    .addComponent(),
                    newBlockColumns.SettingLayoutStyle("default")
                        .SettingLayoutMargin(2)
                        .SettingLayoutChildrenSpacingNumber(1)
                        .SettingLayoutWidth(200)
                        .SettingLayoutHeight(200)
                        .CreateBlockLayout({
                            newText.SettingText("hai!")
                                .SettingStyleName("default")
                                .addComponent(),
                                newHtmlText.SettingHtmlLabel("span")
                                    .SettingText("hello")
                                    .SettingTextSize(TEXT_SIZE_XX_SMALL)
                                    .SettingFontWeight(TEXT_WEIGHT_BOLD)
                                    .SettingFontFamily(FONT_FAMILY_SANS_SERIF)
                                    .SettingTextColor(COLOR_BLACK)
                                    .addComponent(),
                                        newButton.SettingButtonLabel("click me")
                                            .SettingButtonStyle("default-dark-button")
                                            .SettingButtonAdaption(BUTTON_ADAPTION_WIDTH_TRUE,
                                                BUTTON_ADAPTION_HEIGHT_TRUE)
                                            .SettingButtonAlign(BUTTON_ALIGN_CENTER)
                                            .SettingButtonWidth(200)
                                            .SettingButtonHeight(100)
                                            .UserClick(true)
                                            .Click([](){
                                                cout << "click" << endl;
                                            })
                                            .addComponent()
                    })
                }
            );
    })
    .start();
}