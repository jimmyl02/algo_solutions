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

    int num = 0, sum = 0;

    while ( fin >> num ) {

        int fuel = (num / 3) - 2;
        
        sum += fuel;

        while((fuel / 3) - 2> 0){

            sum += (fuel / 3) - 2;
            fuel = (fuel / 3) - 2;
        
        }

    }

    cout << sum;
	
    fin.close();
    fout.close();

    return 0;
    
}