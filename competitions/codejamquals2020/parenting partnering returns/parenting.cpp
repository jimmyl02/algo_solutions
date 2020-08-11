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

bool customSort(const pair< pair<int, int>, int > &a, 
                    const pair< pair<int, int>, int > &b) 
{ 
    return (a.first.first < b.first.first); 
} 

int T, caseNum = 0;

int main()
{

    ios::sync_with_stdio(false);
    
    cin >> T;

    while(T--){
        caseNum++;
        int N;
        cin >> N;

        vector< pair< pair<int, int>, int > > times; // ((start, end), index)
        char outOrdered[1005];

        for(int i = 0; i < N; i++){
            int start, end;
            cin >> start >> end;
            times.push_back(make_pair(make_pair(start, end), i));
        }

        sort(times.begin(), times.end(), customSort);

        int cTime = 0, jTime = 0;
        string out;

        // Assign first event to C always
        cTime = times[0].first.second;
        outOrdered[times[0].second] = 'C';

        for(int i = 1; i < times.size(); i++){
            if(times[i].first.first >= cTime){
                // C can do this one
                cTime = times[i].first.second;
                outOrdered[times[i].second] = 'C';
            }else{
                // C cannot do this one, J must do this one
                if(times[i].first.first >= jTime){
                    jTime = times[i].first.second;
                    outOrdered[times[i].second] = 'J';
                }else{
                    // It is not possible
                    out = "IMPOSSIBLE";
                    break;
                }
            }
        }

        if(out != "IMPOSSIBLE"){
            // Construct the output string
            for(int i = 0; i < N; i++){
                out += outOrdered[i];
            }
        }

        cout << "Case #" << caseNum << ": " << out << endline;

    }

    return 0;
    
}