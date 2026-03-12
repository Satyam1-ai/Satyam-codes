/*
    Okay ...tell me what Prime Numbers are....you've got ....primes as ...some numbers thart are not ....part of the ..odd*odd set ..
    which is based on teh ...2p+1 * (2q+1) ..formular fro the sundarum sieve theorem ....then you have another definition where 
    its not composite meaing the only 2 divisors being ........1 and the number itself ..
    So if i have ...a number like x which is prime and i EXPRESS it as ....x*y ..then the lower would have to ...be ...1 ..
    and the higher would have to be thenumber itslelf ..that is the sole condition ...This question effectively dictates .....
    me doing the same thing ....i have ...a number like ...a^2-b^2 .....which is my difference in the sqaure ..
    i see hte constraint ...10^11 .....and squared would mean .....10^22 ....which is simply too ..high ......for the coputer to store using 
    the existing ..data types ...
    long long is good like 18 ...that is why we have to crafty about this ....whe you see something like ..a^2 -b ^2 ...immeediately 
    you have to be thingking ..(a+b)(a-b)......


    


*/



#include <iostream>
#include <vector>
#include <unordered_map>


bool trial_division(long long n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}



bool figure(long long a,long long b){
    long long temp=(a+b)*(a-b);

    if((a-b)!=1)
        return false;
    else{
        return trial_division(a+b);
    }

}




int main(){
    int t;
    std::cin>>t;
    while(t--){
        long long a,b;
        std::cin>>a>>b;
        bool x=figure(a,b);
        if(x==1)
            std::cout<<"YES";
        else
            std::cout<<"NO";
        std::cout<<"\n";
    }

}