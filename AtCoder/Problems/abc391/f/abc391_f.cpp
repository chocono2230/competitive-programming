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
  int n, ta;
  cin >> n >> ta;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> b(n);
  rep(i, n) cin >> b.at(i);
  vector<ll> c(n);
  rep(i, n) cin >> c.at(i);
  sort(ALL(a), greater<ll>());
  sort(ALL(b), greater<ll>());
  sort(ALL(c), greater<ll>());
  set<tuple<ll, int, int, int>> se;
  auto fc = [&](int i, int j, int k) -> tuple<ll, int, int, int> {
    if (i >= n || j >= n || k >= n)
      return {0, -min(n, i), -min(n, j), -min(n, k)};
    return {a.at(i) * b.at(j) + b.at(j) * c.at(k) + c.at(k) * a.at(i), -i, -j,
            -k};
  };
  se.insert(fc(0, 0, 0));
  rep(tt, ta) {
    auto itr = se.end();
    itr--;
    auto [ss, i, j, k] = *itr;
    i *= -1;
    j *= -1;
    k *= -1;
    // cerr << tt << " " << ss << endl;
    if (tt == ta - 1) {
      cout << ss << endl;
    }
    se.erase(itr);
    se.insert(fc(i + 1, j, k));
    se.insert(fc(i, j + 1, k));
    se.insert(fc(i, j, k + 1));
  }
  return 0;
}