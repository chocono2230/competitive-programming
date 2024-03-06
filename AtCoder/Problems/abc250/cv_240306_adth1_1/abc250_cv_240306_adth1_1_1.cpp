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
  int n, qe;
  cin >> n >> qe;
  vector<int> p(n), q(n);
  rep(i, n) p.at(i) = q.at(i) = i;
  while (qe--) {
    int x;
    cin >> x;
    x--;
    int idx = q.at(x);
    int nidx = idx + 1;
    if (idx == n - 1) {
      nidx = idx - 1;
    }
    int y = p.at(nidx);
    swap(p.at(idx), p.at(nidx));
    swap(q.at(x), q.at(y));
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << p.at(i) + 1;
  }
  cout << endl;
  return 0;
}