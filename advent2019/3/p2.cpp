#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <unordered_map>

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

    unordered_map< pair<int, int>, int, pair_hash > m1;
    unordered_map< pair<int, int>, int, pair_hash > m2;

    int curlocx = 0, curlocy = 0, currstep = 0;

    while( getline(fin1, line, ',') ) {
        
        if(line[0] == 'R'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocx += 1;
                currstep++;
                if( m1.count(make_pair(curlocx, curlocy)) == 0 ){
                    // Have not already visited this point
                    m1.insert(make_pair(make_pair(curlocx, curlocy), currstep));
                }
            }

        }else if(line[0] == 'L'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocx -= 1;
                currstep++;
                if( m1.count(make_pair(curlocx, curlocy)) == 0 ){
                    // Have not already visited this point
                    m1.insert(make_pair(make_pair(curlocx, curlocy), currstep));
                }
            }

        }else if(line[0] == 'U'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocy += 1;
                currstep++;
                if( m1.count(make_pair(curlocx, curlocy)) == 0 ){
                    // Have not already visited this point
                    m1.insert(make_pair(make_pair(curlocx, curlocy), currstep));
                }
            }

        }else if(line[0] == 'D'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocy -= 1;
                currstep++;
                if( m1.count(make_pair(curlocx, curlocy)) == 0 ){
                    // Have not already visited this point
                    m1.insert(make_pair(make_pair(curlocx, curlocy), currstep));
                }
            }

        }else{
            cout << "Error in opcode" << endline;
        }

    }

    curlocx = 0;
    curlocy = 0;
    currstep = 0;

    while( getline(fin2, line, ',') ) {
        
        if(line[0] == 'R'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocx += 1;
                currstep++;
                if( m2.count(make_pair(curlocx, curlocy)) == 0 ){
                    // Have not already visited this point
                    m2.insert(make_pair(make_pair(curlocx, curlocy), currstep));
                }
            }

        }else if(line[0] == 'L'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocx -= 1;
                currstep++;
                if( m2.count(make_pair(curlocx, curlocy)) == 0 ){
                    // Have not already visited this point
                    m2.insert(make_pair(make_pair(curlocx, curlocy), currstep));
                }
            }

        }else if(line[0] == 'U'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocy += 1;
                currstep++;
                if( m2.count(make_pair(curlocx, curlocy)) == 0 ){
                    // Have not already visited this point
                    m2.insert(make_pair(make_pair(curlocx, curlocy), currstep));
                }
            }

        }else if(line[0] == 'D'){

            int numSteps = stoi(line.substr(1, line.size() - 1));
            for(int i = 0; i < numSteps; i++){
                curlocy -= 1;
                currstep++;
                if( m2.count(make_pair(curlocx, curlocy)) == 0 ){
                    // Have not already visited this point
                    m2.insert(make_pair(make_pair(curlocx, curlocy), currstep));
                }
            }

        }else{
            cout << "Error in opcode" << endline;
        }

    }

    int dist = INF;

    for( const pair< pair<int, int>, int> elem : m1){
        if(m2.find(elem.first) != m2.end()){
            if((elem.second + m2[elem.first]) < dist){
                dist = elem.second + m2[elem.first];
            }
        }
    }

    cout << "Final shortest distance: " << dist;
	
    fin1.close();
    fin2.close();
    fout.close();

    return 0;
    
}