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

int n, m;
vector <int> A, B, C;

void merge(vector <int>& A, vector <int>& B, vector <int>& C){
    C.resize(A.size() + B.size());
    int i, j, a, b;
    i = j = 0;
    while (i <= A.size() && j <= B.size()){
	a = A[i]; b = B[j];
//	cout << "a[" << i << "]: " << a << ", b[" << j << "]: " << b << endl;
	if (i == A.size()){ a = INF;}
	if (j == B.size()){ b = INF;}

	if (a <= b){
	    C[i + j] = A[i];
	    i ++;
	} else {
	    C[i + j] = B[j];
	    j ++;
	}
    }
}

int main() {
    scanf("%d", &n);
    A.resize(n);
    FORN(i, n){scanf("%d", &A[i]);}
    scanf("%d", &m);
    B.resize(m);
    FORN(i, m){scanf("%d", &B[i]);}

    merge(A, B, C);
    FORN(i, C.size()) cout << C[i] << " ";
    cout << endl;

    return 0;
}