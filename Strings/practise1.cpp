#include<bits/stdc++.h>
using namespace std;


int countWords(string s){
    int countNumWords = 1;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' ' && s[i-1]!=' ' ){
            countNumWords++;
        }
    }
    return countNumWords;
}

int countVowell(string str){
    int countNumbreOfVowells = 0;
    //Converting everything to upper case
    for(int i=0;i<str.length();i++){
        str[i] = toupper(str[i]);
    }

    //Checking for upper case only
    for(int i=0;i<str.length();i++){
        if(str[i] == 'A'||str[i] == 'E'||str[i] == 'I'||str[i] == 'O'||str[i] == 'U'){
                countNumbreOfVowells++;
            }
    }
    return countNumbreOfVowells;
}

int validateString(string s){
    //32–47 / 58–64 / 91–96 / 123–126
    if(s.length()<=8 || s.length() >=15){
        cout<<"The length must be between 8-15"<<endl;
        return false;
    }else{
        for(int i=0;i<s.length();i++){
            if(
                !(s[i] >= 65 && s[i]<=90) && 
                !(s[i]>=97 && s[i]<=122) && 
                !(s[i]>=48 && s[i]<=57) &&
                !(s[i]>=32 && s[i]<=47) &&
                !(s[i]>=58 && s[i]<=64) &&
                !(s[i]>=91 && s[i]<=96) &&
                !(s[i]>=123 && s[i]<=126) 

                 ){  
                    return false;
                 }
        }
        return true;
    }
}

int compare(char *s1,char *s2){
    if(strcmp(s1,s2)){
        return true;
    }else{
        return false;
    }
}

/*
 
 Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

*/

int convertStringToInteger(string str){
    vector<int>v;
    if(str[0]!='-'){
        for(int i=0;i<str.length();i++){
             if(str[i]>='0' && str[i]<='9'){
                 v.push_back(int(str[i]) - 48);
            }else{
                return -1;
        }
    }
    int sum = 0;
    int mul = 1;
    for(int i=v.size()-1;i>=0;i--){
        sum = sum + v[i]*mul;
        mul = mul*10;
    }
        return sum;
    
}else{
    for(int i=1;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9'){
                v.push_back(int(str[i]) - 48);
            }else{
                return -1;
        }
    }
    
    int sum = 0;
    int mul = 1;
    for(int i=v.size()-1;i>=0;i--){
        sum = sum + v[i]*mul;
        mul = mul*10;
    }
        return -sum;
    }

}

/*
  Your task is to implement the function strstr. The function takes two strings as 
  arguments (s,x) and  locates the occurrence of the string x in the 
  string s. The function returns and integer denoting the first occurrence of the 
  string x in s (0 based indexing).

*/
int strstr(string s,string x){
    for(int i=0;i<s.length();i++){
        if(s.substr(i,x.length()) == x){
            return i;
        }
    }
    return -1;
}

string x(string y){
    sort(y.begin(),y.end());
    return y;
}

int anagram(string A,string B){
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int i,j;
    if(A.length() == B.length()){
        
        for(i=0,j=0;i<A.length();i++,j++){
            if(A[i] !=B[j]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }

}

/*
Remove Characters
 Given two strings string1 and string2, remove those characters from first string(string1) which are present in second string(string2). Both the strings are different and contain only lowercase characters.
NOTE: Size of  first string is always greater than the size of  second string( |string1| > |string2|).
*/

string removeStrings(string s1,string s2){
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

string findDuplicates(string s){
    string result;
    for(int i=0;i<s.length();i++){
        s[i] = tolower(s[i]);
    }

    vector<char>v(26);
    for(int i=0;i<26;i++){
        v[i] = 0;
    }

    for(int i=0;i<s.length();i++){
        v[(s[i])-97]++;
    }
    for(int i=0;i<v.size();i++){
        if(v[i] > 1){
           result.push_back(i+97);
        }
    }
    return result;
}

int main(){
    string str1,str2;
    // cout<<"Enter 1st string: ";
    // getline(cin,str1);
    // cout<<"\n";
    // cout<<"Enter 2nd string: ";
    // getline(cin,str2);
    // cout<<"\n";

    
    // cout<<"Given Strings are  : "<<str1<<"\t"<<str2<<endl;
    //To check if the string is lower or upper and return true or false.
    // for(int i=0;i<str.length();i++){
    // if(islower(str[i])){
    //     cout<< true<<endl;
    // }else{
    //     cout<< false<<endl;
    // }


    //Convert to lower case or upper case
    // for(int i=0;i<str.length();i++){
    //     str[i] = tolower(str[i]);
    // }
    // cout<<"Lower case: "<<str<<endl;
    // for(int i=0;i<str.length();i++){
    //     str[i] = toupper(str[i]);
    // }
    // cout<<"Upper Case: "<<str<<endl;

    // for(int i=0;i<str.length();i++){
    // if(isupper(str[i])){
    //     str[i] = tolower(str[i]);
    // }else if(islower(str[i])){
    //     str[i] = toupper(str[i]);
    // }else if(isdigit(str[i])){

    // }

    // }
    //     cout<<str<<endl;
    // cout<<"Number of Words: "<<countWords(str)<<endl;
    // cout<<"Number of Vowells: "<<countVowell(str)<<endl;
    
    //cout<<validateString(str)<<endl;
   // cout<<compare(str1,str1)<<endl;
   //cout<<convertStringToInteger("-12323");
   //cout<<x("zabc");
   //cout<<anagram("grip","riig")<<endl;
   //cout<<removeStrings("Ravindran","id")<<endl;
   cout<<findDuplicates("AAAAMMpPo")<<endl;

  }