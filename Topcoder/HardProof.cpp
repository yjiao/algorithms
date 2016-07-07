// BEGIN CUT HERE

// END CUT HERE
#line 5 "HardProof.cpp"
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

#define MOD 1000000007
#define INF 2000000000

class HardProof {
    public:
    vector< vector <int> > adj;
    int N;

    int dfs(int parent, vector <vector<int> >& adj, vector<int>& visited, int low, int high, int cnt, bool fwd){
	visited[parent] = true;
	cnt ++;

	FORN(i, adj.size()){
	    int child;
	    if (fwd) {
		child = adj[parent][i];
	    } else {
		child = adj[i][parent];
	    }
	    bool pass = (child >= low) && (child <= high) && (!visited[i]);
	    if (pass){
		cnt = dfs(i, adj, visited, low, high, cnt, fwd);
	    }
	}
	return cnt;
    }

    int binsearch(int low, int high){
	vector<int> visited; 
	visited.resize(N, false);

	int ll = low, rr=high;
	int mid, guess = -1;

	while (ll <= rr){
	    mid = (ll + rr)/2;
	    FORN(i, visited.size()) visited[i] = false;
	    int nf = dfs(0, adj, visited, low, mid, 0, true);
	    
	    FORN(i, visited.size()) visited[i] = false;
	    int nr = dfs(0, adj, visited, low, mid, 0, false);
	    if (nf == N && nr == N){
		guess = mid;
		rr = mid - 1;
	    } else {
		ll = mid + 1;
	    }
	}

	return guess;
    }

    int minimumCost(vector <int> D) {
	N = pow(D.size(), 0.5);
//	int adj[N][N];
	
	adj.resize(N);

	FORN(i, N) {
	    adj[i].resize(N);
	    FORN(j, N) {
		adj[i][j] = D[i*N+j];
	    }
	}

	sort(D.begin(), D.end());
	int soln = INF;
	int previous = INF;
	// itereate on small bound, binsearch on upper bound, find best case
	for (auto low : D){
	    if (low != previous){
		int lim = binsearch(low, D.back());
		
		previous = low;
		if (lim > -1 && (lim - low < soln)){soln = lim - low;}
	    }
	}

	return soln;
        
    }
};
