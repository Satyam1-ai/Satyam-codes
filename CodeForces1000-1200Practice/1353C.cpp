/*
    Here we have ..an odd box grid ..Have to move figures ..from outer layers to inner layers ...When you have figures in the outer 
    layers ...you simply move all of them inward ..and all directions are okay ..So ..3->1 combination for each ..recurse ..
    i^2 -(i-i)^2 ...but here we have only odd squares so ..2i+1 combinations ..(2i+1)^2 and (2i-1)^2 ...and recurse towards indoor ..
    but the number of figures wont reduce ...
    basically we have ..i*(the square differnece)..
    Upon solving we have ...Summation(8i^2)...and sum of squares will be n(n+1)(2n+1)/6 ...
    So substitute ..and we have ..8(Summantion) ..


*/







#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;


long long up(long long n){
    return (n-1)/2;
}

long long BoardMoves(long long n){
    if(n==1){
        return 0;
    }
    n=up(n);

    return 8*((n)*(n+1)*((2*n)+1))/6;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        cout<<BoardMoves(n);
        cout<<endl;
    }




}