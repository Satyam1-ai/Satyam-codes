/*
Very popular Question ...dragons. ....i am playing a game ..have to beat all dragons to win .each ddragon i beat ..I get some bonus health ..
So yeah super easy ..simply sort ...pick the easiest dragon(the one whose health is lesser than mine) ....kill ...get bonus 
got the next .....2 possibilities ..if you can beat all you win 
other ise you loose 

LETS CODE 
should be 800 rated this probelm 

*/



#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
#include <cctype>  
using namespace std;






bool Dragon(int s,int n,vector<pair<int,int>> &strength)
{
    int current_health=s;
    sort(strength.begin(),strength.end(),[](const auto &a,const auto &b){
        return a.first<b.first;
    });


    for(int i=0;i<n;i++){
        if(current_health<=strength[i].first){
            return false;
        }
        current_health+=strength[i].second;
    }

    return true;

}


int main(){
    int s;
    int n;
    vector<pair<int,int>> strength;
    cin>>s;
    cin>>n;
    int k=n;
    while(k--){
        int x;
        int y;
        cin>>x;
        cin>>y;
        strength.emplace_back(x,y);
    }
    k=n;

    bool ans=Dragon(s,n,strength);
    if(ans)
        cout<< "YES";
    else    
        cout<< "NO";

    return 0;




}