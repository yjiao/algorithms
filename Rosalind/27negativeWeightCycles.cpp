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

int tests, nv, ne, u, v, w;
//vector <vector <PII> > adj;
vector <vector<int> > edgelist;
vector<int> dist;

bool update(int u, int v, int w){
    if (dist[v] > dist[u] + w){
	dist[v] = dist[u] + w;
	return true;
    }
    return false;
}

bool bf(){
    int repeat = nv - 1;
    bool updateflag = false;
    while (repeat --){
	for (auto edge : edgelist){
//	    cout << "      edge: " << u << "->" << v << ", " << w << endl;
	    int& u = edge[0];
	    int& v = edge[1];
	    int& w = edge[2];
	    bool temp = update(u, v, w);
	    updateflag = updateflag || temp;
	}

	if (! updateflag){
	    return false;
	}
    }

//    for (auto d : dist) cout << d << " "; cout << endl;

    // last round of update
    for (auto edge : edgelist){
	int& u = edge[0];
	int& v = edge[1];
	int& w = edge[2];
	if (update(u, v, w)){ return true;}
    }
    return false;
}

int main() {

    scanf("%d", &tests);
    while(tests--){
//	vector < vector<PII> > ().swap(adj);
	vector <vector<int> >().swap(edgelist);

	scanf("%d%d", &nv, &ne);
//	cout << "------------ " << nv << ", " << ne << endl;

	vector<int>().swap(dist);
	dist.resize(nv, 0);

	FORN(i, ne){
	    scanf("%d%d%d", &u, &v, &w);
	    u--; v--;
	    edgelist.PB({u, v, w});
	}


	if (bf()) {
	    cout << 1 << "\n";
	} else {
	    cout << -1 << "\n";
	}
    }
    return 0;
}