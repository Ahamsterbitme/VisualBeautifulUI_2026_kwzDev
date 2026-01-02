#include "gtkmm/enums.h"
#include "gtkmm/object.h"
#include "gtkmm/widget.h"
#include <gtkmm/box.h>
#include <gtkmm.h>
#include <utility>
#include <vector>

namespace VisualUI {
    class FlexLayoutRow{
        private:
        std::string _style;
        int _width;
        int _height;
        int _margin;
        int _number;
        public:
        /**
        this layout default param
        */
            FlexLayoutRow():_style("default-dark-layout"),
                _width(-1) , _height(-1) , _margin(1) , _number(1){}
            /**
            @param LayoutSetyleName setting css class name
            */
            FlexLayoutRow& SettingLayoutStyle(const std::string&& LayoutStyleName){
                _style = std::move(LayoutStyleName);
                return *this;
            }
            /**
            @param LayoutWidth setting layout Width 
            */
            FlexLayoutRow& SettingLayoutWidth (const int&& LayoutWidth){
                _width = std::move(LayoutWidth);
                return *this;
            }
            /**
            @param LayoutHeight setting layout Height
            */
            FlexLayoutRow& SettingLayoutHeight(const int&& LayoutHeight){
                _height = std::move(LayoutHeight);
                return *this;
            }
            /**
            @param LayoutMargin setting layout Margin
            */
            FlexLayoutRow& SettingLayoutMargin(const int&& LayoutMargin){
                _margin = std::move(LayoutMargin);
                return *this;
            }
            /**
            @param LayoutChildrenNumber setting layout children number
            */
            FlexLayoutRow& SettingLayoutChildrenSpacingNumber(const int&& LayoutChildrenNumber){
                _number = std::move(LayoutChildrenNumber);
                return *this;
            }
            /**
            @param children add your component
            */
            inline Gtk::Box* CreateFlexLayout(const std::vector<Gtk::Widget*> children){
                auto FlexLayoutRowBox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL , _number);
                FlexLayoutRowBox -> set_size_request(_width , _height);
                FlexLayoutRowBox -> set_margin(_margin);
                FlexLayoutRowBox -> add_css_class(_style);
                for (auto _children : children){
                    FlexLayoutRowBox->append(*_children);
                }
                return FlexLayoutRowBox;
            }
    };
}