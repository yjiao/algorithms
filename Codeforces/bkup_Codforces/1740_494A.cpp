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
    string parens;
    vector <int> ans;
    int open = 0, nhash = -1;

    cin >> parens;
    
    int imbal = 0;
    FORN(i, parens.size()){
	if (parens[i] == '#'){
	    nhash = i;
	    open --;
	}
	else if (parens[i] == '('){ open ++; }
	else { open --;}

	if (open < 0){ // even min number of close parens would not satisfy
	    printf("-1\n");
	    return 0;
	}
    }

    imbal = open;

    FORN(i, parens.size()){
	if (parens[i] == '#'){
	    if (i == nhash){ // last hash
		ans.PB(1 + imbal);
	    } else {
		ans.PB(1);
	    }
	}
    }
    
    int h = 0;
    open = 0;
    FORN(i, parens.size()){
//	printf("ans[%d]: %d\n", h, ans[h]);
//	printf("parens[%d]: %c, open: %d\n", i, parens[i], open);
	if (parens[i] == '(') { open ++; }
	else if (parens[i] == ')') { open --;}
	else {
	    open -= ans[h];
	    h ++;
	}
	if (open < 0){ // even min number of close parens would not satisfy
	    printf("-1\n");
	    return 0;
	}
    }
    
    if (open == 0){
	for (auto a : ans) printf("%d ", a); printf("\n");
    } else {
	printf("-1\n");
    }
    return 0;
}