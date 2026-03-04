/*
..We have a dude who wants to invirte ...a bunch of his friends ...for his party ..But his friends are dipshits ...who seem to be haing 
insecuritires ergo jealously ..Now he cannot invite all of them ...so naturally he will only have to pick a few ...
Now each friend is assosisated with a particular friendship value not market by money .....So basicallly a poor guy could be the best friend
hence he will have the highest value attacjhed ..
Easy shit ...

Now how do we take in the values ..Simple ...we use pairs..........to take int he values ......store them in a vector ..
Now we could sort them in ascening or descending ..order ..Both work ...For the money ofcourse ...not the ...friendship value ..
Once you have done that ....you can simply .....check ...which one gives the max friendship value ......NOw you could do it using ....2 pointer 
or simply brute force .....but they would both be giving you a n^2 complexity ..If you wanna avoid all that ..simply do ...
..
Sliding windows .....wehre each and every ..windows ...will encompass ...just the cumulaltive friendship values ...Then you have something like 
...0 till ...4 lets say ...and then we move ..to 1 ...so we could delete the 0th value ..and then add the next ...creating a linear type 
window .......
..
Voila ..just figure out the max out of all those and you have ..the answer ...Easy shit ...Lets goooo 








*/


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>




long long findMax(std::vector<std::pair<long long,long long>> &v,long long n,long long d){
    std::sort(v.rbegin(),v.rend());
    int i=0;
    int j=0;
    long long cumm_sum=0;
    long long maxi=0;
    while(j<n){
        cumm_sum+=v[j].second;
        while(v[i].first-v[j].first>=d){
            cumm_sum=cumm_sum-v[i].second;
            i++;
        }
        j++;
        maxi=std::max(maxi,cumm_sum);

    }

    return maxi;
}




int main(){
    
    long long n;
    long long d;
    std::cin>>n>>d;
    std::vector<std::pair<long long,long long>> v;
    for(int i=0;i<n;i++){
        long long x;
        long long y;
        std::cin>>x>>y;
        v.push_back({x,y});



    }

    std::cout<<findMax(v,n,d);
}

