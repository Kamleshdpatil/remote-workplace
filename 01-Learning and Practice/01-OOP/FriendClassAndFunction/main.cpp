/*Note: We can declare friend class or function 
anywhere in the base class body whether its private, 
protected or public block. It works all the same.*/

#include<iostream>
#include<Cstdlib>

class CSky;

class CSparrow{
    int value;
    public:
    //CSky skyObject;
    void Display(CSky&);
    void Display(CSky*);
};

class CSky{
    private:
    int idata;
    float fdata;

    public:
    CSky()
    {
        idata = 100;
        fdata = 105.15f;
    }

    void GetData(float);
    void GetData(int);
    void SetData(int, float);
    friend void printCskyMembers(CSky&);
    friend void CSparrow::Display(CSky&);
    friend void CSparrow::Display(CSky*);
    //friend class CSparrow;
};

void CSparrow::Display(CSky* skyObj)
{
    skyObj->SetData(1200, 2500.05f);
    std::cout<<"inside Display Int data: "<<skyObj->idata<<std::endl;
    std::cout<<"inside Display Float data: "<<skyObj->fdata<<std::endl;
}

void CSparrow::Display(CSky& skyObj)
{
    skyObj.SetData(12, 25.05f);
    std::cout<<"inside Display Int data: "<<skyObj.idata<<std::endl;
    std::cout<<"inside Display Float data: "<<skyObj.fdata<<std::endl;
}

void CSky::SetData(int i, float f)
{
    idata = i;
    fdata = f;
}

void CSky::GetData(float f)
{
    std::cout<<fdata<<std::endl;
}

void CSky::GetData(int i)
{
    std::cout<<idata<<std::endl;
}


void printCskyMembers(CSky& obj)
{
    std::cout<<"Inside printCskyMembers"<<std::endl;
    std::cout<<"Int data: "<<obj.idata<<std::endl;
    std::cout<<"Float data: "<<obj.fdata<<std::endl;
}

int main(void)
{
    CSky objSky;
    CSky *p = new CSky();
    CSparrow objSparrow;
    //printCskyMembers(objSky);
    objSparrow.Display(objSky);
    objSparrow.Display(p);
    delete p;
    // objSparrow.skyObject.SetData(14, 10.33);
    // std::cout<<objSparrow.skyObject.GetData()<<std::endl;

    // objSparrow.Display(objSky);
    // objSky.SetData(10, 14.33);
    //objSky.GetData(1.4f);
    //objSky.GetData(1);

    return(0);
}
