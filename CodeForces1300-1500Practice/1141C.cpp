/*
    Reverse Permutations ....an important concept in the domain of ...pattern recognition ..You usually have a ....condition ..which detertmines 
    the original permutation ..you have use that system of equations ...to figure out the problem ..
    In this question you have ..the condition as ....array q-> pi+pi+1 ....now you have ...p2=p1+p2...
    now you could solve this as a system of equations ...but it would take you a lot of time ..and effort ..because ...the complexity 
    will go really high ...
    or think about this beautiful idea ...simply ...consider the ..p1 to be 0...Once you get that ..out ..
    the p2 can be ..0+q1 which is q1 ..then your ..p3 ..can be ...q2





*/










#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>





std::vector<int> restore(std::vector<int> &q,int n){
    std::vector<int> p(n,0);
    p[0]=0;
    for(int i=1;i<n;i++){
        p[i]=q[i-1]+p[i-1];
    }
    int mini=INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++){
        if(mini>p[i]){
            mini=p[i];
            index=i;
        }
    }
    int offset=1-p[index];
    for(int i=0;i<n;i++){
        p[i]=p[i]+offset; 
        if(p[i]>(n))
            return {};
    }
    std::vector<int> check = p;
    std::sort(check.begin(), check.end());

    for(int i = 0; i < n; i++){
        if(check[i] != i + 1) { 
            return {}; 
        }
    }

    return p;

}




int main(){
    int n;
    std::cin>>n;
    std::vector<int> q;
    for(int i=0;i<n-1;i++){
        int x;
        std::cin>>x;
        q.push_back(x);
    }
    std::vector<int> p=restore(q,n);
    if(p.empty()){
        std::cout<<-1;
    }
    else{
        for(int i=0;i<n;i++){
            std::cout<<p[i]<<" ";
        }
    }
}