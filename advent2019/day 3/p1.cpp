#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <unordered_set>

using namespace std;

#define INF INT_MAX
#define endline '\n'

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

int main()
{

    ios::sync_with_stdio(false);
    
    ifstream fin1("inputw1");
    ifstream fin2("inputw2");
    ofstream fout(".out");
    string line;

    unordered_set< pair<int, int>, pair_hash > w1;
    unordered_set< pair<int, int>, pair_hash > w2;

    int curlocx = 0, curlocy = 0;

    while( getline(fin1, line, ',') ) {
        
        if(line[0] == 'R'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocx += 1;
                w1.insert(make_pair(curlocx, curlocy));
            }

        }else if(line[0] == 'L'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocx -= 1;
                w1.insert(make_pair(curlocx, curlocy));
            }

        }else if(line[0] == 'U'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocy += 1;
                w1.insert(make_pair(curlocx, curlocy));
            }

        }else if(line[0] == 'D'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocy -= 1;
                w1.insert(make_pair(curlocx, curlocy));
            }

        }else{
            cout << "Error in opcode" << endline;
        }

    }

    curlocx = 0;
    curlocy = 0;

    while( getline(fin2, line, ',') ) {
        
        if(line[0] == 'R'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocx += 1;
                w2.insert(make_pair(curlocx, curlocy));
            }

        }else if(line[0] == 'L'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocx -= 1;
                w2.insert(make_pair(curlocx, curlocy));
            }

        }else if(line[0] == 'U'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocy += 1;
                w2.insert(make_pair(curlocx, curlocy));
            }

        }else if(line[0] == 'D'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocy -= 1;
                w2.insert(make_pair(curlocx, curlocy));
            }

        }else{
            cout << "Error in opcode" << endline;
        }

    }

    vector< pair<int, int> > intersects;

    for( const pair<int, int> elem : w1){
        if(w2.find(elem) != w2.end()){
            intersects.push_back(elem);
        }
    }

    // Intersects now has all interescting points

    int dist = INF;

    for(int i = 0; i < intersects.size(); i++){
        pair<int, int> curr = intersects[i];
        if(abs(curr.first) + abs(curr.second) < dist){
            dist = abs(curr.first) + abs(curr.second);
        }
    }

    cout << "Final shortest distance: " << dist;
	
    fin1.close();
    fin2.close();
    fout.close();

    return 0;
    
}