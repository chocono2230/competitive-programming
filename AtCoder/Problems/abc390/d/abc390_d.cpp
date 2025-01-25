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

vector<ll> a(12);
vector<ll> v;
vector<ll> ansv;
void rc(int lv, int n) {
  if (lv == n) {
    ll add = 0;
    for (auto now : v) {
      add ^= now;
    }
    ansv.push_back(add);
    // dbg++;
    return;
  }
  v.push_back(a.at(lv));
  rc(lv + 1, n);
  v.pop_back();
  ll t = a.at(lv);
  rep(i, v.size()) {
    v.at(i) += t;
    rc(lv + 1, n);
    v.at(i) -= t;
  }
}

int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> a.at(i);
  rc(0, n);
  sort(ALL(ansv));
  // for (auto now : ansv) cerr << now << " ";
  // cerr << endl;
  ll ans = 1;
  rep(i, ansv.size() - 1) {
    if (ansv.at(i) == ansv.at(i + 1)) continue;
    ans++;
  }
  cout << ans << endl;
  // cerr << dbg << endl;
  return 0;
}