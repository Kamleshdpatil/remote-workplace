#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution{	
public:		
    string largeOddNum(string& s){
        int j = -1, firstIndex = 0;
        for(int i = s.length(); i > 0; i--){
            if((s[i] - '0') % 2 == 1){
                j = i;
                break;
            }
        }
        if(j == -1){return "";}
        for(firstIndex = 0; firstIndex < s.length(); firstIndex++){
            if(s[firstIndex] != '0'){
                break;
            }
        }
        cout<<"firstIndex: "<<firstIndex<<endl;
        cout<<"j: "<<j<<endl;
        cout<<"j - firstIndex + 1: "<<j - firstIndex + 1<<endl;
        return s.substr(firstIndex, j - firstIndex + 1);
    }

    bool checkIfCharPresentInVector(vector<string>& str, char ch, int ele){
        bool found = false;
        for(int i = 0; i < str.size(); i++){
            char check = str[i][ele];
            if(ch == check){
                found = true;
                continue;
            }else{
                found = false;
            }
        }
        return found;
    }

    string longestCommonPrefix(vector<string>& str){
        string sub = "";

        for(int i = 0; i < str.size(); i++){
            string temp = str[i]; // flowers
            char sun = temp[i];
            bool isFound = checkIfCharPresentInVector(str, sun, i);

            if(isFound){
                sub = sub + sun;
            }else{
                break;
            }

            //bool isFound = checkIfCharPresentInVector(str, sun);
            cout<<"sub: "<<sub<<" "<<endl;
        }

        return sub;
	}

    string shiftStringLeftToRightMost(string& s){
        cout<<"Before Shift S: "<<s<<endl;
        
		s = (s.substr(1, s.length()-1) + s[0]);

        cout<<"After shift S: "<<s<<endl;
		return s;
	}
	public:
		bool rotateString(string& s,string& goal){
			bool flag = false;
			//if(s != goal){return false;}
			if(s.length() != goal.length()){return false;}

            cout<<"Initially S: "<<s<<endl;
            cout<<"Initially goal: "<<goal<<endl;
            cout<<endl;

			for(int i = 0; i < s.length() * goal.length(); i++){
				s = shiftStringLeftToRightMost(s);
                cout<<endl;
				if(s == goal){
					flag = true;
					break;
				}
			}
			return flag;
		}

    void sortString(string& str, int n){
        cout<<"Before sort: "<< str<<endl;
		for(int i = 0; i < n; i++){
            if(str[i] > str[n-i-1]){
			    swap(str[i], str[n-i-1]);
            }
		}   
        cout<<"After sort: "<< str<<endl;
	}	
	public:
		bool anagramStrings(string& s,string& t){
			if(s.length() != t.length()){return false;}
			
			// sortString(s, s.length());
            // cout<<endl;
			// sortString(t, t.length());
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());

			if(s!=t){return false;}

			return true;
		}
};


int main(void){
    Solution *obj = new Solution();
    vector<string> str = {"flowers" , "flow" , "fly", "flight", "flag"};
    // string s = "0800214638";
    // cout<<endl;
    // cout<<"Output: "<<obj->largeOddNum(s);

    // cout<<endl;
    // cout<<"Output: "<<obj->longestCommonPrefix(str);

    cout<<endl;

    // //string s = "abcde", goal = "cdeab";
    // string s = "abcde" , goal = "adeac";
    // bool bRet = obj->rotateString(s, goal);
    // if(bRet){
    //     cout<<"Rotate string true"<<endl;
    // }else{
    //     cout<<"Rotate string false"<<endl;

    string s = "anagram" , t = "nagaram";
    bool bRet = obj->anagramStrings(s, t);
    if(bRet){
        cout<<"Rotate string true"<<endl;
    }else{
        cout<<"Rotate string false"<<endl;
    }
    return(0);
}