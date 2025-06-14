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
  int n, q;
  cin >> n >> q;
  vector<int> box(n, 0);
  vector<int> ans;
  rep(i, q) {
    int in;
    cin >> in;
    if (in > 0) {
      in--;
      box.at(in)++;
      ans.push_back(in);
    } else {
      int mn = 1001001, mni = -1;
      rep(i, n) {
        if (box.at(i) < mn) {
          mn = box.at(i);
          mni = i;
        }
      }
      box.at(mni)++;
      ans.push_back(mni);
    }
  }
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}