#include "gtkmm/enums.h"
#include "gtkmm/object.h"
#include <charconv>
#include <gtkmm/entry.h>
#include <string>
#include <utility>

namespace VisualUI {

    enum InputType{
        INPUT_TEXT,
        INPUT_PASSWORD,
        INPUT_EMAIL,
        INPUT_URL,
        INPUT_PHONE,
        INPUT_NAME,
        INPUT_PIN,
    };

    enum InputAlign{
        INPUT_ALIGN_CENTER,
        INPUT_ALIGN_START,
        INPUT_ALIGN_END,

        INPUT_VALINGN_CENTER,
        INPUT_VALINGN_START,
        INPUT_VALINGN_END,
    };

    class InputComponent{
        private:
            std::string _placeholder;
            std::string _style;
            gunichar _invisible = '*'; 
            std::string _CacheStyle;
            std::string _CachePlaceholder;

            int _align = 1;
            bool _type_value;

            InputType input_type;
            InputAlign input_align;

            Gtk::Entry* _Entry = Gtk::make_managed<Gtk::Entry>();

            public:
                InputComponent(): _placeholder("input") , _style("default-input"),
                    _CacheStyle("") , _CachePlaceholder("")  , _align(1) , 
                    _type_value(false) , input_type(INPUT_TEXT),
                    input_align(INPUT_ALIGN_CENTER){}

                    InputComponent& SetInputPlaceholder(const std::string& Placeholder){
                        _placeholder = Placeholder;
                        _CachePlaceholder = Placeholder;
                        return *this;
                    }

                    InputComponent& SetInputStyle (const std::string&& InputStyleName){
                        _style = std::move(InputStyleName);
                        _CacheStyle = std::move(_style);
                        return *this;
                    }

                    InputComponent& SetReactiveStyle (const std::string&& NewInputSyleName){
                        if (_CacheStyle.empty()){
                            _Entry -> add_css_class(NewInputSyleName);
                            _CacheStyle = std::move(NewInputSyleName);
                            return *this;
                        }
                        _Entry -> remove_css_class(_CacheStyle);
                        _Entry -> add_css_class(NewInputSyleName);
                        _CacheStyle = std::move(NewInputSyleName);
                        return *this;
                    }

                    InputComponent& SetInputType(const InputType&& type){
                        switch (type) {
                            case INPUT_TEXT:
                                _type_value = true;
                                _Entry -> set_input_purpose(Gtk::InputPurpose::FREE_FORM);
                                break;
                            case INPUT_PASSWORD:
                                _type_value = false;
                                _Entry -> set_input_purpose(Gtk::InputPurpose::PASSWORD);
                                break;
                            case INPUT_EMAIL:
                                _type_value = true;
                                _Entry -> set_input_purpose(Gtk::InputPurpose::EMAIL);
                                break;
                            case INPUT_URL:
                                _type_value = true;
                                _Entry -> set_input_purpose(Gtk::InputPurpose::URL);
                                break;
                            case INPUT_PHONE:
                                _type_value = true;
                                _Entry -> set_input_purpose(Gtk::InputPurpose::PHONE);
                                break;
                            case INPUT_NAME:
                                _type_value = true;
                                _Entry -> set_input_purpose(Gtk::InputPurpose::NAME);
                                break;
                            case INPUT_PIN:
                                _type_value = true;
                                _Entry -> set_input_purpose(Gtk::InputPurpose::PIN);
                                break;
                            default:
                                _type_value = true;
                                break;
                        };

                        return *this;
                    }

                    InputComponent& Setinvisible(const char&& Invisible){
                        _invisible = std::move(Invisible);
                        return *this;
                    }

                    InputComponent& SetInputAlign(const InputAlign&& SetInputAlign){
                        switch (SetInputAlign) {
                            case INPUT_ALIGN_CENTER:
                                _align = 1;
                                break;
                            case INPUT_ALIGN_START:
                                _align = 2;
                                break;
                            case INPUT_ALIGN_END:
                                _align = 3;
                                break;
                            case INPUT_VALINGN_CENTER:
                                _align = 4;
                                break;
                            case INPUT_VALINGN_START:
                                _align = 5;
                                break;
                            case INPUT_VALINGN_END:
                                _align = 6;
                                break;
                            default:
                                _align = 1;
                                break;
                        };

                        return *this;
                    }

                    inline std::string GetInputStr (){
                        const std::string str_value = _Entry -> get_text();
                        return str_value;
                    }

                    InputComponent& SetErrorMessage (const std::string&& ErrorMessage){
                        if (_CachePlaceholder == ""){
                            _placeholder = std::move(ErrorMessage);
                            _CachePlaceholder = _placeholder;
                            return *this;
                        }

                        _placeholder = std::move(ErrorMessage);
                        return *this;
                    }


                    inline int GetInputInt (){
                        int int_value = 0;
                        const std::string int_value_str = _Entry -> get_text();
                        auto result_int = std::from_chars(int_value_str.data()
                         , int_value_str.data()  + int_value_str.size() , int_value);
                        if  (result_int.ec == std::errc() && result_int.ptr == int_value_str.data() + int_value_str.size()){
                            return int_value;
                        }else {
                            return 1;
                        }
                    }

                    inline Gtk::Entry* addComponent(){
                        switch (_align) {
                            case 1:
                            _Entry -> set_halign(Gtk::Align::CENTER);
                            break;
                            case 2:
                            _Entry -> set_halign(Gtk::Align::START);
                            break;
                            case 3:
                            _Entry -> set_halign(Gtk::Align::END);
                            break;
                            case 4:
                            _Entry -> set_valign(Gtk::Align::CENTER);
                            break;
                            case 5:
                            _Entry -> set_valign(Gtk::Align::START);
                            break;
                            case 6:
                            _Entry -> set_valign(Gtk::Align::END);
                            break;
                            default:
                            _Entry -> set_halign(Gtk::Align::CENTER);
                            break;
                        }
                        _Entry -> set_placeholder_text(_placeholder);
                        _Entry -> add_css_class(_style);
                        _Entry -> set_visibility(_type_value);
                        if (_type_value){
                            _Entry -> set_invisible_char(_invisible);
                        }
                        return _Entry;
                    }

    };
}