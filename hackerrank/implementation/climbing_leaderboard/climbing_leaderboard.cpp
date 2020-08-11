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
    
    //ofstream fout("out.txt");
    ofstream fout(getenv("OUTPUT_PATH"));

    int N, M, leaderboard[(int) 2e+5 + 5], alice[(int) 2e+5 + 6], places[(int) 2e+5 + 6];

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> leaderboard[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> alice[i];
    }

    int currPlace = 1;
    places[0] = 1;
    for(int i = 1; i < N; i++){
        if(leaderboard[i] != leaderboard[i - 1]){
            currPlace++;
        }
        places[i] = currPlace;
    }

    int alicePos = 0, leaderPos = N - 1;

    while(alicePos != M){
        // There is more alice to find TODO: Make sure to track the case where alice is 1
        // Special case alice is first
        if(leaderPos == 0 && alice[alicePos] > leaderboard[0]){
            fout << "1" << endline;
            alicePos++;
            continue;
        }
        if(alice[alicePos] == leaderboard[leaderPos]){
            fout << places[leaderPos] << endline;
            alicePos++;
        }else if(alice[alicePos] > leaderboard[leaderPos]){
            leaderPos--;
        }else{
            fout << places[leaderPos] + 1 << endline;
            alicePos++;
        }
    }

    fout.close();

    return 0;
    
}