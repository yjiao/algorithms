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
vector <vector<int> > adj;
vector <int> dist;
queue<int> q;

int main() {
    scanf("%d%d", &v, &e);
    adj.resize(v);
    dist.resize(v);
    FORN(i, v){dist[i] = -1;}
    FORN(i, e){
	scanf("%d%d", &v1, &v2);
	v1--; v2--;
	adj[v1].PB(v2);
//	adj[v2].PB(v1);
    }
    
    q.push(0);
    dist[0] = 0;
    int node;
    while (!q.empty()){
	node = q.front();
//	cout << "---------------- node: " << node << endl;
//	cout << "     dist: " << dist[node] << endl;
	q.pop();
	FORN(i, adj[node].size()){
	    if (dist[adj[node][i]] == -1){
//		cout << "      child: " << adj[node][i] << endl;
		q.push(adj[node][i]);
		dist[ adj[node][i] ] = dist[ node ] + 1;
//		cout << "      child dist : " << dist[adj[node][i]] << endl;
	    }
	}
    }
    
    for (auto d : dist) { cout << d << " ";}
    cout << endl;

    return 0;
}