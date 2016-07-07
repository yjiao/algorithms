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

int n; vector<int> arr;

vector<int> mergeCnt(vector<int> l, vector<int> r, int& cnt){
    auto li = 0, ri = 0;
    vector<int> merged;

    while ( li < l.size() || ri < r.size() ){
	if (li == l.size()){
	    merged.PB(r[ri]);
	    ri ++;
	}
	else if (ri == r.size()){
//	    cout << "adding " << l[li] << "from l\n";
	    merged.PB(l[li]);
	    li ++;
	}
	else if (l[li] <= r[ri]){
	    merged.PB(l[li]);
	    li ++;
	} 
	else {
//	    for (auto ll : l ) { cout << ll << " "; } cout << endl;
	    merged.PB(r[ri]);
	    cnt += l.size() - li;
	    ri ++;
	}
    }
//    cout << "merged: ";
//    for (auto m: merged) cout << m << " "; cout << endl;
    return merged;
}

vector<int> countInv(vector<int> v, int& cnt){
//    for (auto m: v) cout << m << " "; cout << endl;

    int mid = v.size()/2;
    if (v.size() <= 1) return v;
    
    auto b = v.begin();
    vector<int> l(b, b+mid), r(b+mid, b+v.size());

//    countInv(l, cnt);
//    countInv(r, cnt);
    return mergeCnt(countInv(l, cnt), countInv(r, cnt), cnt);
}

int main() {
    scanf("%d", &n);
    arr.resize(n);
    FORN(i, n){ scanf("%d", &arr[i]);}

    int cnt = 0;
    countInv(arr, cnt);
    cout << cnt << endl;

    return 0;
}