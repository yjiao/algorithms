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

void pivot(vector<int>& arr, int pivot){
    swap(arr[pivot], arr[arr.size()-1]);
    int i = 0, j = arr.size()-2;

    while (i != j){
	if (arr[i] <= arr[arr.size()-1]){
	    i ++;
	} else {
	    swap(arr[i], arr[j]);
	    j--;
	}
    }
    swap(arr[i], arr[arr.size() - 1]);
    
}

int main() {
    int n;
    vector <int> arr, sorted;
    scanf("%d", &n);
    arr.resize(n);
    FORN(i, n){scanf("%d", &arr[i]);}

    pivot(arr, 0);
    for (auto a: arr) {cout << a << " ";} cout << endl;

    return 0;
}