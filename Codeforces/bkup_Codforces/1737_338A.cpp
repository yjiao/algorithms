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

//#define MOD 1000000007
#define INF 2000000000
LL n, m, k, doub;
LL longseg, powers, steps;
const LL MOD = 1000000009;

LL powmod(LL a, LL b) {LL res=1; a %= MOD; for(;b;b>>=1) {if (b&1) res = res*a % MOD; a = a*a % MOD;} return res;}

LL solve(){
    doub = max(0LL, m - (n/k)*(k-1) - n%k);

//    cout << "doubling: " << doub << endl;
    LL soln;
    if (doub == 0){
	soln = 0;
    } else {
	LL coeff_k = powmod(2, doub + 1) - 2;
//	cout << "coeff_k: " << coeff_k << endl;
	soln = (coeff_k*k) % MOD;
    }
//    cout << "partial soln: " << soln << endl;
//    cout << "leftover: " << m - doub*k << endl;
//    cout << m - doub * k  << endl;
    
    return (soln + m - doub*k + MOD) % MOD; // need this here in case the -2 messes up when %MOD == 0
}

int main() {
    cin >> n >> m >> k;
//    LL base, power;
//    while (cin >> base){
//	cin  >> power;
//	cout << base << "^" << power << endl;
//	cout << powmod(base, power);
//    }
    cout << solve() << endl;

    return 0;
}