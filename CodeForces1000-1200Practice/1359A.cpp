/*
We are introduced to Berland Poker ..A game wehre the  winner is the person who has the most number of jokers ..and he wins by the difference 
between his jokers and the max number of joker another players has ..This makes this qurestion very interesting ,..and intuitive 
..
So yeah ..n cards ..k players...each player will be having n/k cards ...so lets assume n as 12 and k as ...3 ..
which gives us ....n/k as ..4 ..total of 4 cards per player ..

and we have m jokers ..So effectively ..if m<=4 ..then the maximum a person can score ..if the max-(max another person has)..so it should 
be 4 ,,..as the winnner hoards all the cards .....next if the m is greater than the n/2 ...imagine i have ...4 cards per person
however the number of jokers is limited to .10 ....then the winner can have 4 ...but his score will be 4- max of others ..
if someone else have 4 aswell then score will be 0 ..to maximize we can simply report the max as ...4-(6/no of [players]) ...
so 6/4...which is 1.5 ..ceil of that will be 2 ...so max score is .. 4-2 ..






*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;


int up(int x,int y){
    return (x+y-1)/y;
}

int findMaxProfit(int n,int m,int k){
    int cards_pp=(n/k);
    if(m<=cards_pp){
        return m;
    }
    int ans=up(m-cards_pp,k-1);
    int x=cards_pp-ans;
    if(x==cards_pp)
        return 0;
    else
        return x;





}





int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int m;
        int k;
        cin>>n;
        cin>>m;
        cin>>k;

        cout<<findMaxProfit(n,m,k)<<endl;
    }



}