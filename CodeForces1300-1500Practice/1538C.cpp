/*

We have ...a basic 2 pointer .....question ...bit of twist here and there ...the first major twist being the fact that ...
you have to look at a partiuclar range ....and not ...a particular ..sum ...
Ideally we'd have ....2 pointers ...on a sorted array ..where patetern recognition screams ...to emply sort+2 pointer 
or Binary Search ...But nahhh ...we can't do that anymore ...
We ahve a range to ..handle such problems ...you simply focus on the ..range ....So L....R ....
See how many satisfy the ......R condition ...now from what you have ...subtract the . ones that donot satisfy the L condition ...

...........so yeah ....create a simple function ...abc(limit) ...where the limit is simply the upper bound ...
and calcualte ...how many  pairs you have ....

*/





#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>




long long abc(std::vector<long long> &A,long long n,long long limit){
    long long total=0;
    long long i=0;
    long long j=n-1;
    while(i<=j){
        int sum=A[i]+A[j];
        if(sum>limit){
            j--;
        }
        else{
            total+=(j-i);
            i++;
        }
    }
    return total;
}

long long findpairs(std::vector<long long> &A,long long n,long long l, long long r){
    std::sort(A.begin(),A.end());
    long long x=abc(A,n,r);
    long long y=abc(A,n,l-1);
    return x-y;
}


int main(){
    int t;
    std::cin>>t;
    while(t--){
        long long n,l,r;
        std::cin>>n>>l>>r;
        std::vector<long long> A;
        for(int i=0;i<n;i++){
            long long x;
            std::cin>>x;
            A.push_back(x);
        }
        std::cout<<findpairs(A,n,l,r)<<"\n";
    }
}