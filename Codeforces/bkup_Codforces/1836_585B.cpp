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

const int nrows = 3;
const int maxcols = 110;
int dp[nrows][maxcols];
int trains[nrows][maxcols];
int ntest, ncols, ntrains;
int startrow, startcol;
string rowstr;
int dcol[3] = {3, 3, 3};
int drow[3] = {0, -1, 1};

void printTrains(int start){
    for (int irow = start; irow < 3; irow ++){
	FORN(icol, ncols) cout << trains[irow][icol] << ' ';
	cout << endl;
    }
}

void printDP(){
    FORN(irow, 3) {
	FORN(icol, ncols+10){
	    if (dp[irow][icol] == -1)
		cout << dp[irow][icol] << ' ';    
	    else 
		cout << ' ' << dp[irow][icol] << ' ' ;
	}
	cout<<endl; 
    }
}

int step(int irow, int icol){
    int& result = dp[irow][icol];
    if (result != -1) return result; // if this position has already been calculated
    
    result = 0;
    FORN(i, 3){
	int mv_row = irow + drow[i];
	int mv_col = icol + dcol[i];
	
	bool valid_loc = mv_row >= 0 && mv_row <3 && mv_col >=0 && mv_col <ncols;

	if (valid_loc){
	    bool no_train = trains[mv_row][icol+1] == 0 && trains[irow][icol+1] == 0;
	    if (no_train) if (trains[mv_row][mv_col]==0){
		if (step(mv_row, mv_col) == 1) result = 1;
	    }
	}
    }

    return result;
}

int main() {
    cin >> ntest;
    FORN(i, ntest){ // for each test

	memset(dp, -1, sizeof dp);
	memset(trains, 0, sizeof trains);

	int last[3] = {0, 0, 0};

	scanf("%d%d", &ncols, &ntrains);
	FORN(irow, 3) {
	    cin >> rowstr;
	    FORN(icol, ncols){
		char& pt = rowstr[icol];
		if (pt == 's') {startrow = irow; startcol=icol;	}
		trains[irow][icol] = (pt != '.') && (pt != 's') ? 1:0;
		dp[irow][icol] = (pt != '.') && (pt != 's') ? 0:-1;
	    }
	}
	
	FORN(irow, 3) FORD(icol, ncols){ 
	    if(trains[irow][icol] == 1){
		last[irow] = icol+1; 
		break;
	    } 
	}

	// set success
	// everything after the last train in the row is successful
	FORN(irow, 3) {
	    for (int icol = last[irow]; icol < maxcols; icol ++)
		dp[irow][icol] = 1;
	}
	if (step(startrow, startcol)) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
    

    return 0;
}