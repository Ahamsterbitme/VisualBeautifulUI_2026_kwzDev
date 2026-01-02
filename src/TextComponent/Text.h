#include "gtkmm/label.h"
#include "gtkmm/object.h"
#include <memory>
#include <string>
#include <utility>

namespace VisualUI {
    class StaticComponentText{
        private:
            std::shared_ptr<std::string> _text;
            std::shared_ptr<std::string> _style;
        public:
        /**
        this text Component default data
        */
            StaticComponentText(): _text(std::make_shared<std::string>("hai vbui 2026")),
            _style(std::make_shared<std::string>("default_dark")){}

            /**
            @param text this settings your text data
            */
            StaticComponentText& SettingText(const std::string&& text){
                _text = std::move(std::make_shared<std::string>(text));
                return *this;   
            }
            /**
            @param textStyleName this settings your text class name 
            */
            StaticComponentText& SettingStyleName(const std::string&& textStyleName){
                _style = std::move(std::make_shared<std::string>(textStyleName));
                return *this;
            }

            inline Gtk::Label* addComponent () {
                auto NewLabel = Gtk::make_managed<Gtk::Label>();
                NewLabel -> set_label(*_text);
                NewLabel -> add_css_class(*_style);
                return NewLabel;
            }
    };
}