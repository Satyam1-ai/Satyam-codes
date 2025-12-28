/*This is another intersting story type question ..Here ..we have a parent aka ..some guy who wants to give  his kids some things ..
The things are counted....by some metric and are numerically given in an array ..namely s[i]...Now every kid has great affinity towars these candies 
This makes the kid have an element of greed aswell ..Now their greed can be measured by some metric and its numeric interpretation is listed in the form of 
an array namely g[k] ...now to make a kid happy you have to give him the candy that makes his greed satiate ..This makes it incredibly 
difficult to follow ....Now we can use a greedy approach and select the candy .....bt a problem comes about ..that problem being ..that if 
the g[i] is too small. ..bt we give the kid that .......that would mean that we  waste it on one of the candidates who misses out ..
Naturally our ......goal is to make max kids happy ...so we would have to sort the greed in ascending order aswell ..
in addition to that ..WE  will be having to ...also...arrange the ..........size of the cookie in sorted order ..creating 
some sort of mapping into how they work ....Pretty neat ...now lets get to coding ..  */




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int MaxHappiness(vector<int> &g, vector<int> &s){
    int i=0;
    int j=0;
    int cnt=0;
    sort(s.begin(),s.end());
    sort(g.begin(),g.end());
    while(i!=g.size() && j!=s.size()){
        if(s[j]>=g[i]){
            cnt++;
            i++;
        }
        j++;
    }
    return cnt;



}




int main(){
    vector<int> g={9,8,10,7};
    vector<int> s={7,6,8};
    return MaxHappiness(g,s);
}


