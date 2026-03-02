/*









*/




#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>




int Accomodation(std::string &s,int L,int k,int flag){
    if(L<=0)
        return 0;
    if(flag==0){
        return L/(k+1);
    }
    if(flag==1){
        if(L-(2*k))
        return (L-k)/(k+1);
    }
    if(flag==2){
        int n=s.size();
        return 1+(n-1)/(k+1);
    }

}





int Maxi(std::string s,int k){
    int n=s.size();
    int first_one=-1;

    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            first_one=i;
            break;
        }
    }

    if(first_one==-1){
        return Accomodation(s,n-1,k,2);
    }
    
    int total=0;

    total+=Accomodation(s,first_one,k,0);

    int prev_index=first_one;
    for (int j = first_one + 1; j < n; j++) {
        if (s[j] == '1') {
            int gap_len = j - prev_index - 1;
            total += Accomodation(s, gap_len, k, 1);
            prev_index = j;
        }
    }

    int last_one = n - 1 - prev_idex;
    total += Accomodation(s, last_one, k, 0);


    return total;

}






int main(){

    int t;
    std::cin>>t;
    std::cin>>k;
    while(t--){
        std::string s;
        std::cin>>s;
        std::cout<<Maxi(s,k);

    }

}