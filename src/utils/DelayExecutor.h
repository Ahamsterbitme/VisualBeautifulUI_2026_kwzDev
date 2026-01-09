#pragma once
#include "glibmm/main.h"
#include "glibmm/refptr.h"
#include <memory>
#include <atomic>
#include <gtkmm.h>
#include <chrono>
#include <functional>
#include <thread>
#include <iostream>

namespace VisualUI {
    class Delaytool{
        private:
        std::atomic<bool> _stop{false};
        std::unique_ptr<std::thread> _thread;
        std::shared_ptr<std::function<void()>> _callBack;
        public:

            void stop_thread () {
                _stop = true;
                if (_thread && _thread -> joinable()){
                    _thread -> join();
                }
            }

            static Glib::RefPtr<Glib::MainContext> getMainContext(){
                return Glib::MainContext::get_default();
            }

            ~Delaytool(){
                stop_thread();
                std::cout << "[INFP] ---- stop thread ----" << std::endl;
            }

            Delaytool(){std::cout << "[INFO] ---- create new thread ---- " << std::endl;}

            inline void setTimeoutCallBack (const std::function<void()>& callBack_function,int delay_time){
                _stop = false;
                _thread = std::make_unique<std::thread> ([this , callBack_function , delay_time]{
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));
                    if (!_stop && callBack_function){
                        callBack_function();
                    }
                });
            }

            inline void setTimeoutCallBack_ui (const std::function<void()>&& callBack_function , int delay_time){
                stop_thread();
                _stop = false;
                _callBack = std::make_shared<std::function<void()>>(callBack_function);
                _thread = std::make_unique<std::thread>([this,delay_time](){
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));
                    if (!_stop && _callBack){
                        Glib::signal_idle().connect_once([this]{
                            if (_callBack){
                                (*_callBack)();
                            }
                        });
                    }
                });
            }
    };
}