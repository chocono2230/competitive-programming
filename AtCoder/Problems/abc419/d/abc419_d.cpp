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
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<int> imos(n + 1, 0);
  rep(i, m) {
    int l, r;
    cin >> l >> r;
    l--;
    imos.at(l)++;
    imos.at(r)--;
  }
  int now = 0;
  string ans;
  rep(i, n) {
    now += imos.at(i);
    if (now % 2 == 0)
      ans.push_back(s.at(i));
    else
      ans.push_back(t.at(i));
  }
  cout << ans << endl;
  return 0;
}