/*
    constructive  ...algorithm ..where you have...2 sequences ....one is strictly increasing ..while the other is striclty decreasoing ..
    We are given one array ......which is a mixed bag consisting of the ..elements from both the sequences ...both jumbled .
    We are to figure out .......if we can make ...a new series which is strictly increasing or strictly decreasing ...from the mixed bag ...
    it does not have to be th esame ...So yeah ..pretty ..easy ..sorting is obvious ..post that ..you could .go up up up ..
    till you find a duplicate if there is ...count the duplicates ...(or use a hash at the start to see if it is possible ) ..if ..2 duplicates 
    then ...YES ..possible ..becasue ...one could be part of the increasing sequnce and the other could be part of the decreasing sequence ..
    3 ...not possibile as it would break the ..."strictly " ...keyword ..definitely ..not advisable ..
    Not possible to do so ...
    once you've done ..that retireate ..and voila you have your sequences ..


*/








#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>



void finding(std::vector<int> &v,int n){
    std::unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[v[i]]++;
        if(map[v[i]]>2){
            std::cout<<"NO";
            return ;
        }
    }
    std::cout<<"YES"<<"\n";
    std::vector<int> increasing;
    std::vector<int> decreasing;
    std::sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(map[v[i]]!=2){
            increasing.push_back(v[i]);
        }
        else{
            increasing.push_back(v[i]);
            decreasing.push_back(v[i+1]);
            i++;
        }

    }

    std::reverse(decreasing.begin(),decreasing.end());

    std::cout<<increasing.size()<<"\n";
    for(int i=0;i<increasing.size();i++){
        std::cout<<increasing[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<decreasing.size()<<"\n";
    for(int i=0;i<decreasing.size();i++){
        std::cout<<decreasing[i]<<" ";
    }


}




int main(){

    int n;
    std::cin>>n;
    std::vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        v.push_back(x);
    }

    finding(v,n);


}