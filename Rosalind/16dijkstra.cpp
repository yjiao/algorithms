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
priority_queue< PII, vector<PII>, greater<PII> > Q;
vector < vector <PII> > adj;
vector<int> dist;

void dijkstra(int node){
    for (auto p : adj[node]){
	dist[p.SS] = p.FF;
	Q.push(p);
    }

    while (!Q.empty()){
	PII wv = Q.top();
	Q.pop();
	for (auto p : adj[wv.SS]){
	    if ( dist[p.SS] == -1 || dist[p.SS] > dist[wv.SS] + p.FF ){
		dist[p.SS] = dist[wv.SS] + p.FF;
		Q.push(p);
	    }
	}
    }

}

int main() {

    scanf("%d%d", &v, &e);

    adj.resize(v);
    dist.resize(v, -1);

    FORN(i, e){
	scanf("%d%d%d", &v1, &v2, &w);
	v1 --; v2--;

	adj[v1].PB(MP(w, v2));
    }
    
    dist[0] = 0;
    dijkstra(0);
    for (auto d : dist) cout << d << " "; cout << endl;

    return 0;
}