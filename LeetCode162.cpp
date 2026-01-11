/*
Very basic problem ..Appeared in MITOCW lectures aswell ..infact it was the first or second example shown there ..Quite easy 
assume you have an array ..with n numbers ..and you have to show that a peak exists ...not the peak ..But a peak ..
So use Binary Search ...go to the middle ..check the left element(will have some indexing issues as neegtive appear when you have 1 element) ..or right .....whatever works. ...
so you check the right element ...which is mid+1 ...check ....if that is greater than mid ...if no means you have already found your
temporary peak ..becasue it is > than the right ..we should consider it ..include 0 to mid and exclude
mid+1 till n ..
repeat ...the recursion ...
Now we know for a fact that if there is a peak it will 100 percent be there ..in this segement becasue pf the nature of our BS ..
where we move ledt if we see a peak  ..so the left will always have a peak ..when you have only one element ..that will be the peak 'as it
is derived from a previous condition that that element was bigger than the right element ..
now ..if it were not true then we would not have reached the last element ..we wpild have moved to the right ..and right would havwe been the peak 
if none of the left are greater than the right ...then simply ....we come back to our first mid ...which will be proved to be the peak ..
becasue it is greater than the left ..element (proven now) ...and the right element(proven when we did our first inclusion)

Bit intuitive ...but pattern building ..






*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int findPeak(vector<int> &nums){
    int i=0;
    int j=nums.size()-1;

    int mid;
    if(nums.size()==0)
        return -1;
    while(i<j){
        mid=(i+j)/2;
        if(nums[mid]>nums[mid+1])
            j=mid;
        else
            i=mid+1;
    }

    return i;



}





int main(){
    vector<int> nums={1,2,3,1};
    cout<<"Hello";
    cout<<findPeak(nums);


}