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
  int si = -1, sj = -1;
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == 'S') {
      si = i, sj = j;
      break;
    }
  }
  auto fc = [&](int sdi, int sdj) -> bool {
    int ssi = si + sdi, ssj = sj + sdj;
    if (ssi < 0 || h <= ssi || ssj < 0 || w <= ssj) return false;
    if (s.at(ssi).at(ssj) == '#') return false;
    vector table(h, vector<int>(w, -1));
    table.at(ssi).at(ssj) = 0;
    queue<pair<int, int>> q;
    q.push({ssi, ssj});
    int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};

    set<pair<int, int>> se;
    rep(k, 4) {
      int ni = si + di[k], nj = sj + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (ni == ssi && nj == ssj) continue;
      if (s.at(ni).at(nj) == '#') continue;
      se.insert({ni, nj});
    }

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
        if (s.at(ni).at(nj) == '#' || s.at(ni).at(nj) == 'S' ||
            table.at(ni).at(nj) != -1)
          continue;
        if (table.at(i).at(j) >= 1 && se.find({ni, nj}) != se.end()) {
          return true;
        }
        q.push({ni, nj});
        table.at(ni).at(nj) = table.at(i).at(j) + 1;
      }
    }
    return false;
  };
  bool ans = fc(0, 1) | fc(0, -1) | fc(1, 0) | fc(-1, 0);
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}