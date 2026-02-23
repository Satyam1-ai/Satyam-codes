/*
Simple Linear Algebra ...based couting problme ....you have to simply substitute..
You are given ....total as 100 ..Spanish lets assume ..s , french as 2s ..Not porn genres ofcourse ..
f-both + s-both +N=100

then you have .....2s-2 both+N=100 
both = 3 N.....So 3S-2N=100 
3s=100+2N...
now ....n has to be such that ....s is even ...even +odd is odd ...even +even is even ..lets assume ...the ,..even to be 
......3s=100+ 2N ....
So we could have ...N values as .......1 till ....9 ..but ....wd could have having it suc that it is divisible by ...3 ..becasue that is important 



*/





#include <iostream>
#include <vector>
#include <unordered_map>



int main(){
    int index;
    for(int n=2;n<10;n=n+2){//The n will always be ...even as both are ...even 
        long long s=(100+(2*n));
        if(s%3==0){
            index=n;
            break;
        }
    }

    int s=(100+(2*index))/(3);
    std::cout<<s;




}

