/*
New Day ..New problem...Get some practice on the Bitwise oeprators ...so you are asked to find binary bits with the alternating  bits ./
So essentially 1010101010101 .....is valid ...now very intuitive ..this one ..just slide it over left or right EITHER IS okay ..
So imagine i HAVE 5 which is 1001 ...slide it over we get 10110 ..we xor them ...(if alt then they would all return 1.) ...now to check if
they are all 1 ..we have to simply & with the n+1 ...because n+1 will give you ..100000 as(11111+1 ) ...and performing & will return 0
EASY 




*/





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;








bool AlternateBits(int n){
    long long p=n>>1;
    long long temp=p^n; //Stores the  xor of the slide and the original number ..if yes then has to be stored as 1 
    temp=(temp & (1LL*(temp+1)));  //checks if it is 1 ...
    
    if(temp==0)
        return true;
    else 
        return false;


}


int main(){
    int n=10;
    AlternateBits(n);
} 