/* CLASSIC PROBLEM ....the optimised solution is not very intuitive..It often entails .....searching throught the entire ...target dp vector ..
and then cheking if each coin fits or not ...and how it would impact the min coins till that point ..
Not very nice ..I kinda followed that approach ....at first ..But yeah ....some small edge case errors just happened ..and again a bit taxing sortin
all of them out ...I did solve it ..bt when you think about it ..it was really stupid of consistantly checking stuff you had already checked ...
So i looked up the optimal solution ...and it was right there ...SO you basically itereate through the coins to see ...whcih coin 
works and whcih doesn't ..cuz this way ..you can jsut go back and then take the min of i-coins in the dp ...see if it is lesseer than what you already have 
If you find that ...then replace ...otherwise no ...But for this to work you hhave to make sure you keep the dp array as soemthing ..
which has the max values initlaised ..expect gfor index 0 ..which is 0 for obvious reason ofcourse ..*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int CoinChange(int target,vector<int> &Coins){
    vector<int> dp(target+1,target+1);
    dp[0]=0;

    for(auto &i:Coins){
        for(int j=i;j<=target;j++){
            dp[j]=min(dp[j],1+dp[j-i]);
        }
    }
    if(dp[target]!=target+1)
        return dp[target];
    else
        return -1;
} 




int main(){
    int target=3;
    vector<int> Coins={2};
    cout<<CoinChange(target,Coins);
}