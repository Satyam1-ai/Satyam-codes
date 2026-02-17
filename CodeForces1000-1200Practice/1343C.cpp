/*
I dont really like subsequence questions ..they are too random ....and more often than not ..you end up using DP to solve them 
But i like this one ..Really intuitive ..Dunno how you could go wrong with this .....
So max length of the subsequence is essentally ....one of ..the positive ..and one of negetive ..till ..the end ..
and ofcourse ideal scenario would be you having .....one positive and one negetive ....but ...sometimes ..you get ..like a block of positive 
and a block of negetives ....


You use that block ..figure out the max..from each block ...and simply .....pick the max out of all that ...and voila ..(for negetive the min)

*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>



bool check_parity(long long a, long long b){
    if(a>0){
        if(b>0)
            return true;
    }
    else{
        if(b<0)
            return true;
    }
    return false;
}



long long maximum_two(long long maxi,long long x){
    if(x>maxi)
        return x;
    else
        return maxi;
}



long long MaxAlt(std::vector<long long> &A,int n){
    int i=0;
    long long cumm_sum=0;
    while(i<n){
        long long maxi=A[i];
        while((i+1)<n && check_parity(A[i],A[i+1])){
            maxi=maximum_two(maxi,A[i]);
            i++;
        }
        maxi=maximum_two(maxi,A[i]);
        cumm_sum+=maxi;
        i++;
    }
    return cumm_sum;
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
        std::cout<<MaxAlt(A,n)<<"\n";





    }



}