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

int v, e, v1, v2;
vector < vector <int> > adj;
vector <int> deg;

int main() {
    scanf("%d%d", &v, &e);
    adj.resize(v);
    deg.resize(v);

    FORN(i, v) {deg[i] = 0;}

    FORN(i, e){
	scanf("%d%d", &v1, &v2);
	v1 --; v2 --;
	adj[v1].PB(v2);
	adj[v2].PB(v1);
	deg[v1] += 1;
	deg[v2] += 1;
    }

    FORN(i, v){
	int cnt = 0;
	FORN(j, adj[i].size()){
	    cnt += deg[adj[i][j]];
	}
	cout << cnt << " ";
    }
    cout << endl;

    return 0;
}