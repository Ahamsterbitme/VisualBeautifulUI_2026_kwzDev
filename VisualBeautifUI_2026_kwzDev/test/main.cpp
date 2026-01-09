#include "../src/LayoutComponentController/LayoutBlockComponentController.h"
#include "../src/ApplicationController/Application.h"
#include "../src/ButtonComponentController/Button.h"
#include "../src/ImagesComponent/ImageComponent.h"
#include "../src/TextComponent/ReactiveText.h"
#include "../src/InputComponent/Input.h"
#include "../src/utils/DelayExecutor.h"
#include "../src/TextComponent/Text.h"
#include "gtkmm/widget.h"

using namespace std;
using namespace Gtk;
using namespace VisualUI;

int main () {
    VisualUI::Application()
        .SetAppID("com.app.my")
        .SetAppName("Input Test")
        .SetAppTitle("Input Test")
        .SetWindowStyleName("default-windows-css")
        .SetWindowSize(700, 500)
        .CreateContent([]() -> Widget*{
            MAKE_COMPONENT(InputComponent, NewInput);
            MAKE_COMPONENT(ButtonComponent, NewButton)
            MAKE_COMPONENT(StaticComponentText, NewText);
            MAKE_COMPONENT(BlockLayoutColumns, MainLayout);
            MAKE_COMPONENT(ReactiveComponentText, newReactiveText);
            MAKE_COMPONENT(Delaytool, newDelaytool);
            MAKE_COMPONENT(ImageComponent, NewImages);
            return MainLayout
                .SetLayoutHeight(500)
                .SetLayoutWidth(500)
                .SetLayoutMargin(1)
                .SetLayoutStyle("default-layout-css")
                .CreateBlockLayout({
                    NewText
                        .SetText("input your name")
                        .addComponent(),
                        NewInput
                            .SetInputAlign(INPUT_ALIGN_CENTER)
                            .SetInputType(INPUT_TEXT)
                            .addComponent(),
                                newReactiveText
                                    .SetDefaultText("click button sumibt your name")
                                    .addComponent(),
                                        NewImages
                                            .SetImageWidth(100)
                                            .SetImageHeight(100)
                                            .SetImageAdaptionWidth(IMAGE_ADAPTION_WIDTH_FALSE)
                                            .SetImageAdaptionHeight(IMAGE_ADAPTION_HEIGHT_FALSE)
                                            .SetImageMargin(0)
                                            .SetImageAlign(IMAGE_ALIGN_CENTER)
                                            .SetImageFile("logo.png")
                                            .addComponent(),
                },[&NewButton , &newReactiveText , &NewInput , &newDelaytool]() -> Widget*{
                    NewButton
                        .SetButtonWidth(100)
                        .SetButtonHeight(40)
                        .SetButtonAdaption(BUTTON_ADAPTION_WIDTH_FALSE,BUTTON_ADAPTION_HEIGHT_FALSE)
                        .SetButtonAlign(BUTTON_ALIGN_CENTER)
                        .SetButtonLabel("sumibt")
                        .UserClick(true)
                        .Click([&newReactiveText,&NewInput,&newDelaytool]{
                            if (NewInput.GetInputStr().empty()) {
                                newReactiveText
                                    .ReactiveText("请输入名字!");
                                    newDelaytool.setTimeoutCallBack_ui([]{
                                        std::cout << "hai" << std::endl;
                                    }, 1000);
                                    return;
                            }
                            newReactiveText
                            .ReactiveText("原来你叫" + NewInput.GetInputStr());
                        });
                        return NewButton.addComponent();
                });
        })
        .start();   
        return 0;
}