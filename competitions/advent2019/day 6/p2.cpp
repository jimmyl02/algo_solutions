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

// The goal here is to use dijkstras to find the shortest path in an efficient manner

unordered_map<string, unordered_set<string> > info;

int main()
{

    ios::sync_with_stdio(false);
    
    ifstream fin("input");

    string line;

    while( fin >> line ){

        // The difference here is we make it a two way relationship
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
            info[p1].insert(p2);
        }

        // Insert the other direction
        if(info.find(p2) == info.end()){
            // Key not in info
            unordered_set<string> newSet;
            newSet.insert(p1);
            info.insert(make_pair(p2, newSet));
        }else{
            // Key is already in info
            info[p2].insert(p1);
        }

    }

    // Info array is now filled correctly with bidirectional data

    // Here I will use BFS to find the lowest cost

    unordered_set<string> visited;

    queue<pair<string, int> > bfsqueue;

    bfsqueue.push(make_pair("YOU", 0)); //Pushing the source with distance from itself as 0

    while(!bfsqueue.empty()){

        pair<string, int> curr = bfsqueue.front();
        bfsqueue.pop();

        string node = curr.first;
        int cost = curr.second;

        if(node == "SAN"){
            cout << "Distance to SAN from YOU found: " << cost;
            cout << "Distance between nodes to SAN from YOU found: " << cost - 2;
        };

        if(visited.find(node) != visited.end()){
            // Node has already been visited
            continue;
        }

        visited.insert(node);

        for(string str : info[node]){
            // For each adjacent node, we queue it with a cost of 1 greater
            bfsqueue.push(make_pair(str, cost + 1));
        }

    }
	
    fin.close();

    return 0;
    
}