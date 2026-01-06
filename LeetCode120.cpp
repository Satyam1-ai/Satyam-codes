/*
Another good pattern problem in dynamic array .....Here we are working on finding the best way that possioble to reach the top...from the bottom
Now this is ..very easy to solve using memoisation and recursion ..wehre we simply start from the top and check each and every index ...as
to how much ..it costs and calulate the least using th eequation ...
for(*)min(func(*)) ..
But this will take too much time and consume a lot of stack memory ..We should try implementing it with the bottom up approach .
Now the common apporach would be to start at the top ..so you record ..the top (min) in yout DP ..now for every elemrtnt int he i+1
that follows you have to compare that to the top ..this is not possible ..because we have to check each and every column for the index..
if we follow the top to down approach then we won't ..be able to ..solve it ..because we have to loop into the future to make an 
estimate as to whether or not ..we should go into the next ..number which is i+1 and then fill up the dp ...But in dp ITS usuallty the opposite 
we fill something ..and when we see soemthing else ..we look into our past ..results and accordingly ..make a decision .

So we will try to start from the bottom like we did with the dungeon game .Here for each row we see the next row ..becaue path from top to bottom 
will be th esame as the path from the bottom to top ...Becasue we can go from i to ..i+1 and i+2 ...we can effectively do this ...
by checkting the j and j+1 of the next row from the previous row .....

quite easy it seems ..so when you are at the current index ...check j+1 and j to see if you can find a min..add that ..to your DP 



*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int triangleProblem(vector<vector<int>> &triangle){
    int m=triangle.size();
    int n=triangle[m-1].size();
    vector<int> dp;

    for(int i=0;i<n;i++){
        dp.push_back(triangle[m-1][i]);
    }
    for(int i=m-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
        }
    }

    return dp[0];//our dp still size will remain the same ....The only thing that changes is the fact that we are constantly updating the dp array 

}







int main(){
    vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<triangleProblem(triangle);


}