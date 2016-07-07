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

int T;
const int maxn = 50;
int adj[maxn][maxn];
int N;
LL M;
string ans;

string solve(int N, LL M){
    if ((M - 1)>>(N-2)) return "IMPOSSIBLE\n";

    memset(adj, 0, sizeof(adj));
	

    for (int i = 1; i < N; i ++){
	for (int j = i+ 1; j < N; j ++){
	    adj[i][j] = 1;
	}
    }

    // always set extra 1 bit
    adj[0][N-1] = 1;
    for (int bit_idx = 0; bit_idx < N; bit_idx++){
	if ( (1LL << bit_idx) & (M-1) ) adj[0][N - bit_idx - 2] = 1;
    }
    
    string soln = "POSSIBLE\n";
    FORN(i, N){
	FORN(j, N) soln += (char)('0'+adj[i][j]);
	soln += '\n';
    }
    return soln;
}

int main() {
    cin >> T;
    FOR1(t, T){
	cin >> N >> M;
	ans = solve(N, M);

	cout << "Case #" << t << ": " << ans;
    }


    return 0;
}