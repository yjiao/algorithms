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

int v, e, v1, v2, w;
//vector < vector <PII> > adj;
vector < vector<int> > edgelist;
vector< int > dist;

bool update(vector<int> edge){
    int v = edge[1], u = edge[0], w = edge[2];
//    cout << u << "->" << v << ", " << w << endl;
    if (dist[v] > dist[u] + w && dist[u] < INF){
	dist[v] = dist[u] + w;
	return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &v, &e);
    dist.resize(v, INF);
    FORN(i, e){
	scanf("%d%d%d", &v1, &v2, &w);
	v1--; v2--;
	edgelist.PB({v1, v2, w});
    }
    
    dist[0] = 0;
    bool flag = false;
    FORN(i, v - 1){
	for (auto edge : edgelist){
	    bool upd = update(edge);
//	    for (auto d: dist) cout << d << " "; cout << endl;
	    flag = flag || upd;
	}
	if (! flag){ break;}
    }

    for (auto d : dist){
	if (d == INF) cout << "x" << " ";
	else cout << d << " ";
    }  cout << endl;

    return 0;
}