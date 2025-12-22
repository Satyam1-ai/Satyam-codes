//HARMONIC SUM is the cummulative difference between 2 numbers being equal to exactly 1 
//The main idea is that we take a hash array ..and each of the hash values are found by hashing the numbers/cahracter of a string 
//The idea of subsequence is not like subarray where the order matters 
//If it was  subarray we could have used Sliding Windows howver here we cannot use it 
//Since we know order does not matter ..we have 2 approaches we can use ..

//First one would be sorting and then sliding windows(till the condition of diffence = 1) is met
//Otherwise we don't do it ...We can simply use ...the Hash ..where we store each and every ..number along with their count 
//Followed by that is simple Math ...x+y=1 ;x-1=y



//HappyCoding

//author@Satyam1-ai




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int findLHS(vector<int>& nums){
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
    }
    int longest=0;
    for(auto i=map.begin();i!=map.end();i++){
        int x=i->first;
        if(map.count(x-1)){
            longest=max(longest,map[x]+map[x-1]);
        }
    }
    return longest;



}


int main(){
    vector<int> nums;
    
}
