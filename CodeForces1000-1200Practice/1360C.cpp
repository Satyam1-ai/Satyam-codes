/*
Pretty intuitive ....Basic ..parity problem ..you have ..an array ..where you can group them together ..as pairs or atleast try to ..
To do so ..you simply .
Your objective figure out if the pairs exists ..according to certain conditon that they can be even/odd or ..their diff in value will be 
1 ..
So yeah ..simply chekc the oddcount or the even count ..if it is equal to ...a even number then YES ..because n is even ...so N- (odd_count is even)
wiull be even ..
Howeveer if it is odd cout ..you individually check each and every elemrnt ...better to sort it ..in any order ..
then from ther e..you simply ..check if absolute (A[i]-A[i-1]) is ..1 ...if yes then great .....
rememebr we only need to find one ..becasue ....the others can be grouped as ...odds .evens ..imagine even count is 7 ...6 can be grouped togerther 
same with the odds ...n-odd_even_count =odd_oddcount ..
At the end you will ahve ...one odd and one even left ..but it can be anything ...So you just fifugre out which one from the lot 
will be that ...
if you do find one where the diff is 1 ...VOILA ...YOU found the answer ...becasue others group by themselves ...

Happy coding ..






*/






#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>



int absolute_value(int x,int y){
    if(x>y){
        return (x-y);
    }
    else
        return (y-x);
}


bool checker(int x,int y){
    if(x%2==0){
        if(y%2==0)
            return true;
    }
    else{
        if(y%2!=0)
            return true;
    }
    return false;



}



bool printt(std::vector<int> &v,int n){
    int count_evens=0;
    for(int i=0;i<n;i++){
        if(v[i]%2==0)
            count_evens++;
    }   
    if(count_evens%2==0)
        return 1;
    else{
        std::sort(v.begin(),v.end());
        for(int i=1;i<n;i++){
            if(absolute_value(v[i],v[i-1])==1)
                return 1;
        }
    }

    return 0;






}








int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::vector<int> v(n,0);
        for(int i=0;i<n;i++){
            int x;
            std::cin>>x;
            v[i]=x;
        }
        if(printt(v,n)){
            std::cout<<"YES";
        }
        else 
            std::cout<<"NO";
        std::cout<<std::endl;
    }




}

