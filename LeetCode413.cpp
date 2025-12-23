/*
Arithmetic Slices can be defined as a subarray (which is a subsequence with contigous blocks ..)
where each adjacent element has a difference of 1  and the size of this slice cannot be less than 3 

So our first thing should be looking at the word subarray ...Could be solved by Divide and Conquer and 
Sliding windows ..Dry run them ....
I will be showcasing those approaches

*/

//DIVIDE AND CONQUER.  ..
//Quite simple ...Very intuitive .."the walls" will be all those elements ..where the adjacant numbers don't have the same difference as compared to the adjoiing neighbours
//find the partition with the findPartition() ...and then split it both ways

//Now if we find out subarray ..then if the length..is 3 or more ..then we cannot return 1 as the question specifies that we have to
//return    ALL the subarrays ..and we know the forumla as (n-1)(n-2)/2 ..where n is the total elements(j-i+1) ..
//Then just add them together  the left and the right side ...
 



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

    int findPartition(int i, int j, vector<int> &nums) {
        int x = nums[i + 1] - nums[i];
        int start;
        for (start = i + 2; start <= j; start++) {
            if (nums[start] - nums[start - 1] != x) {
                return start;
            }
        }
        return -1;
    }

    int solve(vector<int> &nums, int i, int j) {
        if (j - i + 1 < 3) return 0;

        int x = findPartition(i, j, nums);

        if (x == -1) {
            long long L = j - i + 1;
            return (int)((L - 1) * (L - 2) / 2);
        } else {
            long long L = (x - 1) - i + 1;
            int currentCount = (int)((L - 1) * (L - 2) / 2);
            return currentCount + solve(nums, x - 1, j);
        }
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        return solve(nums, 0, nums.size() - 1);
    }





int main(){
    vector<int> nums;



}