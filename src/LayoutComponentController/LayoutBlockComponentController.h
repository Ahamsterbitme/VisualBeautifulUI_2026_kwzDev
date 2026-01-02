#include "gtkmm/enums.h"
#include "gtkmm/object.h"
#include "gtkmm/widget.h"
#include <gtkmm/box.h>
#include <utility>
#include <vector>

namespace VisualUI {
    class BlockLayoutColumns {
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
            BlockLayoutColumns(): _style("default-dark-layout"),
            _width(-1) , _height(-1) , _margin(1) , _number(1){}
            /**
            @param LayoutSetyleName setting css class name
            */
            BlockLayoutColumns& SettingLayoutStyle(const std::string&& LayoutStyleName){
                _style = std::move(LayoutStyleName);
                return *this;
            }
            /**
            @param LayoutWidth setting layout Width 
            */
            BlockLayoutColumns& SettingLayoutWidth(const int&& LayoutWidth){
                _width = std::move(LayoutWidth);
                return *this;
            }
            /**
            @param LayoutHeight setting layout Height
            */
            BlockLayoutColumns& SettingLayoutHeight(const int&& LayoutHeight){
                _height = std::move(LayoutHeight);
                return *this;
            }
            /**
            @param LayoutHeight setting layout Margin
            */
            BlockLayoutColumns& SettingLayoutMargin(const int&& LayoutMargin){
                _margin = std::move(LayoutMargin);
                return *this;
            }
            /**
            @param LayoutChildrenNumber setting layout children number
            */
            BlockLayoutColumns& SettingLayoutChildrenSpacingNumber(const int&& LayoutChildrenNumber){
                _number = std::move(LayoutChildrenNumber);
                return *this;
            }
            /**
            @param children add your component
            */
            inline Gtk::Box* CreateBlockLayout (std::vector<Gtk::Widget*> children){
                auto BlockLayoutColumnsBox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL,_number);
                BlockLayoutColumnsBox -> set_size_request(_width , _height);
                BlockLayoutColumnsBox -> set_margin(_margin);
                BlockLayoutColumnsBox -> add_css_class(_style);
                for (auto children_ : children){
                    BlockLayoutColumnsBox -> append(*children_);
                }
                return BlockLayoutColumnsBox;
            }
            
    };
}