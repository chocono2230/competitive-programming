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
  rep(i, n) cin >> a.at(i);
  map<int, pair<int, int>> gr;
  rep(i, n - 1) {
    gr[a.at(i)].first = a.at(i + 1);
    gr[a.at(i + 1)].second = a.at(i);
  }
  int st = a.front();
  int q;
  cin >> q;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x, y;
      cin >> x >> y;
      int nx = gr[x].first;
      gr[x].first = y;
      gr[y].first = nx;
      gr[y].second = x;
      if (nx != 0) {
        gr[nx].second = y;
      }
    } else {
      int now;
      cin >> now;
      if (st == now) {
        st = gr[now].first;
        gr[st].second = -1;
        gr.erase(now);
        continue;
      }

      int nx = gr[now].first;
      int pr = gr[now].second;
      gr[pr].first = nx;
      gr[nx].second = pr;
      gr.erase(now);
    }
  }

  int now = st;
  vector<int> ans;
  while (now != 0) {
    ans.push_back(now);
    now = gr[now].first;
  }
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}