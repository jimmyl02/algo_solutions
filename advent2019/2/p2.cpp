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
    ofstream fout("output");
    string line;

    int currPos = 0;
    vector<int> program;
    vector<int> memory;

    while ( getline(fin, line, ',') ) {

        program.push_back(stoi(line));

    }

    for(int noun = 0; noun <= 99; noun++){
        for(int verb = 0; verb <= 99; verb++){

            memory.clear();

            // Initialize program by copying into memory

            for(int i = 0; i < program.size(); i++){
                memory.push_back(program[i]);
            }

            memory[1] = noun;
            memory[2] = verb;

            // Program is now loaded into memory

            for(int i = 0; i < memory.size(); i += 4){

                int opcode = memory[i];
                int pos1 = memory[i + 1];
                int pos2 = memory[i + 2];
                int pos3 = memory[i + 3];

                if(opcode == 1){
                    int sum = memory[pos1] + memory[pos2];
                    memory[pos3] = sum;
                }else if(opcode == 2){
                    int mult = memory[pos1] * memory[pos2];
                    memory[pos3] = mult;
                }else if(opcode == 99){
                    break;
                }else{
                    cout << "incorrect opcode";
                }

            }

            if(memory[0] == 19690720) cout << "Found correct noun and verb: " << (100 * noun) + verb;

        }
    }
	
    fin.close();
    fout.close();

    return 0;
    
}