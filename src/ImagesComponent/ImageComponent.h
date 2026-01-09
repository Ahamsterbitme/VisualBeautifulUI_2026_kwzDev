#pragma once
#include "glibmm/main.h"
#include "glibmm/refptr.h"
#include "gtkmm/enums.h"
#include "gtkmm/image.h"
#include "gtkmm/object.h"
#include <atomic>
#include <chrono>
#include <filesystem>
#include <functional>
#include <memory>
#include <ostream>
#include <string>
#include <thread>
#include <iostream>
#include <utility>
#include "../ApplicationController/Application.h"

namespace VisualUI {

    enum ImageScaleMode{
        IMAGE_SCALE_ORIGNAL,
        IMAGE_SCALE_COVER,
        IMAGE_SCALE_NONE,
        IMAGE_SCALE_FILL,
        IMAGE_SCALE_DOWN,
    };

    enum ImageAlign{
        IMAGE_ALIGN_CENTER,
        IMAGE_ALIGN_LEFT,
        IMAGE_ALIGN_RIGHT,
    };

    enum ImageVlign{
        IMAGE_VLIGN_CENTER,
        IMAGE_VLIGN_LEFT,
        IMAGE_VLIGN_RIGHT,
    };

    enum ImageAdaption_Width{
        IMAGE_ADAPTION_WIDTH_TRUE,
        IMAGE_ADAPTION_WIDTH_FALSE,
    };

    enum ImageAdaption_Height{
        IMAGE_ADAPTION_HEIGHT_TRUE,
        IMAGE_ADAPTION_HEIGHT_FALSE,
    };

    class ImageComponent{
        private:
            std::shared_ptr<std::string> _fileName;
            std::string _StyleName;
            std::string _CacheStyle;
            std::string _file_path;

            int _width;
            int _height;
            int _margin;

            int _align;
            bool _adaption_width;
            bool _adaption_height;
            
            std::atomic<bool> _click{false};
            std::unique_ptr<std::thread> stop_click_thread;
            std::shared_ptr<std::function<void()>> _stop_function;

            VisualUI::assets_path app_path;

            Gtk::Image* newImages = Gtk::make_managed<Gtk::Image>();

            private:

            static Glib::RefPtr<Glib::MainContext> getMainContext(){
                return Glib::MainContext::get_default();
            }

            const std::string css_scale_fill = 
            ".images_scale_fit{\r\n"
            "object-fit: fill; \r\n"
            "border-radius: 10px; \r\n"
            "}";

            const std::string css_scale_contain = 
            ".images_scale_contain{ \r\n"
            "object-fit: contain; \r\n"
            "border-radius: 10px; \r\n"
            "}";

            const std::string css_scale_cover = 
            ".images_scale_cover{ \r\n"
            "object-fit: cover; \r\n"
            "border-radius: 10px; \r\n"
            "}";

            const std::string css_scale_down =
            ".images_scale_down{ \r\n"
            "object-fit: scale-down; \r\n"
            "border-radius: 10px; \r\n"
            "}";

            public:
                ImageComponent():_fileName(std::make_shared<std::string>("")),_StyleName("default-images-styles"),
                    _CacheStyle(""), _width(20),_height(20),_margin(),_align(1),
                    _adaption_width(false),_adaption_height(false){}

                    ImageComponent& SetImageFile(const std::string&& fileName){
                        _fileName = std::move(std::make_shared<std::string>(fileName));
                        const std::string picture_path = app_path.get_picture_path();
                        _file_path = picture_path + *_fileName;
                        if (std::filesystem::exists(_file_path)){

                        }
                        return *this;
                    }

                    ImageComponent& SetImageStyle(const std::string&& styleName){                       
                        _StyleName = std::move(styleName);
                        _CacheStyle = _StyleName;
                        return *this;
                    }

                    ImageComponent& SetImageReactiveStyle(const std::string&& newStyleName){
                        if (_CacheStyle == ""){
                            newImages -> add_css_class(newStyleName);
                            return *this;
                        }
                        newImages -> remove_css_class(_CacheStyle);
                        newImages -> add_css_class(newStyleName);
                        _CacheStyle = std::move(newStyleName);
                        return *this;
                    }

                    ImageComponent& SetImageWidth(const int&& ImageWidth){
                        _width = std::move(ImageWidth);
                        return *this;
                    }

                    ImageComponent& SetImageHeight(const int&& ImageHeight){
                        _height = std::move(ImageHeight);
                        return *this;
                    }

                    ImageComponent& SetImageMargin(const int&& ImageMargin){
                        _margin = std::move(ImageMargin);
                        return *this;
                    }

                    ImageComponent& SetImageVlign(const ImageVlign& vlign){
                        switch (vlign) {
                            case IMAGE_VLIGN_CENTER:
                                _align = 4;
                                break;
                            case IMAGE_VLIGN_LEFT:
                                _align = 5;
                                break;
                            case IMAGE_VLIGN_RIGHT:
                                _align = 6;
                                break;
                            default:
                                _align = 1;
                                break;
                        };
                        return *this;
                    }

                    ImageComponent& SetImageAlign(const ImageAlign& align){
                        switch (align) {
                            case IMAGE_ALIGN_CENTER:
                                _align = 1;
                                break;
                            case IMAGE_ALIGN_LEFT:
                                _align = 2;
                                break;
                            case IMAGE_ALIGN_RIGHT:
                                _align = 3;
                                break;
                            default:
                                _align = 1;
                                break;
                        };

                        return *this;
                    }

                    ImageComponent& SetImageAdaptionWidth(const ImageAdaption_Width& adaption_width){
                        switch (adaption_width) {
                            case IMAGE_ADAPTION_WIDTH_TRUE:
                                _adaption_width = true;
                                break;
                            case IMAGE_ADAPTION_WIDTH_FALSE:
                                _adaption_width = false;
                                break;
                        };
                        return *this;
                    }

                    ImageComponent& SetImageAdaptionHeight(const ImageAdaption_Height& adaption_height){
                        switch (adaption_height) {
                            case IMAGE_ADAPTION_HEIGHT_TRUE:
                                _adaption_height = true;
                                break;
                            case IMAGE_ADAPTION_HEIGHT_FALSE:
                                _adaption_height = false;
                                break;
                        }
                        return *this;
                    }

                    ImageComponent& SetNewImageFile(const std::string&& fileName){
                        _fileName = std::move(std::make_shared<std::string>(fileName));
                        const std::string picture_path = app_path.get_picture_path();
                        _file_path = picture_path + *_fileName;
                        if (std::filesystem::is_empty(_file_path)){
                            std::cout << "[WRAING] this ->"
                            << _file_path << "<- not found !"
                            << std::endl;
                        }
                        newImages -> set(_file_path);
                        return *this;
                    }

                    ImageComponent& SetImageClick(const std::function<void()> _clickFunction){
                        if (_clickFunction){
                            _clickFunction();
                            return *this;
                        }
                        return *this;
                    }

                    template<typename fun_type>
                    inline void stopClick(const int& delay_time , const fun_type& stop_function){
                        _click = false;
                        _stop_function = std::make_shared<std::function<void()>>(stop_function);
                        stop_click_thread = std::make_unique<std::thread>([delay_time , this]{
                            std::cout << "[INFO]- --- click user images click ----" 
                            << "STOP_DELAY_TIME:" << delay_time 
                            << std::endl;
                            Glib::signal_idle().connect_once([this]{
                                (*_stop_function)();
                            });
                            std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));
                            if (!_click){
                                _click = true;
                            }
                        });
                    }

                    inline Gtk::Image* addComponent(){
                        newImages -> set(_file_path);
                        newImages -> set_margin(_margin);
                        switch (_align) {
                            case 1:
                            newImages -> set_halign(Gtk::Align::CENTER);
                            break;
                            case 2:
                            newImages -> set_halign(Gtk::Align::START);
                            break;
                            case 3:
                            newImages -> set_halign(Gtk::Align::END);
                            break;
                            case 4:
                            newImages -> set_valign(Gtk::Align::CENTER);
                            break;
                            case 5:
                            newImages -> set_valign(Gtk::Align::START);
                            break;
                            case 6:
                            newImages -> set_valign(Gtk::Align::END);
                            break;
                            default:
                            break;
                        };
                        newImages -> set_vexpand(_adaption_height);
                        newImages -> set_expand(_adaption_width);
                        newImages -> add_css_class(_StyleName);
                        newImages -> set_size_request(_width , _height);
                        return newImages;
                    }

                    
    };
}