/*
Straight forward question ..Simply ..use the first cell to go to other cells ...and recurse ..if you can reach the cell via the portals  then happy
otherwise Sad 
Straightforward question ..
*/




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



bool Will_Reach_cell(vector<int> &moves,int n,int destination){
    int current_position=0;
    while(current_position<n-1){
        if(current_position==destination)
            return true;
        current_position+=moves[current_position];
    }
    return false;
}






int main(){
    int n;
    int destination;
    cin>>n;
    cin>>destination;
    vector<int> moves;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        moves.push_back(x);
    }

    if(Will_Reach_cell(moves,n,destination-1)){
        cout<<"YES";
    }
    else
        cout<<"NO";






}