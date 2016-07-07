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
int t, v, e, v1, v2;
vector < vector <int> > adj;

void solve(){
    vector <vector <int> > ().swap(adj);

    scanf("%d%d", &v, &e);

    adj.resize(v);

    FORN(i, e){
	scanf("%d%d", &v1, &v2);
	v1 --; v2--;

	adj[v1].PB(v2);
	adj[v2].PB(v1);
    }
    
    FORN(v1, v){
	for (auto v2 : adj[v1]){
	    if (v2 != v1) for (auto v3 : adj[v2]){
		if (v3 != v2 && v3 != v1) for (auto v4: adj[v3]){
		    if (v4 != v1 && v4 != v3 && v4!=v2){
			for (auto v5: adj[v4]) if (v5 == v1){
			    cout << 1 << endl;
			    return;
			}
		    }
		}
	    }
	}

    }
    cout << -1 << endl;
    return;
}


int main() {
    scanf("%d", &t);

    while (t--){
	solve();
    }

    return 0;
}