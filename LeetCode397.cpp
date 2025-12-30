/*
Really basic problem ..Dunno why they put it as medium difficult on LeetCode ..So you have a number n ....all yoou have to do it ....
count the ways you get from ..n to 1...and you are given some operations ..which you can perform ..
if even go n/2
if odd ...go n-1 or n+1 which essentially means you can move forward ...or abckkwards ..

now ....you are asked numbers of way to reach ..somewehre ..naturally you think of recursion ,dp ,or maybe you try to solve in in linear time 
you could you DP bottom up ...but the constraints are that the n might be too big ...so imagine our n is something like 2^31 ...we would have 
to fill the array  up entirely a+1 ...the space complexity would be huge ..So lets try top down approach ..
Here our normal recursion works because  if i encounter even then ...follow the condition follow the condition ..
If I were to use memoization same space contraints.. ,...
To solve it ..you have to be be consious with the datastructutre you use ..memoization involves creating a vector whcih is not sustainanble 
so we have to use a hashing array ....lets doo unordered_map for now ....this will solve our sppace complexity issue 


another thing which a alot of ppl dont tend to get right is that ...if you use int ..tehn when we do ..1+MAX_INT ....it will wrap around..
So we have to make sure that the ...we use long or long long ..lets just use long long ..


*/




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;





int Integer_Replacement(unordered_map<long long , int > &map,int n){
    long long k=n;
    if(map.count(k)){
        return map[k];
    }

    if(k%2==0)
        return map[k]=1+Integer_Replacement(map,k/2)];
    else{
        return map[k]=2+min(Integer_Replacement(map,(k-1)/2),Integer_Replacement(map,(k+1)/2));
    }





}






int main(){
    unordered_map<long long,int> map;
    map[1]=0;
    int n=15;
    Integer_Replacement(map,n);

}