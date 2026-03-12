/*



*/






#include <iostream>
#include <vector>
#include <unordered_map>




std::vector<int> sieve(int n){
    

    std::vector<int> temp(n+1,1);
    temp[0]=0;
    temp[1]=0;

    for(int i=2;i<=n;i=i+2){
        if(i!=2){
            temp[i]=0;
        }
    }
    for(int i=3;i*i<=n;i++){
        if(temp[i]!=0){
            for(int j=i*i;j<=n;j=j+2*i){
                temp[j]=0;
            }
        }
    }

    return temp;


} 

void printt(std::vector<int> &p,int start){
    for(int i=100;i<p.size();i++){
        if(p[i]==1)
            std::cout<<i<<" ";
    }
    std::cout<<"\n";
}

int main(){
    std::vector<int> p=sieve(200);
    printt(p,100);




}