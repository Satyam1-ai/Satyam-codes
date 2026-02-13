



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <cmath>





int finding(std::vector<int> A,std::vector<int> B,int n,int k){
    int global_sum=0;
    int current_prefix=0;
    int max_till=0;
    for(int i=0;i<n;i++){
        if(i>=k)
            break;
        current_prefix=current_prefix+A[i];
        max_till=std::max(B[i],max_till);
        int current_sum=current_prefix+((k-(i+1))*max_till);

        global_sum=std::max(global_sum,current_sum);
    }

    return global_sum;
}








int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n,k;
        std::cin>>n;
        std::cin>>k;

        std::vector<int> A(n,0);
        std::vector<int> B(n,0);

        for(int i=0;i<n;i++){
            int x;
            std::cin>>x;
            A[i]=x;
        }   


        for(int i=0;i<n;i++){
            int x;
            std::cin>>x;
            B[i]=x;
        }
    
        std::cout<<finding(A,B,n,k)<<"\n";
    }



}