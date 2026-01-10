/*
We are given a problem where we have to find k distinct numbers ...such that each one should contribute as a produt to the number ..

Now think about a number like ....20 ..whle finding the factor what do we do ...we keep dividing by primes .So /2 /2 /2 /2 till i can't anymore 
and 2 will be recorded as the factor(could be multuiple aswell ) ....the from whagt is left we simply ..divide by 3 ....then 5 ..then 7 then 
9(9 being a bit redundant becasue 9 is a composite so it must have 2 primes dividing it ..3 and 3) ..so we could use the 6k-1 trick 
But not needed for a 1100 rated problem ...no need of using sieve aswell...just simple loop .



So yeah ....so you will effectively have ...a1,a2,a3,a4 as prime factors....Now simply check if they are greater than k or not ..if no 
then -1 ..if YES then ....print till k-1 which is a(k-1)...and now to match the k ..count ..just multiply everything remaining and 
group them as one number .so you effectibely have k numbers ..

LETS GET CODING .....Will try to do ...another 20 questions today ..


*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



vector<int> findPrimes(int n){
    vector<int> Primes;
    while(n%2==0){
        Primes.push_back(2);
        n=n/2;
    }
    for(int i=3;i*i<=n;i=i+2){
        while(n%i==0){
            Primes.push_back(i);
            n=n/i;
        }
    }
    if(n>1){
        Primes.push_back(n);
    }

    return Primes;


}










int main(){

    int n,k;
    cin>>n>>k;


    vector<int> Primes=findPrimes(n);
    if(Primes.size()<k){
        cout<<-1;
    }
    else{
        for(int i=0;i<k-1;i++){
            cout<<Primes[i]<<" ";
        }
        int product=Primes[k-1];
        while(k<Primes.size()){
            product=product*Primes[k];
            k++;
        }
        cout<<product;
    }

    return 0;

}