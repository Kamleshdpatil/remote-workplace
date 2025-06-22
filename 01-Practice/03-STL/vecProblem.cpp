#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

template<class T>
void Display(vector<T> v)
{
    if(v.size() == 0)
    {
        cout<<"Empty vector list"<<endl; 
        return;
    }
    for(int i = 0; i<v.size(); i++)
    {
        cout<<"| "<<v[i].first<<", "<<v[i].second<<" |";
    }
    cout<<"\n\n";
}

template<class T>
int findMean(vector<T> vec)
{
    int iMean = 0;
    int iSize = 0;
    int iSum = 0;
    if(vec.empty())
    {
        return(-1);
    }

    for(int i = 0; i < vec.size(); i++)
    {
        iSum = iSum + vec[i].second;
        iSize ++;
    }

    iMean = iSum / iSize;
    return iMean;
}

template<class T>
int findMedian(vector<T> vec)
{
    int iMedian = 0;
    int iSize = 0;
    
    if(vec.empty())
    {
        return(-1);
    }

    iSize = vec.size();             //Count the number of students in the set
    sort(vec.begin(), vec.end());   //Arrange the grades in order from smallest to largest

    iMedian = vec[iSize/2].second; //The middle grade
    
    if(vec.size() % 2 == 0) //If There are an even number of students, need to calculate middle's two's avg.
    {
        short mid = iSize/2;
        iMedian = iMedian + vec.at(mid-1).second;
        return iMedian/2;
    }

    //There are an odd number of students, so we do not need to take the average of two middle students.
    return iMedian;
}

template<class T>
string findTopper(vector<T> vec)
{
    int max = vec.front().second;
    string name;
    for(auto& it : vec)
    {
        if(it.second > max)
        {
            max = it.second;
            name = it.first;
        }
    }

    return name;
}

int main()
{
    vector<pair<string, long>> vStudent;
    int iLen = 0;
    int iGrade = 0;
    string strName;
    // cout<<"Enter the how many number of students: "<<endl;
    // cin>>iLen;

    // for(int i = 0;  i<iLen; i++)
    // {
    //     cout<<"Enter name of student: "<<endl;
    //     cin>>strName;

    //     cout<<"Enter grade of student: "<<endl;
    //     cin>>iGrade;

    //     vStudent.push_back(make_pair(strName, iGrade));
    // }

    vStudent = {
        {"Amlesh", 1000}, {"Bouri", 12}, {"Crakash", 14}, {"Deswin", 1056}, {"Eimanhika", 18}, {"Fffff", 200}
    };

    int mean = findMean(vStudent);
    if(mean != -1)
    {
        cout<<"Mean of student vector is: "<<mean<<endl;
    }
    int median = findMedian(vStudent);
    if(median != -1)
    {
        cout<<"Median of student vector is: "<<median<<endl;
    }

    string strStudent = findTopper(vStudent);
    if(strStudent.length() > 0)
        cout<<"Topper is: "<<strStudent<<endl;
}
