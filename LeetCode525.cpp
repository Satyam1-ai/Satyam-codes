/*
We are introduced to a classic interview style question....where you have ..a subarray of binary numbers ...and you have to find th e
maximum out of them such that ..the number of 0s and 1s will be identical....
So very understandable that you can't use sliding windows ..becasue you can't form a window without including ....non constraint characters 
like no equal number of ..0s and 1s ...even if you do find ..you have to think about shrinking them ..which is another hassle by itself 
...so yeah ...if its subarray .I feel the most options you have are with sliding windows ,prefix sum and 2 pointer approach ..
Here i THINK we can use prefix sum which actually works ...
So logic is that ...when you have a sum as ...8 at one point and a sum as 8 at another point ..you can simply assume that ..all the elements in the 
middle cancel out with each other ..now .it could have non -uniformity ...but ..here in this case ..we should be having a uniform distribution of 
numbers becasue the probability to get each number is exactly 1/2 ...

so we know that ....if there are 10 number between 2 identical sums and there are only 2 numbers to choose from ..they have to cancel out 
and be equal ...but the comliment of each other..so 1 become -1 ..2 becomes -2 ....since we cna only choose 1....we having to makee is -1 
bt we have 0 ..we could just assign -1 to all the zeros ..
DONT DO IT USING A SEPARATE LOOP ..Just do it on the go ...really easy ....

*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




int SubarrayEquals(vector<int> &v){
    unordered_map<int ,int> map;
    map[0]=-1;//Because initilaly we have a sum of 0 ..which is effectivey unattaiable at the start 
                //because our 0 becomes -1 ....and 1 stays 1 ...1..
    int sum=0;
    int length=0;
    for(int i=0;i<v.size();i++){
        sum+=(v[i]==0 ? -1 : 1);

        if(map.count(sum)){
            int temp=i-map[sum];
            length=max(length,temp);
        }
        else
            map[sum]=i;
    }
    return length;
}




int main(){
    vector<int> v={1,0,1,0,1,0,1};
    cout<<SubarrayEquals(v);
}