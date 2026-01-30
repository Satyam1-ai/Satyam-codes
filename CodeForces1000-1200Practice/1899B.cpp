/*
Here we have ..some boxes (size n )...always ...divisible by k ...so n/k is an integer ..we have to figure out ...the max we can get 
after applying the formula (max in the group of size k after n is equally divided by k) ..the min ...find the difference ...
Figure out for what k the ...diffrece would be the maximum ..

Now we can't sort ..because consequetie boxes mentioned in the question ..This is a classic pattern of ....division followed by comaprison among groups..
For these kinds of question ...you use the brute force approach ..take ..arbitary k ....ranging from ...1 to n  ....now ..k is simply a factor 
so nomal factorization limit root n applies ...However we shpould include ....n/i aswell..because paritions ...couldbe possible for both numbers 
i*i <n ...so ...both sides of the factors should be considered ..

Now that our partiion is made ..we could manually calculate max_sum and min_sum....figure out the difference ..but each time 
we would have to spend 0(n)...which would makt it ...n root n  overall complexity ......Or we could simply increase our space complexity by 
n ....and then use ...0(1) calculations ..to figure out the difference .,

Simple stuff ...take the prefix Sum here ...



*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map> 
#include <cmath>





long long findDiff(std::vector<long long> &pref , int k,int n){
    long long max_diff=LLONG_MIN;
    long long min_diff=LLONG_MAX;
    for(int i=k-1;i<n;i=i+k){
        long long diff;
        if(i==k-1){
            diff=pref[k-1];
        }
        else
            diff=pref[i]-pref[i-k];
        if(diff>max_diff){
            max_diff=diff;
        }
        if(diff<min_diff){
            min_diff=diff;
        }
    }
    return max_diff-min_diff;
}





long long Max_diff(std::vector<long long> &A,int n){
    if(n==0)
        return -1;

    std::vector<long long> pref(n,0);
    pref[0]=A[0];
    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]+A[i];
    }
    long long ans=0;
    for(int i=1;i*i<=n;i++){
        long long ans_temp;
        if(n%i==0){
            long long temp_a=findDiff(pref,i,n);
            long long temp_b=findDiff(pref,n/i,n);
            ans_temp=std::max(temp_a,temp_b);
        }
        ans=std::max(ans,ans_temp);
    }
    return ans;
    



}

int main(){
    int t;
    std::cin>>t;
    while(t--){
        std::vector<long long> A;
        int n;
        std::cin>>n;
        for(int i=0;i<n;i++){
            long long x;
            std::cin>>x;
            A.push_back(x);
        }
        std::cout<<Max_diff(A,n)<<std::endl;


    }




}