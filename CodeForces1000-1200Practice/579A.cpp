/*
RAISING BACTERIA ....INTERESTING QUESTION ..you have to .get to a certain .....numbe of bacteria ...given ..you can 
have 1 bacteria multiplyimg all the time ....you could start with 100+ bacteria or just 1 bactierail ...give me as many days as you want 
it should amount to exactly what the input is ...

Could we reach that ??


Quite easy to do it ...think about how 1 multiplies (in cf when you see stuff like doubling or multiplying ...or even anything by 2 alwasy 
consider Bitwise operations)

So simply check the length of the binary of the given ...x ..wheere each decimal point will be denoting the days wehre the bacteria was put 
in 

*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
using namespace std;



int main(){
    int x;
    cin>>x;
    bitset<32> b(x);

    cout<<b.count();

}