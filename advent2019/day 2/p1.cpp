#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

#define INF INT_MAX
#define endline '\n'

int main()
{

    ios::sync_with_stdio(false);
    
    ifstream fin("input");
    ofstream fout("output");
    string line;

    int currPos = 0;
    vector<int> program;

    while ( getline(fin, line, ',') ) {

        program.push_back(stoi(line));

    }

    // Program is now loaded in memory

    for(int i = 0; i < program.size(); i += 4){

        int opcode = program[i];
        int pos1 = program[i + 1];
        int pos2 = program[i + 2];
        int pos3 = program[i + 3];

        if(opcode == 1){
            int sum = program[pos1] + program[pos2];
            program[pos3] = sum;
        }else if(opcode == 2){
            int mult = program[pos1] * program[pos2];
            program[pos3] = mult;
        }else if(opcode == 99){
            break;
        }else{
            cout << "incorrect opcode";
        }

    }

    cout << program[0];
	
    fin.close();
    fout.close();

    return 0;
    
}