#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<utility>
#include<string>
#include<sstream>
using namespace std;
#define INF 10^20
#define V_MAX 50

int costTotal[V_MAX+1] = {0};	
typedef struct {
    int from, to, cost;
} edge; 
vector<edge> G[V_MAX+1];

class PowerOutage {
	public:
	int estimateTimeOut (vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength) {
// BEGIN CUT HERE
        for (int i = 1; i <= V_MAX; i++) {
            G[i].clear();
            costTotal[i] = 0;
        }
// END CUT HERE
        int ret = 0;
        for (int i = 0; i < (int)fromJunction.size(); i++) {
            edge e;
            e.from = fromJunction[i];
            e.to = toJunction[i];
            e.cost = ductLength[i];
            G[e.from].push_back(e);
            ret += ductLength[i] * 2;
        }
        calcTotalCost(0, 0);
        int maxCost = *max_element(costTotal, costTotal + V_MAX);
        return ret - maxCost;
	}

    void calcTotalCost(int v, int cost) {
        if (G[v].size() == 0) {
            costTotal[v] = cost;
            return;
        }
        for (vector<edge>::iterator it = G[v].begin(); it != G[v].end(); it++) {
            edge e = *it;
            calcTotalCost(e.to, cost + e.cost);
        }
    }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; verify_case(1, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,4,2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,100,10,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 165; verify_case(2, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,1,4,4,6,7,7,7,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,4,2,5,6,7,20,9,10,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,100,10,5,1,1,100,1,1,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 281; verify_case(3, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,200,300,400,500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2500; verify_case(4, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PowerOutage __test;
	__test.run_test(-1);
}
// END CUT HERE
