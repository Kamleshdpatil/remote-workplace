#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include"desktop_builder.hpp"

class DesktopDirector{
    private:
    DesktopBuilder* desktopBuilder;
    public:
    DesktopDirector(DesktopBuilder* pDesktopBuilder)
    {
        desktopBuilder = pDesktopBuilder;
    }
    Desktop* BuildDesktop(){
        desktopBuilder->buildMonitor();
        desktopBuilder->buildMouse();
        desktopBuilder->buildRam();
        desktopBuilder->buildProcessor();
        desktopBuilder->buildKeyboard();
        desktopBuilder->buildSpeaker();
        desktopBuilder->buildMotherBoard();
        
        return desktopBuilder->getDesktop();
    }
};

#endif