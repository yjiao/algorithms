// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysCandyBags.cpp"
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

class EllysCandyBags {
    public:
    int getSize(vector <string> packets) {
	vector <int> candies; candies.resize(26, 0);
	FORN(i, packets.size()){
	    FORN(j, packets[i].size()){
		candies[packets[i][j] - 'A'] ++;
	    }
	}
	
	int ans = 0;
	FORN(i, candies.size()){
	    ans += candies[i]/2;
	}
	return ans;
    }
};
