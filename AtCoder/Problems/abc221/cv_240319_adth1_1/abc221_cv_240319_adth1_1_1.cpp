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
  string s;
  cin >> s;
  ll ans = 0;
  int n = s.size();
  rep(bit, 1 << n) {
    string p, q;
    rep(i, n) {
      if ((bit & (1 << i)) == 0)
        p.push_back(s.at(i));
      else
        q.push_back(s.at(i));
    }
    if (p.size() == 0 || q.size() == 0) continue;
    sort(ALL(p), greater<char>());
    sort(ALL(q), greater<char>());
    ll a = stoll(p);
    ll b = stoll(q);
    ans = max(ans, a * b);
  }
  cout << ans << endl;
  return 0;
}