/*
Really funcamental question ..Good way to test your DP foundational knowledge ...Could be ..done by so many methods ..
you could try the brute force method ..so each ..index ..you iterate through..you see if you have something better ...
if and calc the profit ..repeat for i+1 ...till n-1....complexity will be n^2 ..Not worth it ..
so for obvious reasons we can try sliding  windows ..bt again you can't set the limit in any way ....so the window won't work 
then you come to recursion with memoizatino ..which works but its almost like brute force .So it won't really help you with intuition bbuilding 
Instead you do ...dynamic programming with the bottom up aproach ..this way we could ...check at each index the max profit ..and then decide 
whether you want to carry it forward or not ..now for profit if the selling cost is higher than the buying cost ..you will record it a rofit made compare with the 
dp[i-1] ..which has the max profit till that number ..
otherwise ..you just carry the dp[i-1] forward..
Pretty easy ..

Bt we could optimize the time complexity ..by realizing that because it is only checking dp[i-1] at each step .we could just record it 
as a variable ...so ..max_profit variable till that particular index ...if we find something bigger we update it ..Otherwise ..just move forward 
updating the min_buy if needed ..

Pretty Simple problem .....

EASY ..lets get coding .
*/




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int max_profit(vector<int> &nums){
    int n=nums.size();

    int min_buy=nums[0];
    int max_profit=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]>min_buy){
            max_profit=max(max_profit,nums[i]-min_buy);
        }   
        else{
            min_buy=nums[i];
        }
    }
    return max_profit;
}









int main(){
    vector<int> nums={7,1,5,3,6,4};
    cout<<max_profit(nums);




}
