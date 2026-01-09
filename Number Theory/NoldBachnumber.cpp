/*
Here we encounter a problem that is rather very straightforward ..Only rated 1000 on codeforces uses simple math ..
Here ...
we have the norlbach problem a derivative of the goldbach problem ..A person makes a proposition saying ...2 prime numbers ...
added wih the number 1 will make a prime number  namely the norlbach number 
Quite intuitive and really basic number theory ...
NOW ...we know that an even number can be thought of as the sum of 2 primes
so 2 primes +1 will always be odd .
naturally the norlbach number has to be odd 

now the constraint specifies that the primes have to be adjacant ...to get n-1(even number)...so we simply add 1 
GET those odd primes .........now checking the condition ..you could simply create a loop ..check a1 with a2 and a3 ...if they form a 
proper sequence or not ...
But we are programmers not tool users like the full stack or devops ppl ....

To optimize this we can create ....something like ..take the average of the two numbers *2 +1 to see if it maps to he third number 
because the mid point of 2 primes is their average or middle or whatever you wanna call it ..and if you do ..(nordbach nnumber-1)/2 
you get that number,the average ..if they match you can take it  ...Too easy...




NOW LETS GET CODING




*/










#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



vector<int> generatePrimes(int n){
    vector<int> A;
    A.push_back(2);
    for(int i=3;i<=n;i=i+2){
        int flag=0;
        for(int j=3;j*j<=i;j=j+2){
            if(i%j==0)
                flag=1;
        }
        if(flag==0)
            A.push_back(i);
    }
    return A;
}


int Nordbach(int n){
    vector<int> odd_primes=generatePrimes(n);
    int cnt=0;
    for(int i=2;i<odd_primes.size();i++){
        int temp=odd_primes[i-1]+odd_primes[i-2];
        if(temp/2==((odd_primes[i])-1)/2){
            cnt++;
        }
    }
    return cnt;







}


int main(){
    int n;

    vector<int> A=generatePrimes(12);

    //NOW JUST CALL IT WITH THE TEST CASES ...

}