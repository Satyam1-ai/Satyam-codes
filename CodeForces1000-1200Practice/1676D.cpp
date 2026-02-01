/*
Boring Question .....Simple diagonal question  ......first calcualte  the sum of all the diagonals "\" this way ..then "/" way ..
So yeah ..find the max sum out of all that ......so (m-1),0 till ...0 ,(n-1) ...incrementing //decrementing by .. 1,1 at each step ..
and ..from 0,0 till m-1 ,n-1 ...becoming ..1,1,2,2 etc ..


REMEMBER ....i+j is the anti-diagonal and i-j+(n-1) is the ..diagonal mapping of a 2d MATRIX into a single dimentional matrix ..

*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>





int maxSum(std::vector<std::vector<int>>&A, int m, int n){
    std::vector<int> antiDiagonal(m+n);
    std::vector<int> Diagonal(m+n);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            antiDiagonal[i+j]+=A[i][j];
            Diagonal[i-j+(n-1)]+=A[i][j];
        }
    }
    int max_sum=INT_MIN;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int sum=Diagonal[i-j+(n-1)]+antiDiagonal[i+j]-A[i][j];
            max_sum=std::max(max_sum,sum);
        }
    }
    return max_sum;


}








int main(){
    int t;
    std::cin>>t;
    while(t--){
        int rows;
        int columns;
        std::cin>>rows;
        std::cin>>columns;

        std::vector<std::vector<int>>A(rows,std::vector<int>(columns));

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                int x;
                std::cin>>x;
                A[i][j]=x;
            }
        }

        std::cout<<maxSum(A,rows,columns)<<"\n";

    }
}
