/*
Finding what works and what doesn't ..pretty basic again ......2 pointers used here ...Simply check with the x+i element ..
if it is the saqme that means there is a repetation ..But it is quite possible that this repetation is because of genuine repetation 
howeevr we cant be for sure ..
so yeah if its 11 ..we jsut consider it as a genuine repetation not a abroken character ..Quite key in this problem ..
*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;





string BrokenKeyBoard(string &s){
    string new_str="";
    for(int i=0;i<s.length();){
        int j=i+1;
        while(s[j]==s[i] && j<s.length()){
            j++;
        }

        int temp=j-i;
        if(temp%2!=0){
            if(find(new_str.begin(),new_str.end(),s[i])==new_str.end()){
                new_str+=s[i];
            }
        }
        i=j;

    }
    sort(new_str.begin(),new_str.end());
    return new_str;
}











int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        cout<<BrokenKeyBoard(s)<<endl;
        
    }



}