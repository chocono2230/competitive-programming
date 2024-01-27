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
  int h, w, k;
  cin >> h >> w >> k;
  const int INF = 1001001001;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  auto fc = [&](vector<string> &ss) {
    int h = ss.size();
    int w = ss.front().size();
    int res = INF;
    rep(i, h) {
      int now = 0, sum = 0;
      rep(j, w) {
        if (ss.at(i).at(j) == 'x') {
          now = 0;
          sum = 0;
        } else {
          sum++;
          if (ss.at(i).at(j) == '.') now++;
          if (sum > k) {
            if (ss.at(i).at(j - k) == '.') now--;
            sum--;
          }
          if (sum == k) {
            res = min(res, now);
          }
        }
      }
    }
    return res;
  };
  int ans = INF;
  rep(_i, 4) {
    ans = min(ans, fc(s));
    vector<string> ns(w, string(h, '.'));
    rep(i, h) rep(j, w) ns.at(w - j - 1).at(i) = s.at(i).at(j);
    swap(s, ns);
    swap(h, w);
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}