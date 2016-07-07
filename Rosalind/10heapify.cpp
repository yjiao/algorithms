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
vector <int> arr;

int left(int node){ return node*2;}
int right(int node){ return node*2 + 1;}

void heapify(int node){
    int l = left(node), r = right(node);
//    cout << "node: " << arr[node] << ", left: " << arr[l] << ", right: " << arr[r] << endl;
    int maxnode = node;
    if (l < arr.size() && arr[l] > arr[maxnode]) {maxnode = l;}
    if (r < arr.size() && arr[r] > arr[maxnode]) {maxnode = r;}
    if (maxnode != node){
	swap(arr[node], arr[maxnode]);
	heapify(maxnode);
    }
}

int main() {
    scanf("%d", &n);
    arr.resize(n+1);
    FORN(i, n){scanf("%d", &arr[i+1]);}

    for (int i = n/2 + 1; i > 0; i --){
//	cout << i << endl;
	heapify(i);
    }

    FORN(i, n){
	cout << arr[i+1] << " ";
    }
    cout << endl;

    return 0;
}