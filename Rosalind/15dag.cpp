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
int t, v, e, v1, v2, clk;
vector < vector <int> > adj;
vector <int> pre, post;

bool dfs_acyl(int node, int clk){
    pre[node] = clk;

    bool flag = true;
    for (auto a : adj[node]){
	clk ++;
	if (pre[a] == -1){
	    flag = flag && dfs_acyl(a, clk);
	} else {
	    if (post[a] == -1){ 
		return false;
	    }
	}
    }
    post[node] = clk;
    return flag;
}

void solve(){
    vector <vector <int> > ().swap(adj);
    vector < int > ().swap(pre);
    vector < int > ().swap(post);

    scanf("%d%d", &v, &e);

    adj.resize(v);
    pre.resize(v, -1);
    post.resize(v, -1);

    FORN(i, e){
	scanf("%d%d", &v1, &v2);
	v1 --; v2--;

	adj[v1].PB(v2);
    }
    
    clk = 0;
    FORN(i, v){
	if (pre[i] == -1){
	    if (!dfs_acyl(i, clk)) { cout << -1 << endl; return;}
	}
    }
    cout << 1 << endl; return;
}

int main() {
    scanf("%d", &t);

    while (t--){
	solve();
    }

    return 0;
}