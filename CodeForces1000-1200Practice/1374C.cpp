/*
A use of the 1,-1 notation to solve this. ....becasue we know the number of ( equals the number of ) ..We can discard one ( to the back or front 
knowing there will be a pair in the future ..we take ( as 1 and ) as -1 ...so we have something like ..((( ..it is 1+1+! ..and if we meet 
) .then 3-1=2 ...
 If we start with ..)) ...then -2 ..push all all at the back ..
 Find the cumm sum at the end ..it  would indicate the leftover '('



*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;






int Brackets(string &a,int n){
    int balance=0;
    for(int i=0;i<n;i++){
        if(a[i]=='(')
            balance++;
        else
            balance--;

        if(balance==-1){
            balance=0;
        }
    }

    return balance;


}








int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        cout<<Brackets(a,n)<<endl;
    }


    return 0;



}
