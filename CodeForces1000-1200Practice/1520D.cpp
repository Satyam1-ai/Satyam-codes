/*





*/






#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>






long long findMatches(std::vector<long long> &v,long long n){
    std::vector<int> diffArray(n,0);
    for(int i=0;i<n;i++){
        diffArray[i]=v[i]-i;
    }
    std::unordered_map<long long,int> cnt;
    long long maxi=0;
    for(int i=0;i<n;i++){
        cnt[diffArray[i]]++;
    }




    for(auto i=cnt.begin();i!=cnt.end();i++){
        long long k=i->second;
        if(k>1)
            maxi+=(k*(k-1))/2;
    }
    return maxi;

}


int main(){
    int t;
    std::cin>>t;
    while(t--){
        long long n;
        std::cin>>n;
        std::vector<long long> v(n,0);
        for(int i=0;i<n;i++){
            long long x;
            std::cin>>x;
            v[i]=x;
        }

        std::cout<<findMatches(v,n)<<"\n";
    }






}