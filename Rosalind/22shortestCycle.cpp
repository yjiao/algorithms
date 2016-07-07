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
int t, v, e, v1, v2, w;
priority_queue < PII, vector<PII>, greater<PII> > Q;

void dijkstra(int node, vector<vector<PII> >& adj, vector <int>& dist){
    Q.push(MP(0, node));
    while (!Q.empty()){
	PII uw = Q.top();
	Q.pop();

	int u = uw.SS;
	for (auto a : adj[ u ]){
	    int v = a.SS, w = a.FF;
//	    cout << u << "->" << v << endl;
	    if (dist [ v ] == -1){
		dist[ v ] = dist[u] + w;
		Q.push(a);
	    }
	    else if (dist[ v ] > dist[ u ] + w){
		dist[v] = dist[u] + w;
		Q.push(a);
	    }
	}
    }
}

void solve(){
    vector < vector <PII> > adj;
    vector <int> dist;

    scanf("%d%d", &v, &e);

    adj.resize(v);
    dist.resize(v, -1);
    
    int start1, start2, startw;
    FORN(i, e){
	scanf("%d%d%d", &v1, &v2, &w);
	v1 --; v2--;
	if (i == 0){
	    start1 = v1; start2 = v2; startw = w;
	}

	adj[v1].PB(MP(w, v2));
    }

//    FORN(i, v){ cout << "adj " << i << ": "; for(auto a : adj[i]) cout << a.SS << " "; cout << endl;}
    
    dist[start2] = 0;
//    cout << "------------------------\n";
    dijkstra(start2, adj, dist);

//    for (auto d: dist) cout << d << " "; cout << endl;

    if (dist[start1] > 0) cout << dist[start1] + startw << endl;
    else cout << -1 << endl;
}

int main() {
    scanf("%d", &t);

    while (t--){
	solve();
    }

    return 0;
}