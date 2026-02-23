/*
Intro counting ......we are given ...a 10 digit ...number where the product of the ...first and the last digit ..will be ....
even that gives us ....3 types /combiantions ....that is ......odd*even +odd*odd +even*odd  ...
In this case ..we simply ...do ...4 ---10 + 5-----5 ...so ...4*10*10^7
in addition to ...5*5*10^7 ...
or we could just do ocmplementary counting ....which is the standard way of doing this problem ..
*/




#include <iostream>
#include <vector>
#include <unordered_map>



int main(){
    int n=9;
    long long total=9LL*1000000000LL;
    long long odd_product=5LL*5LL*(10000000LL);
    long long ans=total-odd_product;
    std::cout<<ans<<"\n";
}