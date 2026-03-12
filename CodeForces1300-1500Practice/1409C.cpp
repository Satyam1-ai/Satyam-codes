/*
    We are given an array ...arranged in arithmetic progression....if sorted ...We know ...2 elements of that list ...x and y such that ..
    y>x ...
    ..we are to reinvent the list again ....So yeah ...lets think about AP for now ..inital element is always ..
    a0 ...the difference is d ..any element in there would be of the form ..a0+xd ......now 
    put the x as ..a0+pd ....and y as a0+qd .....
    now picture this being ...y-x ...you get ..d(q-p) ..where d is a divisor ...Easy stuff ...so now we know the difference 
    has to be a divisor .....now what will the d be ??
    all the divisors that ...divide ...(y-x)....
    ...Now we could brute force with each and every d ..see the combinations they make .......and see if it is lower than n ..
    becasue the n is only 50 ...so yeah ...we could do that 
    but there is an easier trick here ...
    you could have ...(y-x)/n+1 .....
    so if it can house ...n things inside of it ...great ..if it can't then ....we won't consider it ..this works becasue the 
    worst case scenario would be to simply ...
    having ..x and y ..as first and last numbers ..

*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>




std::vector<int> findFactor(int x){
    std::vector<int> temp;

    for(int i=1;i<=x;i++){
        if(x%i==0){
            temp.push_back(i);
        }
    }

    return temp;
}


void printt(std::vector<int> &l){
    for(int i=0;i<l.size();i++){
        std::cout<<l[i]<<" ";
    }
    std::cout<<"\n";
}

void listing(int y,int x,int n){
    int diff=y-x;
    
    std::vector<int> p=findFactor(diff);
    int i;
    int d;
    for(i=0;i<p.size();i++){
        if((diff/p[i])+1<=n){
            d=p[i];
            break;
        }
    }

    std::vector<int> l;
    int temp=y;
    while(temp>0 && l.size()<n){
        l.push_back(temp);
        temp=temp-d;
    }

    temp=y+d;
    while(l.size()<n){
        l.push_back(temp);
        temp+=d;
    }


    printt(l);
}

int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n,x,y;
        std::cin>>n>>x>>y;
        listing(y,x,n);
    }

}