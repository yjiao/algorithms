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

LL a, b, n, l, m, t, val, mid;
LL lo, hi;

LL get(LL idx){
    return a + (idx-1) * b;
}

LL sum(LL idx) {
    return (get(l) + get(idx)) * (idx-l+1) / 2;
}

bool check(LL idx){
    if (get(idx) <= t && sum(idx) <= m*t) return true;
    else return false;
}

LL solve(){
    if (get(l) > t) return -1;

    lo = l;
    hi = (t - a) / b + 10;

    while ( lo < hi ){
	mid = (lo + hi)/ 2;
	if (check(mid)) lo = mid + 1;
	else hi = mid;
    }

    if (check(lo)) return lo;
    else return lo - 1;

}

int main() {
    scanf("%I64d%I64d%I64d", &a, &b, &n);
    while (n--){
	scanf("%I64d%I64d%I64d", &l, &t, &m);
	cout << solve() << '\n';
    }

    return 0;
}