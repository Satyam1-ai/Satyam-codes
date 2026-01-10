
/*

Brute force LCS ....Not using dp HERE ..becasue its a 1000 rated prolem ..Dont overcomplicate it ..But you could learn 
2 inbuilt c++ string  functions namely ...string::find and string::substr ..find returns the starting index if found ...otherwise simply 
npos ...and substr literally gives out the the substring  from the i to the j ..i could have looped around and creater a string 
But just use the inbuilt function ..It has been optimised ....

NOW THIS BRUTE FORCE APPROACH WORK ONLY BECAUSE WE HAVE n<20 as our c onstraints ..for larger n it will give a TLE erro
have to use a 2D DP ..which I will upload later .

But yeah do that once .you figure that out ..you have ...the max common already ..now just shaving is left ..simply shave from the 2 
strings how much is needed ..for s1 length of s1-max and for s2 ...length of s2-max .Or simply s.szie()+s2.size()-2*(max)



EASY 




*/



#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;



int findLCS(string s,string s2){
    int m;
    int n;
    if(s.size()>s2.size()){
        m=s.size();
        n=s2.size();
    }
    else{
        m=s2.size();
        n=s.size();
        string temp=s2;
        s2=s;
        s=temp;

    }
    int max_length=0;
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            string temp=s.substr(i,j-i+1);
            if(s2.find(temp)!=string::npos){
                max_length=max(max_length,j-i+1);
            }
        }
    }

    return max_length;


}








int main(){



    int t;
    cin>>t;

    while(t--){
        string s;
        string s2;
        cin>>s>>s2;

        int value=findLCS(s,s2);
        int temp=s.size()+s2.size()-(2*value);
        cout<<temp<<endl;
    }


    return 0;





}





