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
int n, p;
char buf[1500];

PII findPos(){
    int start, space, r1, r2;
    FORD(d, n){
//	if (d < 2) break;
	start = buf[d] - 'a';
	space = p - start;
	
	if (d >= 2){
	    r1 = buf[d-2] - 'a';
	} else {
	    r1 = -1;
	}
	if (d >= 1){
	    r2 = buf[d-1] - 'a';
	} else {
	    r2 = -1;
	}
	for (int i = 1; i < space; i ++){
	    if (start + i !=r1 && start + i != r2){
		return MP(d, start+i+'a');
	    }
	}
    }
    return MP(-1, -1);
}

bool fillPos(int pos){
    int r1, r2;
    if (pos >= 2){
	r1 = buf[pos-2] - 'a';
    } else {
	r1 = -1;
    }
    if (pos >= 1){
	r2 = buf[pos-1] - 'a';
    } else {
	r2 = -1;
    }

    for (int i = 0; i < p; i ++){
	if (i !=r1 && i != r2){
	    buf[ pos ] = (char)'a'+i;
	    return true;
	}
    }
    return false;
}

int main() {

    scanf("%d%d", &n, &p);
    scanf("%s", buf);
    
    PII pos = findPos();
    if (pos.FF > -1){
	buf[pos.FF] = (char)pos.SS;
	for (int i = pos.FF + 1; i < n; i ++){
	    bool fill = fillPos(i);
	    if (!fill){
		printf("NO\n");
		return 0;
	    }
	}
	printf("%s\n", buf);
    } else {
	printf("NO\n");
    }
    
    return 0;
}