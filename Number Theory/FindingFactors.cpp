/*
    A very fundamental concept in Number Theory where we have to find ..the number of factors for the number .
    so 12 will be  2,2,3 
    18 will be 3,3,2
    you could ofcourse loop around ..the n ..to find it ..so 1..n and then you find the things that divide the number ...but it would 
    be too taxing on the computer ..Better to avoid it ...Instead what we could do is ...
    reduce the n ..now think about it ...81 is 9*9 ..Its factors will be everythign ..from 1 to 9 including 9 ..doing it 2 times will be a arepeatation 
    so we might aswell do it till root n .
    now 1 is auomatically a factor ..no need of considering it ....so 2 till root n ..But we can further optimize it 
    imagine ...a number like 16 which is divisible by 2 ..if we keep dividing it by 2 consistantly we reach a prime pr a number whcih cannot be 
    divisivle by 2 ..which would also meman that it is an odd number ...so instead of iterating theough all the numbers 
    we are reducing our search by half ..we simply check the divisor +2 .. ...
    so first /2 ..till you can't ..then do it with other numbers ..3,5,7 ..till root n 






*/





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;






vector<int> findFactors(int x){ 
    vector<int> v;
    while(x%2==0){
        v.push_back(2);
        x=x/2;
    }

    for(int i=3;i*i<=x;i=i+2){
        while(x%i==0){
            v.push_back(i);
            x=x/i;
        }
    }

    if(x>1){
        v.push_back(x);
    }

    return v;


}




int main(){
    int x=12;
    vector<int> v; 
    v=findFactors(x);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

