/*
JUST USE THE PREBUILT GCD FUNCTION ...THis is just when you can't use it ....Pretty easy ...



*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;





int findGCD(int x,int y){
    if(y==0)
        return x;
    return findGCD(y,x%y);

}




int main(){
    int x=14;
    int y=7;
    cout<<findGCD(x,y);
}