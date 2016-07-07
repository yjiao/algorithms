// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysBounceGame.cpp"
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

class EllysBounceGame {
    public:
    int n;
    LL sim(int pos, int dir, vector <int> tiles){
	LL soln = 0;
	LL csum = 0;
	int lasti = pos;

	while (pos >= 0 && pos < n){
	    soln += tiles[pos];

	    if (tiles[pos] & 1){
		tiles[pos] ++;
		soln += csum;
		swap(lasti, pos);
		dir *= -1;
		lasti += dir;
	    } else {
		csum += tiles[pos];
	    }
	    pos += dir;
	}
	return soln;
    }
    long long getScore(vector <int> tiles) {
	n = tiles.size();
	LL t, ans = 0;
	FORN(i, tiles.size()){

	    t = sim(i, -1, tiles);
	    ans = max(ans, t);

	    t = sim(i, 1, tiles);
	    ans = max(ans, t);
	}
        return ans;
    }
};
