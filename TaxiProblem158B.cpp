/*
YOu are given a question where ...you have to find the minimum number of Taxis ...needed to transport a group of friends given by n 
where each i is the number of friends in the circle ...so we can try differnt approaches ..because it is minimum ..we could try sorting 
and then greedy ...so essentially we are sorting  iin decreasing order ..then taking ...the max ..number ..like 4 in one taxi. ...
then 3 in another ...tthen another 3 in anouter taxi ...and then group some 1s or 2s ....and so on ..However the constraint mentioned in the 
question states that  we have to group all the ppl from one group into 1 taxi ...so 1s could potentially pair with the 3s..This would 
make our count go really low ..especially because we are asked to find the minimum taxis needed ..
SO CANT USE THIS APPPROACH ....CAN'T USE BITWISE LOGIC ASWELL .AS NO POWER OF 2 OR HALF OR DOOUBLE MENTIONED ANYWHERE 
But think about it ....we could try to use ...thingk about this way ...where 4 being the maximum limit ...so all 4s can be grouped togehter 
and should have their own taxis ....when it comes to 3 ...we have ...all 3s grouped together ...four 3s would mean ..4 taxis with 1 empty seat in 
each of them ..we cannot include 2 becauuse the 2s can't be split according to the question constraints ...
So instead we do it with 1s ..now ...we have to count the number of 1s .....if the number of 1s is greater thna tha number of ...3s then we 
simplu take alll the 1s we can ..whic is equal to the number of 3s .....then the same for 2s ...if the 2s ocunt ends in lets say ...
14 ..or 18 which are not devisible by 4 ....we have space for ...2 more ...which we can build based on  count of 1s ..we can accomoadte 2 ones
if we have 2 ones...or only 1 one remaining ..we simply take it and incremenet the count of the taxis ..

if you have remainig at the end ..group them till capacity and send ..

EASY ...Very intuitive ...But very logical aswwell. Great question 




ACTUALLY I DID IMPLEMENT IT AGAIN AFTER 3 YEARS OF NOT SEEING IT ..IT IS A PAIN IN THE ARSE IN TERMS OF EDGE CASES
GOOG LUCK THOUGH..





*/





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int upperCount(int x,int y){
    return (x+y-1)/y;
}



int TaxiProblem(vector<int> &nums){
    unordered_map<int,int> frequency;
    for(int i=0;i<nums.size();i++){
        frequency[nums[i]]++;
    }

    int taxi_count=0;
    taxi_count+=frequency[4];
    taxi_count+=frequency[3];
    frequency[1]=max(0,frequency[1]-frequency[3]);

    int temp=upperCount(frequency[2],2);
    taxi_count+=temp;
    if(frequency[2]%2!=0){
        frequency[1]-=2;
    }

    taxi_count+=upperCount(frequency[1],4);


    return taxi_count;




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

    cout<<TaxiProblem(nums);




}