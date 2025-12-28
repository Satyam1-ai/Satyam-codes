/*Another interview question ....A variation of the usual duplication of arrays ...here we are allowed to have upto 2 count of the smae number
bt the constrain of the array being a sorted array will remain
The idea behind this question is that you have to recognize a particular pattern
So out pattern goes like ....a-b =0 ..then valid  becasue we can take 2 elements ...at most .However when we get ..somethign like 
a-b=negetive then it is an anomaly ..it can be positive becasue that would indicate the elements are not the same ansd the right 
element is greater than the elft element .....Or we could keep a count of the number from the start of our supposed window
It is a solution that works ..However the optimised solution for this problem is that....we try to keep track of the start of the new element 
as we move forward we compare it wiht that ....
We are assuming a variable k .....where k-2 will be indicating the start of the new variable .....and k will the end_count of that variable 
this enables us to make this possible .....now everytime our i will be seeing a new variable that is equal to element k-2 ,it will 
it will just move forward because it is simply a continuation of the same number ....BUT SEE ITS COUNT(This is how we limit our duplicates to o2 )
its like you;re going on a rollerCoaster ...but everytime you see an object you pull back. the object ...out i is the roller coaster

FUN QUESTION ::We can  modify this question sich that we keep track of the ...roller coaster ..bt the roller coaster ..track has a few obstacles ..
We have to pick them up by our hand ..To do ..so we can use a similar logic and group all the obejjects in the order of their size 
LETS GET TO CODING NOW */



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int RemoveDuplicates(vector<int> &nums,int n){
    if(n==1 || n==2)
        return n;
    int i=2;
    int j=2;//could be k whatever you wanna call it 

    for(i;i<n;i++){
        if(nums[i]!=nums[j-2]){
            nums[j]=nums[i];
            j++;
        }
    }
    return j;
}




int main(){
    vector<int> nums={1,1,1,2,2,3};
    RemoveDuplicates(nums,nums.size());
}