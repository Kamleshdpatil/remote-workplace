#ifndef HP_DESKTOP_BUILDER_HPP
#define HP_DESKTOP_BUILDER_HPP

#include<string>
#include"desktop_builder.hpp"

using namespace std;

class HpDesktopBuilder: public DesktopBuilder{
    
    void buildMonitor();
    void buildKeyboard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherBoard();
    
};

#endif // !HP_DESKTOP_BUILDER_HPP