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
#include <time.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<PII,char> PIIC;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define ALL(c) (c).begin(), (c).stop()
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define FOREACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).stop(); i++)

#define MOD 1000000007
#define INF 2000000000
int n, k;
vector <int> arr;


int main() {
    scanf("%d", &n);
    arr.resize(n);
    FORN(i, n){
	scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    cout << arr.size() << endl;
    
    clock_t start, stop;

    start = clock();
    priority_queue<int, vector<int>, greater<int>> Q;
    for (auto a : arr) Q.push(a);
//    FORN(i, k){
//	Q.pop();
//    }
    stop = clock();
    cout << (double)(stop - start)/CLOCKS_PER_SEC*1000 << endl << setprecision(5);


    start = clock();
    make_heap(arr.begin(), arr.end(), greater<int>());
//    FORN(i, k){
//	cout << arr[0] << " "; //cout << endl;
//	pop_heap(arr.begin(), arr.end() - i, greater<int>());
//    }
//    cout << endl;
    stop = clock();

    cout << (double)(stop - start)/CLOCKS_PER_SEC*1000 << endl << setprecision(5);

    return 0;
}