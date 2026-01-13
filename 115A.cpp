/*
With BFS ..It is quite an easy problem ...Just requires some insight into graphs ...Bt yeah ..really easy once you've learnt graphs and '
trees ..Here we simply use a for loop bottoms up .keep track of each and every ...node till you reach -1 which will act as your delimiter aswell 
EASY 






*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int maxDepth(vector<int> &nums){
    int max_group=0;
    for(int i=0;i<nums.size();i++){
        int depth=1;
        int manager=nums[i];
        while(manager!=-1){
            depth++;
            manager=nums[manager-1];
        }
        max_group=max(max_group,depth);
    }


    return max_group;

}




int main(){
    int n;
    cin>>n;
    vector<int> nums;
    while(n--){
        int x;
        cin>>x;
        nums.push_back(x);
    }

    cout<<maxDepth(nums);


}