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
        std::string _CacheStyle;
        Gtk::Box* BlockLayoutColumnsBox = nullptr;
        public:
        /**
        this layout default param
        */
            BlockLayoutColumns(): _style("default-dark-layout"),
            _width(-1) , _height(-1) , _margin(1) , _number(1) , _CacheStyle(""){}
            /**
            @param LayoutSetyleName setting css class name
            */
            BlockLayoutColumns& SetLayoutStyle(const std::string&& LayoutStyleName){
                _style = std::move(LayoutStyleName);
                _CacheStyle = std::move(LayoutStyleName);
                return *this;
            }
            /**
            @param LayoutWidth setting layout Width 
            */
            BlockLayoutColumns& SetLayoutWidth(const int&& LayoutWidth){
                _width = std::move(LayoutWidth);
                return *this;
            }
            /**
            @param LayoutHeight setting layout Height
            */
            BlockLayoutColumns& SetLayoutHeight(const int&& LayoutHeight){
                _height = std::move(LayoutHeight);
                return *this;
            }
            /**
            @param LayoutHeight setting layout Margin
            */
            BlockLayoutColumns& SetLayoutMargin(const int&& LayoutMargin){
                _margin = std::move(LayoutMargin);
                return *this;
            }
            /**
            @param LayoutChildrenNumber setting layout children number
            */
            BlockLayoutColumns& SetLayoutChildrenSpacingNumber(const int&& LayoutChildrenNumber){
                _number = std::move(LayoutChildrenNumber);
                return *this;
            }
            /**
            @param newLayoutStyle setting your new css class
            */
            BlockLayoutColumns& ReaciveStyle(const std::string&& newLayoutStyle){
                if (_CacheStyle.empty()){
                    BlockLayoutColumnsBox -> add_css_class(newLayoutStyle);
                    _CacheStyle = std::move(newLayoutStyle);
                    return *this;
                }
                BlockLayoutColumnsBox -> remove_css_class(_CacheStyle);
                BlockLayoutColumnsBox -> add_css_class(newLayoutStyle);
                return *this;
            }
            /**
            @param children add your component
            @param action reactive call back function
            */
            inline Gtk::Box* CreateBlockLayout (std::vector<Gtk::Widget*> children , std::function<Gtk::Widget*()> action){
                if(!BlockLayoutColumnsBox){
                    BlockLayoutColumnsBox = Gtk::make_managed<Gtk::Box>
                    (Gtk::Orientation::VERTICAL,_number);
                }
                BlockLayoutColumnsBox -> set_size_request(_width , _height);
                BlockLayoutColumnsBox -> set_margin(_margin);
                BlockLayoutColumnsBox -> add_css_class(_style);
                for (auto children_ : children){
                    BlockLayoutColumnsBox -> append(*children_);
                }
                if (Gtk::Widget* dyn = action()){
                    BlockLayoutColumnsBox -> append(*dyn);
                }
                return BlockLayoutColumnsBox;
            }
    };
}