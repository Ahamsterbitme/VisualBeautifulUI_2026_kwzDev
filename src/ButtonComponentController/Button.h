#include "gtkmm/button.h"
#include "gtkmm/enums.h"
#include "gtkmm/object.h"
#include <functional>
#include <utility>

namespace VisualUI {
    enum ButtonAlign {
        BUTTON_ALIGN_CENTER,
        BUTTON_ALIGN_START,
        BUTTON_ALIGN_END,
    };
    enum ButtonAdaptionWidth{
        BUTTON_ADAPTION_WIDTH_TRUE,
        BUTTON_ADAPTION_WIDTH_FALSE,
    };
    enum ButtonAdaptionHeight{
        BUTTON_ADAPTION_HEIGHT_TRUE,
        BUTTON_ADAPTION_HEIGHT_FALSE,
    };

    class ButtonComponent{
        private:
        std::string _buttonlabel;
        std::string _style;
        int _width ; int _height;
        int _margin; bool _adaption_width;
        bool _adaption_height; int _align;
        bool _click;

        std::function<void()> _clickaction;

        public:
        ButtonComponent():_buttonlabel("button"),
        _style("default-dark-button"),_width(-1),
        _height(-1) , _margin(1) , _adaption_width(true),
        _adaption_height(true) , _align(1) , _click(false) {}

        ButtonComponent& SettingButtonLabel(const std::string&& ButtonLabelText){
            _buttonlabel = std::move(ButtonLabelText);
            return *this;
        }

        ButtonComponent& SettingButtonStyle(const std::string&& ButtonStyle){
            _style = std::move(ButtonStyle);
            return *this;
        }

        ButtonComponent& SettingButtonWidth(const int&& ButtonWidth){
            _width = std::move(ButtonWidth);
            return *this;
        }

        ButtonComponent& SettingButtonHeight(const int&& ButtonHeight){
            _height = std::move(ButtonHeight);
            return *this;
        }

        ButtonComponent& SettingButtonMargin(const int&& ButtonMargin){
            _margin = ButtonMargin;
            return *this;
        }

        ButtonComponent& SettingButtonAdaption(const ButtonAdaptionWidth&& adaption_width,
            const ButtonAdaptionHeight&& adaption_height){
                switch (adaption_width) {
                    case BUTTON_ADAPTION_WIDTH_TRUE:
                        _adaption_width = true;
                        break;
                    case BUTTON_ADAPTION_WIDTH_FALSE:
                        _adaption_width = false;
                        break;
                };

                switch (adaption_height) {
                    case BUTTON_ADAPTION_HEIGHT_TRUE:
                        _adaption_height = true;
                        break;
                    case BUTTON_ADAPTION_HEIGHT_FALSE:
                        _adaption_height = false;
                        break;
                }
                
                return *this;
            }
        
        ButtonComponent& UserClick (const bool& UserClick){
            _click = UserClick;
            return *this;
        }
        
        ButtonComponent& SettingButtonAlign(const ButtonAlign&& ButtonAlign){
            switch (ButtonAlign) {
                case BUTTON_ALIGN_START:
                    _align = 1;
                    break;
                case BUTTON_ALIGN_CENTER:
                    _align = 2;
                    break;
                case BUTTON_ALIGN_END:
                    _align = 3;
                    break;
            };
            return *this;
        }

        ButtonComponent& Click(const std::function<void()>&& action){
            _clickaction = std::move(action);
            return *this;
        }

        inline Gtk::Button* addComponent(){
            auto NewButtonComponent = Gtk::make_managed<Gtk::Button>();
            NewButtonComponent -> set_label(_buttonlabel);
            NewButtonComponent -> add_css_class(_style);
            NewButtonComponent -> set_size_request(_width , _height);
            switch (_align) {
                case 1:
                NewButtonComponent -> set_halign(Gtk::Align::START);
                break;
                case 2:
                NewButtonComponent -> set_halign(Gtk::Align::CENTER);
                break;
                case 3:
                NewButtonComponent -> set_halign(Gtk::Align::CENTER);
                break;
            }
            if (_click){
                NewButtonComponent -> signal_clicked().connect(_clickaction);
            }
            NewButtonComponent -> set_hexpand(_adaption_width);
            NewButtonComponent -> set_vexpand(_adaption_height);
            return NewButtonComponent;
        }
    };
} 