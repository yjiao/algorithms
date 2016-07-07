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
int n, k;
//const LL maxn = 250;
vector < LL > arr;
//LL[maxn] arr;

LL solve(){
    LL soln = -INF, temp;
    int idx;

    FORN(i, n) for (int j = i+1; j <= n; j ++){
	//cout << "-------------------" << "i: " << i << ", j: " << j << endl;
	vector <LL> in, out;
	vector <LL> ::iterator begin = arr.begin();
	in.insert(in.end(), begin+i, begin+j);
	out.insert(out.end(), begin, begin+i);
	out.insert(out.end(), begin+j, arr.end());
	
	//cout << "in array: \n";
	//FORN(ii, in.size()) cout << in[ii] << ' ';
	//cout << endl;
	//cout << "out array: \n";
	//FORN(ii, out.size()) cout << out[ii] << ' ';
	//cout << endl;

	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
	
	int outsize = out.size();
	int insize = in.size();
	FORN(kk, min(min(outsize, k), insize)){
	    idx = outsize - kk - 1;
	    //cout << "comparing in[" << kk << "] = " << in[kk] << " with out[" << idx << "] = " << out[idx]<< endl;
	    if (in[kk] > out[idx]) break;
	    in[kk] = out[idx];
	}
	
	temp = 0;
	FORN(ii, in.size()) {temp += in[ii]; }
	//cout << "temp: " << temp << endl;

	if (temp > soln) soln = temp;
    }

    if (soln < 0) FORN(i, n) if (arr[i] > soln) soln = arr[i];
    //cout << "solution: \n";
    return soln;
}

int main() {
    scanf("%d%d", &n, &k);
    arr.resize(n);

    for (auto i = 0; i < n; i ++) {
	scanf("%I64d", &arr[i]);
    }
    
    cout << solve() << endl;
    return 0;
}