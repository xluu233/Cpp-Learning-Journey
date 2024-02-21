//
// Created by xlu on 2023/10/26.
//
#include <iostream>
#include <functional>
#include <map>

/**
 * 实现简易版的Qt信号槽机制
 */
class Signal {
public:
    template<typename Func>
    void connect(Func&& func) {
        slots_.push_back(std::forward<Func>(func));
    }

    void emit() {
        for (auto& slot : slots_) {
            slot();
        }
    }

private:
    std::vector<std::function<void()>> slots_;
};

class Button {
public:
    Signal clicked;

    void click() {
        clicked.emit();
    }
};

class Application {
public:
    void run() {
        Button button;
        button.clicked.connect([](){
           std::cout << "btn clicked" << std::endl;
        });
        button.click();
    }

    void onButtonClicked() {
        std::cout << "Button clicked!" << std::endl;
    }
};