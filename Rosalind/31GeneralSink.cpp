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

int dfs(int root, vector< vector<int> >& adj, vector<bool>& visited, int cnt){
    visited[root] = true;
    cnt ++;

    for (auto child : adj[root]){
	if (!visited[child]){
	    cnt = dfs(child, adj, visited, cnt);
	}
    }
    return cnt;
}

void solve(){
    int nvertices, nedges, a, b, nvisited;
    vector < vector<int> > adj;
    vector<bool> couldBeGenSink;

    scanf("%d%d", &nvertices, &nedges);
    adj.resize(nvertices);
    couldBeGenSink.resize(nvertices, true);

    FORN(i, nedges){
	scanf("%d%d", &a, &b);
	a--; b--;
	adj[a].PB(b);
    }


    FORN(node, nvertices){
	vector<bool> visited;
	visited.resize(nvertices, false);
	if (couldBeGenSink[node]){
//	    cout << "testing " << node << " as possible gen sink\n";
	    int cnt = dfs(node, adj, visited, 0);
	    if (cnt < nvertices){
		FORN(i, nvertices){
		    if (visited[i]) { couldBeGenSink[i] = false;}
		}
	    } else {
		cout << node+1 << endl;
		return;
	    }
	}
    }
    cout << -1 << endl;
    return;
}

int main() {
    int ntests;
    scanf("%d", &ntests);
    while (ntests -- ){
	solve();
    }

    return 0;
}