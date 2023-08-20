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
  vector<map<char, int>> vh(h), vw(w);
  rep(i, h) rep(j, w) {
    char c = s.at(i).at(j);
    vh.at(i)[c]++;
    vw.at(j)[c]++;
  }

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      q;
  vector<bool> ch(h, false), cw(w, false);
  vector chk(h, vector<bool>(w, false));
  rep(i, h) {
    if (vh.at(i).size() == 1) {
      q.push({0, 0, i});
      ch.at(i) = true;
    }
  }
  rep(j, w) {
    if (vw.at(j).size() == 1) {
      q.push({0, 1, j});
      cw.at(j) = true;
    }
  }
  set<int> banh, banw;
  rep(i, h) banh.insert(i);
  rep(j, w) banw.insert(j);
  rep(now, 1001001001) {
    vector<pair<int, int>> vv;
    bool end = false;
    while (!q.empty() && get<0>(q.top()) == now) {
      end = true;
      auto [t, mode, idx] = q.top();
      q.pop();
      if (mode == 0) {
        for (auto add : banw) {
          if (chk.at(idx).at(add)) continue;
          vv.push_back({idx, add});
          chk.at(idx).at(add) = true;
        }
        auto itr = banh.find(idx);
        if (itr != banh.end()) banh.erase(itr);
      } else {
        for (auto add : banh) {
          if (chk.at(add).at(idx)) continue;
          vv.push_back({add, idx});
          chk.at(add).at(idx) = true;
        }
        auto itr = banw.find(idx);
        if (itr != banw.end()) banw.erase(itr);
      }
    }
    for (auto [i, j] : vv) {
      char c = s.at(i).at(j);
      vh.at(i)[c]--;
      if (vh.at(i)[c] == 0) {
        vh.at(i).erase(c);
      }
      if (vh.at(i).size() == 1 && vh.at(i).begin()->second != 1 && !ch.at(i)) {
        q.push({now + 1, 0, i});
        ch.at(i) = true;
      }
      vw.at(j)[c]--;
      if (vw.at(j)[c] == 0) {
        vw.at(j).erase(c);
      }
      if (vw.at(j).size() == 1 && vw.at(j).begin()->second != 1 && !cw.at(j)) {
        q.push({now + 1, 1, j});
        cw.at(j) = true;
      }
    }
    if (!end) break;
  }

  int ans = 0;
  rep(i, h) rep(j, w) {
    if (!chk.at(i).at(j)) ans++;
  }
  cout << ans << endl;
  return 0;
}