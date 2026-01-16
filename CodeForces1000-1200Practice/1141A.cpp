/*
A CLASSIC PROBLEM ..INVOLVING ..2S AND 3S ...VERY SIMILAR TO A QUESTION THAT INVOLVED DIVIDING BY 6 ..AND MATCHING THE 2S AND 3S
Here we have to see ..if a particular number can be divided by another number ...ie see if we multiply 2 and 3 with that smaller number ..
can we get to the required number ..
Simple logic ..if x/y and y is a factor of x then we can simply divide them ..like 39/13 is 3 ..so multuiplying 3 gets us the result

Easy Ass ..
smae concept ...if the quotient is a multiple of 3 and 2 only ..then we can say ..it is possible to reach that number 
So yeah ..find the quotient see if we can reach that quotient with 2 or 3 ...count them and voila ..those many number of moves needed

*/






#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




int FindFactors(int x){
    if(x==1)
        return 0;
    vector<int> nums;
    while(x%2==0){
        nums.push_back(2);
        x=x/2;
    }
    while(x%3==0){
        nums.push_back(3);
        x=x/3;
    }
    if(x!=1)
        return -1;
    else{
        return nums.size();
    }
}






int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;

    if(m%n!=0 || n>m){
        cout<<-1;
    }
    else{
        int x=m/n;
        int value=FindFactors(x);
        if(value!=-1)
            cout<<value;
        else
            cout<<-1;
    }
    return 0;

}