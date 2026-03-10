/*
    So we have a penalty shootout ...2 teams...we know the scores already .......in the form of a string ...now ...we just gotta divide hte 
    string in 2 .....5 for the team A and 5 for the team B ...Now idf it were your normal scoresheet ..you would simply check the total difference 
    and the number of games remaining ...is the total games - differnece ...<0 then the other team will be declared the winner...
    Here you have ? which can be ...1 or 0 ..depending on .....its ability to influence the game into getting over quicker and quicker ...
    so YEAH ....you are given some options of your choice ......now you could calcualte the number of ? for each team at each index ..
    see if it would ......exceed the number of remaining games ...for either ..which ever works ,,.
    basically the number of ? + number of 1 (differece bw the 2 teams) ...> remianing games .....and then do it for each index ..
    see where to stop ....This will work but ..you're effectively computing ..for ..each step ...
    To hsorten this ...we could consider giving ...either team ...A full set of ? as 1 and a full set of ? as 0 ..flipping it ...
    so 2 ..scenarios ...and we pick the min from nboth of them ..easy 

*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>





int conversions(std::vector<char> team_a, std::vector<char> team_b, int flag){
    for(int i=0; i<5; i++){
        if(team_a[i]=='?') team_a[i] = (flag == 0 ? '1' : '0');
        if(team_b[i]=='?') team_b[i] = (flag == 0 ? '0' : '1');
    }

    int score_a=0;
    int score_b=0;
    int rem_a=5; 
    int rem_b=5; 

    for(int i=0; i<5; i++){
        if(team_a[i] == '1') score_a++;
        rem_a--;
        if(score_a > score_b + rem_b || score_b > score_a + rem_a) 
            return (i * 2) + 1; 

        if(team_b[i] == '1') score_b++;
        rem_b--;
        if(score_a > score_b + rem_b || score_b > score_a + rem_a) 
            return (i * 2) + 2;
    }
    return 10;
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        std::string s;
        std::cin >> s; 
        
        std::vector<char> a, b;
        for(int i=0; i<10; i++){
            if(i%2==0) a.push_back(s[i]);
            else b.push_back(s[i]);
        }

        int x = conversions(a, b, 0);
        int y = conversions(a, b, 1);
        std::cout << std::min(x, y) << std::endl;
    }
    return 0;
}
