// BEGIN CUT HERE

// END CUT HERE
#line 5 "Plusonegame.cpp"
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

class Plusonegame {
    public:
    string getorder(string s) {
	int plus = 0;
	vector<int> num;
	FORN(i, s.size()){
	    if (s[i] == '+'){
		plus++;
	    } else {
		num.PB((int)s[i] - '0');
	    }
	}
	
	sort(num.begin(), num.end());

	int nix, pix; nix=pix=0;
	string ans;
	FORN(i, s.size()){
	    if (nix < num.size() && pix == num[nix]){
		ans += (char) num[nix] + '0';
		nix ++;
	    } else if (pix < plus && pix < num[nix]){
		ans += '+';
		pix ++;
	    } else{
		if (pix < plus){ ans += '+'; pix ++;}
		else if (nix < num.size()){ ans += (char) num[nix] + '0'; nix ++;}
	    }
	
	}

	return ans; 
    }
};
