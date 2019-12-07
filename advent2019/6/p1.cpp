#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX
#define endline '\n'

int main()
{

    ios::sync_with_stdio(false);
    
    ifstream fin("input");

    string line;

    while( fin >> line ){

        // Practice splitting strings in c++; I know this isn't needed
        string p1, p2;

        size_t splitPos = line.find(")");

        p1 = line.substr(0, splitPos);
        p2 = line.substr(splitPos + 1, line.size() - splitPos);

        

    }
	
    fin.close();

    return 0;
    
}