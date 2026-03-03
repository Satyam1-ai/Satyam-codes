/*
We are given a flea ...A simple Flea in the center of a cell on a board that houses .....m*n cells ..It can move up/down ..left/right 
Based on this we can simply assume ...that the highest a person ..could go row wise is essentially  ..when he starts from the first ...
so 1,3,5 ..if n =5 and s=2 ...so ...(n-1)/s+1 .. times the ....number of ..sets you could create ....we could have ..{2,4,6} ..spitting otuthe 
same ...result ...
..(n-1)%s+1 ..gives us the total number of set ...

Basically ..we have ....
How many can you get to maximize the result........most ..possible ..ones start from the ..0 place ........and we can figure out the 
cells .....If you choose something in the middle ..it alwasy goes ..+c and -c  .......
So that balance is alwasy created ..to account for both ways ...Very much like a circle .....a modular circle ...
Now we know the max number ..Now we have to account for the sets ...if ..a perfecet ..divisible thing then ans will be evrything ..
if c is 1 ..then ..we have ...everything again ....if ..2 ..then use modulo ....
Howervr we have to handle some edge cases here and there ..and we arrive at the pattern based formula 
which is ...(n-1)%c +1 .....this gives the sets ..so sets* (maximum) ...will be giving us ....

Do the same for the ....column aswell ..so basicallly ...each row ...will have some thing .....which is ...responsive to ...each column ..
along the line...Basically ...row*column ..will give you the answer .



*/


#include <iostream>
#include <vector>
#include <unordered_map>






int main() {
    long long n, m, s;
    if (!(std::cin >> n >> m >> s)) return 0;

    long long countX = (n - 1) / s + 1;
    long long countY = (m - 1) / s + 1;
    long long startsX = (n - 1) % s + 1;
    long long startsY = (m - 1) % s + 1;

    long long ans = countX * countY * startsX * startsY;

    std::cout << ans << std::endl;

    return 0;
}






}