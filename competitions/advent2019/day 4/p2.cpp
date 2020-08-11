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
        bool cont = false;

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
            }
        }

        if(cont) continue;

        // Check first and last for solutions
        if((digits[0] == digits[1]) && (digits[1] != digits[2])){
            solutions++;
            continue;
        }else if((digits[digits.size() - 1] == digits[digits.size() - 2]) && (digits[digits.size() - 2] != digits[digits.size() - 3])){
            solutions++;
            continue;
        }

        // Number is ascending but need to find a double pair excluding first and last
        for(int i = 1; i < digits.size() - 2; i++){
            if((digits[i] == digits[i + 1]) && (digits[i - 1] != digits[i]) && (digits[i + 1] != digits[i + 2])){
                solutions++;
                break;
            }
        }

    }

    cout << "Found number of solutions: " << solutions << endline;
	
    fin.close();
    fout.close();

    return 0;
    
}