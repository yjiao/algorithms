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

// version using in degrees instead of DFS

int nv, ne, u, v, itime;
vector<int> indeg, Q, ans;
vector<vector<int> > adj;

void toposort(){
    FORN(i, nv){
	if (indeg[i] == 0){
	    Q.PB(i);
	    ans.PB(i);
	}
    }
    while (Q.size() > 0){
	int source = Q.back();
	Q.pop_back();

	for (auto child : adj[source]){
	    indeg[child] --;
	    if (indeg[child] < 0){
		cout << "ERROR: NOT A DAG!!!\n";
	    } else if (indeg[child] == 0){
		Q.PB(child);
		ans.PB(child);
	    }
	}
    }
}

int main() {
    clock_t start, stop;
    start = clock();
    scanf("%d%d", &nv, &ne);
    itime = 0;

    indeg.resize(nv, 0);
    adj.resize(nv);

    FORN(i, ne){
	scanf("%d%d", &u, &v);
	u--; v--;
	indeg[v] += 1;
	adj[u].PB(v);
    }
    
    toposort();
//    for (auto a : ans) cout << a + 1 << " "; cout << endl;
    stop = clock();
    cout << (double)(stop - start)/CLOCKS_PER_SEC*1000 << endl << setprecision(5);
    return 0;
}