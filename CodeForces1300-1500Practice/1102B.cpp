






#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm> 

bool finding(std::vector<std::pair<int,int>> &a, int n, int k, std::vector<int> &result){
    std::sort(a.begin(), a.end());
    int i = 0;
    int color_count = 1; 

    while(i < n){
        int j = i;
        int repetion_count = 0;
        while(j < n && a[j].first == a[i].first){
            if(repetion_count == k)
                return false;
            
            color_count = (color_count) % k + 1;
            result[a[j].second] = color_count;
            
            repetion_count++;
            j++;
        }
        i = j;
    }
    return true; 
}

int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int,int>> a(n);
    std::vector<int> result(n); 

    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        a[i].first = x;
        a[i].second = i;
    }

    if(finding(a, n, k, result)){
        std::cout << "YES" << std::endl;
        for(int i = 0; i < n; i++){
            std::cout << result[i] << " ";
        }
    }
    else{
        std::cout << "NO";
    }
    return 0;
}
