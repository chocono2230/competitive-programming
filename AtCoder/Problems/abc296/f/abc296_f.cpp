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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  auto p = a, q = b;
  sort(ALL(p));
  sort(ALL(q));
  if (p != q) {
    cout << "No" << endl;
    return 0;
  }
  rep(i, p.size() - 1) {
    if (p.at(i) == p.at(i + 1)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  fenwick_tree<int> f1(n + 2), f2(n + 2);
  ll a1 = 0, a2 = 0;
  rep(i, n) {
    a1 += f1.sum(0, a.at(i));
    f1.add(a.at(i), 1);
    a2 += f2.sum(0, b.at(i));
    f2.add(b.at(i), 1);
  }
  if (a1 % 2 == a2 % 2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}