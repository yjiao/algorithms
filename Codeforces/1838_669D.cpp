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

LL sw, sh, n, q, type, cmv, out, in;
LL mvs = 0;
LL inmv = 0;
LL omv = 0;

int main() {
    scanf("%I64d%I64d", &n, &q);
    while (q--){
	scanf("%I64d", &type);
	if (type == 1){
	    scanf("%I64d", &cmv);
	    cmv = (cmv + ((abs(cmv/n) + 1) * n)) % n;
	    if (cmv & 1) { // odd number shift
		sw = (sw + 1) % 2;
		swap(inmv, omv);
		omv += cmv/2 + 1;
	    } else { // even number shift
		omv += cmv/2;
	    }
	    inmv += (cmv)/2;
	} else { // swap
	    swap(inmv, omv);
	    sw = (sw + 1)%2;
	}
	omv %= n/2;
	inmv %= n/2;

    }

    FORN(i, n/2){
	out = 2*i + 1 + sw;
	in =  2*i + 2 - sw;

	out += omv * (n-2);
	in += inmv * (n-2);

	out %= n;
	in %= n;
	if (out == 0) out = n;
	if (in == 0) in = n;
	
	printf("%I64d ", out);
	printf("%I64d ", in);
    
    }
    cout << '\n';
    return 0;
}