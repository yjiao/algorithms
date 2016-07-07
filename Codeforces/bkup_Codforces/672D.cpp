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

LL n, k;
const LL maxN = 500010;
vector <LL> vec;

int main() {
    cin >> n >> k;
    vec.resize(n);

    LL med = 0;
    LL medl = 0;
    FORN(i, n) {scanf("%I64d ", &vec[i]); med += vec[i];}

    sort(vec.begin(), vec.end());
    
    if (med % n == 0){
	medl = med = med / n;
    } else {
	medl = med/n+1;
	med /=n;
    }

    LL small2med = 0;
    LL large2med = 0;
    LL small = med;
    LL large = medl;
    LL kk = k;
    LL steps;
    // how many steps to the smaller median?
    FORN(i, n){
	// how many steps does it take for the NEXT number to be the smallest in the vector?
	if (vec[i] > med) break;
	steps = (i+1 < n && vec[i+1] <= med) ? (1LL *(vec[i+1] - vec[i])*(i+1)) : (max(0LL, 1LL *(med-vec[i])*(i+1)));

	if (kk >= steps) kk -= steps;
	else {small = kk/(i+1) + vec[i]; break;}
    }
    // how many steps to the larger median?
    kk = k;
    FORD(i, n){
	// how many steps does it take for the NEXT number to be the largest in the vector?
	if (vec[i] < medl) break;
	steps = (i-1 > 0 && vec[i-1] >= medl ) ? (1LL *(vec[i] - vec[i-1])*(n-i)) : (max(0LL, 1LL *(vec[i] - medl)*( n-i ))) ;

	if (kk >= steps) kk -= steps;
	else {large = vec[i] - kk/( n-i ); break;}
    }
    
    cout << large - small << endl;

    return 0;
}