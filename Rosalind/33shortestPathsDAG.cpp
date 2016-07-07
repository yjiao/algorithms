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
int nvertices, nedges, a, b, w;
vector < vector<PII> > adj;
vector<int> indeg, sorted_nodes, dist;

void toposort(){
    vector<int> Q;

    FORN(i, indeg.size()){
	if (indeg[i] == 0){ Q.PB(i);}
    }

//    cout << "Q:"; for (auto q: Q) cout << q << " "; cout << endl;

    while (Q.size() > 0){
	int parent = Q.back();
//	cout << "parent: " << parent << "-------\n";
	Q.pop_back();
	sorted_nodes.PB(parent);
//	cout << "sorted list: "; for (auto s: sorted_nodes) cout << s << " "; cout << endl;
	
	for (auto child : adj[parent]){
//	    cout << parent << " --> " << child.FF << ", " << child.SS << endl;
	    indeg[child.FF] --;
	    if (indeg[child.FF] == 0) { Q.PB(child.FF); }
	}
    }

}

void update(int u, int v, int w){
    if (dist[u] < INF){
	if (dist[v] > dist[u] + w){ dist[v] = dist[u] + w;}
    }
}

int main() {
    scanf("%d%d", &nvertices, &nedges);
    adj.resize(nvertices);
    indeg.resize(nvertices, 0);
    dist.resize(nvertices, INF);
    // read variables
    FORN(i, nedges){
	scanf("%d%d%d", &a, &b, &w);
	a--; b--;
	adj[a].PB(MP(b, w));
	indeg[b] ++;
    }
    
    
    toposort();

    dist[0] = 0;
    for (auto node : sorted_nodes){
	for (auto child : adj[node]){
	    update(node, child.FF, child.SS);
	}
    }

    for (auto d : dist){
	if (d == INF) {cout << "x ";}
	else {cout << d << " ";}
    }
    cout << endl;

    return 0;
}