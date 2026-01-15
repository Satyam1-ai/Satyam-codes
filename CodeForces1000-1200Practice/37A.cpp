/*



*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;





vector<pair<int,int>> Towers(vector<int> &v,int n) {
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[v[i]]++;
    }

    int count=0;
    int maxi=0;

    for(auto it=map.begin();it!=map.end();it++)
    {
        count++;
        maxi=max(maxi,it->second);
    }
    vector<pair<int,int>> y={{maxi,count}};
    return y;

}


int main(){
    int n;
    cin>>n;
    vector<int> v;
    int k=n;
    while(k--){
        int x;
        cin>>x;
        v.push_back(x);
    }

    vector<pair<int,int>>y=Towers(v,n);
    cout<<y[0].first<<" ";
    cout<<y[0].second;




}