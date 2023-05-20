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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
  }
  auto b = a;
  sort(ALL(b));
  vector gr(4, vector<int>(4, 0));
  ll ans = 0;
  rep(i, n) { gr.at(a.at(i)).at(b.at(i))++; }
  rep(i, 4) rep2(j, i + 1, 4) {
    int mn = min(gr.at(i).at(j), gr.at(j).at(i));
    ans += mn;
    gr.at(i).at(j) -= mn;
    gr.at(j).at(i) -= mn;
  }
  rep(z, 4) {
    vector<int> p;
    rep(i, 4) {
      if (i == z) continue;
      p.push_back(i);
    }
    do {
      int mn = 1001001001;
      rep(k, 3) {
        int i = p.at(k), j = p.at((k + 1) % 3);
        mn = min(mn, gr.at(i).at(j));
      }
      rep(k, 3) {
        int i = p.at(k), j = p.at((k + 1) % 3);
        gr.at(i).at(j) -= mn;
      }
      ans += mn * 2;
    } while (next_permutation(ALL(p)));
  }
  vector<int> p;
  rep(i, 4) p.push_back(i);
  do {
    int mn = 1001001001;
    rep(k, 4) {
      int i = p.at(k), j = p.at((k + 1) % 4);
      mn = min(mn, gr.at(i).at(j));
    }
    rep(k, 4) {
      int i = p.at(k), j = p.at((k + 1) % 4);
      gr.at(i).at(j) -= mn;
    }
    ans += mn * 3;
  } while (next_permutation(ALL(p)));
  cout << ans << endl;
  return 0;
}