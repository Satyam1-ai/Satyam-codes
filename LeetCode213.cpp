/*
Another very intuitive problem ....I mean if you think of circular form of arrays ..it will make a lot of sense ...but you have tocomapre it 
witht the House Robber 1 problem where we checked a basic condition that being ..if the dp[i-2] +current i compared with the dp[i-1]

Our base case was ..dp[0]=furst number ,.
dp[1] was the max of the first 2 numbers 

sp here its a simple problem ...what do we take as out dp[0] ....because it is circular we can't possibly take the last number .becasue they are connected 
we have to start from teh n-2 element ...however if we start from the n-2 eleemt we are effectively skipping the number n-1 
we could start from the n-1 element ...bt they we's have to skip teh 0th element ..


so yeah ..becasue we can have 2 starts ..intuition tells that ..we can sovle it ..in a way that we include both of our results ..
now think about our 2 ...scenarios ..

n-1,1,2,3,4,5 .....n-3. and 
n-2,0,1,2,3,4,5 .....n-4...

toggle over ..this is simply ....0,1,2,3,4,5.....n-2 and 1,2,3,4,5 .....n-1

now we can have our starts as ..0 and 1 ...while keeping the endings different ...SO yeah a bit tricky ...but if you think for a couple
mins..you should be able to find it ...Pretty easy ...in general ..




*/





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;






int HouseRobber(int start,int end,vector<int> &nums){
    vector<int> dp(nums.size()-1);
    dp[0]=nums[start];
    dp[1]=max(nums[start],nums[start+1]);
    int dp_index=2;
    for(int i=start+2;i<=end;i++){
        dp[dp_index]=max(dp[dp_index-2]+nums[i],dp[dp_index-1]);
        dp_index++;
    }
    for(int i=0;i<dp.size();i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    return dp[dp.size()-1];

}






int main(){
    vector<int> nums={200,3,140,20,10};
    int n=nums.size();
    if(n==1)
        return nums[0];
    else if(n==2)
        return max(nums[0],nums[1]);
    cout<<HouseRobber(0,n-2,nums)<<endl;
    cout<<HouseRobber(1,n-1,nums)<<endl;


    
    

}

