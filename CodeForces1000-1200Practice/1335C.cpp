/*
not another .....pairing question ...quite basic ...simply arrange things according to the frequency array ...nnd see if you can make 
equal pairs 



So min(group1,group2).....keep a disctinct elemts ..list as n-1 ...and for each ..frequecny match it ...
So if you have...3 repeated 4 times ...in a list likje {1,1,1,2,2,3,3,3} ....
freq array :: 1->3 , 2->2 3->3 
so ...n-1 will be the max ....disctinct ...with respct to 1 other element ..you simply ..take that count ...compare with highest frequcny 
of elemnt like 3 ...so min(3,2)...you get 2 ...if the "remianing elemnts are 0" ..then ans will be 1 ..



*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>




int findPair(std::vector<int> &A,int n){
    int maxi=INT_MIN;
    int index=-1;
    std::unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[A[i]]++;
        maxi=std::max(maxi,map[A[i]]);
        if(maxi==map[A[i]])
            index=i;

    }

    int unique_elements=map.size();
    return std::max(std::min(unique_elements-1,maxi),std::min(unique_elements,maxi-1));

}







int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            std::cin>>x;
            A.push_back(x);
        }
        std::cout<<findPair(A,n)<<"\n";
    }


}