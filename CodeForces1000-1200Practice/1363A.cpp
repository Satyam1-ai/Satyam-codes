/*




*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;



bool OddSelection(vector<int> &v,int n,int x){
    int count_odds=0;
    int count_evens=0;
    for(int i=0;i<n;i++){
        if(v[i]%2!=0)
            count_odds++;
        else
            count_evens++;
    }
    if(count_odds==0)
        return false;
    for(int i=1;i<=count_odds;i=i+2){
        int needed_evens=x-i;
        if(count_evens>=needed_evens && needed_evens>=0){
            return true;   
        }
    }
    return false;

}








int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int x;
        vector<int> v; 
        cin>>n;
        cin>>x;

        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        bool y=OddSelection(v,n,x);
        if(y)
            cout<<"YES";
        else    
            cout<<"NO";
        cout<<endl;
    }








}




