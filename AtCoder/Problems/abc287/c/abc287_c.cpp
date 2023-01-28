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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  dsu uf(n);
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.merge(a, b);
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  int s = -1, t = -1;
  rep(i, n) {
    if (gr.at(i).size() == 1) {
      if (s == -1)
        s = i;
      else if (t == -1)
        t = i;
      else {
        cout << "No" << endl;
        return 0;
      }
    } else if (gr.at(i).size() != 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (uf.groups().size() == 1 && t != -1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}