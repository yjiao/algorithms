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
string bstr;

LL powmod(LL a, LL b) {LL res=1; a %= MOD; for(;b;b>>=1) {if (b&1) res = res*a % MOD; a = a*a % MOD;} return res;}

LL solve(int loc){
    LL ans;
    if (loc == bstr.size()){
	return ans % MOD;
    }
    if ( bstr[loc]  == '0'){ return (2*solve(loc+1))%MOD; }
    else { 
	LL recurse = 2*solve(loc+1)%MOD; 
	LL cross = powmod (2, 2*(bstr.size() - loc) - 2);
//	cout << "bstr[" << loc << "]: " << bstr[loc] << endl;
//	cout << "recurse: " << recurse << endl;
//	cout << "cross: " << cross << endl;
	
	return (recurse + cross)%MOD;
    }

}

int main() {
    cin >> bstr;
    cout << solve(0)%MOD << endl;

    return 0;
}