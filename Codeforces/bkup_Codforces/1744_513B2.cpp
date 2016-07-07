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

//LL powmod(LL a, LL b) {LL res=1; a %= MOD; for(;b;b>>=1) {if (b&1) res = res*a % MOD; a = a*a % MOD;} return res;}

int main() {
    LL m, n;
    scanf("%I64d%I64d", &n, &m);

    LL comp = 1;
    FORN(i, n) comp <<= 1;
    comp /= 4;

    vector<int> ff, ss;
    
    for (int i = 1; i <= n; i ++){
//	printf("n: %d, comp: %d, m: %d\n", n, comp, m);

	if (m <= comp){
//	    printf("m <= comp\n");
	    ff.PB(i);
	}
	else {
	    ss.PB(i);
	    m -= comp;
	}
       comp >>= 1;

    }
    
    FORN(i, ff.size()){ printf("%d ", ff[i]);}
    FORD(i, ss.size()){ printf("%d ", ss[i]);}

    printf("\n");

    return 0;
}