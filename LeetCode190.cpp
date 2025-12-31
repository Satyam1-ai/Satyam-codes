
/*A new problem into the bitwise operators ..Really a handy tool on codeforces..but goota watch out for certain things like the sign bits 
you could use divide and conquer here after converting to binary ..but it would take too many artihmetic operatins ..isntead we can use the bitwise
operators ....in general I feel ... when you see a question where bits are mentioned ..then we will have to  treat them in such way ..

Now just to make sure we are working with 32 bit numbers ..make sure you update the given variable to a 32 bit unsigned format ..
Otherwise it might treat it differently...
so I have n as lets say ..26 ..which is ..11010 ....convert to unsigned int ..which is simply ..unsigned int x= n ..now you have a proper
unsigned 32 bit ...number .Now we have to reverse all the bits ..Simple reversing involces ..taking a the last bit ..putting it as the
first bit in another variable or vectotr ..bt a vector would just take up too much space .So we have to try to do it with ..
only ...32 ..bits which is essentially one interger variable (not lesser as 32 bits mentioned other we could use char and then concvertt to a 2 bit sort integer )
..SO YEAH ..take the last bit of the n ...simply n&1(returns 1 if rightbit i 1 or 0 if the right bit is 0) ..EXTRACTION PHASE DONE
then we move to the .. caoptures and storing phase ..we have alrady capturted our bit ..now ..simply store it somewhere else as the first bit 
to do so simply take a new variable ..namely  answer ...define its type as  unsigned ..
now ans=0 ;
ans can be left shifted to create a vaccum ..for the newly captured bit ..But yeah don;t forget to put answer as a gloabl variable 
and yeah ..d it till the n is not 0 or lesser than 0 ..either works .

and simply return the asnwer ..

BASIC SHIT ..HAPPY CODING

*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int Reverse_Bit(int n){
    unsigned int s=n;
    unsigned int ans=0;
    for(int i=0;i<32;i++){
        int temp=s&1;
        ans=ans<<1;//creating the vaccume as mentioned in the text above
        ans=ans|temp;
        s=s>>1;
    }
    return int(ans)


}






int main(){
    int n=19;

    Reverse_Bit(n);
}
