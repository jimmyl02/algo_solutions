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

    ofstream fout(getenv("OUTPUT_PATH"));

    int Q;
    cin >> Q;
    while(Q--){
        int N, mat[105][105];
        cin >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> mat[i][j];
            }
        }

        // container space must match the amount of ball types

        int containerSizes[105], ballCounts[105];

        for(int r = 0; r < N; r++){
            int total = 0;
            for(int c = 0; c < N; c++){
                total += mat[r][c];
            }
            containerSizes[r] = total;
        }

        for(int c = 0; c < N; c++){
            int total = 0;
            for(int r = 0; r < N; r++){
                total += mat[r][c];
            }
            ballCounts[c] = total;
        }

        sort(containerSizes, containerSizes + N);
        sort(ballCounts, ballCounts + N);

        bool possible = true;
        for(int i = 0; i < N; i++){
            if(containerSizes[i] != ballCounts[i]){
                possible = false;
                break;
            }
        }

        if(possible){
            fout << "Possible" << endline;
        }else{
            fout << "Impossible" << endline;
        }

    }

    fout.close();

    return 0;
    
}