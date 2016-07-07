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
int n;
const int maxn = 200010;
int arr[maxn];

PII partition(int start, int stop){
    // pick pivot
    int pidx = start + rand() % (stop - start + 1);

    //3way partition
    int l, r, orig_stop = stop, pivot = arr[pidx];
    l = r = start;

    // move pivot to the end
    swap(arr[pidx], arr[stop]);
    stop--;

//    cout << "   pivot at " << pidx << ": " << pivot << endl;

    while (r <= stop){
//	cout << "   -----" << arr[r] << " vs " << pivot << "\n";
//	cout << "   ";
//	FORN(i, n) printf("%d ", arr[i]); cout << '\n';
	if (arr[r] < pivot){
	    swap(arr[l], arr[r]);
	    l++; r++;
	} else if (arr[r] == pivot){
	    r ++;
	} else {
	    swap(arr[r], arr[stop]);
	    stop--;
	}
    }

    // move pivot back
    swap(arr[r], arr[orig_stop]);
    r++;

    return MP(l, r);
}

void quicksort(int start, int stop){
    if (start >= stop) return;
    // partion
    PII lr = partition(start, stop);

//    for (auto a : arr ) cout << a << " "; cout << endl;

    // call parition on each segment
//    cout << "   " << start << ", " << lr.FF-1 << endl;
//    cout << "   " << lr.SS << ", " << stop << endl;
    quicksort(start, max(lr.FF-1, 0));
    quicksort(lr.SS, stop);


}

int main() {
    scanf("%d", &n);
    FORN(i, n){
	scanf("%d", &arr[i]);
    }
    quicksort(0, n-1);

    FORN(i, n) printf("%d ", arr[i]);

    // code for double checking    
    vector<int> sarr;
    FORN(i, n) sarr.PB(arr[i]);
    sort(sarr.begin(), sarr.end());

    FORN(i, n){
	if (arr[i] != sarr[i]){
	    cout << "Position " << i << "mismatch, " << arr[i] << " vs " << sarr[i] << endl;
	}
    }

    cout << "\n";
    return 0;
}