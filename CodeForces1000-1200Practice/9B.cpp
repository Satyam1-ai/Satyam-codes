/*
Geometry problem ...Need to have a basic undersatnding of .....speed ,distance ,time relation ....We have a student ..who wants to arraive 
at the ...exam center in the least possible time ..He is on the bus starting at the ......coordinate ..0,0 ...from here he will move ..into 
each and every stop ....one by one ...and then ...run till uni ..at a constant pace ..
We gotta figure out ...the minimum time it will be needed to reach the university ...To do so ...we can simply ..compute
the ...time =distance / speed ...for each and every stop ..along with he time it takes to get to the uni by foot ...
So yeah ...the by ..bus distance is computed by the ...x coordinate itslef ...simply (x-0) ...and the by foot distance 
will be computed by the ...eucledean Distance ...from ...the ..bus stop coordinate which ..some...x,0 and the uni coorindate 
which is x,y ..so yeah ......root((xuni-xbus_stop)^2 -(y^2)) ... 



*/









#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cfloat>

double calculate_distance(std::pair<int,int> University, int Vb, int Vs, int x) {
    double d = sqrt(pow((double)University.first - x, 2) + pow((double)University.second, 2));
    double time = (double)d / Vs + (double)x / Vb;
    return time;
}

int RunningStudent(std::vector<int> &A, int n, int Vb, int Vs, std::pair<int,int> University) {
    double mini = DBL_MAX;
    double min_run_dist = DBL_MAX;
    int best_index = -1;

    for(int i = 1; i < n; i++) {
        double current_time = calculate_distance(University, Vb, Vs, A[i]);
        double current_run_dist = sqrt(pow((double)University.first - A[i], 2) + pow((double)University.second, 2));

        if(current_time < mini - 1e-9) {
            mini = current_time;
            min_run_dist = current_run_dist;
            best_index = i + 1;
        } else if (std::abs(current_time - mini) < 1e-9) {
            if(current_run_dist < min_run_dist) {
                min_run_dist = current_run_dist;
                best_index = i + 1;
            }
        }
    }
    return best_index;
}

int main() {
    int n;
    int Vb;
    int Vs;

    if (!(std::cin >> n >> Vb >> Vs)) return 0;
    
    std::vector<int> A(n, 0);
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        A[i] = x;
    }

    std::pair<int,int> University;
    std::cin >> University.first >> University.second;

    std::cout << RunningStudent(A, n, Vb, Vs, University) << std::endl;

    return 0;
}

