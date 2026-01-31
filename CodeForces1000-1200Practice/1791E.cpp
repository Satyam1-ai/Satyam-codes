/*
Classic parity problem ....pretty obvious you use brute force here ..maybe sorting ....will work ....pushing negetives asides ...
then taking them as pairs ...if even ..perfect pair ..if odd one is left out ..to maximise the sum ..
Simply make the least element as the neegtive ....you could bi-swap...each element with the next ..till you make the least number
as negetive ....but too mucg work ..
Better ..take the absolute lowest ..ireespective of its sign ....
find the count of even parity ...if ...even then take it as a whole ...if odd then simply ...follow preveious method ..

Just an observation problem ..





*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map> 
#include <cmath>







long long findAbs(long long x){
    return (x<0)?-x:x;
}

long long findMax(std::vector<long long> &A,int n){
    int neg_count=0;
    long long sum=0;
    long long min_value=LLONG_MAX;
    for(int i=0;i<n;i++){
        if(A[i]<0)
            neg_count++;
        A[i]=findAbs(A[i]);
        sum=sum+A[i];
        min_value=std::min(min_value,A[i]);

    }
    if(neg_count%2!=0){
        return (sum-2*(min_value));
    }

    return sum;



}




int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::vector<long long> A;
        for(int i=0;i<n;i++){
            long long x;
            std::cin>>x;
            A.push_back(x);
        }
        std::cout<<findMax(A,n)<<std::endl;


    }



}