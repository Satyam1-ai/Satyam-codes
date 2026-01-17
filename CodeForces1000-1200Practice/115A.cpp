/*
I did this question in the main ,...repo aswell ..This is simply a redoing of it ..to practice ..Simple question ..
We have a graph like structure where an employee can be represented as a node .branching out from the root ..as you go higher 
you discover the hirerchy ..So yeah ..could solve it by trees ..finding the mex depth..
its realy simple boss->employee ->employee ->employee...and lets assume n similar braches ...and each level can be layered together ,
as they dont belong to a ahirerechy ..maybe indepenent ..controls 
so yeah ...find the  levels ..if you get it ,then simply count ..
Standard approach would be start from the bottom ..if you are using loop




*/







#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




int main(){
    int n;
    cin>>n;
    int k=n;
    vector<int> manager;
    while(k--){
        int x;
        cin>>x;
        manager.push_back(x);
    }

    int levels=0;
    for(int i=0;i<n;i++){
        int new_i=i;
        int temp_levels=1;
        while(manager[new_i]!=-1){
            new_i=manager[new_i]-1;
            temp_levels++;
        }
        levels=max(levels,temp_levels);
    }
    cout<<levels;





    return 0;



}

