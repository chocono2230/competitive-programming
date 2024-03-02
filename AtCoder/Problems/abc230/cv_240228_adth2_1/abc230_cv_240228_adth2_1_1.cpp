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
  ll n, a, b;
  cin >> n >> a >> b;
  ll p, q, r, s;
  cin >> p >> q >> r >> s;
  vector<string> ans;
  for (ll i = p; i <= q; i++) {
    string add;
    for (ll j = r; j <= s; j++) {
      ll di = i - a, dj = j - b;
      char c = '.';
      if (abs(di) == abs(dj)) c = '#';
      add.push_back(c);
    }
    ans.push_back(add);
  }
  for (auto &o : ans) cout << o << endl;
  return 0;
}