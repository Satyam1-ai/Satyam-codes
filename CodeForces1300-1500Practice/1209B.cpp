/*
Simulate .simple brute force simulation ..Dont use your mind too much ...Simply do .....t till 125 ..or whatevr ethe constraint it 
change the toggles according to the formula ...ai+bi*times ......so yeah ..have a gloabl variable name maxi ..
and then ..work on cheking if somehting exeeds that or not ..if yeah ..return ..it otherwise ....0 ..


*/







#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>







int finding(std::vector<std::pair<int,int>> &v,std::string s,int n){
    int maxi=0;
    for(int t=0;t<1000;t++){
        int count=0;
        for(int i=0;i<s.size();i++){
            if(t>=v[i].second){
                if((t-v[i].second)%v[i].first==0){
                    s[i]=s[i]^1;                    
                }
            }
        }

        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
            }
        }
        maxi=std::max(maxi,count);
    }

    return maxi;


}



int main(){
    int n;
    std::cin>>n;
    std::string s;
    for(int i=0;i<n;i++){
        char x;
        std::cin>>x;
        s+=x;
    }
    std::vector<std::pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int x;
        int y;
        std::cin>>x;
        std::cin>>y;
        v[i].first=x;
        v[i].second=y;
    }

    std::cout<<finding(v,s,n);


}