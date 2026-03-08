/*
Gate keeper ..question on the trees ...Very foundational ..based on recursion ..So we have something like the ...root node which is vertex `1 
as indicated by the qeusiton. ...now this is simply ...starting point ..
the question wants us to find a balance between all the ......Whites and the ..black ..starting from the ..root node for each and evry subtree
if my subtree has ....4 Black and 5 whites ....then my overall difference would be ....1 white ..so not balanced ..could effectively write it down 
as ..vertex X->NOT BALANCED ...and return the .......1 white ...to its parent which would recursiuvely check all the children
to figure out if the ..overall .....difference is ..0 or not ..
Once you find that ...then we could simply record that and moce to a higher branch ...
recurse recurse recurse ... EASY ..lets goooo mate ...

And ofcourse ...don't forget ..trees are always ...adjancy list more often then not ...in CP ..So yeah ...STOP USING NODES ..
IF YOU INTO THAT ...SHIT 




*/










#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>


int maxi=0;


int dfs(int u,std::vector<std::vector<int>> &T,std::vector<char> &color){
    int current_balance=(color[u]=='W'?-1:1);
    for(int i=0;i<T[u].size();i++){
        current_balance+=dfs(T[u][i],T,color);
    }

    (current_balance==0?maxi=maxi+1:maxi=maxi);
    return current_balance;

}



int findBalanced(std::vector<std::vector<int>> &T,std::vector<char> &color,int n,int visited){
    dfs(1,T,color);
    return maxi;
}

std::vector<std::vector<int>> create_tree(std::vector<int> &parent,int n){
    std::vector<std::vector<int>> T(n+1);
    for(int i=2;i<=n;i++){
        T[parent[i]].push_back(i);
    }
    return T;

}



int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::vector<int> parent(n+1,0);
        std::vector<char> color(n+1,0);
        for(int i=2;i<=n;i++){
            int x;
            std::cin>>x;
            parent[i]=x;
        }
        for(int i=1;i<=n;i++){
            char x;
            std::cin>>x;
            color[i]=x;
        }
        std::vector<std::vector<int>> T=create_tree(parent,n);
        std::cout<<findBalanced(T,color,n,1)<<"\n";

        maxi=0;

    }


}