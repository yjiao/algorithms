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
int k, n;

void printAns(vector<int> ans){
    sort(ans.begin(), ans.end());
    for (auto a : ans){
	cout << a+1 << " ";
    } cout << endl;
}

void solve(){
    map <int, vector<int> > dict;
    int temp;
    bool ok;

    FORN(i, n){
	scanf("%d", &temp);
	dict[temp].PB(i);
    }
    

    for (auto k1 : dict) for (auto k2 : dict){
	int k3 = -k1.FF - k2.FF;
	if (k1.FF == 0 && k2.FF == 0 && k3 == 0){
	    if (dict[0].size() >= 3) { printAns({ dict[0][0], dict[0][1], dict[0][2] }); return;}
	}

	else if (k1.FF == k2.FF){
	    if (k1.SS.size() > 1){
		if (dict.find(k3) != dict.end()) { printAns({ dict[k1.FF][0], dict[k1.FF][1], dict[k3][0] }); return;}
	    }
	}
	else if (k1.FF == k3) {
	    if (k1.SS.size() > 1){
		printAns({ dict[k1.FF][0], dict[k1.FF][1], dict[k3][0] }); return;
	    }
	}
	else if (k2.FF == k3){
	    if (k2.SS.size() > 1){
		printAns({ dict[k1.FF][0], dict[k1.FF][1], dict[k3][0] }); return;
	    }
	}
	else {
	    if (dict.find(k3) != dict.end()) { printAns({ dict[k1.FF][0], dict[k2.FF][0], dict[k3][0] }); return;}
	}
    }
    cout << -1 << endl;


}

int main() {

    scanf("%d%d", &k, &n);
    while (k--){
	solve();
    }

    return 0;
}