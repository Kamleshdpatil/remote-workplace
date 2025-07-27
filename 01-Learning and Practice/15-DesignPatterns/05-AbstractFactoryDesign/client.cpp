#include<iostream>

using namespace std;

class IButton{
    public:
        virtual void press()=0;
};
class ITextBox{
    public:
        virtual void showText()=0;
};

class MacButton: public IButton{
    public:
        void press(){
            cout<<"MacButton Pressed !!"<<endl;
        }
};

class WinButton: public IButton{
    public:
        void press(){
            cout<<"WinButton Pressed !!"<<endl;
        }
};
class MacTextBox: public ITextBox{
    public:
        void showText(){
            cout<<"Showing MacTextBox !!"<<endl;
        }
};

class WinTextBox: public ITextBox{
    public:
        void showText(){
            cout<<"Showing WinTextBox !!"<<endl;
        }
};

class IFactory{
    public:
        virtual IButton* CreateButton() = 0;
        virtual ITextBox* CreateTextBox() = 0;
};

class MacFactory: public IFactory{
    public:
        IButton* CreateButton(){
            return new MacButton();
        }

        ITextBox* CreateTextBox(){
            return new MacTextBox();
        }
};

class WinFactory: public IFactory{
    public:
        IButton* CreateButton(){
            return new WinButton();
        }

        ITextBox* CreateTextBox(){
            return new WinTextBox();
        }
};


class GUIAbstractFactory{
    public:
        static IFactory* CreateFactory(const string& osType){
            if(osType == "windows" || osType == "win")
                return new WinFactory();
            else if(osType == "macos" || osType == "mac")
                return new MacFactory();
            else
                cout<<"Invalid type"<<endl;
        }
};

int main()
{
    string osType;
    cout<<"Enter your machine OS: ";
    cin>>osType;

    IFactory* fact = GUIAbstractFactory::CreateFactory(osType);

    IButton* button = fact->CreateButton();
    button->press();

    ITextBox* textBox = fact->CreateTextBox();
    textBox->showText();

    return(0);
}