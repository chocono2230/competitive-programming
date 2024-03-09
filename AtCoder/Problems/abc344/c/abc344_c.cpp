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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  int m;
  cin >> m;
  vector<int> b(m);
  rep(i, m) cin >> b.at(i);
  int l;
  cin >> l;
  vector<int> c(l);
  rep(i, l) cin >> c.at(i);
  set<int> se;
  rep(i, n) rep(j, m) rep(k, l) { se.insert(a.at(i) + b.at(j) + c.at(k)); }
  int q;
  cin >> q;
  while (q--) {
    int in;
    cin >> in;
    if (se.find(in) != se.end())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}