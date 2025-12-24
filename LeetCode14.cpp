/*Pretty Basic Question ...Just gotta figure out what prefix means in this context ..It refers to ..the commmon chars between all the 
strings in our array .measure fromt the start of the respective strings. ....Otherwise it become a question where we have to find any substring 
Inside of our Array of strings ..which becomes really challendingas we might have to DP or trees

Here pretty standar..Take a string from the array of string ..Could be first last or middle ...extract it ..check if its characters match 
those of the other strings from the array ....basically a Vertical scanning from index 0..of our first string ..checked with al the other strings ...
Could be solved by Divide and conquer aswell...which I will implement here ...

*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


string compare(string &x,string &y){
    string result;
    int i=0;
    int n=x.size();
    while(i<n){
        if(i==y.size() || x[i]!=y[i])
            return result;
        result+=x[i];
        i++;
    }
    return result;
}


string longestCommonPrefix(vector<string>& strs,int i,int j) {

    if(i>j)
        return "";
    if(i==j)
        return strs[i];

    int mid=(i+j)/2;

    string x=longestCommonPrefix(strs,i,mid);
    string y=longestCommonPrefix(strs,mid+1,j);
    return compare(x,y);

}







int main(){
    vector<string> strs={"flower","flow","flames"};
    int i=0;
    int j=strs.size()-1;

    cout<<longestCommonPrefix(strs,i,j);

}