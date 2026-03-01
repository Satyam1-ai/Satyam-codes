/*
Keyboard is there ....some right keys some wrong ...we knwo the functional keys and the non-functional keys ...already ..
basically ..simple logic ...just ..iterate throgh the ...string ...figure out ..which one is not ....part of the ..functional ..keys ..
so imagine you have ...abhdkjabrg ....if h and ..k are not  functional ..I cam somply have ....ab ,d,jabrg ...as my three groups ...
....
then simply do ...n(n)+1/2 as the number of ...substrings they can form  ...Easy shit ...Too easy maybe ....only a 1300 rated problem


*/






#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>




long long BrokenKeyboard(std::string s,std::unordered_map<long long,int> &map, int n){
    long long cumm_sum=0;
    for(int i=0;i<n;){
        long long start=i;
        while(i<n && map.count(s[i])){
            i++;
        }
        long long x=i-start;
        cumm_sum+=(x*(x+1))/2;
        if(i==start)
            i++;

    }

    return cumm_sum;

}


int main(){

    long long n,k;
    std::cin>>n>>k;
    std::string s;
    std::cin>>s;
    std::unordered_map<long long, int> map;
    for(int i=0;i<k;i++){
        char working_key;
        std::cin>> working_key;
        map[working_key]=1;


    }
    std::cout << BrokenKeyboard(s, map, n) << std::endl;

}
