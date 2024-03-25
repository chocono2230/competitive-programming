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
  ll n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int sn = s.size();
  vector sum(26, vector<int>(sn + 1, 0));
  vector pos(26, vector<int>());
  rep(i, sn * 2) {
    pos.at(s.at(i % sn) - 'a').push_back(i);
    if (i < sn) {
      rep(j, 26) sum.at(j).at(i + 1) = sum.at(j).at(i);
      sum.at(s.at(i) - 'a').at(i + 1)++;
    }
  }
  const ll INF = 1e18;
  ll ok = 0, ng = INF;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    auto fc = [&]() {
      ll sIdx = 0;
      for (auto c : t) {
        int ci = c - 'a';
        ll csum = sum.at(ci).at(sn);
        if (csum == 0) return false;
        ll m = (mid - 1) % csum + 1;
        ll ss = (mid - m) / csum;
        if (ss > INF / sn) return false;
        sIdx += ss * sn;
        int b = sum.at(ci).at(sIdx % sn);
        int ma = pos.at(ci).at(b + m - 1);
        sIdx += ma - sIdx % sn + 1;
        if (sIdx > sn * n) return false;
      }
      return true;
    };
    if (fc())
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}