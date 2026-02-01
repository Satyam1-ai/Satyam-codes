/*
Intuitive problem if  you understand ...sets ...annd access times ..because access time for strings would be ...O(1)..
simple brute force can be used here ..the question gives a major hint stating ....that ....it is atmost lenght 8 ..more often than 
not ..it  is simply brute force ..or case by case check ..


*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <map> 
#include <cmath>





void func(std::vector<std::string> &v,int n){
    std::unordered_set<std::string> has;
    for(int i=0;i<n;i++){
        has.insert(v[i]);
    }
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=1;j<v[i].size();j++){
            std::string first_part=v[i].substr(0,j);
            std::string second_part=v[i].substr(j);
            if(has.count(first_part) && has.count(second_part)){
                flag=1;
                break;
            }
        }
        if(flag==1)
            std::cout<<"1";
        else
            std::cout<<"0";
    }


    std::cout<<std::endl;
}









int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::vector<std::string> v;
        for(int i=0;i<n;i++){
            std::string x;
            std::cin>>x;
            v.push_back(x);
        }
        func(v,n);
    }




}