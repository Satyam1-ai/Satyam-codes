
/*
    Easy tree construction ...Mostly an implementation based problem ...where we have ...to ...construct a tree ..based on numbers in an 
    array ...We have ..{} ...some elements given ....naturally we'd have a max element aswell ..Now using this ...max as root 
    we base our left and right ...recursively ...Will be using .Adjacancy list as usual ...

*/



#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>




int d[105];


void findDepth(std::vector<int> &A,int start,int end,int current_depth)
{

    if(end<start)
        return ;
    int maxi=A[start];
    int maxi_index=start;
    for(int i=start;i<=end;i++){
        maxi=std::max(maxi,A[i]);
        if(maxi==A[i])
            maxi_index=i;

    }

    d[maxi_index]=current_depth;

    findDepth(A,start,maxi_index-1,current_depth+1);
    findDepth(A,maxi_index+1,end,current_depth+1);

}





int main(){

    int t;
    std::cin>>t;
    while(t--){
        std::fill(d,d+105,0);
        int n;
        std::cin>>n;
        std::vector<int> A(n,0);
        for(int i=0;i<n;i++){
            std::cin>>A[i];
        }
        findDepth(A,0,n-1,0);
        
        for(int i=0;i<n;i++){
            std::cout<<d[i]<<(i==n-1 ? "": " ");
        }
        std::cout<<"\n";
    }


}