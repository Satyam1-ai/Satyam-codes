/*
An important logic building question where ....you have to move beyond ..the tradional ..1D dp ..this is important if you come accross
a problem where you have to check all the previous numbers .....to find something in them..

Very applicable to subsequences where ...unlike subarray you don't have contigious memorty allocations ..So yeah..
To start lets assume ...why our normal dp DOES NOT work ..Imagine ..you decide on taking the first number as your max ...and then 
you start iterating through the array ..checking each element from i+1 ...you check for a number which is higher than our number ..
if you find it you can add it ..and then increment .....
do this for the all the other i ..and voilaa....you got it ...BUT NOOOOO BIG TRAP ....imagine this scenario where 
you have ...10 as your first number ...then you go through all the other numbers ........anf then you see 12 ...take it ..
you see 13 take it ..you see 50 take it ...you got ...4 as your highest ..But  think about it .... ...then you missed out this ..thing ..
you essentially missed ..the entire ..array of numbers whioch might have been smaller than your max ...and their colletive sum 
qould have been greater than the total you found ..

so that won't work 


Now essentially when you calculate a max ..you have to check your current element with each and every element whether it is actually the max or not ..
if yes ..then you simply add 1+that count ..otherwise ..just add 1 ..because you did not find an increasing subsequence with that .number in the 
your counting ...

So yeah do that ..till n ..you will find the answer ..



*/





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int findLCS(vector<int> &nums){
    vector<int> dp(nums.size());
    dp[0]=1;


    for(int i=1;i<nums.size();i++){
        int maxi=INT_MIN;
        for(int j=0;j<i;j++){
            if(dp[j]<nums[i]){
                int temp=dp[j];
                maxi=max(maxi,temp);
            }
        }
        if(maxi!=INT_MIN)
            dp[i]=maxi;
        else
            dp[i]=1;
    }
    int maxi=INT_MIN;      //NOW WE EXECUTE THIS FOR LOOP TO CHECK for the max ...amongstwhat we have found in our DP ..Easy 
    for(int i=0;i<nums.size();i++){
        if(dp[i]>maxi)
            maxi=dp[i];
    }
    return maxi;



}



int main(){
    vector<int> nums;

    findLCS(nums);




}






