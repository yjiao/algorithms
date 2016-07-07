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
int guess = 0, lo = 2, hi = 10;
string ver;
vector <int> primes = {11,13,17,19,23,29,31,37,41,43,47};

int cnt = 0;
bool check(int test){
    FORN(i, primes.size()){
	if (primes[i] > test and primes[i] * test <= 100){
	    cout << primes[i] << endl;
	    guess ++;

	    cin >> ver;
	    if (ver == "yes"){
		return true;
	    }
	}
    }

    if (test == 5 || test == 7){
	cout << test*test << endl;
	cin >> ver;
	if (ver == "yes"){
		return true;
	    }
    }
    return false;
}

string solve(){
    lo = 2;
    hi = 10;
    cnt = 0;
    guess = 0;
    int last = -1;

    while (lo <= hi && guess <= 20){
	cout << lo << endl; 
	guess ++;
    	cin >> ver;
    	if (ver == "yes") {
	    cnt ++;
	    last = lo;
	}
	lo ++;
    }
    if (cnt == 1){
	if (check(last)){
	    return "composite";
	}
    }
    if (cnt > 1) return "composite";
    else return "prime";

}


int main() {
    string soln = solve();
    cout << soln << endl;
    return 0;
}