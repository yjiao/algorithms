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
    vector <PII> dat, ans, bkup;
    int n, t;

    cin >> n;
    FORN(i, n){
	cin >> t;
	dat.PB(MP(t, i));
    }
    bkup = dat;

    sort(dat.begin(), dat.end());
    
    int pos = -1;
    FORN(i, n){
	if (dat[i].SS != i){
	    pos = dat[i].SS;
	    dat[i].SS = i;
	    
	    if (i > pos){
		for (int j = pos; j < i; j++){
		    ans.PB(MP(j, j+1));
		}
	    } else {
		for (int j = pos; j > i; j--){
		    ans.PB(MP(j-1, j));
		}
	    }
	    
	    FORN(j, n){
		if (dat[j].SS <= pos) dat[j].SS ++;
	    }
	}
    }
    
    FORN(i, ans.size()){
	swap(bkup[ans[i].FF], bkup[ans[i].SS]);
    }

    bool cor = true;
    FORN(j, n){ 
	if (bkup[j].FF != dat[j].FF) {
	    cor = false;
	}
    }

    FORN(i, ans.size()){
	printf("%d %d\n", ans[i].FF+1, ans[i].SS+1);
    }

    return 0;
}