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

int ntests, nvar, nclause, a, b;

void dfs(int root, vector< vector<int> >& adj, vector<int>& stack, vector<int>& visited, int itime){
    // returns a stack in order of increasing post number (source would be at the very end)
    visited[root] = itime;
    for (auto child : adj[root]){
	if (visited[child] < 0){
	    dfs(child, adj, stack, visited, itime);
	}
    }
    stack.PB(root);
}

int negateNode(int node){ 
    return (node + nvar) % (2*nvar);
}

void solve(){
    scanf("%d%d", &nvar, &nclause);

    // set variables
    vector< vector<int> > fwd_adj, rev_adj;
    vector<int> fwd_visited, rev_visited;
    vector<int> fwd_stack, rev_stack;
    vector<int> idx_map;

    fwd_adj.resize(nvar*2);
    rev_adj.resize(nvar*2);
    fwd_visited.resize(nvar*2, -1);
    rev_visited.resize(nvar*2, -1);
    idx_map.resize(nvar*2);
    
    // read input    
    FORN(i, nclause){
	scanf("%d%d", &a, &b);
	int ta=a, tb=b;
	a = (a < 0) ? abs(a) - 1: a + nvar - 1;
	b = (b < 0) ? abs(b) - 1: b + nvar - 1;
//	idx_map[a] = ta;
//	idx_map[b] = tb;
//	idx_map[negateNode(a)] = -ta;
//	idx_map[negateNode(b)] = -tb;
	
	// push inference to forward adj matrix
	rev_adj[a].PB(negateNode(b));
	rev_adj[b].PB(negateNode(a));

	// push inference to reverse adj matrix
	fwd_adj[negateNode(b)].PB(a);
	fwd_adj[negateNode(a)].PB(b);
    }
    FORN(i, nvar){
	idx_map[i] = -(i+1);
	idx_map[i+nvar] = (i+1);
    }
//    FORN(i, idx_map.size()){
//	cout << "idx_map[" << i << "] = " << idx_map[i]<< endl;
//    }

    // find sources on reverse graph
    FORN(i, 2*nvar){
	if (rev_visited[i] < 0){
	    dfs(i, rev_adj, rev_stack, rev_visited, 0);
	}
    }

    // pull out SCCs on fwd graph
    int itime = 0;
    FORD(i, 2*nvar){
	int node = rev_stack[i];
//	cout << "traverse forward graph from node: " << idx_map[node] << endl;
	if (fwd_visited[node] < 0){
	    dfs(node, fwd_adj, fwd_stack, fwd_visited, itime);
	    itime ++;
	}
    }
    
    vector<vector<int> > ccs; ccs.resize(itime);
    vector<int> soln;
    
    // build strong ccs
    FORN(i, 2*nvar){
	if (fwd_visited[i] > -1){
	    if (fwd_visited[i] == fwd_visited[negateNode(i)]){
		cout << 0 << endl;
		return;
	    } else {
		ccs[ fwd_visited[i] ].PB(i);
	    }
	}
    }
    

//    cout << "---------------------\n";
//    FORN(i, itime){
//	cout << "CC" << i << ": ";
//	for (auto v: ccs[i]) cout << idx_map[v] << " "; cout << endl;
//    }

    // pull out strong ccs and assign values
    FORN(cc_id, itime){
	for (auto v : ccs[ cc_id ]){
	    if (fwd_visited[v] > -1){
		soln.PB(idx_map[v]); 
		fwd_visited[negateNode(v)] = -1;
	    }
	}
    }
    auto func=[](int i, int j) { return abs(i) < abs(j); };
    sort(soln.begin(), soln.end(), func);
    cout << "1 ";
    for (auto s : soln) cout << s << " "; cout << endl;
//    printSol(soln);
}

int main() {
    scanf("%d", &ntests);

    while (ntests -- ){
	solve();
    }

    return 0;
}