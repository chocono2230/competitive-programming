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

const int A = 26 * 2;

pair<int, int> s2p(const string &s) {
  auto ff = [](const string &t) -> int {
    int res = 0;
    rep(i, 3) {
      res *= A;
      if ('A' <= t.at(i) && t.at(i) <= 'Z')
        res += t.at(i) - 'A';
      else
        res += t.at(i) - 'a' + 26;
    }
    return res;
  };
  return {ff(s.substr(0, 3)), ff(s.substr(s.size() - 3))};
}

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector<int> ans(A * A * A, -1);
  vector<int> s2a(n);
  vector rgr(A * A * A, set<int>());
  vector deg(A * A * A, 0);
  rep(i, n) {
    cin >> s.at(i);
    auto p = s2p(s.at(i));
    s2a.at(i) = p.second;
    ans.at(p.second) = 0;
    rgr.at(p.second).insert(p.first);
  }
  rep(i, A * A * A) {
    for (auto nx : rgr.at(i)) {
      deg.at(nx)++;
    }
  }
  queue<int> q;
  rep(i, deg.size()) {
    if (deg.at(i) == 0 && ans.at(i) == 0) {
      q.push(i);
      ans.at(i) = 1;
    }
  }
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto nx : rgr.at(now)) {
      if (ans.at(nx) != 0) continue;
      deg.at(nx)--;
      if (ans.at(now) == 1) {
        deg.at(nx) = 0;
        ans.at(nx) = 2;
        q.push(nx);
        continue;
      }
      if (deg.at(nx) == 0) {
        ans.at(nx) = 1;
        q.push(nx);
      }
    }
  }
  rep(i, n) {
    int idx = s2a.at(i);
    string o = "Draw";
    if (ans.at(idx) == 1) o = "Takahashi";
    if (ans.at(idx) == 2) o = "Aoki";
    cout << o << endl;
  }
  return 0;
}