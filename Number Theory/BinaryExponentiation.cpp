/*
    Here we are introduced to ....Binary Exponentiation Asimple way to solve a big exponent probelme ..imagine we have something like ...
    a^n ...which is ...4^16 ..lets assume ..Here the exponentiation refers to dividing this proble intp smaller smaller parts 
    So 4^16 will be (4^2)^8 which is (4^2)^2) ^4 which is (4^2^2^2) ^2 ....followed by ...(4^2^2^2^2) ^ 1 ...
    effectively we are squaring constantly ....and reducing the exponent ..a^n is literaly (a^(n/2)*2)..if even if odd .
    Simply a*(a^(n-1/2)*2)....so we are simply squaring the base .....till we find some odd exponent ...which we then use ...to record the value 
    


*/






#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




int BinaryExponentiation(int base,int exponent){
    int result=1;
    while(exponent>0)
    {
        if(exponent%2!=0){
            result=result*base;
            exponent=exponent-1;
        }

        base=base*base;
        exponent=exponent/2;
    }

    return result;


}





int main(){ 
    int base=2;
    int exponent=12;
    cout<<BinaryExponentiation(base,exponent);




}
