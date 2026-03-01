/*
Okay okay ...Everyone ...come back ...We are having a retrial ...
...First things first ............we have an array ....we have to figure out how to arrrange it based on the equation ....abs(a1-a2)<=abs(a2-a3)
So the absolute diffenrcve ....between the 2 array elements  must be lower than the ...adjacant pair ...and i would go on ..
....
to do this we have to ensure that the gaps between the ....two elemments in the array ....are at the ...highest ...
..simple sort ought to the trick ,,...then pickthe first and the last element ....and move inward .....save the  pairs in a  ..
array ...

*/



#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>





void WeirdSorting(std::vector<int> &v,int n){
    std::sort(v.begin(),v.end());
    int i=0;
    int j=n-1;

    std::vector<int> temp;
    while(i<=j){
        if(i==j){
            temp.push_back(v[i]);
            break;
        }
        temp.push_back(v[i]);
        temp.push_back(v[j]);
        i++;
        j--;
    }


    std::reverse(temp.begin(),temp.end());

    for(int i=0;i<n;i++){
        std::cout<<temp[i]<<" ";
    }


}









int main(){

    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            std::cin>>x;
            v.push_back(x);
        }
        WeirdSorting(v,n);
        std::cout<<"\n";
    }
}