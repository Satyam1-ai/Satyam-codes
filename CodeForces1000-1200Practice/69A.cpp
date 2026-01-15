/*
Mkake the x coordinates as 0..y as 0 and the z as 0 ..



*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main(){
    int n;
    cin>>n;

    int total_x=0;
    int total_y=0;
    int total_z=0;
    while(n--){
        int x;
        int y;
        int z;
        cin>>x>>y>>z;
        total_x+=x;
        total_y+=y;
        total_z+=z;
    }

    if(total_x==0 && total_y==0 && total_z==0)
        cout<<"YES";
    else
        cout<<"NO";


    return 0;



}