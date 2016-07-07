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
#define INF 200000000000000

// cases to consider:
// A picks up nothing, or A picks up something
// Either A or B must pick up something in the beginning
LL ax, ay, bx, by, tx, ty;
int n;
vector < pair<LL, LL> > pts;
vector < double > dist;

double distance(LL x1, LL y1, LL x2, LL y2){
    return sqrt( pow( (x1 - x2), 2 ) + pow((y1 - y2), 2) );
}

int main() {
    scanf("%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty, &n);

    pts.resize(n + 10);
    dist.resize(n + 10);

    FORN(i, n) scanf("%d%d", &pts[i].FF, &pts[i].SS);

    // Total of everything from t
    double t_pt = 0;
    FORN(i, n){
	dist[i] = distance(tx, ty, pts[i].FF, pts[i].SS);
	t_pt += 2*dist[i];
    }
    
    
    // distances from a to t, b to t
    double a_t = distance(ax, ay, tx, ty);
    double b_t = distance(ax, ay, tx, ty);

    pair <double, double> amin = MP(INF, INF);
    PII aidx = MP(-1, -1);
    pair <double, double> bmin = MP(INF, INF);
    PII bidx = MP(-1, -1);
    double temp;
    FORN(i, n){
	temp = distance(ax, ay, pts[i].FF, pts[i].SS) - dist[i];
	if (temp < amin.FF) {amin.SS = amin.FF; amin.FF = temp; aidx.SS = aidx.FF; aidx.FF = i;} // switch smallest and second smallest
	else if (temp < amin.SS) {amin.SS = temp; aidx.SS = i;}

	temp = distance(bx, by, pts[i].FF, pts[i].SS) - dist[i];
	if (temp < bmin.FF) {bmin.SS = bmin.FF; bmin.FF = temp; bidx.SS = bidx.FF; bidx.FF = i;} // switch smallest and second smallest
	else if (temp < bmin.SS) {bmin.SS = temp; bidx.SS = i;}
    }

    double mindistA = t_pt + amin.FF; // only A works
    double mindistB = t_pt + bmin.FF; // only B works
    double distA1B1 = t_pt + amin.FF + bmin.FF;
    double distA2B1 = t_pt + amin.SS + bmin.FF;
    double distA1B2 = t_pt + amin.FF + bmin.SS;
    double distA2B2 = t_pt + amin.SS + bmin.SS;
    
    double ans = INF;
    if (mindistA < ans) ans = mindistA;
    if (mindistB < ans) ans = mindistB;
    if (distA1B1 < ans && (aidx.FF != bidx.FF)) ans = distA1B1;
    if (distA1B2 < ans && (aidx.FF != bidx.SS)) ans = distA1B2;
    if (distA2B1 < ans && (aidx.SS != bidx.FF)) ans = distA2B1;
    
    cout.precision(12);
    cout << ans << endl;

    return 0;
}