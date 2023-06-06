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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  vector<string> t(h);
  rep(i, h) cin >> t.at(i);
  auto fc = [&](vector<string> &s) -> map<string, int> {
    map<string, int> sm;
    rep(j, w) {
      string add;
      rep(i, h) { add.push_back(s.at(i).at(j)); }
      sm[add]++;
    }
    return sm;
  };
  auto sm = fc(s), tm = fc(t);
  if (sm == tm)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}