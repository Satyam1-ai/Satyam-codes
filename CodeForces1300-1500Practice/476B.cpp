/*
Simple Combinatrics problem  really ....here we are doing ..something like .....






*/




#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

int Combinations(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    return Combinations(n - 1, r - 1) + Combinations(n - 1, r);
}

void solve() {
    std::string s, s2;
    if (!(std::cin >> s >> s2)) return;

    int pluses_first = 0, minus_first = 0;
    int pluses_second = 0, minus_second = 0;
    int k = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') pluses_first++;
        else minus_first++;
    }

    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == '+') pluses_second++;
        else if (s2[i] == '-') minus_second++;
        else k++;
    }

    int target = pluses_first - minus_first;
    int current = pluses_second - minus_second;
    int d = target - current;
    if ((k + d) % 2 != 0 || std::abs(d) > k) {
        std::cout << std::fixed << std::setprecision(12) << 0.0 << std::endl;
        return;
    }
    int a = (k + d) / 2;
    
    double ways = Combinations(k, a);
    double total_outcomes = std::pow(2, k);

    std::cout << std::fixed << std::setprecision(12) << (ways / total_outcomes) << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
