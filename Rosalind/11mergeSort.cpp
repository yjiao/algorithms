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

vector <int> merge(vector<int> left, vector<int> right){
    vector<int> merged;

    auto li = left.begin();
    auto ri = right.begin();

    while (li != left.end() || ri != right.end()) {
	if (li == left.end()) {
	    merged.PB(*ri);
	    ri++;
	}
	else if (ri == right.end()) {
	    merged.PB(*li);
	    li++;
	}
	else if (*li <= *ri) {
	    merged.PB(*li);
	    li++;
	}
	else {
	    merged.PB(*ri);
	    ri++;
	}
    }

    return merged;
}

vector<int> mergesort(vector<int> arr){
    if (arr.size() <= 1){ return arr;}

    int mid = (arr.size())/2;
    auto b = arr.begin();
    vector<int> left(b, b+mid), right(b+mid, arr.end());

    return merge(mergesort(left), mergesort(right));
}

int main() {
    int n;
    vector <int> arr, sorted;
    scanf("%d", &n);
    arr.resize(n);
    FORN(i, n){scanf("%d", &arr[i]);}

    sorted = mergesort(arr);
    for (auto s: sorted) { cout << s << " ";}
    cout << endl;

    return 0;
}