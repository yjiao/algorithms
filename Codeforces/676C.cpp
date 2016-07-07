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
#define FOREACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MOD 1000000007
#define INF 2000000000
LL n, k;
string s;
char prev;
vector < LL > cnts;

LL solve(char target){
    int L = 0, R = 0;
    int ans = 0;
    int cntTar = 0, cntCost = 0;
    while (R < n){
	if (s[R] == target) cntTar ++;
	else cntCost ++;
	while (cntCost > k){
	    if (s[L] == target) cntTar --;
	    else cntCost --;
	    L ++;
	}
	if (ans < cntTar + cntCost) ans = cntTar + cntCost;
	R++;
    }
    return ans;
}


int main() {
    cin >> n >> k;
    cin >> s;

    cout << max(solve('a'), solve('b')) << endl;
    return 0;
}