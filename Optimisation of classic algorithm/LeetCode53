/*This is your simple .....Max Sum array which people mostly solve using the Kadene's algorithm aka prefix sum method 
However what if I told you there was an approch that was a bit less popular .
We use a concept called Divide and Conquer(NO Binary search bullshit --ppl always assosiate DAC with binary search when it has to be the other way around)
So lets get to teh problem 


We solve our question ..by dividing our given integer array into 2 segments..
In any given int array ...if you had to find subarrays in geeral .you would have to look at the right of the partition ..or the left .

Bt wait ..we could also ..have a case where it could be a mix of both ..
Consider this ..

A [1,-1,2,3,-2,1] ...here the A[mid] is  2 ....we look at the left..max is 1 ..we look at the right : 3 we missed [2,3] completey ..which would have mad eit 5 

Bt we can make an estimate here saying that the maximium subarray can be found in these 3 areas ..

(start..mid)
(mid+1..end)
and somewhere between(start..end)


So we use recursion to find the max on the left hand side...and the max subarray on the right hand side ..storing them in separate variables 
Now we  have to worry about subarray created by the mixing of 2 arrays..
the most basic approach would be to use ...a loop to check the left from the middle till we find max sum (. L   <- mid    R.)
(Illustrarted) ...so max of that ...and the same thing on the right hand side .....this would be our subarray ..Then just max of all the 3 ..O(n)...Total complexity...O(nlogn)


HAPPY HAPPY ..(actually sad becasue we loose against KADENE...)



BT WAIT THE FUCK UP....WE ARE NOT PEASANTS .....we can actually optimize this further.Think about it ...everytime we calculate the subaary from teh leeft
or the right hand side ..we can also keep track of the starting point of our combined array..(IT IS THE STARTING POINT OF THE CUMMULATIVE SUBARRAY 
WE ARE AFTER )..we can achieve this by backtracking ....The problem which I had faced was returning multiple values 
I just created a structure to help me with it ..So we can keep track of multiple things ...


While merging to find the merged indicator for the future left of an array we simple do ..max(leftindicator,right indicator+total elements of the left array)

Same logic while calcuting the end of the cumm subarray on the right side of the array ..bt there we do ....a comaprison between the right 
subbary's Max till last element ..and the left's max element..bUT WAIT ...if we take left's max element ..then we also have to include the 
fodder elements between the two ...so inactuality it is a comparison .between left's end(max) +fodder elements and right's end elements(max)
ALas we get our subarray ..

Here the time complexity will remain ...O(n)....space will increase because of the extra structures created ...

*/


#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Data {
    int maxSub;
    int maxPre;
    int maxSuf;
    int sum;
};

class Solution {
public:
    Data solve(vector<int>& nums, int left, int right) {
        if (left == right) {
            return {nums[left], nums[left], nums[left], nums[left]};
        }

        int mid = left + (right - left) / 2;
        Data L = solve(nums, left, mid);
        Data R = solve(nums, mid + 1, right);

        Data current;
        current.sum = L.sum + R.sum;
        current.maxPre = max(L.maxPre, L.sum + R.maxPre);
        current.maxSuf = max(R.maxSuf, R.sum + L.maxSuf);
        current.maxSub = max({L.maxSub, R.maxSub, L.maxSuf + R.maxPre});

        return current;
    }

    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return solve(nums, 0, nums.size() - 1).maxSub;
    }
};






int main(){
    vector<int> nums;
    int left=0;
    int right=nums.size();

}