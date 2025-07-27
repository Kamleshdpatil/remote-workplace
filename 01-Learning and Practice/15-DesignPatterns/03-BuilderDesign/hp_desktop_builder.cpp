#include<string>
#include "hp_desktop_builder.hpp"

using namespace std;

void HpDesktopBuilder::buildMonitor(){
    desktop->setMonitor("HP Monitor");
}

void HpDesktopBuilder::buildKeyboard(){
    desktop->setKeyboard("HP Keyboaed");
}

void HpDesktopBuilder::buildMouse(){
    desktop->setMouse("HP Mouse");
}

void HpDesktopBuilder::buildSpeaker(){
    desktop->setSpeaker("HP Speaker");
}

void HpDesktopBuilder::buildRam(){
    desktop->setRam("HP RAM");
}

void HpDesktopBuilder::buildProcessor(){
    desktop->setProcessor("HP Processor");
}

void HpDesktopBuilder::buildMotherBoard(){
    desktop->setMotherBoard("HP Motherboard");
}

