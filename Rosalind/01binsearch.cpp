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

int n, m, q;
vector < int > arr;

int binsearch(int q){
    int ans = -1;
    int ll, rr, mid;
    ll = 0;
    rr = n;
    while (ll <= rr){
	mid = (ll + rr)/ 2;
	if ( arr[mid] <= q ){
	    if (arr[mid] == q){ ans = mid; return ans + 1;}
	    ll = mid + 1;
	} else {
	    rr = mid - 1;
	}
    }
    return ans;
}

int main() {

    cin >> n >> m;
    arr.resize(n);

    FORN(i, n){
	scanf("%d", &arr[i]);
    }

    FORN(i, m){
	scanf("%d", &q);
	cout << binsearch(q) << " ";
    }
    cout << endl;
    return 0;
}