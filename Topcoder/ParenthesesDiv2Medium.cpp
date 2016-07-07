// BEGIN CUT HERE

// END CUT HERE
#line 5 "ParenthesesDiv2Medium.cpp"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>

using namespace std;

typedef long long LL;                                                                                                                                                              
typedef pair<int,int> PII;
typedef pair<PII,char> PIIC;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define MOD 1000000007
#define INF 2000000000

class ParenthesesDiv2Medium {
    public:
    vector<int> traverse (int curpos, int cnt, int nopen, vector<int> moves, int N, string s){
	if (nopen > N - curpos) {return {};}
	if (cnt > N/2 + 1) {return {};}
	if (curpos == N-1){
	    if (nopen != 1){return {};}
	    else {return moves;}
	}
	
	vector<int> mvs1, mvs2;
	//open
	if (s[curpos] == ')'){
	    moves.PB(curpos);
	    cnt++;
	}
	mvs1 = traverse(curpos+1, cnt, nopen + 1, moves, N, s);

	// close
	if (s[curpos] == '('){
	    moves.PB(curpos);
	    cnt ++;
	}
	if (nopen > 0){
	    mvs2 = traverse(curpos+1, cnt, nopen - 1, moves, N, s);
	}

	if (mvs1.size()) {return mvs1;}
	else if (mvs2.size()) {return mvs2;}
	else return {};

	
    }

    vector <int> correct(string s) {
	vector <int> mvs;
	int sz = s.size();
	mvs = traverse(0, 0, 0, mvs, sz, s);
	for (auto m : mvs) cout << m << " "; cout << endl;
	return mvs;
        
    }
};
