#include "gtkmm/label.h"
#include "gtkmm/object.h"
#include <string>
#include <iostream>
#include <utility>

namespace VisualUI {

    //enum text font family
    enum HtmlTextFontFamily {
        FONT_FAMILY_DEFAULT,       
        FONT_FAMILY_SERIF,        
        FONT_FAMILY_SANS_SERIF,     
        FONT_FAMILY_MONOSPACE,     
        FONT_FAMILY_CURSIVE,       
        FONT_FAMILY_FANTASY,       
        FONT_JETBRAINS_MONO,
    };

    //enum text font size
    enum HtmlTextSize{
        TEXT_SIZE_XX_SMALL,   
        TEXT_SIZE_X_SMALL,     
        TEXT_SIZE_SMALL,      
        TEXT_SIZE_MEDIUM,     
        TEXT_SIZE_LARGE,     
        TEXT_SIZE_X_LARGE, 
        TEXT_SIZE_XX_LARGE,
    };

    //enmu text weight
    enum HtmlFontWeight{
        TEXT_WEIGHT_THIN,
        TEXT_WEIGHT_ULTRALIGHT,
        TEXT_WEIGHT_LIGHT,
        TEXT_WEIGHT_NORMAL,
        TEXT_WEIGHT_MEDIUM,
        TEXT_WEIGHT_SEMIBOLD,
        TEXT_WEIGHT_BOLD,
        TEXT_WEIGHT_ULTRABOLD,
        TEXT_WEIGHT_HEAVY,
    };

    //enum text color
    enum HtmlTextColor {
        COLOR_DEFAULT,
        COLOR_BLACK,
        COLOR_WHITE,
        COLOR_RED,
        COLOR_GREEN,
        COLOR_BLUE,
        COLOR_YELLOW,
        COLOR_ORANGE,
        COLOR_PURPLE,
        COLOR_PINK,
        COLOR_CYAN,
        COLOR_MAGENTA,
        COLOR_BROWN,
        COLOR_GRAY,
        COLOR_LIGHT_GRAY,
        COLOR_DARK_GRAY,
        COLOR_LIGHT_BLUE,
        COLOR_DARK_BLUE,
        COLOR_LIGHT_GREEN,
        COLOR_DARK_GREEN,
        COLOR_LIGHT_RED,
        COLOR_DARK_RED,
        COLOR_LIGHT_PURPLE,
        COLOR_DARK_PURPLE,
        COLOR_LIGHT_CYAN,
        COLOR_DARK_CYAN,
        COLOR_GOLD,
        COLOR_SILVER,
        COLOR_TRANSPARENT
    };
    class HtmlText {
        private:
        std::string _htmlLabel;
        std::string _htmlText;
        std::string _size;
        std::string _famity;
        std::string _wight;
        std::string _color;
        int _letter_spacing;
        HtmlFontWeight _htmlwight;
        HtmlTextSize _htmlsize;
        HtmlTextColor _htmlcolor;
        HtmlTextFontFamily _htmlfontfamily;

        public:
        //this HtmlText default config
            HtmlText(): _htmlLabel("span") , _htmlText("hello word")
            ,  _letter_spacing(3) , _htmlwight(TEXT_WEIGHT_BOLD)
            , _htmlsize(TEXT_SIZE_MEDIUM) , _htmlcolor(COLOR_BLACK)
            , _htmlfontfamily(FONT_FAMILY_DEFAULT){}

            /**
            @param LabelName settings your Html Label
            */
            HtmlText& SetHtmlLabel (const std::string&& Labelname){
                _htmlLabel = std::move(Labelname);
                return *this;
            }
            /**
            @param HtmlData this settings your text
            */
            HtmlText& SetText (const std::string&& HtmlData){
                _htmlText = std::move(HtmlData);
                return *this;
            }
            /**
            @param TextColor this settings your TextColor
            */
            HtmlText& SetTextColor(const HtmlTextColor& TextColor){
                switch (TextColor) {
                    case COLOR_DEFAULT:
                        _color = "";
                        break;
                        return *this;
                    case COLOR_BLACK:
                        _color = "black";
                        break;
                        return *this;
                    case COLOR_WHITE:
                        _color = "white";
                        break;
                        return *this;
                    case COLOR_RED:
                        _color = "red";
                        break;
                        return *this;
                    case COLOR_GREEN:
                        _color = "green";
                        break;
                        return *this;
                    case COLOR_BLUE:
                        _color = "blue";
                        break;
                        return *this;
                    case COLOR_YELLOW:
                        _color = "yellow";
                        break;
                        return *this;
                    case COLOR_ORANGE:
                        _color = "orange";
                        break;
                        return *this;
                    case COLOR_PURPLE:
                        _color = "purple";
                        break;
                        return *this;
                    case COLOR_PINK:
                        _color = "pink";
                        break;
                        return *this;
                    case COLOR_CYAN:
                        _color = "cyan";
                        break;
                        return *this;
                    case COLOR_MAGENTA:
                        _color = "magenta";
                        break;
                        return *this;
                    case COLOR_BROWN:
                        _color = "brown";
                        break;
                        return *this;
                    case COLOR_GRAY:
                        _color = "gray";
                        break;
                        return *this;
                    case COLOR_LIGHT_GRAY:
                        _color = "lightgray";
                        break;
                        return *this;
                    case COLOR_DARK_GRAY:
                        _color = "darkgray";
                        break;
                        return *this;
                    case COLOR_LIGHT_BLUE:
                        _color = "lightblue";
                        break;
                        return *this;
                    case COLOR_DARK_BLUE:
                        _color = "darkblue";
                        break;
                        return *this;
                    case COLOR_LIGHT_GREEN:
                        _color = "lightgreen";
                        break;
                        return *this;
                    case COLOR_DARK_GREEN:
                        _color = "darkgreen";
                        break;
                        return *this;
                    case COLOR_LIGHT_RED:
                        _color = "lightcoral";
                        break;
                        return *this;
                    case COLOR_DARK_RED:
                        _color = "darkred";
                        break;
                        return *this;
                    case COLOR_LIGHT_PURPLE:
                        _color = "plum";
                        break;
                        return *this;
                    case COLOR_DARK_PURPLE:
                        _color = "darkviolet";
                        break;
                        return *this;
                    case COLOR_LIGHT_CYAN:
                        _color = "lightcyan";
                        break;
                        return *this;
                    case COLOR_DARK_CYAN:
                        _color = "darkcyan";
                        break;
                        return *this;
                    case COLOR_GOLD:
                        _color = "gold";
                        break;
                        return *this;
                    case COLOR_SILVER:
                        _color = "silver";
                        break;
                        return *this;
                    case COLOR_TRANSPARENT:
                        _color = "transparent";
                        break;
                        return *this;
                };
                return *this;
            }
            /**
            @param TextSize this settings your text size
            */
            HtmlText& SetTextSize(const HtmlTextSize& TextSize){
                switch (TextSize) {
                    case TEXT_SIZE_XX_SMALL:
                        _size = "xx-small";
                        break;
                    case TEXT_SIZE_X_SMALL:
                        _size = "x-small";
                        break;
                    case TEXT_SIZE_SMALL:
                        _size = "small";
                        break;
                    case TEXT_SIZE_MEDIUM:
                        _size = "medium";
                        break;
                    case TEXT_SIZE_LARGE:
                        _size = "large";
                        break;
                    case TEXT_SIZE_X_LARGE:
                        _size = "x-large";
                        break;
                    case TEXT_SIZE_XX_LARGE:
                        _size = "xx-large";
                        break;
                    default:
                        _size = "x-large";
                        break;
                };
                return *this;
            }
            /**
            @param SetFontFamily this settings your font styles
            */
            HtmlText& SetFontFamily(const HtmlTextFontFamily& FontFamily){
                switch (FontFamily) {
                    case FONT_FAMILY_SERIF:
                        _famity = "serif";
                        break;
                    case FONT_FAMILY_SANS_SERIF:
                        _famity = "sans_serif";
                        break;
                    case FONT_FAMILY_MONOSPACE:
                        _famity = "monospace";
                        break;
                    case FONT_FAMILY_CURSIVE:
                        _famity = "cursive";
                        break;
                    case FONT_FAMILY_FANTASY:
                        _famity = "fantasy";
                        break;
                    case FONT_FAMILY_DEFAULT:
                        _famity = "";
                        break;
                    case FONT_JETBRAINS_MONO:
                        _famity = "Jetbrains Mono";
                        break;
                };

                return *this;
            }
            /**
            @param SettingFontWeight settings your font weight
            */
            HtmlText& SetFontWeight(const HtmlFontWeight&& FontWeight){
                switch (FontWeight) {
                    case TEXT_WEIGHT_THIN:
                        _wight = "thin";
                        break;
                    case TEXT_WEIGHT_ULTRALIGHT:
                        _wight = "ultralight";
                        break;
                    case TEXT_WEIGHT_LIGHT:
                        _wight = "light";
                        break;
                    case TEXT_WEIGHT_NORMAL:
                        _wight = "normal";
                        break;
                    case TEXT_WEIGHT_MEDIUM:
                        _wight = "medium";
                        break;
                    case TEXT_WEIGHT_SEMIBOLD:
                        _wight = "semibold";
                        break;
                    case TEXT_WEIGHT_ULTRABOLD:
                        _wight = "ultrabold";
                        break;
                    case TEXT_WEIGHT_HEAVY:
                        _wight = "heavy";
                        break;
                    case TEXT_WEIGHT_BOLD:
                        _wight = "bold";
                        break;
                    default:
                        _wight = "";
                        break;
                };
                return *this;
            }
            /**
            add component for widegt
            */
            inline Gtk::Label* addComponent() {
                const std::string html = "<" + _htmlLabel 
                + " "   + "size = " + "\"" + _size + "\""  
                + " " + "font_family = " + "\"" + _famity + "\""
                + " " + "foreground = " + "\"" + _color + "\""
                + " " + "weight = " + "\"" + _wight + "\""
                + ">" + _htmlText 
                + "<" + "/" + _htmlLabel + ">";
                auto HtmlLabel = Gtk::make_managed<Gtk::Label>();
                std::cout << html << std::endl;
                HtmlLabel -> set_markup(html);
                return HtmlLabel;
            }
    };
}