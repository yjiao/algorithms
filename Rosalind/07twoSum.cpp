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

int k, n;

void solve(){
    map<int, vector <int> > d;
    vector <int> A; A.resize(n);
    FORN(i, n){ scanf("%d", &A[i]); }
    FORN(i, n){
	d[ A[i] ].PB(i);
	if (d.find( -A[i] ) != d.end() && A[i] != 0){
//	    cout << "\n" << k << ": " << A[i] << " ------------- found\n";
	    cout << min(i+1, d[-A[i]][0]+1) << " " << max(i+1, d[-A[i]][0]+1) << endl;
	    return;
	} else if (A[i] == 0 && d[0].size() > 1){
//	    cout << "\n" << k << ": " << A[i] << " ------------- found\n";
	    cout << min(d[0][0], d[0][1])+1 << " "<< max(d[0][0], d[0][1])+1 << endl;
	    return;
	}
    }
    cout << -1 << endl;
    return;
}

int main() {
    scanf("%d%d", &k, &n);

    while (k--){
	solve();
    }

    return 0;
}