#include "glibmm/refptr.h"
#include "gtkmm/object.h"
#include "gtkmm/widget.h"
#include "gtkmm/window.h"
#include <iostream>
#include <functional>
#include <gtkmm/application.h>
#include <string>

namespace VisualUI {
    //this user assets file path
    class assets_path {
        public:
        static inline std::string rootPath = "../assets/";
        static inline std::string picturePath = rootPath + "/picture/";
        static inline std::string videoPath = rootPath + "/video/";
        static inline std::string audioPath = rootPath + "/audio/";
        static inline std::string stylePath = rootPath + "/css/";
    };
    class Application{
        private:
        std::string appName;
        std::string appID;
        std::string Window_class;
        std::string Window_title;
        int window_width;
        int window_height;
        //this is gtkmm windows and app creat
        Glib::RefPtr<Gtk::Application> UserAPP;
        std::function<Gtk::Widget*()> callBack_widget;

        public:
        //the default app settings 
            Application():appName("NewVBapp"),appID("myapp"),Window_class("default-dark"), 
            Window_title("myapp"),window_width(100),window_height(100){}
            /**
            @param _AppName your app name
            */
            Application& SettingAppName (const std::string& _AppName){
                appName = _AppName;
                return *this;
            }
            /**
            @param _AppID your app id
            */
            Application& SettingAppID (const std::string& _AppId){
                appID = _AppId;
                UserAPP = Gtk::Application::create(appID);
                return *this;
            }
            /**
            @param tl your app title
            */
            template<typename title>
            Application& SettingAppTitle (const title& tl) {
                const std::string title_ = std::string(tl);
                Window_title = title_;
                return *this;
            }
            /**
            @param _className your css class name
            */
            Application& SettingWindowStyleName (const std::string& _StyleName){
                Window_class = _StyleName;
                return *this;
            }
            /**
            @param _width settings your window width
            @param _height settings your window height
            */
            Application& SettingWindowSize (const int& _width , 
                const int& _height){
                window_width = _width;
                window_height = _height;
                return *this;
            }
            /**
            @param _callBack_widget write your layout and component
            */
            Application& CreateContent (const std::function<Gtk::Widget*()> _callBack_widget){
                callBack_widget = _callBack_widget;
                return *this;
            }
            inline void start () {
                static auto UserWindow = Gtk::make_managed<Gtk::Window>();
                UserWindow -> set_size_request(window_width , window_height);
                UserWindow -> add_css_class(Window_class);
                UserWindow -> set_title(Window_title);
                UserAPP -> signal_activate().connect([&]{
                    if (callBack_widget){
                        auto Content = callBack_widget();
                        if (Content){
                            UserWindow -> set_child(*Content);
                        }
                    }
                    std::cout << "[INFO] APP INFORMTAION\n" 
                    << "APP[NAME] : " << appName 
                    << "\nAPP[ID] : " << appID 
                    << std::endl; 
                    UserWindow -> show();
                });
                UserAPP -> hold();
                UserAPP -> run();
            }
    };
}