#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

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
        int N, mat[100][100], trace = 0, repRows = 0, repCols = 0;

        cin >> N;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> mat[i][j];
            }
        }

        // Find the trace
        for(int i = 0; i < N; i++){
            trace += mat[i][i];
        }

        // Find rows with repeats
        bool nums[105];
        for(int i = 0; i < N; i++){
            // Zero out nums tracker
            for(int j = 0; j < 105; j++){
                nums[j] = false;
            }
            // Look for repeats
            for(int j = 0; j < N; j++){
                if(nums[mat[i][j]]){
                    repRows++;
                    break;
                }else{
                    // Element nto seen yet
                    nums[mat[i][j]] = true;
                }
            }
        }

        // Find columns with repeats
        for(int i = 0; i < N; i++){
            // Zero out nums tracker
            for(int j = 0; j < 105; j++){
                nums[j] = false;
            }
            // Look for repeats
            for(int j = 0; j < N; j++){
                if(nums[mat[j][i]]){
                    repCols++;
                    break;
                }else{
                    // Element nto seen yet
                    nums[mat[j][i]] = true;
                }
            }
        }

        cout << "Case #" << caseNum  << ": " << trace << " " << repRows << " " << repCols << endline;
    }

    return 0;
    
}