

/*
    Hamming distance is the difference in the bits between 2 numbers .here we have got 2 numbers ...whose bits are differnet ofcours 
    we are essentially finding how many bits are differnt in the two numbers ..very pattern based ..Use the XOR operator ..
    Once you do the XOR operator whichh output ..1^0 (differnec in the bits) we get ..1...so wherever we find the differnece we can put 1 
    Now counting all the 1s...this is fairly straight forward ..Simply keep updating the cnt ....while snipping the rightmost set bit 
    using the equation ....a & (a-1)

*/




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




int hammingDistance(int a,int b){

    long long temp=a^b;
    int cnt=0;
    while(temp>0){
        temp=temp & (1LL*(temp-1));
    }
    return cnt;

}


int main(){
    int a=15;
    int b=20;
    hammingDistance(a,b);



}