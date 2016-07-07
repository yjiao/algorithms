// BEGIN CUT HERE

// END CUT HERE
#line 5 "DoubleString.cpp"
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

class DoubleString {
    public:
    string check(string S) {
	if (S.size()%2 > 0) return "not square";

	int half = S.size()/2;
	FORN(i, half){
	    if (S[i] != S[i+half]){
		return "not square";
	    }
	}
	return "square";
    }
};
