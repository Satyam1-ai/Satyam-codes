/*
Another simple Matrix Question ....very introductory ...so we have to take a array ..find the -1 in the array ..and replace them with the 
max i that column ..
you could do ...a col ,row iteration and solve it .......
And you could have multiple ...-1 in there aswell ..which ofcourse is not a bad thing ....bt yeah youmight have to use a vector or hash table to 
keep track of all the -1 in there which would simply be too much work and space ..

instead just loop the entire column ..find the max in 1 loop ..take abother loop figre out where the -1 is there accordignly you 
could simply ..substitute 



*/





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<vector<int>> Substitute(vector<vector<int>> &matrix){
    vector<vector<int>> copy=matrix;
    int col=matrix.size()-1;
    int row=matrix[0].size()-1;
    for(int i=0;i<=col;i++){
        int maxi=INT_MIN;
        for(int j=0;j<=row;j++){
            maxi=max(maxi,copy[j][i]);
        }

        for(int j=0;j<=row;j++){
            if(copy[j][i]==-1)
                copy[j][i]=maxi;
        }
    }
    return copy;

}



int main(){
    vector<vector<int>> v={{1,2,-1},{4,-1,6},{7,8,9}};
    vector<vector<int>>a=Substitute(v);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

}