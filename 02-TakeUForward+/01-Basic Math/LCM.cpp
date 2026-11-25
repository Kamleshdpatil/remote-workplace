#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<int> getDivisorsArrayOfGivenNumber(int n){
        int temp = n, count = 0;
        vector<int> vec;
        while(temp > 1){
            if(n % temp == 0){
                vec.push_back(temp);
                cout<<temp<<" ";
            }
            temp--;
        }
       cout<<"--------------------------------------------------"<<endl;
        return(vec);
    }

    int LCM(int n1,int n2) {
        int iRet = 1, mult = 1;
        vector<int> n1Vec = getDivisorsArrayOfGivenNumber(n1);
        vector<int> n2Vec = getDivisorsArrayOfGivenNumber(n2);

        for(int i = 0; i < n1Vec.size(); i++){
            int num1 = n1Vec[i];

            for(int j = 0; j< n2Vec.size(); j++){
                int num2 = n2Vec[j];

                mult = num1 * num2;
                if((mult % n1 == 0) && (mult % n2 == 0)){
                    iRet = mult;
                    cout<<"iRet: "<<iRet<<endl;
                }
            }
        }
        
        return(iRet);
    }
};

int main(){

    Solution *obj = new Solution();

    cout<<"LCM: "<<obj->LCM(4, 6)<<endl;

    return(0);
}