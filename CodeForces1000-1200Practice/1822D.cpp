/*
    Serioius toolkit building problme ...No way this was ....1200 rated....but ...if you know how to solve this ...then voila we can 
    get it ...
    So yeah ...Srs stuff to solve this ...we have to  mkae a unique mth observation ..that is ......See the ..n ...and the 
    bi ...which is simply ...a1+a2+a3+... ..now we know a ....n exists ...and n%n is 0 ......and in the b array it will be 1 ..
    Now every time we have an odd n ...and we  do ...n*(n+1)/2 ...........we always get a multiple of the n ...which would 
    make the value as 0 ....now ..shit ...its messed up .....cuz we got ....2 0s .....which won't work ...so odd n alreayd elminated..
    next for evens ....think about how ....bi =Si%n ....bi+1=Si+1 %n ...
    now these sums are simply ....so ..Bi+1 - Bi=ai+1 ....we know this ..and ..the A will be in a permutation so they cannoth repeat ..
    Now becasue they cannot repeat ...they have to be differenve ...so each ...Bi-Bi-1 ..should have a different ...value ..
    THis is importatn....there is soemthing called as a zig zag pattern ....Very cruical to learn it .....
    when you ..go from the 1 till the n ...you have n-1 slots ...when you go from ...n-1 to 2 ...you have ..n-2 slots ..
    when you go from ...2 to n-2 ...you have ...n-3 slots ..imagine ..a kid ...going from ...one end to another ..and comming back 
    to a spot further from where he started ..criss cross zig zag ...this ensures ...unique distances ...
    It is of the sequence ...1,n-1,2,n-2,3,n-3 .....0,n ...



*/






#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map> 
#include <cmath>




std::vector<int> finding(int n){
    if(n==1)
        return {1};
    if(n%2!=0)
        return {};

    std::vector<int> temp;
    int low=0;
    int high=n-1;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            temp.push_back(low++);
        }
        else{
            temp.push_back(high--);
        }
    }

    std::vector<int> A(n,0);
    A[0]=n;
    for(int i=1;i<n;i++){
        int diff=temp[i]-temp[i-1];
        int val=(diff % n + n) % n; 
        if (val==0)
            val=n; 
        A[i]=val;
    }
    return A;
    

}

void printt(std::vector<int> &p,int n){
    for(int i=0;i<n;i++){
        std::cout<<p[i]<<" ";
    }
    std::cout<<"\n";
}

int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::vector<int> p=finding(n);
        if(p.empty()){
            std::cout<<-1<<"\n";
        }
        else{
            printt(p,n);
        }

    }

}