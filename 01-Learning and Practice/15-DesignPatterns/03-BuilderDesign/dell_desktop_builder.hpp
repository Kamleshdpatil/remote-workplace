#ifndef DELL_DESKTOP_BUILDER_HPP
#define DELL_DESKTOP_BUILDER_HPP

#include<string>
#include"desktop_builder.hpp"

using namespace std;

class DellDesktopBuilder: public DesktopBuilder{
    
    void buildMonitor();
    void buildKeyboard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherBoard();
    
};

#endif