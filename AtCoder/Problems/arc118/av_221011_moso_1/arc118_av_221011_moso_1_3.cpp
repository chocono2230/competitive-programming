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
  int t, n;
  cin >> t >> n;
  n--;
  set<int> se;
  rep(i, 100) { se.insert((100 + t) * i / 100); }
  vector<int> v;
  rep(i, 100 + t) {
    if (se.find(i) == se.end()) v.push_back(i);
  }
  int p = n / (int)v.size(), m = n % (int)v.size();
  cerr << p << " " << m << endl;
  ll ans = (ll)(100 + t) * p + v.at(m);
  cout << ans << endl;
  return 0;
}