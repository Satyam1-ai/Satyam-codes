/*
VERY INTERESTING QUESTION  ..QUITE LOGICAL ..BUT YOU KEEP DOUBTING YOURSELF ..ALL THE TIME ..I HAD TO STUGGLE WITH CONVINCNG MYSELF ..
THAT WHEN YOU ADD A NEW NUMBER ..HOW THE PREVIOUS NUMBERS CHANGE ...was a shocker ..and a confidence breaker 


So ..yeah ..the problem dictates that we have a string given to us ....this string will be having numbers from ..1 till 10 in conjunction 
and can form ..certain pairs with each other ...like ..123 can be 1,2,3 or 12,3 or 1,23 ....which is fairly easy to solve ..you 
simply take ....a dp counting the num of way till the ith character ...If you find it then at each time ..you simply check 
if the element before  it ..makes out current element a part of a combination or no ..if no then you have treat it individually ..Otherwise 
we have to start taking it as a pair ..now if we try to do it individually then ..you just carry over ...the number of ways from 
what you stored in dp[i-1] which stores till our previous number....If it is taken as a pair then we have to ..consider two possibilities ..
2 branches of a tree ..so number of ways you can decode it ..while taking for example "12"  ...and the number of ways you can decode
it as .."1" "2"....Higly intuitive ..this one ..
Till here it is fairly easy ...But now comes a 0 ..

while encountering a 0 ..we again have 2 possibilites ..one when I put 0 in the end as part of something else ..or 0 individually 
now 0 individually would simply not qualify ..so we can return 0 ....now the tricky part is what happens when 0 has a number before it 
that is a valid comination ...like 10 or 20 .....here we have to make sure ..that we consider them as a group.....and then take the dp[i] as a group 
simply by doing dp[i-2]...this way you treat it as one ...

ITS LIKE THE TIE THEOREM IN COMBINATIONS ....when you have to group tow things and find how many ..

So yeah ...Lets code this ./.





*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




bool checker(int prev,int curr){
    int temp=(prev*10)+curr;
    if(temp>=10 && temp<27)
        return true;
    return false;
}




int Decodeways(string nums){

    int n=nums.size();

    vector<int> dp(nums.size()+1);

    dp[0]=1;//empty string
    if(nums[0]!=0)
        dp[1]=1;
    else
        return 0;


    for(int i=2;i<=n;i++){
        int curr=nums[i-1]-'0';//calculates the current element
        int prev=nums[i-2]-'0';//calculates the previous element

        if(curr==0){
            if(prev!=0 && checker(prev,curr)){
                dp[i]=dp[i-2];
            }
            else
                return 0;//no point in checking further
        }
        else{//should do continue in the previous codeblock if a case arises where we have negetive numbers 
            if(prev!=0 && checker(prev,curr)){
                dp[i]=dp[i-1]+dp[i-2];
            }
            else{
                dp[i]=dp[i-1];
            }
        }
    }

    return dp[nums.size()];








}








int main(){
    string nums="226"; //random stirng
    cout<<Decodeways(nums);



}



