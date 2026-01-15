/*
    HERE WE ARE TRYING TO XENIA AND THE RING ROAD WHERE ...XENIA HAPPENS TO BE PART OF A  CIRCULAR SOCIETY ..SHE HAS TO PERFORM CERTAIN JOBS 
    AT EACH HOUSE .....SHE IS AT HOUSE NUMBER 1 ..AND HAS M THINGS TO DO ..
    THE INPUT IS ...ALL THE HOUSES N ..FOLLOWED BY M THE TASKS ..
    THE NEXT LINE IS ..THE TASKS AT THE HOUSES ...SO Ai is the task at ...house Ai ..she cannot move to Ai+1 without finishing the task as 
    Ai ..Now question i FEEL IS GRAMMATICALLY incorrect ..here ..probably becasue of some...Russian translation ....so yeah basically 
    she is at house Ai completes the task moves to the next one ...
    now circular makes us use the % modular operator ...so ..we have to use a%n every time she moves ..
    To solve this ..just start from 1...check the Ai ..calc difference stroe it in a different variable ...Once you are done with that 
    go the next Ai ..if the house is before ..the current house ..use the %n logic ..other wise simply move to the next Ai ..
    Easy 
    Dunno why it was rated B ..should be a A ..900 ..max 




*/




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



long long RingRoad(long long n,long long m,vector<int> &A){
    long long current_position=1;
    long long distance_covered=0;
    for(int i=0;i<m;i++){
        if(current_position<=A[i]){
            distance_covered+=A[i]-current_position;
            current_position=A[i];
        }
        else{
            distance_covered+=n+A[i]-current_position;
            current_position=A[i];
        }
    }
    return distance_covered;
}






int main(){
    long long n;
    long long m;
    cin>>n>>m;
    long long k=m;
    vector<int> s;
    while(k--){
        int x;
        cin>>x;
        s.push_back(x);
    }

    cout<<RingRoad(n,m,s);







}



