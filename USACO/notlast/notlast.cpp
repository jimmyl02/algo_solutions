#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

#define INF INT_MAX
#define endline '\n'
#define ll long long

struct cow {
    string name;
    int milk;
};

bool cowComparator(cow a, cow b){
    return a.milk < b.milk;
}

int main()
{

    ios::sync_with_stdio(false);
    
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");
	
    unordered_map<string, int> allCows;
    
    allCows["Bessie"] = 0;
    allCows["Elsie"] = 0;
    allCows["Daisy"] = 0;
    allCows["Gertie"] = 0;
    allCows["Annabelle"] = 0;
    allCows["Maggie"] = 0;
    allCows["Henrietta"] = 0;

    int N;

    fin >> N;

    for(int i = 0; i < N; i++){
        string name;
        int milk;

        fin >> name >> milk;

        allCows[name] += milk;

    }

    vector<cow> cowList;

    for(auto i : allCows){
        cow c;
        c.name = i.first;
        c.milk = i.second;

        cowList.push_back(c);
    }

    // sort so smallest is at the beginning
    sort(cowList.begin(), cowList.end(), cowComparator);

    int smallest = cowList[0].milk;
    int moreThanOne = -1;
    bool tie = false;
    for(int i = 1; i < cowList.size(); i++){
        if(cowList[i].milk != smallest){
            // check if moreThanOne has been set
            if(moreThanOne != -1){
                // there has been a previous one, see if same value. If same, it is a tie
                if(cowList[i].milk == cowList[moreThanOne].milk){
                    tie = true;
                }
                break;
            }else{
                // first instance that is not smallest
                moreThanOne = i;
            }
        }
    }

    if(moreThanOne == -1 || tie){
        // All cows were the same or there was a tie
        fout << "Tie" << endline;
    }else{
        // There is no tie, just print cow at position moreThanOne
        fout << cowList[moreThanOne].name << endline;
    }

    fin.close();
    fout.close();

    return 0;
    
}