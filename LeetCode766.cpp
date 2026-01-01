 /*WHAT IS A TOEPLITZ MATRIX ...well it is simply a matrix that has its diagonal elemnts all equal ..now in a matrix when we see diagonal 
 the first thing that comes to my mind ..is the i+1 ,j+1 ....cuz that constitutes the diagonal ..If you are starting at. ....0,0
 then .......you basically look through the entire diagonal ...so ..0,0. then 1,1 then 2,2  ,3,3 if it is a square matrix ...or if rectangular 
 then similar concept ....you could do like this ..and then recursively do it ..for all teh other diagonals ..bit like divide and 
 conquer ...BUT THAT WOULD BE THE NAIVE WAY OF SOLVING IT ...
 BUT PROGRAMMING IS ABOUT MAKING LIFE EEASIER ....So we have to find something that does this quicker ..
 Now think about it ...flip the equation ..if i+1 =i and j+1=j ..then i-1 =i and j-1 will equal j ...bt if we do it from 0,0 index then we 
 will be runnning into out of bound error ...
 that is why we have to start fromt he first reasonalble index ..which is 1,1 .....and iterate through every indx ..trying to figure out 
 which all are the diagonals which are equal */


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




bool Toeplitz(vector<vector<int>> &matrix){
    int row=matrix.size()-1;
    int col=matrix[0].size()-1;


    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(matrix[i][j]!=matrix[i-1][j-1]){
                return false;
            }
        }
    }
    return true;
}



int main(){

    vector<vector<int>> matrix={{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    cout<<Toeplitz(matrix);


}






