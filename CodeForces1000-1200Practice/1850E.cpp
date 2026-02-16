




#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map> 
#include <cmath>






long long findw(std::vector<long long> &A, int n, long long c) {
    __int128 a = 0;
    __int128 b = 0;
    for(int i = 0; i < n; i++) {
        b += A[i];
        a += (__int128)A[i] * A[i];
    }    

    long long l = 1;
    long long h = 1000000000;
    
    while(l <= h) {
        long long mid = l + (h - l) / 2;
        __int128 m = mid;
        __int128 ans = a + ((__int128)n * 4 * m * m) + (4 * m * b);
        
        if(ans == (__int128)c)
            return mid;
        else if(ans < (__int128)c)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}






int main(){
    int t;
    std::cin>>t;
    while(t--){
        long long n;
        long long c;
        std::cin>>n;
        std::cin>>c;

        std::vector<long long> A;
        for(int i=0;i<n;i++){
            long long x;
            std::cin>>x;
            A.push_back(x);
        } 
        std::cout<<findw(A,n,c)<<"\n";

    }



}