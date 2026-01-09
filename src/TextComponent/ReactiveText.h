#include "gtkmm/object.h"
#include <gtkmm/label.h>
#include <memory>
#include <string>
#include <utility>

namespace VisualUI {
    class ReactiveComponentText{
        private:
        std::shared_ptr<std::string> _label;
        std::string _style;
        std::string _CacheStyle;
        Gtk::Label* ComponentLabel;
        public:
            ReactiveComponentText()
            :_label(std::make_shared<std::string>("text")) , _style("default-text") , _CacheStyle("") ,
             ComponentLabel(nullptr){}
            ReactiveComponentText(const ReactiveComponentText&) = delete;
            ReactiveComponentText(ReactiveComponentText&&) = default;
            ReactiveComponentText& operator=(ReactiveComponentText&&) = default;
            /**
            @param text settings your init text
            */
            ReactiveComponentText& SetDefaultText(const std::string&& text){
                *_label = std::move(text);
                if (ComponentLabel){
                    ComponentLabel -> set_label(text);
                    return *this;
                }
                return *this;
            }
            /**
            @param textStyleName settings init text class name
            */
            ReactiveComponentText& SetStyleName(const std::string&& textStyleName){
                if (ComponentLabel){
                    ComponentLabel -> add_css_class(textStyleName);
                    _CacheStyle = std::move(textStyleName);
                    return *this;
                }
                _style = std::move(textStyleName);
                _CacheStyle = std::move(_style);
                return *this;
            }
            /**
            @param text this is settings your new Text
            */
            ReactiveComponentText& ReactiveText(std::string&& text){
                if (ComponentLabel){
                    ComponentLabel -> set_label(text);
                    return *this;
                }
                *_label = std::move(text);
                return *this;
            }
            /**
            @param newtextStyleName this settings your new Text class Name
            */
            ReactiveComponentText& ReactiveStyleName(std::string&& newtextStyleName){
                if (ComponentLabel){
                    ComponentLabel -> remove_css_class(_CacheStyle);
                    ComponentLabel -> add_css_class(newtextStyleName);
                    _CacheStyle = std::move(newtextStyleName);
                    return *this;
                }
                _style = newtextStyleName;
                _CacheStyle = std::move(newtextStyleName);
                return *this;
            }
            inline Gtk::Label* addComponent(){
                if (!ComponentLabel){
                    ComponentLabel = Gtk::make_managed<Gtk::Label>();
                }
                ComponentLabel -> set_label(*_label);
                ComponentLabel -> add_css_class(_style);
                return ComponentLabel;
            }
    };
}