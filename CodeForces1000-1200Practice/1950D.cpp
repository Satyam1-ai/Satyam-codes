/*
VERY 1200 LIKE BRUTE FORCE PROBLEM .you have a number x ..whose product is known .it should be binary decimals ..WHich means they could be 
1,10,110,101..basically every binary orientation till the limit ..but base 10 ..
now we have to try out differnet variations .....till the limit ..if something divides x ..then we have to check if that number canbe divided 
by our numbers ...should check till it goes till 1 ..

So many recursions have to checked ..Just use boolean DP array for optimisation ..regarding finding all the number ..you could simply use ..
[10,11] and append combiantions or you could simply hardcode all of them ..
*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <cmath>



std::map<int, bool> mem;

void Rec(std::vector<int> &Factors,int x){
    if(x>100000){
        return;
    }
    Factors.push_back(x);
    Rec(Factors,x*10);
    Rec(Factors,x*10+1);
    return ;
}


std::vector<int> FindFactors(){
    std::vector<int> Factors;
    Rec(Factors,11);
    Rec(Factors,10);

    return Factors;



}


bool answer(std::vector<int> &A,int n){
    if(n==1)
        return true;
    if(mem.count(n))
        return mem[n];

    if(n<0)
        return false;

    bool flag=false;
    for(int i=0;i<A.size();i++){
        int y=A[i];
        if(n%y==0){
            bool x=answer(A,n/y);
            if(x==true)
                return mem[n]=true;
        }
    }
    return mem[n]=false;


}


int main(){

    std::vector<int> A=FindFactors();
    
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        bool ans=answer(A,n);
        if(ans==1)
            std::cout<<"YES";
        else
            std::cout<<"NO";
        std::cout<<std::endl;

    }



}



