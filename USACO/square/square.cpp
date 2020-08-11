#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>

using namespace std;

#define INF INT_MAX
#define endline '\n'
#define ll long long

int main()
{

    ios::sync_with_stdio(false);

    int x1, y1, x2, y2;
    int lx, ly, hx, hy;

    cin >> x1 >> y1 >> x2 >> y2;

    lx = x1;
    ly = y1;
    hx = x2;
    hy = y2;

    cin >> x1 >> y1 >> x2 >> y2;

    lx = min(lx, x1);
    ly = min(ly, y1);
    hx = max(hx, x2);
    hy = max(hy, y2);

    int area = pow(max(hx - lx, hy - ly), 2);

    cout << area;

    return 0;
    
}