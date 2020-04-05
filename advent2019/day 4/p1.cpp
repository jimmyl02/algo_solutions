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

    int start = 0, end = 0, solutions = 0;

    cin >> start;
    cin >> end;

    vector<int> digits;

    for(int i = start; i <= end; i++){

        int tmp = i;
        bool cont = false, foundDouble = false;

        digits.clear();
        
        while(tmp > 0){

            int digit = tmp % 10;
            digits.push_back(digit);
            tmp /= 10;

        }

        // Digits array is now filled with numbers backwards

        for(int i = 0; i < digits.size() - 1; i++){
            if(digits[i] < digits[i + 1]){
                cont = true;
                break;
            }else if(digits[i] == digits[i + 1]){
                foundDouble = true;
            }
        }

        if(cont || !foundDouble) continue;

        solutions++;

    }

    cout << "Found number of solutions: " << solutions << endline;
	
    fin.close();
    fout.close();

    return 0;
    
}