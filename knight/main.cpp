
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Corridor {
    int nextIntersection;
    double f;
    
    Corridor(int i, float f) : nextIntersection(i), f(f) {};
};

int main(int argc, const char * argv[])
{
    int n, m, x, y, intersection;
    double f, newf;
    while(true){
        scanf ("%d %d", &n, &m);
        if(n == 0 && m == 0){
            return 0;
        }
        
        vector<vector<Corridor>> intersections(n);
        vector<double> bestValue(n);
        bestValue[0] = 1;
        
        for(int i = 0; i < m; i++) {
            scanf("%d %d %lf", &x, &y, &f);
            if(x != n - 1) {
                intersections[x].push_back(Corridor(y, f));
            }
            if(y != n -1) {
                intersections[y].push_back(Corridor(x, f));
            }
        }
        
        queue<int> pathQueue;
        pathQueue.push(0);
        
        while(!pathQueue.empty()) {
            intersection = pathQueue.front();
            pathQueue.pop();
            f = bestValue[intersection];
            for(Corridor cor: intersections[intersection]){
                y = cor.nextIntersection;
                newf = f * cor.f;
                if(newf > bestValue[y] && newf > bestValue[n - 1]) {
                    bestValue[y] = newf;
                    pathQueue.push(y);
                }
            }
        }
        printf("%.4f\n", bestValue[n-1]);
    }
}

