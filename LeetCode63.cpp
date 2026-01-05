
/*
Another very interesting question ..Here its just variation of the unique paths problem ..where ..we are simply calculating the 
the numbr of unique paths with a small obstacle in the middle ..Really easy problem ..Should not be hard ..just initializing needs a bit of visulatisation
So you see a 0 ..you cannot go further if you are in the first row or the first column...becasue the robot can only move down and right 
..but if you are in the middle somewhere you can move ...down ..so a path if it can't be reached from the right can be reached from te 
top ...That is why we simply put 0 when ..we see an obstacle ..pretty intuitive ..

Lets get coding 







*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;





int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int> (n,0));
        if(obstacleGrid[0][0]==0)
            dp[0][0]=1;
        else 
            return 0;
        int i=1;
        while(i<n && obstacleGrid[0][i]!=1){
            dp[0][i]=1;
            i++;
        }
        for(int k=i;k<n;k++){
            dp[0][k]=0;
        }

        for(i=1;i<m;i++){
            if(obstacleGrid[i][0]==0)
                dp[i][0]=1;
            else{
                while(i<m){
                    dp[i][0]=0;
                    i++;
                }
            }
        }




        for(i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else
                    dp[i][j]=0;
            }
        }

        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                cout<<dp[x][y]<<". ";
            }
            cout<<endl;
        }

        return dp[m-1][n-1];

}













int main(){
    vector<vector<int>> obstacleGrid={{0,0},{0,1}};
    cout<<uniquePathsWithObstacles(obstacleGrid);


}