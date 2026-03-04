/*
Very pattern based constructive ......graph based question ....you have ...A,B,C ...given which are essentially ...a set of nodes ..wehre ..
A reaches C without ....going through B ...so B effectively cannot act like ....a middle man ...
Now here we try to ....make sure ..thst the ...
middle elements ..are not touched ...
the easiest possible way to do this ..will be .........to create a fake center ...Then you add ....all the ..A - C via the center ..
now ...we know all the middle elements ...At the end ..simply ..swap ..the ...center with one ...nuber which isn;t part of tgeh 
middle B elements ..now this only works becasue the ...n>m..if it were not ...then ...we couldn't have done this ..
So basically a wee trick in the question ..


*/







#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>



void Printt(std::vector<bool> &v,int n,int m){
    int index=-1;
    for(int i=1;i<=n;i++){
        if(v[i]!=true){
            index=i;
            break;
        }
    }

    for(int i=1;i<=n;i++){
        if(i!=index){
            std::cout<<i<<" "<<index<<"\n";
        }
    }

}


int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        int m;
        std::cin>>n>>m;
        std::vector<bool> v(n+1,false);
        for(int i=0;i<m;i++){
            int x,y,z;
            std::cin>>x>>y>>z;
            v[y]=true;
        }

        Printt(v,n,m);
        std::cout<<"\n";

    }



}