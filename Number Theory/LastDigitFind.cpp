/*
Pretty fundamental pattern problem ...the last digit cycles as the n prigresses ..which is the case with almost any number and this happens
due to the modularity principles of n in relation to 10 ..(0 to 9)

Here we come across 1378^n..where n ranges from 0 to 10^9 ..
simply run it multiple times ..you see a pattern of ....8,4,2,6...starting from n=1 .



*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;










int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<1;
        return 0;
    }

    vector<int> A={6,8,4,2};
    cout<<A[n%4];
    return 0;




}