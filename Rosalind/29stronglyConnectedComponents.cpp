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

int ne, nv, u, v;
vector< vector<int> > fdj, rdj;
vector<int> fstack, rstack;
vector<bool> fvisit, rvisit;

void dfs(int root, vector< vector<int> >& adj, vector<bool>& visited, vector<int>& stack){
    visited[root] = true;
    for (auto child : adj[root]){
	if (!visited[child]){
	    dfs(child, adj, visited, stack);
	}
    }
    stack.PB(root);
}

int main() {
    scanf("%d%d", &nv, &ne);

    fdj.resize(nv);
    rdj.resize(nv);
    fvisit.resize(nv);
    rvisit.resize(nv);

    FORN(i, ne){
	scanf("%d%d", &u, &v);
	u--; v--;
	fdj[u].PB(v);
	rdj[v].PB(u);
    }
    
    // get fwd SINK SCCs from rev SOURCE SCCs
    FORN(root, nv){
	if (! rvisit[root]){
	    dfs(root, rdj, rvisit, rstack);
	}
    }
//    for(auto s : rstack) cout << s << " "; cout << endl;
    
    
    int ans = 0;
    FORD(i, nv){
	int root = rstack[i];
//	cout << "root: " << root << "\n";
	if (! fvisit[root]){
	    dfs(root, fdj, fvisit, fstack);
	    ans ++;
	}
    }

    cout << ans << endl;
    
    return 0;
}