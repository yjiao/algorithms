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
int nvertices, nedges, a, b, nvisited;
vector < vector<int> > fwd_adj, rev_adj;
vector<int> rev_stack, fwd_stack;
vector<int>fwd_visit, rev_visit;

void dfs(int root, vector< vector<int> >& adj, vector<int>& visited, vector<int>& stack, int cc_id){
    visited[root] = cc_id;

    for (auto child : adj[root]){
	if (visited[child] == -1){
	    dfs(child, adj, visited, stack, cc_id);
	}
    }

    stack.PB(root);
}

void toposort(vector<int>& indeg, vector< set<int> >& adj){
    vector <int> Q;
    FORN(i, indeg.size()){
	if (indeg[i] == 0){ Q.PB(i);}
    }

    if (Q.size() > 1){
	cout << "-1\n";
	return;
    }

    while (Q.size() > 0){
//	cout << "Q: "; for (auto q: Q) cout << q << " "; cout << endl;

	if (Q.size() > 1){
	    cout << "-1\n";
	    return;
	}

	int node = Q[0];
	Q.pop_back();

	for (auto child: adj[node]){
//	    cout << "  child: " << child << endl;
	    indeg[child] --;
	    if (indeg[child] == 0){
		Q.PB(child);
	    }
	}
    }
    cout << "1\n";
    return;
}

void solve(){

    // variable defs
    vector < vector<int> >().swap(fwd_adj);
    vector < vector<int> >().swap(rev_adj);
    vector <int>().swap(rev_stack);
    vector <int>().swap(fwd_stack);
    vector <int>().swap(rev_visit);
    vector <int>().swap(fwd_visit);

    scanf("%d%d", &nvertices, &nedges);
    fwd_adj.resize(nvertices);
    rev_adj.resize(nvertices);
    fwd_visit.resize(nvertices, -1);
    rev_visit.resize(nvertices, -1);
    
    // read variables
    FORN(i, nedges){
	scanf("%d%d", &a, &b);
	a--; b--;
	fwd_adj[a].PB(b);
	rev_adj[b].PB(a);
    }
    
    // call dfs on reverse graph
    FORN(i, nvertices){
	if (rev_visit[i] == -1){
	    dfs(i, rev_adj, rev_visit, rev_stack, 0);
	}
    }
    
// call dfs on foward graph to get SCCs    
    int cc_id = 0;
    FORD(i, nvertices){
	int node = rev_stack[i];
	if (fwd_visit[node] == -1){
	    dfs(node, fwd_adj, fwd_visit, fwd_stack, cc_id);
	    cc_id ++;
	}
    }
    
//    FORN(i, nvertices){
//	cout << "vertex " << i << ": " << fwd_visit[i]<< endl;
//    }
//    int prevCC = fwd_visit[fwd_stack[0]];

    // Create metagraph
    vector < set<int> > meta_adj; 
    vector <int> meta_indeg; 
    meta_adj.resize(cc_id);
    meta_indeg.resize(cc_id, 0);
    
    FORN(i, nvertices){
	int current_cc = fwd_visit[i];
	for (auto child : fwd_adj[i]){
	    int child_cc = fwd_visit[child];
	    if (child_cc != current_cc){ // out edge
		meta_adj[current_cc].insert(child_cc);
		meta_indeg[child_cc] ++;
	    }
	}
    }

//    FORN(i, cc_id){
//	cout << i << ": " << meta_indeg[i] << endl;
//	cout << "     adj: "; for (auto a : meta_adj[i]) cout << a << " "; cout << endl;
//    }
    
    toposort(meta_indeg, meta_adj);
//	if (outedges.size() > 1){
//	    cout << "-1\n";
//	    return;
//	}
//    cout << "1\n";
    return;

}

int main() {
    int ntests;
    scanf("%d", &ntests);
    while (ntests -- ){
//	cout << "test: " << ntests << "-------------------------\n";
	solve();
    }

    return 0;
}