
/*

Pretty Basic Question.Dunno why it is classified as a medium rated problem..Here we try to implement ... the max ..sum out of
the first row ...replace that with -1 or something ...Do this ..for the duration of teh columns of the ..array

TOO EASY
*/






#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int matrixSum(vector<vector<int>> &m,int row,int column){
    for(int i=0;i<=row;i++){
        sort(m.begin(),m.end());
    }
    int final_score=0;
    while(column>=0){
        int score=0;
        for(int i=0;i<=row;i++){
            int temp=m[i][column];
            score=max(score,temp);
        }
        final_score+=score;
        column--;
    }
    return final_score;


}




int main(){
    vector<vector<int>> m={{7,2,1},{6,4,2},{6,5,3}};
    int row=m.size()-1;
    int column=m[0].size()-1;

    cout<<matrixSum(m,row,column);



}
