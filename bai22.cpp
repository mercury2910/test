#include<iostream>
#include<vector>
#include<string>

using namespace std;

//helping functions
bool SoSanh(string s1, string s2){
    if(s1[0]-s2[0] < 0) return true;
    else return false;
}

string maxNumberFromArr (vector<int> arr) {
    // arr is the array of int, length of the array is arr.size() and arr[i] is element at index i
    // TODO
    vector<string> str;
    for(unsigned int i=0;i<arr.size();i++){
        str.push_back(to_string(arr[i]));
    }
    for(unsigned int i=0; i<str.size();i++){
        for(unsigned int j=i+1; j<str.size();j++){
            if(SoSanh(str[i].substr(0,1), str[j].substr(0,1))){
                swap(str[i], str[j]);
            }
        }
    }
    string result="";
    for(unsigned int i=0; i<str.size();i++){
        result=result+str[i];
    }
    return result;
}

int main(){
    vector<int> arr({10,2,3});
cout << maxNumberFromArr(arr);
}