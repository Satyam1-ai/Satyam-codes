/*
Um ..i made this a bit complicated ...dunno why ..Pretty late at ight ...probably becasue of that ..
But yeah ..take   prefix sum ..suffix sum ..for each prefix sum perform Binary Search ....to ...check if the same sum is present as 
a suffix sum ..if yes ..then simply ...pass that index on ...that indicates how much ...rob ate from the rigth ..
alice's count is simply i ...so add theie counts ...you have ...total count ...using a maxi variable that ..keeps track of 
the maximum such counts ..So effectively it becomes realy esy ..Though you could have used 2 pointer which is significantly more easier to
implement ...simply 2 pointers front and back ...Each pointer moves when theh cumm_sum from theri respective side .shows it is lagging in the sum 
when you find an exact match ..simply ...store it ..find the max out of all this ...
Easy 
*/







#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>


int BinarySearch(std::vector<int> &A,int start ,int end,int target){
    int i=start;
    int j=end;
    while(i<=j){
        int mid=(i+j)/2;
        if(A[mid]==target)
            return mid;
        if(target>A[mid]){
            j=mid-1;
        }
        else
            i=mid+1;
    
    }
    return -1;
}






int findCount(std::vector<int> &v,int n){
    std::vector<int> prefix(n,0);
    std::vector<int> suffix(n,0);
    prefix[0]=v[0];
    suffix[0]=v[n-1];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+v[i];
        suffix[i]=suffix[i-1]+v[n-1-i];
    }
    sort(suffix.rbegin(),suffix.rend());
    int maxcount=0;
    for(int i=0;i<n;i++){
        int alice_count=i;
        int x=BinarySearch(suffix,i+1,n-1,prefix[i]);
        if(x!=-1){
            int rob_count=n-x;
            maxcount=std::max(maxcount,rob_count+alice_count+1);
        }
    }
    return maxcount;


}





int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::vector<int> w;
        for(int i=0;i<n;i++){
            int x;
            std::cin>>x;
            w.push_back(x);
        }

        std::cout<<findCount(w,n)<<std::endl;



    }





}