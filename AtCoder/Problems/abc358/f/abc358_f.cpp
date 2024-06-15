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
  int n, m, k;
  cin >> n >> m >> k;
  bool f = false;
  f |= (k < n);
  int z = k - n;
  f |= (z % 2 == 1);
  f |= (z - (m - 1) * (n / 2 * 2) > 0);
  if (f) {
    cout << "No" << endl;
    return 0;
  }
  vector table(n, vector<bool>(m, false));
  vector<string> ans(2 * n + 1, string(2 * m + 1, '+'));
  cout << "Yes" << endl;
  ans.at(0) = string(2 * m - 1, '+') + "S+";
  auto ps = [](int i, int j) -> pair<int, int> {
    int ri = i * 2 + 1;
    int rj = j * 2 + 1;
    return {ri, rj};
  };
  rep(i, n) {
    string add = "+";
    rep(j, m) {
      add.push_back('o');
      add.push_back('|');
    }
    add.pop_back();
    add.push_back('+');
    ans.at(2 * i + 1) = add;
    add = "+";
    rep(j, m) {
      add.push_back('-');
      add.push_back('+');
    }
    ans.at(2 * i + 2) = add;
  }
  ans.back() = string(2 * m - 1, '+') + "G+";

  rep(i, n) {
    auto [ri, rj] = ps(i, m - 1);
    if (ans.at(ri + 1).at(rj) != 'G') ans.at(ri + 1).at(rj) = '.';
    if (z == 0) {
      continue;
    }
    int d = min(z, (m - 1) * 2);
    rep(p, d / 2) {
      auto [ri, rj] = ps(i, m - 1 - p);
      ans.at(ri + 1).at(rj) = '-';
      auto [ri2, rj2] = ps(i, m - 1 - p - 1);
      ans.at(ri2 + 1).at(rj2) = '.';
      ans.at(ri2).at(rj2 + 1) = '.';
      ans.at(ri2 + 2).at(rj2 + 1) = '.';
    }
    z -= d;
    tie(ri, rj) = ps(i + 1, m - 1);
    if (ans.at(ri + 1).at(rj) != 'G') ans.at(ri + 1).at(rj) = '.';
    i++;
  }

  for (auto s : ans) cout << s << endl;
  return 0;
}