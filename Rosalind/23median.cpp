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
#define ALL(c) (c).begin(), (c).stop()
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define FOREACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).stop(); i++)

#define MOD 1000000007
#define INF 2000000000
int n, k;
vector <int> arr;

PII partition(int p, int start, int stop){
    int pivot = arr[start + p];
    int l, r, orig_stop = stop;
    l = r = start;

    swap(arr[start + p], arr[stop]);
    stop --;
    
    while (r <= stop){
	if (arr[r] < pivot){
	    swap(arr[r], arr[l]);
	    r ++; l ++;
	} else if (arr[r] == pivot){
	    r ++;
	} else {
	    swap(arr[r], arr[stop]);
	    stop --;
	}
    }
    
    swap(arr[orig_stop], arr[r]);
    // before l: less than pivot
    // after r: greater than pivot
    // at r: == pivot
//    cout << "   "; for (auto a : arr) cout << a << " "; cout << endl;
    return MP(l, r);
}

int select(int start, int stop, int k){
    int p = rand() % (stop - start + 1);
    srand (time(NULL));
//    cout << "-----------------\n";
//    cout << "start: " << start << ", stop: " << stop << ", p: " << p  << ", start + p: " << start + p<< endl;
//    cout << "pivot: " << arr[start + p] << endl;
    PII lr = partition(p, start, stop);


    int a = max(lr.FF, 0); 
    int b = max(lr.SS + 1, 0);
    int c = stop;
    
//    cout << "   a: " << a << ", b: " << b << ", c: " << c << endl;
//    cout << "   a: "; FORN(i, a) cout << arr[i] << " "; cout << endl;
//    cout << "   b: "; for(int i = a; i < b; i++) cout << arr[i] << " "; cout << endl;
//    cout << "   c: "; for(int i = b; i < arr.size(); i++) cout << arr[i] << " "; cout << endl;

    // before l: less than pivot
    // after r: greater than pivot
    // at r: == pivot
    if (k <= a){ 
	select(start, a - 1, k);
    } else if (k > b){
	select(b, stop, k);
    } else {
	return arr[b-1];
    }
}

int main() {
    scanf("%d", &n);
    arr.resize(n);
    FORN(i, n){
	scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    
    cout << select(0, n-1, k) << endl;

    return 0;
}