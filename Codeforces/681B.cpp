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

LL n;
LL aval = 1234567, bval = 123456, cval = 1234;

void solve(){
    FORN(a, n/aval+1){
	FORN(b, (n - a*aval)/bval + 1){
	    LL leftover = n - a*aval- b*bval;
	    if (leftover % cval == 0LL){
		cout << "YES\n";
		return;
	    }
	}
    }
    cout << "NO\n";
    return;

}

int main() {
    cin >> n;
    solve();

    return 0;
}