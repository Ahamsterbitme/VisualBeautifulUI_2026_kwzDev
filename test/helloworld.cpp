#include "../src/LayoutComponentController/LayoutBlockComponentController.h"
#include "../src/ApplicationController/Application.h"
#include "../src/ButtonComponentController/Button.h"
#include "../src/TextComponent/ReactiveText.h"
#include "../src/TextComponent/HtmlText.h"
#include "gtkmm/widget.h"

using namespace std;
using namespace Gtk;
using namespace VisualUI;

int main () {
    VisualUI::Application()
        .SetAppID("myapp")
        .SetAppName("myapp")
        .SetAppTitle("hello world")
        .SetWindowSize(600, 400)
        .CreateContent([]() -> Widget*{
            BlockLayoutColumns blocklayout;
            MAKE_COMPONENT(ReactiveComponentText, newReactiveText);
            MAKE_COMPONENT(ButtonComponent, NewButton);
            MAKE_COMPONENT(HtmlText, newHtmlText)
            return blocklayout
                .SetLayoutHeight(200)
                .SetLayoutWidth(200)
                .CreateBlockLayout({
                    newReactiveText
                        .SetDefaultText("hello world")
                        .SetStyleName("default-txt")
                        .addComponent(),
                    newHtmlText
                        .SetHtmlLabel("span")
                        .SetTextColor(COLOR_WHITE)
                        .SetText("Hai Developer!")
                        .SetTextSize(TEXT_SIZE_MEDIUM)
                        .SetFontWeight(TEXT_WEIGHT_BOLD)
                        .SetFontFamily(FONT_JETBRAINS_MONO)
                        .addComponent()
                },[&newReactiveText , &NewButton]()->Gtk::Widget*{
                    NewButton
                        .SetButtonLabel("Click me")
                        .SetButtonAdaption(BUTTON_ADAPTION_WIDTH_FALSE, 
                            BUTTON_ADAPTION_HEIGHT_FALSE)
                            .SetButtonAlign(BUTTON_ALIGN_CENTER)
                            .SetButtonStyle("default-button")
                            .SetButtonMargin(10)
                            .UserClick(true)
                            .Click([&newReactiveText]{
                                newReactiveText.ReactiveText("hai");
                            });
                            return NewButton.addComponent();
                });
        })
        .start();
}