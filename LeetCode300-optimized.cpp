/*
An optimised version of the LCS ..problem ..i'll be honest ..I looked it up ...after I solved it via ..n^2 ...So I guess I am a bit stupid 
But it is fine ....we learn as we progress ..
So our objective here is to find the maximum subsequence lenght ..which is strictly increasing ..
This makes this solution so beautiful ..It is derived a type or sorting called patience soorting ..which was developed by some mathematicians 
So basically every time we find a number . on the right as we progress on our i ..we are effectively ...simply looking back ..whicj cause
the n^2 ..but this method is simply the substituion of that number ...

So you basically take another array ....with the size being length.....so when I look at a new element ...I will add it to my new array 
..So my first element  of the new array will be recorded as that element ...now I ill look at the second number 
if my second number is larger than the first element ..then i will include it in the second index ...now third element .....I will have to 
look where it is getting inserted ..it could be at anny of the indices...but because ..I know it is a sorted list ..I can use biinary search to 
find the element ..ONCE i have found where i should insert it ..I simply substitute with what is there ..this is indicative of the fact that 
it is a part of teh subsequence ...and anything comming after this would include a bigger subsequence ..

you do this till the end ..and the final length of the subsequence will be the size of the new array ..this was you can solve this problem 
in n log n time complexity instead of the usual .....n^2 ..

*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void BS(vector<int> &m,int end,int x){
    int i=0;
    int j=end;
    int mid;
    while(i<=j){
        mid=(i+j)/2;
        if(x>m[mid]){
            i=mid+1;
        }
        else if(x<m[mid]){
            j=mid-1;
        }
        else
            return ;
    }
    m[i]=x;
    return;



}



int LCS(vector<int>  &nums){
    vector<int> m;
    m.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(nums[i]>m.back())
            m.push_back(nums[i]);
        else
            BS(m,i-1,nums[i]);
    }

    return m.size();





}



int main(){
    vector<int> nums={3,5,6,2,5,4,19,5,6,7,12};
    cout<<LCS(nums);


}
