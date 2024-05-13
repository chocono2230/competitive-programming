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

void print(const std::vector<int>& v) {
  std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
  std::cout << std::endl;
}

void tt(vector<int> v) {
  do {
    print(v);
  } while (std::next_permutation(v.begin(), v.end()));
}

int main() {
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  vector b(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);
  rep(i, h) rep(j, w) cin >> b.at(i).at(j);
  vector<int> p1(h), p2(w);
  rep(i, h) p1.at(i) = i;
  rep(i, w) p2.at(i) = i;
  const int INF = 1001001001;
  int ans = INF;
  while (1) {
    while (1) {
      auto x = a;
      int nw = 0;
      auto t1 = p1, t2 = p2;
      rep(i, h) {
        if (p1.at(i) == i) continue;
        rep2(j, i + 1, h) {
          if (p1.at(j) == i) {
            rrep2(k, i, j) {
              swap(p1.at(k), p1.at(k + 1));
              swap(x.at(k), x.at(k + 1));
              nw++;
            }
          }
        }
      }
      rep(i, w) {
        if (p2.at(i) == i) continue;
        rep2(j, i + 1, w) {
          if (p2.at(j) == i) {
            rrep2(k, i, j) {
              swap(p2.at(k), p2.at(k + 1));
              rep(z, h) { swap(x.at(z).at(k), x.at(z).at(k + 1)); }
              nw++;
            }
          }
        }
      }
      bool t = false;
      rep(i, h) {
        if (b.at(i) != x.at(i)) t = true;
      }
      if (!t) ans = min(ans, nw);
      p2 = t2;
      p1 = t1;
      auto r = next_permutation(ALL(p2));
      if (!r) break;
    }
    auto r = next_permutation(ALL(p1));
    if (!r) break;
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}