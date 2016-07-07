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

int n;
vector < int > A;

LL insertSort(){
    LL cnt = 0;
    for (int i = 1; i < n; i ++){
	int k = i;
	while (k > 0){
	    if (A[k] < A[k-1]){ swap(A[k], A[k-1]); cnt ++;}
	    k --;
	}
    }
    return cnt;
}

int main() {

    cin >> n;
    A.resize(n);
    FORN(i, n){ scanf("%d", &A[i]);}
    cout << insertSort() << endl;

    return 0;
}