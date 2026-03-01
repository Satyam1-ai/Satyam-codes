/*
Simple 2D searching ...............is used here .....We basically have to ...n^2 ...till we find ..
the ......'+' sign ..Once ..we do that ...we simply ...have to check if the elemnts on the other sides of it are also pluses ...
if there are a "+" .....then we could simply ......check it along ...the ....arms ..to see if the condition fits ...othjerwise NO ..
in addition we also have to make sure we are completing ...the entire .....search ... ...to make sure there aren't any ...dangling ..
"+" ..signs ...
if there are any ...then have to return NO ...Lets code this .....Lets warm up this ..thing  ......get back to practice ..
....Get to master in codeforces .......IN 6 MONTHS ..Lets fucking GO ..

*/






#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>







bool Pluses(int rows, int columns, std::vector<std::vector<int>> &v) {
    int r = -1;
    int c = -1;

    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < columns - 1; j++) {
            if (v[i][j] == '*') {
                if (v[i - 1][j] == '*' && v[i + 1][j] == '*' && v[i][j - 1] == '*' && v[i][j + 1] == '*') {
                    r = i;
                    c = j;
                    break; 
                }
            }
        }
        if (r != -1) break; 
    }

    if (r == -1) return false;

    v[r][c] = '.';

    int i = r - 1;
    int j = c;

    while (i >= 0 && v[i][j] == '*') {
        v[i--][j] = '.';
    }
    
    i = r + 1;
    while (i < rows && v[i][j] == '*') {
        v[i++][j] = '.';
    }
    i = r;
    j = c - 1;
    while (j >= 0 && v[i][j] == '*') {
        v[i][j--] = '.';
    }

    j = c + 1;
    while (j < columns && v[i][j] == '*') {
        v[i][j++] = '.';
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (v[i][j] == '*') {
                return false; 
            }
        }
    }

    return true;
}









int main(){
    int h,w;
    std::cin>>h>>w;
    std::vector<std::vector<int>>v(h, std::vector<int>(w,0));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char x;
            v[i][j]=x;
        }
    }
    std::cout<<Pluses(h,w,v);

}