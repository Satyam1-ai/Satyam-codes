



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>



long long solve_path(long long a, long long b, long long x, long long y, long long n) {
    long long can_take_a = std::min(n, a - x);
    a -= can_take_a;
    n -= can_take_a;
    
    long long can_take_b = std::min(n, b - y);
    b -= can_take_b;
    
    return a * b;
}






int main(){
    int t;
    std::cin>>t;
    while(t--){
        long long a,b,x,y,n;
        std::cin>>a>>b>>x>>y>>n;
        std::cout<<std::min(solve_path(a, b, x, y, n), solve_path(b, a, y, x, n)) << "\n";

    }



}