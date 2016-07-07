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

int nv, ne, u, v, itime;
vector<int> indeg;
vector<int> pre, post, stack;
vector<vector<int> > adj;

void topo(int node){
    pre[node] = itime;
    itime ++;

    for (auto child : adj[node]){
	if (pre[child] > -1 && post[child] == -1){
	    cout << "GRAPH INCLUDES A CYCLE!!";
	}
	else if (pre[child] == -1 && post[child] == -1){
	    topo(child);
	}
    }

    post[node] = itime;
    stack.PB(node);
}

int main() {
    clock_t start, stop;
    start = clock();
    scanf("%d%d", &nv, &ne);
    itime = 0;

    indeg.resize(nv, 0);
    pre.resize(nv, -1);
    post.resize(nv, -1);
    adj.resize(nv);

    FORN(i, ne){
	scanf("%d%d", &u, &v);
	u--; v--;
	indeg[v] += 1;
	adj[u].PB(v);
    }
    
    FORN(i, nv){
//	cout << "node: " << i << ", indeg: " << indeg[i] << endl;
	if (indeg[i] == 0) topo(i);
    }

//    FORD(i, stack.size()){
//	 cout << stack[i] + 1 << " ";
//    } cout << endl;

    stop = clock();

    cout << (double)(stop - start)/CLOCKS_PER_SEC*1000 << endl << setprecision(5);
    return 0;
}