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

void rot(vector<string> &s) {
  int h = s.size();
  int w = s.front().size();
  vector<string> res(w, string(h, '.'));
  rep(i, h) {
    rep(j, w) { res.at(w - j - 1).at(i) = s.at(i).at(j); }
  }
  s = res;
}

map<vector<string>, pair<int, int>> mp;

bool dfs(vector<vector<string>> &v, vector<tuple<int, int, int>> &idx, int lv) {
  if (lv == 3) {
    vector<string> t(4, string(4, '.'));
    rep(p, 3) {
      auto [si, sj, r] = idx.at(p);
      auto now = v.at(p);
      rep(i, r) rot(now);
      if (si + now.size() > 4 || sj + now.front().size() > 4) return false;
      rep(di, now.size()) rep(dj, now.at(di).size()) {
        if (now.at(di).at(dj) == '#') {
          if (t.at(si + di).at(sj + dj) == '#') return false;
          t.at(si + di).at(sj + dj) = '#';
        }
      }
    }
    return true;
  }
  bool res = false;
  rep(si, 4) rep(sj, 4) rep(k, 4) {
    idx.at(lv) = {si, sj, k};
    res |= dfs(v, idx, lv + 1);
  }
  return res;
}

int main() {
  vector v(3, vector<string>(4));
  rep(i, 3) rep(j, 4) cin >> v.at(i).at(j);
  auto trim = [](vector<string> &s) {
    rep(i, 4) {
      rot(s);
      string t = string(s.front().size(), '.');
      while (1) {
        if (s.back() != t) break;
        s.pop_back();
      }
    }
  };
  int co = 0;
  rep(idx, 3) {
    rep(i, v.at(idx).size()) rep(j, v.at(idx).at(i).size()) {
      if (v.at(idx).at(i).at(j) == '#') co++;
    }
  }
  if (co != 16) {
    cout << "No" << endl;
    return 0;
  }
  rep(i, 3) trim(v.at(i));
  vector<tuple<int, int, int>> idx(4);
  auto r = dfs(v, idx, 0);
  if (r)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}