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

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
  LL rcap() { return cap - flow; }
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<vector<Edge *> > Lf;
  vector<int> layer;
  vector<int> Q;
  
  Dinic(int N) : N(N), G(N), Q(N) {}
  
  void AddEdge(int from, int to, int cap) {
    if (from == to) return;
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  LL BlockingFlow(int s, int t) {
    layer.clear(); layer.resize(N, -1);
    layer[s] = 0;
    Lf.clear(); Lf.resize(N);
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i]; if (e.rcap() <= 0) continue;
        if (layer[e.to] == -1) {
          layer[e.to] = layer[e.from] + 1;
          Q[tail++] = e.to;
        }
        if (layer[e.to] > layer[e.from]) {
          Lf[e.from].push_back(&e);
        }
      }
    }
    if (layer[t] == -1) return 0;

    LL totflow = 0;
    vector<Edge *> P;
    while (!Lf[s].empty()) {
      int curr = P.empty() ? s : P.back()->to;
      if (curr == t) { // Augment
        LL amt = P.front()->rcap();
        for (int i = 0; i < P.size(); ++i) {
          amt = min(amt, P[i]->rcap());
        }
        totflow += amt;
        for (int i = P.size() - 1; i >= 0; --i) {
          P[i]->flow += amt;
          G[P[i]->to][P[i]->index].flow -= amt;
          if (P[i]->rcap() <= 0) {
            Lf[P[i]->from].pop_back();
            P.resize(i);
          }
        }
      } else if (Lf[curr].empty()) { // Retreat
        P.pop_back();
        for (int i = 0; i < N; ++i)
          for (int j = 0; j < Lf[i].size(); ++j)
            if (Lf[i][j]->to == curr)
              Lf[i].erase(Lf[i].begin() + j);
      } else { // Advance
        P.push_back(Lf[curr].back());
      }
    }
    return totflow;
  }

  LL GetMaxFlow(int s, int t) {
    LL totflow = 0;
    while (LL flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

int T;
int N; // number of nodes
const int maxn = 1010;
vector < pair< string, string > > wordlist;
pair< string, string> wordpair;
map < pair<int, string>, int > dict;
int main() {

    cin >> T;
    FORN(i, T){ // TEST CASE -----------------------------------------------------
	cin >> N;
	wordlist = vector < pair< string, string > > ();
	dict = map < pair<int, string>, int > ();
	FORN(j, N){
	    cin >> wordpair.FF;
	    cin >> wordpair.SS;
	    wordlist.PB(wordpair);
	}
	
	Dinic d(2*N + 5);
	int s = 0;
	int t = 1;
	int id = 2;

	FORN(j, N){
	    if (dict.find( MP(1, wordlist[j].FF) ) == dict.end()){
		dict[ MP(1, wordlist[j].FF) ] = id;
		id ++;
		d.AddEdge(s, dict[ MP(1, wordlist[j].FF) ], 1);
	    }
	    if (dict.find( MP(2, wordlist[j].SS) ) == dict.end()){
		dict[ MP(2, wordlist[j].SS) ] = id;
		id ++;
		d.AddEdge(dict[ MP(2, wordlist[j].SS) ], t, 1);
	    }
	    d.AddEdge(dict[ MP(1, wordlist[j].FF) ], dict[ MP(2, wordlist[j].SS) ], 1);
	}
	
	cout << "Case #" << i+1 << ": " << N - ((id - 2) - d.GetMaxFlow(s, t)) << '\n';
    }

    return 0;
}