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
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s.at(i);
    if (h > w) {
      vector<string> t(w, string(h, '.'));
      rep(i, h) rep(j, w) { t.at(j).at(i) = s.at(i).at(j); }
      swap(s, t);
      swap(h, w);
    }
    h = 550, w = 550;
    rep(i, h) { s.at(i) = string(w, '.'); }
    ll ans = 0;
    vector sums(h + 1, vector<int>(w + 1, 0));
    rep(i, h) {
      rep(j, w) {
        sums.at(i + 1).at(j + 1) += (s.at(i).at(j) == '#' ? 1 : -1);
        sums.at(i + 1).at(j + 1) -= sums.at(i).at(j);
        sums.at(i + 1).at(j + 1) += sums.at(i).at(j + 1);
        sums.at(i + 1).at(j + 1) += sums.at(i + 1).at(j);
      }
    }
    rep(i, h) {
      rep(ii, i + 1) {
        map<int, int> mp;
        mp[0]++;
        rep(j, w) {
          int now = sums.at(i + 1).at(j + 1) - sums.at(ii).at(j + 1);
          ans += mp[now];
          mp[now]++;
        }
      }
    }
    // rep(i, h) {
    //   rep(j, w) cerr << s.at(i).at(j) << " ";
    //   cerr << endl;
    // }
    // rep(i, h + 1) {
    //   rep(j, w + 1) cerr << sums.at(i).at(j) << " ";
    //   cerr << endl;
    // }
    cout << ans << endl;
  }
  return 0;
}