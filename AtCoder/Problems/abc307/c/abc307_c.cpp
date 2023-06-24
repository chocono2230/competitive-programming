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
  auto in = []() -> vector<string> {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s.at(i);
    while (1) {
      if (s.front() == string(w, '.'))
        s.erase(s.begin());
      else
        break;
    }
    while (1) {
      bool f = false;
      rep(i, s.size()) {
        if (s.at(i).front() == '#') f = true;
      }
      if (f) break;
      rep(i, s.size()) { s.at(i).erase(s.at(i).begin()); }
    }
    h = s.size();
    w = s.front().size();
    while (w != 10) {
      rep(i, h) s.at(i).push_back('.');
      w++;
    }
    while (h != 10) {
      s.push_back(string(10, '.'));
      h++;
    }
    return s;
  };
  auto a = in();
  auto b = in();
  auto x = in();
  // for (auto s : a) cerr << s << endl;
  // cerr << endl;
  // for (auto s : b) cerr << s << endl;
  // cerr << endl;
  // for (auto s : x) cerr << s << endl;
  vector chk(0, vector<string>());
  rep(si, 10) rep(sj, 10) {
    vector<string> base(20, string(20, '.'));
    rep(i, 10) rep(j, 10) {
      if (x.at(i).at(j) == '.') continue;
      base.at(si + i).at(sj + j) = '#';
    }
    chk.push_back(base);
  }
  rep(si, 10) rep(sj, 10) rep(ti, 10) rep(tj, 10) {
    vector<string> base(20, string(20, '.'));
    rep(i, 10) rep(j, 10) {
      if (a.at(i).at(j) == '.') continue;
      base.at(si + i).at(sj + j) = '#';
    }
    rep(i, 10) rep(j, 10) {
      if (b.at(i).at(j) == '.') continue;
      base.at(ti + i).at(tj + j) = '#';
    }
    for (auto &ss : chk) {
      if (base == ss) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}