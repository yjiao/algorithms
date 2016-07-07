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

void heapify(int node, int end){
    int maxnode = node;
    int leftnode = left(node);
    int rightnode = right(node);

    if (leftnode < end && arr[leftnode] > arr[maxnode]){ maxnode = leftnode;}
    if (rightnode < end && arr[rightnode] > arr[maxnode]){ maxnode = rightnode;}
    if (maxnode != node){
	swap(arr[maxnode], arr[node]);
	heapify(maxnode, end);
    }
}

int main(){
    scanf("%d", &n);
    arr.resize(n+1); // 1-indexed
    FORN(i, n){scanf("%d", &arr[i + 1]);}

    for (int i = n; i > 0; i --){
	heapify(i, n+1);
    }

//    for (auto h : arr) cout << h << " "; cout << endl;
    
    int idx = n;
    while (idx > 1){
	swap(arr[1], arr[idx]);
//	for (auto h : arr) cout << h << " "; cout << endl;
	heapify(1, idx);
	idx --;
    }

    FOR1(i, n){
	cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}

