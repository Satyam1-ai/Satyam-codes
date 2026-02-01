/*
Pattern based sliding window problem ..you have ...adjacant ....white and Black colors ..you ought to fgure out ...the least number of 
ways to get k blacks ...
pretty intuitive ...take a window of length k ...in that find the Whites present ...(tehy are the things you have to flip)
scroll over one by one ...
Figure out ..if you find ..a window with lesser W ..take it...otherwise nO ..
pretty easy
*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <map> 
#include <cmath>




int findLeast(std::string &s,int n,int k){
    int whites=0;
    int i;
    for(i=0;i<k;i++){
        if(s[i]=='W'){
            whites++;
        }
    }
    if(whites==0)
        return 0;
    int min_white=whites;
    int j=0;
    while(i<n){
        if(s[i]=='W'){
            whites++;
        }
        if(s[j]=='W'){
            whites--;
        }

        min_white=std::min(min_white,whites);
        i++;
        j++;
    }



    return min_white;



}



int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        int k;
        std::string s;
        std::cin>>n;
        std::cin>>k;
        std::cin>>s;

        std::cout<<findLeast(s,n,k)<<"\n";
    }





}