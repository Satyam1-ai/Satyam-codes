/*
    SIMPLE SUBSEQUENCE QUESTION ....JUST HAVE TO SEE IF HELLO IS PART OF THE STRING .....YOU COULD THINK OF IT AS SUBSTRINGS 
    BUT YOU WOULD GET THAT WRONG BECASUE HELLO CAN ANYWHERE IN THE STRING ....NOT PARTICULARLY ADJACENT TO EACH OTHER 
    THOUGHT THE ORDER IS MAINTAINED ...



*/




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




bool Ans(string &s){


    string b="hello";
    int i=0;
    int j=0;
    while(i<s.length() && j<b.length()){
        if(s[i]==b[j]){
            j++;
        }
        i++;
    }

    if(j==b.length())
        return true;
    return false;










}







int main(){
    string s;
    cin>>s;
    if(Ans(s)){
        cout<<"YES";
    }
    else
        cout<<"NO";


    return 0;



}