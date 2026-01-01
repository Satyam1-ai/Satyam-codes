/*
Dunno if they ask these type of questions in the interview or not ..Because its really simple and intuitive ...i think everyone can do it 
intuitevely ..If you saw the solution then you're straight up mid .lol 

But nahh ....2 easy ways  i could think of doing this..harder way would probably take recursion on each row ...then each columnn ..but nahh 

you should treat the array ...as a 1D matrix not 2D ...flatten it in some sense ...so you mid will be the mid of the big matrix ..
but comoputer sees meemory locations ....not ..2D ,3d 1d arrays ...so year ..logically you could solve that ..
But this is not a very intuitive way to solve it despite it being the optimal solution ..I would rather go ...slicing the array horizontally ..
then ..doing the same till I find my row where my element is at ..once i find it ..I could iterate over that row ...through the columbns 
but given it is in ascenmding order ..I would just use a simple binary search ..
TOO EASY LETS GET CODING 



*/




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



bool BS(vector<vector<int>> &v,int row,int target){
    int i=0;
    int j=v[0].size()-1;
    int mid;
    while(i<=j){
        mid=(i+j)/2;

        if(v[row][mid]==target)
            return true;
        else if(target>v[row][mid])
            i=mid+1;
        else
            j=mid-1;


    }
    return false;



}




bool SearchingInMatrix(vector<vector<int>> &v,int target){
    int top_row=0;
    int bottom_row=v.size()-1;
    int cols=v[0].size()-1;
    int mid;
    while(top_row<=bottom_row){
        mid=(top_row+bottom_row)/2;
        if(target>v[mid][cols]){  //you don't have to put the first condition but it there just fpr logic building
            top_row=mid+1;
        }
        else if(target<v[mid][0]){
            bottom_row=mid-1;
        }
        else{
            return BS(v,mid,target);
        }
    }
    return false;

}




int main(){
    vector<vector<int>> v={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=13;

    cout<<SearchingInMatrix(v,target);

}