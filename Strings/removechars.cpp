#include<bits/stdc++.h>
using namespace std;

/*
Given two strings string1 and string2, remove those characters from first string(string1) which are present in second string(string2). Both the strings are different and contain only lowercase characters.
NOTE: Size of  first string is always greater than the size of  second string( |string1| > |string2|).*/

string removeCharacters(string s1,string s2){
    string result;
    for(int i=0;i<s1.length();i++){
        int flag = 0;
        for(int j=0;j<s2.length();j++){
            if(s1[i] == s2[j]){
                flag = 1;
            }
        }
        if(flag == 0){
            result.push_back(s1[i]);
        }
    }
    return result;
}

int main(){
    string string1 = "computer";
    string string2 = "cat";
    cout<<removeCharacters(string1,string2)<<endl;

}