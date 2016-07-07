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

LL a, b, c, n;

LL solve(){
    if (a <= b - c) return n / a;

    LL x = b / (b-c) + 5;
    LL y = n / (b-c);
    
    LL cnt = max(y - x, 0LL);
    if (n >= cnt * (b-c)) n -= cnt * (b-c);
//    cout << n << endl;
    while ( n >= b ){
	n -= b;
	n += c;
	cnt ++;
    }

    cnt += n/ a;
    return max(cnt, 0LL);

}

int main() {
    cin >> n >> a >> b >> c;

    cout << solve() << endl;
    return 0;
}