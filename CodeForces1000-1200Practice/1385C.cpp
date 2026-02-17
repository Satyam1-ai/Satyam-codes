/*
Bit of a peak finder problem ..very related to the MITOCW lecture .....where ..you had to calculate peak ..
We are given an array ...n elements ...ewehre we have to remove some eleements from the front ..such that ...the ..remaining elemnts form 
a goood array ..Now when you're given remove elemtns from the front or like ..prefix sum ..type things ...More often than 
not the question involces reverse iteration ..youstart from the back and see what works ...

Simple concept actually ...

Waht is a good array ??yOU COULd remove elements from the ..start and the end ...one by one ...to create a perfect 


increasing order array ....now this is possible in 3 cases ..the ...max is ..in the left ..so decreasing slope ..
max is on the  roght ...so increasing slope(remove from left ...till you reach max) ..then max is in the middle ..so ..mountain structure 

Now ...we could ...start removing elemtns frorm the ...front of our original array to figure out ...whhich works ...but .massive computation waste 
not good enoguh ,...you could start from the front ...see where the first peak is at ...if you find it ...look for the second peak 
and you have ..one variation ..but how will you know if its the longest ..wE CANNOT predict the future ........that is why we 
start from the back ...find the 2 peaks ..if there exists 2 ....and return the index ..
if only 1 peak is found then simply ...you would have to remove ...all or no elements ...depending on wherther the index is ..n-1 or 0 


*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>




int MinRemovals(std::vector<int> &A,int n){
    int i=n-1;
    for(;i>0;i--){
        if(A[i-1]<A[i]){
            break;
        }
    }
    for(;i>0;i--){
        if(A[i-1]>A[i]){
            break;
        }
    }

    return i;

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

        std::cout<<MinRemovals(A,n)<<"\n";
    }




}