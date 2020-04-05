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

int T, caseNum = 0;

int main()
{

    ios::sync_with_stdio(false);

    cin >> T;
    
    while(T--){
        caseNum++;
        string inp, out = "";
        cin >> inp;

        int depth = 0;
        char currChar = inp[0];

        if(currChar != '0'){
            for(int i = 0; i < (int) currChar - 48; i++){
                out += "(";
                depth++;
            }
        }
        out += currChar;

        for(int i = 1; i < inp.length(); i++){
            if(inp[i] == currChar){
                // Char has stayed the same
                out += inp[i];
            }else{
                // Char changed
                currChar = inp[i];
                int newVal = (int) inp[i] - 48;
                if(newVal < depth){
                    // Need to close some parentheses
                    int changeNeeded = depth - newVal;
                    for(int j = 0; j < changeNeeded; j++){
                        out += ")";
                        depth--;
                    }
                    out += inp[i];
                }else{
                    // Need to open some parentheses
                    int changeNeeded = newVal - depth;
                    for(int j = 0; j < changeNeeded; j++){
                        out += "(";
                        depth++;
                    }
                    out += inp[i];
                }
            }
        }

        // Close off the remaining depth
        while(depth--){
            out += ")";
        }

        cout << "Case #" << caseNum << ": " << out << endline;
    }

    return 0;
    
}