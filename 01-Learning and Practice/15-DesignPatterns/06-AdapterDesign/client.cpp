#include<iostream>
using namespace std;

class XMLData{
    string xmlData;

    public:
    XMLData(string pXmlData){
        xmlData = pXmlData;
    }
    string getXmlData(){
        return xmlData;
    }
};

class DataAnalyticsTool{
    string jsonData;

    public:
    DataAnalyticsTool(){}
    DataAnalyticsTool(string pJsonData){
        jsonData = pJsonData;
    }
    virtual void analyseData(){
        cout<<"Analysing Data: "<<jsonData<<endl;
    }
};

class Adapter : public DataAnalyticsTool{
    XMLData* xmlData;
    public:
        Adapter(XMLData* pXmlData){
            xmlData = pXmlData;
        }
        void analyseData() override{
        cout<<"Converting XML Data: "<<xmlData->getXmlData()<<" to Json Data"<<endl;
        cout<<"Analysing converted JSON Data"<<endl;
    }
};

class Client{
    public:
        void ProcessData(DataAnalyticsTool* tool){
            tool->analyseData();
        }
};

int main()
{
    XMLData* xmlDataObj = new XMLData("Sample XML Data");

    // DataAnalyticsTool* tool = mew DataAnalyticsTool(); // It should change

    DataAnalyticsTool* tool = new Adapter(xmlDataObj);

    Client* client = new Client;

    client->ProcessData(tool);

    return(0);
}