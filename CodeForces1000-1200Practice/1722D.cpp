/*
You have to realizr that the optimal orientaltion ..is "RRRRRLLLLL" if we have ...10 ppl ....So our objective is to try and achioieve this 
kind of orientation ..To do ..you simply ...
See which all positions don;t have this ...orientation ...and try to bring it to this ...You could use 2 pointer technique 
if k==1 check from the ends ...see what matches and what does not ..if k==2 ..do the same ..but you have to keep track of what exacly you 
changed in the first attempt in an array ..and the pointers stay valid ..while you move to the next k ...
But this method would take ...0(n) space...and worst case n^2 ..because ..we would have to check for each ....and change ...not ideal 
Hence we could try to optimise it further
try to think of it as a distance thing ...if i flip any particular i from A ..array ..I could end up with ..a sum which is greater or lesser ...
So you simply find i is casusing how much change to the euqaiton ..based on that ..you could effectively end up  sorting the differnce and 
the person with the max_difference will get priortiy ..when k=1 ...when k=2 ...you simply add both ...when k=3 ..add all 3 ..along 
with the sum ofcourse ..this would make it nlog n for the sorting ...and k for the iteration ..much better than k n^2


*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map> 
#include <cmath>




void findMax(std::string &s,int n){
    long long sum=0;
    std::vector<long long> v;
    long long total_value=0;
    for(int i=0;i<n;i++){
        long long L_sees=i;
        long long R_sees=n-1-i;
        if(s[i]=='L'){
            total_value+=L_sees;
            if(L_sees<R_sees){
                v.push_back(R_sees-L_sees);
            }
        }
        else{
            total_value+=R_sees;
            if(R_sees<L_sees){
                v.push_back(L_sees-R_sees);
            }
        }
    }

    std::sort(v.rbegin(),v.rend());
    for(int i=0;i<n;i++){
        if(i<v.size()){
            total_value+=v[i];
        }
        std::cout<<total_value<<(i==n-1 ? "":" ");
    }
    std::cout<<std::endl;


}







int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::string s;
        std::cin>>s;
        findMax(s,n);
    }
}