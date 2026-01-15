


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;





int main(){
    int n;
    cin>>n;
    unordered_map<string,int> map;
    while(n--){
        string temp;
        cin>>temp;
        map[temp]++;
    }

    auto itr=map.begin();

    if(map.size()==1){
        cout<<itr->first;
    }
    else{
        auto itr_s=next(itr);
        if(itr_s->second>itr->second)
            cout<<itr_s->first;
        else
            cout<<itr->first;
    }


    return 0;;


}