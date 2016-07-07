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

char op[50], buf[50];
priority_queue< int, vector<int>, greater<int> > Q;
vector < pair<string, int> > in;
vector <string> ops;
int n, x, nq = 0;

int main() {
    scanf("%d", &n);
    int nremove = 0;
    Q.push(INF);
    FORN(i, n){
	scanf("%s", &op);

	if (*op == 'i'){
	    scanf("%d", &x);
	    Q.push(x);
	    sprintf(buf, "insert %d", x); ops.PB(buf);
	}
       	else if (*op == 'r'){
	    if (Q.top() == INF){
		sprintf(buf, "insert -1"); ops.PB(buf);
		sprintf(buf, "removeMin"); ops.PB(buf);
	    } else {
		Q.pop();
		sprintf(buf, "removeMin"); ops.PB(buf);
	    }
	}
       	else if (*op == 'g'){
	    scanf("%d", &x);
	    
	    while (Q.top() < x){
		Q.pop();
		sprintf(buf, "removeMin"); ops.PB(buf);
	    }

	    if (Q.top() > x){
		sprintf(buf, "insert %d", x); ops.PB(buf);
		Q.push(x);
	    }
	    sprintf(buf, "getMin %d", x); ops.PB(buf);
	}
    }
    
    printf("%d\n", ops.size());
    for (int i = 0; i < ops.size(); i ++){
	puts(ops[i].c_str());
    }
    return 0;
}