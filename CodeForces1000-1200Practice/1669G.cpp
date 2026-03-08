
/*
We are given ...gravity ...in a 2d space where the ......obstacles are ..fixed onto some cells ..then we have some empty space aswell .in 
ADDITION to that ..we. have some ..stones ..which posses ...the abiltiy to fall down .,.,.
So we have to simply ..check ..how far the stones fall down ...if there are multiple stones ..then the ..lower stone ..will take the 
first available free space form the bottom ..
This calls ..for checking the free spaces from the bottom ...you could be having ..some ...obstacle and some ...prior stone ..etc ..
at the bottom on the ...column(as gravity appears to work in a particular colim only )..
so yeah ...when you start from the ...bottom ..you have look for the available ..space ...it will be the first free spot .
keep track of that ..but as you move up ...if you have .......hit an obstacle ..then ..you will have to  update your first free space 
to the one above the obstacle ..if you find a free one ....

And you have to figure out the final configuration of the grid after all these changes ..Easy ..
...



*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>



void finalConfiguration(std::vector<std::vector<char>> &v, int n, int m) {
    for (int i = 0; i < m; i++) {
        int available_row = n - 1; 
        for (int j = n - 1; j >= 0; j--) {
            if (v[j][i] == 'o') {
                available_row = j - 1;
            } 
            else if (v[j][i] == '*') {
                v[j][i] = '.'; 
                v[available_row][i] = '*'; 
                available_row--; 
            }
        }
    }
}



void printt(std::vector<std::vector<char>> &v,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cout<<v[i][j];
        }
        std::cout<<std::endl;
    }
}


int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n,m;
        std::cin>>n>>m;
        std::vector<std::vector<char>>v(n,std::vector<char> (m,'x'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char x;
                std::cin>>x;
                v[i][j]=x;
            }
        }
        finalConfiguration(v,n,m);
        printt(v,n,m);
        std::cout<<"\n";
    }



}