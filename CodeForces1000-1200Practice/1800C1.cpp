/*
Here we are ...trying .......to give ..our ....heros the  maximum .......boost ...
So we simply .........see a herp card ...pick our m ax boost power up card ....and recurse ..till all the herocards ..are exhausted ...

you could use ...a sorted list for the ..power up card and ....then .do it ..oryoiu could maintian a priotrity queue ...
So essentialy ...we are trying to reduce complexity ...
...bt i will do ....n^2 .... fuck that .
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map> 
#include <cmath>



long long maximum(long long a,long long b){
    if(a>b)
        return a;
    else
        return b;
}


long long findMax(std::vector<long long> &A,int end){
    long long k=-1;
    long long maxi=0;
    for(int i=0;i<=end;i++){
        long long temp=maximum(A[i],maxi);
        if(temp>maxi){
            maxi=temp;
            k=i;
        }
    }
    return k;


}



long long PowerHero(std::vector<long long> &A,int n){
        long long cumm=0;
        for(int i=0;i<n;i++){
            if(A[i]==0){
                long long k=findMax(A,i-1);
                if(k!=-1){
                    long long maxi=A[k];
                    A[k]=-1;
                    cumm+=maxi;
                }
            }
        }

        return cumm;

}





int main(){
    int t;
    std::cin>>t;
    while(t--){
        long long n;
        std::cin>>n;
        std::vector<long long> A(n,0);
        for(int i=0;i<n;i++){
            long long x;
            std::cin>>x;
            A[i]=x;
        }
        std::cout<<PowerHero(A,n)<<"\n";

    }

}