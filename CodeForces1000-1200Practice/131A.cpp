/*
STRART FROM THE INDEX ..1 as you need not check the 0th index ..becasue it is a * ..can be high or low ...


*/






#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>  
using namespace std;





bool checker(string &s){
    for(int i=1;i<s.length();i++){
        if(!isupper(s[i])){
            return false;
        }
    }
    return true;
}

void change(string &s){
    if(s.empty()) return ;



    if(islower(s[0]))
        s[0]=toupper(s[0]);
    else
        s[0]=tolower(s[0]);
    for(int i=1;i<s.size();i++){
        s[i]=tolower(s[i]);
    }
}



int main(){
    string s;
    cin>>s;
    if(checker(s))
        change(s);
    for(const auto &c:s)
        cout<<c;
    return 0;

}