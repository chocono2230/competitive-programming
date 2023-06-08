#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  priority_queue<int, vector<int>, greater<int>> pq;
  set<int> wt;
  rep(i, n) { pq.push(i); }
  while (q--) {
    int qe;
    cin >> qe;
    if (qe == 1) {
      int t = pq.top();
      pq.pop();
      wt.insert(t);
    }
    if (qe == 2) {
      int in;
      cin >> in;
      in--;
      wt.erase(in);
    }
    if (qe == 3) {
      auto itr = wt.begin();
      cout << *itr + 1 << endl;
    }
  }
  return 0;
}