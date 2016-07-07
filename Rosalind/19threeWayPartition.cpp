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
int n; vector<int> arr;

void partition(int pivot){
    int pval = arr[pivot];
//    cout << "pivot: " << arr[pivot] << endl;
    int l = 0, r = 0, end = arr.size() - 1;
    swap(arr[pivot], arr[end]);
    end--;
    
    while (r <= end){
//	    cout << "l: " << l << ", r: " << r << endl;
//	    cout << "     ";
//	    for (auto a : arr) cout << a << " "; cout<<endl;
	if (arr[r] < pval){
	    swap(arr[r], arr[l]);
	    l ++;
	    r ++;
	} else if (arr[r] == pval){
//	    cout << "     ";
//	    cout << "arr[r]: " << arr[end] << endl;
	    r ++;
	} else {
//	    cout << "     ";
//	    cout << "arr[end]: " << arr[end] << endl;
	    swap(arr[end], arr[r]);
	    end --;
	}
    }

//    cout << "l: " << l << ", r: " << r << endl;
//    for (auto a : arr) cout << a << " "; cout<<endl;
    swap(arr[r], arr[arr.size() -1]);
}

int main() {
    scanf("%d", &n);
    arr.resize(n);
    FORN(i, n){
	scanf("%d", &arr[i]);
    }

    partition(0);
    for (auto a : arr) cout << a << " "; cout<<endl;

    return 0;
}