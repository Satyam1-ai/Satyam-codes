/*WE ARE INTRODUCED TO SOME BITWISE operators ...namely ..& , | and XOR ..XOR probably is the most handy ..in most cases ..
This question is your simple power of 2 ..Really elementary 10 th grade stuff..Normally you wold just divide by 2 ..count all the occurances of 
1 in the remainader part ..If we find that ..the total count is 1 then ..well and good otherwise . it won't be the power of 2 ..as 
the ink about 16 ,8 ,4 ..they all only have 1  in them ..10000 ,1000 ,100 ..So yeah ..that is one method ..the other would be to use 
bitwise operator in the form of a for loop where for each rightmost bit we comapre it with 1 using ther & operator ..onCE WE DO THAT 
we just right shift it(move all element to teh right ..effectively removeing the right most bit )..now if we find a 1 anywhere in our 
operations before the n becomes 1 then it would be that ..the n had a 1 somewhere before ...wrong answer ...bt our terminatin  condiiton here becoe 
n==1 or break when you see n==1 and add that asa an if loop while returning ..if(n==1) meaning if the loop has run till n==1 only then will 
be return true ..otherwise ...the n has brooken out of the loop before that ..so ..NOT VALID THAT CASE ...

BT THERE IS SOMETHING EVEN SIMPLER IN THIS CASE ...WE COULD SIMPLY DO .a one liner here ...It would mean ....we check ..the numbver 
8 or 16 or 4 ....compare it wihth n-1 ... so 8 and 7 upon using the & operator on them ......so it would natutrally be 0. because you are subtracting 
1 ...from someting ..so only if the 1 being the right most bit  is also the left most bit will it satisfy this condition ..

*/







#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




bool findPowerofTwo(int n){
    return n>0 && (n & (n-1) )==0 ;    //On leetCode this might fail ...because 2^31 ...when it is a negetive number ..it wraps around 
                                        //When you do ..n-1 that is why you have convert to LL ..easiest way to do this ..is 
                                        //just do ..(1LL * n-1) ....
}


int main(){
    int n=16;
    findPowerofTwo(n);
}
