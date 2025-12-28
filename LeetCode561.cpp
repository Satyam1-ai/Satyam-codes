/*Pretty Intuitive question honestly ..But dont look at the hints or anything wgile attempting ...Because the core logic is just intuition based 
I want you to think .....of numbers in general ...
Imagine you have ......something from ....10 to 100 ...I give you an option to pick a pair out of these ....Naturally you will have multiple pairs 
Inclding .....11,12.  or 200,300 .....Our job here is to figure how we arrange the pairs such that we get .....maximum out of all those ...
in {1,2,3,4,4} ..if we go for the first number then we can find that the numbereed pairs will always be one big ,one second big ..if we dont do this 
then we might loose the second big in one of the other iterations  ..Naturally ..we have to sort the array ..if we do ascending order then 
we have to iterate from the end ...We could save some running time complexity ..However ...We will just do ...Desending order ...Simplify the 
for loop a bit ....The pretty standard choose the i+1 ..element ..for each pair ...add and return */




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int ArrayPartitions(vector<int> &A,int n){
    sort(A.rbegin(),A.rend());
    int count=0;
    for(int i=0;i<n;i=i+2;){
        count+=A[i+1];
    }
    return count;
}



int main(){
    vector<int> A={3,4,1,8,9,4,2};
    return ArrayPartitions(A,n);
}