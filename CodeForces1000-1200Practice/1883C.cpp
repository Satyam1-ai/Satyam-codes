









#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map> 
#include <cmath>






int findDistance(std::vector<int> &A,int k){
    int min_distance=INT_MAX;
    int count=0;
    if(k!=4){
        for(int i=0;i<A.size();i++){
            min_distance=std::min((k-(A[i]%k))%k,min_distance);
        }
        return min_distance;

    }
    else{
        for(int i=0;i<A.size();i++){
            min_distance=std::min((k-(A[i]%k))%k,min_distance);
            if(A[i]%2==0)
                count++;
            
        }

    }
    int evens=(count>=2) ? 0:2-count;
    return std::min(min_distance,evens);



}




int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        int k;
        std::cin>>n>>k;
        std::vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            std::cin>>x;
            A.push_back(x);

        }
        std::cout<<findDistance(A,k)<<std::endl;



    }



}