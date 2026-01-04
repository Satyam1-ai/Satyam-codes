/*
Really easy problem...very standard problem infact ..i simply have my DP..WHICH is 2 dimentional ..

and I go from start to the end ....now I have so many paths to do this ....initialize to 1 ...becasue to that point there is only way yu can go 
then start from i as 1 and jj as 1 ...like a toeplitz matrix ...very standar ...calculate the sum of ways from top and left becasue 
you need the total number of ways to reach ...a particular...index ..






*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int UniquePaths(int m,int n){
    vector<vector<int>> dp(m,vector<int> (n,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        dp[0][i]=1;
    }
    for(int i=0;i<m;i++){
        dp[i][0]=1;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];

}




int main(){
    int m=5;
    int n=5;
    cout<<UniquePaths(m,n);

}