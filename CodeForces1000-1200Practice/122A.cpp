/*
    HARDCODE THE 4,7 NUMBERS TILL 1000 AS ACCORDING TO THE CONSTRAINTS ...OR JUST TAKE A LOOP ...DOES NOT MATTER MUCH 

    HAPPY CODING






*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




bool AlmostLucky(vector<int> &Luckynumbers,int n){
    for(const auto& i:Luckynumbers){
        if(n%i==0){
            return true;
        }
    }
    return false;
}




int main(){

    vector<int> Luckynumbers={4,7,44,47,74,77,447,474,444,477,744,777,747,774};
    int n;
    cin>>n;
    bool x=AlmostLucky(Luckynumbers,n);
    if(x==true)
        cout<<"YES";
    else
        cout<<"NO";


}
