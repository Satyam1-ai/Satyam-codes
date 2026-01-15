#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for find and erase_if
#include <cctype>    // Required for tolower

using namespace std;

void performOperation_uno(string &s) {
    for(auto& c : s) {
        c = tolower(c);
    }
} // Removed the extra } that was here

void performOperation_dos(string &s) {
    vector<char> Vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

    // This does the exact same thing as erase_if
    s.erase(std::remove_if(s.begin(), s.end(), [&](char c) {
        return std::find(Vowels.begin(), Vowels.end(), c) != Vowels.end();
    }), s.end());
}

// In CP, it's usually better to return a string if you're building a word
string performOperation_tres(string &s) {
    string ans = "";
    ans.reserve(s.size() * 2); // Efficiency: prevents multiple reallocations
    
    for(int i = 0; i < s.size(); i++) {
        ans.push_back('.'); // Use single quotes '.' for char, not double quotes "."
        ans.push_back(s[i]);
    }
    return ans;
}

int main() {
    string s;
    if (!(cin >> s)) return 0;

    performOperation_uno(s);
    performOperation_dos(s);
    string result = performOperation_tres(s);

    cout << result << endl;
    
    return 0;
}
