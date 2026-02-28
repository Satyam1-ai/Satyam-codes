/*
Simple Combinatrics problem  really ....here we are doing ..something like .....






*/





#include <iostream>
#include <vector>
#include <unordered_map>


int abs(int x,int y){
    int ans=x-y;
    if(ans>0)
        return ans;
    else
        return -ans;
}



int Combinations(int n,int r){

}







int findCombination(std::string s, std::string s2){
    int pluses_first=0;
    int minus_first=0;
    int pluses_second=0;
    int minus_second=0;
    int k=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+')
            pluses_first++;
        else
            minus_first++;
    }

    for(int i=0;i<s2.size();i++){
        if(s2[i]=='+')
            pluses_second++;
        else if(s2[i]=='-')
            minus_second++;
        else
            k++;
    }



    int target=pluses_first-minus_first;
    int current=pluses_second-minus_second;
    int d=target-current;

    


}









int main(){
    int t;





}