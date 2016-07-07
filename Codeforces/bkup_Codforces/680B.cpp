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

int n, a, temp, cnt = 0;
vector <int> c;

int main() {
    cin >> n >> a;
    a --;
    FORN(i, n){
	cin >> temp;
	c.PB(temp);
    }

    int dist = 0;
    //cout << max(a, n-a-1) << endl;
    while ( dist <= max(a, n - a - 1)){
	//cout << "---------dist: " << dist << endl;
	if (dist == 0){
	    if (c[a] == 1) cnt ++;
	} 
	else{
	    if (a + dist < n && a - dist >= 0){
		//cout << c[a+dist] << " " << c[a-dist] << endl;
		if (c[a+dist] == 1 && c[a-dist] == 1) cnt += 2;
	    }
	    else{
		//cout << "1 case \n";
		if (a - dist >= 0) {
		    if (c[a - dist] == 1) cnt += 1;
		}
		else if (c[a + dist] == 1) cnt += 1;
	    }
	}
    
	//cout << "cnt : " << cnt<< endl;
	dist ++;
    }

    cout << cnt << endl;

    return 0;
}