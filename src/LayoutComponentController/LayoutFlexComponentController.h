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
        std::string _CacheStyle;
        Gtk::Box* FlexLayoutRowBox = nullptr;
        public:
        /**
        this layout default param
        */
            FlexLayoutRow():_style("default-dark-layout"),
                _width(-1) , _height(-1) , _margin(1) , _number(1){}
            /**
            @param LayoutSetyleName setting css class name
            */
            FlexLayoutRow& SetLayoutStyle(const std::string&& LayoutStyleName){
                _style = std::move(LayoutStyleName);
                return *this;
            }
            /**
            @param LayoutWidth setting layout Width 
            */
            FlexLayoutRow& SetLayoutWidth (const int&& LayoutWidth){
                _width = std::move(LayoutWidth);
                return *this;
            }
            /**
            @param LayoutHeight setting layout Height
            */
            FlexLayoutRow& SetLayoutHeight(const int&& LayoutHeight){
                _height = std::move(LayoutHeight);
                return *this;
            }
            /**
            @param LayoutMargin setting layout Margin
            */
            FlexLayoutRow& SetLayoutMargin(const int&& LayoutMargin){
                _margin = std::move(LayoutMargin);
                return *this;
            }
            /**
            @param LayoutChildrenNumber setting layout children number
            */
            FlexLayoutRow& SetLayoutChildrenSpacingNumber(const int&& LayoutChildrenNumber){
                _number = std::move(LayoutChildrenNumber);
                return *this;
            }
            /**
            @param newLayoutStyle setting your new css class
            */
            FlexLayoutRow& ReaciveStyle(const std::string&& newLayoutStyle){
                if (_CacheStyle.empty()){
                    FlexLayoutRowBox -> add_css_class(newLayoutStyle);
                    _CacheStyle = std::move(newLayoutStyle);
                    return *this;
                }
                FlexLayoutRowBox -> remove_css_class(_CacheStyle);
                FlexLayoutRowBox -> add_css_class(newLayoutStyle);
                return *this;
            }
            /**
            @param children add your component
            @param action reactive call back function
            */
            inline Gtk::Box* CreateFlexLayout(const std::vector<Gtk::Widget*> children , std::function<Gtk::Widget*()> action){
                if (!FlexLayoutRowBox){
                    auto FlexLayoutRowBox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL , _number);
                }
                FlexLayoutRowBox -> set_size_request(_width , _height);
                FlexLayoutRowBox -> set_margin(_margin);
                FlexLayoutRowBox -> add_css_class(_style);
                for (auto _children : children){
                    FlexLayoutRowBox->append(*_children);
                }
                if (Gtk::Widget* dyn = action()){
                    FlexLayoutRowBox -> append(*dyn);
                }
                return FlexLayoutRowBox;
            }
    };
}