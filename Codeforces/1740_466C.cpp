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

int main() {

    int n;
    vector<LL> ar;

    scanf("%d", &n);

    ar.resize(n);
    LL sum = 0;

    FORN(i, n){
	scanf("%I64d", &ar[i]);
	sum += ar[i];
    }
    
    LL target = sum/3, csum = 0LL, ans = 0LL;
    if (sum%3 != 0){ printf("0\n"); return 0;} // REMEMBER MODS CAN BE NEGATIVE!!

    LL cnt = 0LL;
//    vector <int> cnt; cnt.resize(2, 0);
    
    FORN(i, n){
	csum += ar[i];
	if (csum == target * 2 && i > 0 && i != n-1){ 
	    // this is the second number, how many ways could we have gotten here from our choice of first numbers?
	    ans += cnt;
	}
	if (csum == target){
	    // this is the number of first numbers we could have chosen
	    cnt ++;
	} 
    }

    printf("%I64d\n", ans);




    return 0;
}