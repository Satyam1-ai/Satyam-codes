/*TODAY WE ARE GOING TO SOLVE A VERY FREQUENTLY ASKED QUESTION IN FANG INTERVIEWS 
The idea revolves around the fact that ... we are trying to remove the duplicates in a sorted List ...Now keep note 
This is only SORTED ...otherwise the logic would not make any sense*/


/*We start by considering different approach ...Now becasue it is a sorted array ..we have to Figure  out whether the array will exist or not 
So we try to take different approaches ..you could use ..Divide and Conquer method ...however then w have keep track of the coinciding subarray of the left ad right half 
this can become complex ..becasue we have to try to figure out how far we have to go from the middle to the left and the middle to the right 
So we instead use the 2 pointer apprach ...where ...we can see ...that our 2 poniters are just i and  ...one keeping track of teh 
initial element while the other will be iterating through the array ...we copare them at each point ,....if they are not equal then
simple A[j]=A[i].....j will move by one after that ...and the i being a part of the for loop wll automatically get icnremented by 1 */


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int RemoveDuplicates(vector<int> &nums,int n){
    int j=0;
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[j]){
            j++; //Increment bebcasue that spot has been filled up..
            nums[j]=nums[i]; //Simple Swapping
            
        }
    }
    return j+1;//Because we have to measure the count of the  shortened array

}




int main(){
    vector<int> nums={1,1,1,3,4,4,4,4,4,4,4,4};
    RemoveDuplicates(nums,nums.size());



}
