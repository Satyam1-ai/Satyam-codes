/* A really good logical problem ..I did not know how to solve this at first .....But then I figured it out ..eventaually with a few hints 
It is a classic pattern on greedy problems ......where you are esentially picking some things based on the best choice decision you are making ..and then you stop ...if it does not work out 
you simply forget about it ..and then select somethig ..else and kind arepeat it ..
Here the same thing applies ..The most obvious decisio wouild be to try to take the gas station where the start could potentially be 
and then check if that works out ..if yes then fine(there is ony one start for every quesiton taht is the constraint) ..otherwsie  we will
have to take another start ....and then repeat ..this method is well andd good ..However it might get complicated becaus eog te time completity involved
Worst case scenario would be whehre all the elements in theh array are potentailly starts ..then for each we have to run 0(n) making the complexity seem 
ridiculously high n^2 ..So instead we have to think baout this problem logiclly ..The constraint mentions tha tif there is a start it wll be unique 
and if it exists then to complete the cycle it should have the total_gas > total_cost 
if NO then simply the start is not going to exist ..Otherwise the statrt will exist ..Now that we know it exists ...we have to find that start 
So lets look at each and every gas stataion. ....if we string togethjer 5 gas stations ..and the cumm_sum is somehting >cumm_cost means 
we are in a valid configuration ..and our start can be 0 ....so using this ..at each step we will be checking ..whether ..the cumm_sum for that
particular .....thing is greater or lesser than n ...if greater we move forward...otherwise we reset ..


THIS IS SO MUCH LIKE KADEDNES ....ITS ALL CONNECTED ...EVERYTHING......GUYS I SWEAR COMPETETIVE PROGRAMMING IS AN ART OF RELAISATION .
YOU HAVE TO LOOSE YOUR MIND .HERE ..PLEASE DONT LEARN IT FOR THE SAKE OF PLACEMENTS ...TREAT IT LIKE AN ART WORK ...AND YOUR RAITNG IS
THE MASTERPIECE SCORE YOU ARE GETTING  



*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int findStart(vector<int> &gas, vector<int> &cost){
    int total_cost=0;
    int total_fuel=0;
    int cumm_cost=0;
    int cumm_gas=0;
    int start=0;

    for(int i=0;i<gas.size();i++){
        total_cost+=cost[i];
        total_fuel+=gas[i];


        cumm_gas+=gas[i];
        cumm_cost+=cost[i];

        if(cumm_gas<cumm_cost){
            start=i+1;//Because this is the point that fails ..so the calc begins from the next point 
            cumm_cost=0;
            cumm_gas=0;
        }
    }
    if(total_cost>total_fuel)
        return -1; //If the fuel is greater than the cost then no poiint in finding the start as it does not exist 
    return start;
}



int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost ={3,4,5,1,2};
    cout<<findStart(gas,cost);





}

