#include<string>
#include "dell_desktop_builder.hpp"

using namespace std;

void DellDesktopBuilder::buildMonitor(){
    desktop->setMonitor("Dell Monitor");
}

void DellDesktopBuilder::buildKeyboard(){
    desktop->setKeyboard("Dell Keyboaed");
}

void DellDesktopBuilder::buildMouse(){
    desktop->setMouse("Dell Mouse");
}

void DellDesktopBuilder::buildSpeaker(){
    desktop->setSpeaker("Dell Speaker");
}

void DellDesktopBuilder::buildRam(){
    desktop->setRam("Dell RAM");
}

void DellDesktopBuilder::buildProcessor(){
    desktop->setProcessor("Dell Processor");
}

void DellDesktopBuilder::buildMotherBoard(){
    desktop->setMotherBoard("Dell Motherboard");
}

