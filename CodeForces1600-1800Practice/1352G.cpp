/*
Very easy question .....intuitively ..but the edge cases will kill you ...
Simple logic ..gather the odds ...together ..then the evens ...but you have to look out the the 2,4 condition ..
My logic was to simply loop ..back..till you find an "index" that will give you some value which is ..satisfying the 
condition ..<=4 ..but more than 2..once you;ve found that number ...just add it ..to the vector..and then ..start 
from the very end ..all of all evens ....go backwards till the first ...but make sure ......that you dont include the index again 
..The consition was very clever ...becasue ..this way its mathematically impossible ..to astray from it ..
Simple intuotove logic ..
    
*/



#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>





std::vector<int> permute(int n){
    if (n<4){
        return {};
    }
    if (n == 4) return {3, 1, 4, 2};
    std::vector<int> v; 
    int last_odd_number;
    for(int i=1;i<=n;i=i+2){
        v.push_back(i);
        last_odd_number=i;
    }
    int index;
    (n%2==0)?index=n:index=n-1;
    int max_even=index;
    while(index>=2 && !(abs(index-last_odd_number)>=2 && abs(index-last_odd_number)<=4)){
        index=index-2;
    }
    if(index<2)
        return {};
    v.push_back(index);

    for(int i=max_even;i>=2;i=i-2){
        if(i!=index){
            v.push_back(i);
        }
    }
    return v;

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
        std::vector<int> p=permute(n);
        if(p.empty()){
            std::cout<<-1<<"\n";
        }
        else{
            printt(p,n);
        }
    }
}