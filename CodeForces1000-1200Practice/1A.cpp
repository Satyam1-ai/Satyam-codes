/*

FIND rows to fit by [m/a]
Same for columsn ..
Multiply


*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




long long Theatre(long long n,long long m,long long a){
    long long temp_l=(m+a-1)/a;
    long long temp_w=(n+a-1)/a;

    return temp_l*temp_w;

}





int main(){
    long long n;
    long long m;
    long long a;
    cin>>n>>m>>a;
    cout<<Theatre(n,m,a);






}