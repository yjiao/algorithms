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

int T, N, M, nlike;
typedef vector < pair< int, int > > VPII;
vector < VPII > people;
const int maxn = 2010;
int ans[maxn];

int main() {
    cin >> T;
    FOR1(t, T){
	fill(ans, ans+maxn, 0);
	people = vector < VPII >();


	cin >> N >> M; people.resize(M);
	FORN(m, M){
	    cin >> nlike;

	    FORN(l, nlike){
		PII temp;
		cin >> temp.FF;
		cin >> temp.SS;
		people[m].PB(temp);
	    }
	}
	bool possible = true;
	while (possible){
	    int h = -1;

	    FORN(iperson, M){
		// check if hard to please
		int test = 0;
		int imalted = 0;
		int total_malted = 0;
		FORN(i, people[iperson].size()){
		    if (ans[people[iperson][i].FF] ^ people[iperson][i].SS) test ++;
		    if (people[iperson][i].SS == 1) imalted=i;
		}
		FORN(i, N){
		    if (ans[i]) total_malted ++;
		}
		if (test == people[iperson].size()) {
		    if (total_malted == N){
			possible = false;
			break;
		    }
		    h = iperson;
		    // flip one bit
		    ans[people[h][imalted].FF] = 1;
		    break;
		}
	    }
	    if ( h == -1) break;
	}


	if (! possible){
	    cout << "Case #" << t << ": " << "IMPOSSIBLE" << '\n';
	} else {
	    FORN(i, N){
		cout << "Case #" << t << ": " << ans[i] << ' ';
	    }
	    cout << '\n';
	}
    }


    return 0;
}