#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define INF INT_MAX
#define endline '\n'

unordered_map<string, unordered_set<string>> info;

// One DFS approach

int orbits = 0;

void dfs(string currPos, int currDepth){
    if(info.find(currPos) == info.end()){
        // Info does not contain the currPos
        orbits += currDepth;
        return;
    }

    // Info contains currPos
    orbits += currDepth;

    for(string str : info[currPos]){
        dfs(str, currDepth + 1);
    }

    return;

}

int main()
{

    ios::sync_with_stdio(false);
    
    ifstream fin("input");

    string line;

    while( fin >> line ){

        // Practice splitting strings in c++; I know this isn't needed
        string p1, p2;

        size_t splitPos = line.find(")");

        if(splitPos == string::npos) cout << "Error, ) not found in input line";

        p1 = line.substr(0, splitPos);
        p2 = line.substr(splitPos + 1, line.size() - splitPos);

        if(info.find(p1) == info.end()){
            // Key not in info
            unordered_set<string> newSet;
            newSet.insert(p2);
            info.insert(make_pair(p1, newSet));
        }else{
            // Key is already in info
            unordered_set<string> existSet = info[p1];
            existSet.insert(p2);
            info[p1] = existSet;
        }

    }

    // Info array is now filled correctly
    dfs("COM", 0);

    cout << "Number of direct and indirect orbits: " << orbits << endline;
	
    fin.close();

    return 0;
    
}