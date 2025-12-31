/*Really basic BitWise operator ...problem ....So are having to count ..the number of 1s in any n ...r....he wants us to find the 
count for all the numbers from one to n and return the cumm vector ...
you could Simply use the regular ..theorrem n & (n-1) ..keep track of the count ..for each ....number in your range and push in to 
the vector ..Bt that is the naive  method ...I THINK ...so yeah..nahh nahhh brute force would be doing n&1 and doing it for 32 bits ...
or till the duration of the n .. ..Leet code will accept it ...bt better to 
do something better ..becasue the aformentioned method has a complexity of nlog n or n^2 ..which is not very nice ..
THINK ABOUT THE EQAULTION WE USED ...n & (n-1) ..this means .......that ..when upon performing this we are snippping our right most bit 
Upon doing so ...we are left with ...a value we have already envountered soomewhere in the bits before this ..
think about bottom up DP ...or even top down memoization will work ..So yeah ...Lets get solving ..
*/






#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



vector<int> CountingBits(int n){
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;//Our general base cases 

    for(int i=2;i<=n;i++){
        dp[i]=1+dp[i&(i-1)];//FIRST SNIPPED THE 1 ...NOW ADDING IT AGAIN..
    }
    return dp;



}






int main(){

}