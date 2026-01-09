/*
Usually for prime numbers ...we could use our good our tradional method where we check till root n ...following that we can simply 
add the stuff to an vector ...but the problem with this metho is that ..we consistantly have to check ..certain things. ..
that are repeated again and agaain ...like common factors ...which makes it supercumbersome ..

THat is why some greek dude invented the sieve of Erasthonesis ...this greatly helps in cp when you see latger constraints like 10 ^7
if its greater then there is another algorithm which i will explain later ..
Here lets focus on this method ..basically when you have a number ....you create an array that will store all the numbers from 0 till 
n ..initliaze to true(we assume that the thing will have all true values because initally we assume all are prime) ..Following that 
we can do ...some eliminations ..start at 2 ...keep that true ...put all the multiples of true as false..Then move to the next number which is 
3 ..do the same ..if the index has a false..just skip it ..keep doing this till root n(i**2 <n condition)....and voila ..you have an arrya 
full of prime numbers ie which are labeled true ....
*/






#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;





vector<bool> SieveofEr(int n){
    vector<bool> A(n+1,true);
    A[0]=false;
    A[1]=false;
    int i=2;
    while(i*i<=n){
        int j=2;
        int temp=i*j;
        while(temp<=n){
            A[temp]=false;
            j++;
            temp=i*j;
        }
        i++;
    }
    return A;

}












int main(){

    int n=12;
    vector<bool> A=SieveofEr(n);
    for(int i=2;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;



}




