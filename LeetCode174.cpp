/*
A bit tricky problem ....But a new pattern to be lodged into the memory ..it goes like if you can't keep track of certain things in the forward iteration 
becasue you depend on the futute ..you start looking from the backwards. ...
Same principle ...here you can't realistically keep track of how much boost increment to store or how much 
to not store becasue it all depends on teh next door ...Now I could subtract ...but the one have is a domino of what i had 
earlier ..so we can't subtrtract ...

this leaves us wth the choice of moving from the back ..calculating the ...min_health at each step ...so we start from m-1 and n-1
At each step we figure out ...if we have to go ..to  up or left ...we simply find the min health needed from the down or right ..
whichevr one we pick ..we that is our min value at that particular box or indice ..now ..that index will be having some deomons / powerup 
to take that into account we simply do dp our min_value-demoon/powerup value at that particular box ...and comapre it with 1 ..
so essentiallly if our residue is >1 then we simply choose 1 ..as the knight can have 1 which is min_value at that point ....
However if we store something like 8/9 that would mean teh ex-min which was lets assume 3 ..needs more more health to handle the -5 monster
because together that makes it 8 ...so 8 is the safe min_limit out knight should have ...we dothis and go upwards


Our final value will be ....min_health[0][0] ..which is the starting point 




*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;






int findMinHealth(vector<vector<int>> dungeon){
    int m=dungeon.size();
    int n=dungeon[0].size();
    vector<vector<int>> min_health(m,vector<int> (n,0));


    min_health[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);
    for(int i=m-2;i>=0;i--){
        min_health[i][n-1]=max(1,min_health[i+1][n-1]-dungeon[i][n-1]);
    }
    for(int i=n-2;i>=0;i--){
        min_health[m-1][i]=max(1,min_health[n-1][i+1]-dungeon[n-1][i]);
    }


    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            min_health[i][j]=max(1,min(min_health[i+1][j],min_health[i][j+1])-dungeon[i][j]);

        }
    }

    return min_health[0][0];




}









int main(){
    vector<vector<int>> dungeon={{-2,-3,3},{-5,-10,1},{10,30,-5}};
    cout<<findMinHealth(dungeon);



}