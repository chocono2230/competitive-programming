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

vector<pair<int, int>> s;
bool rc(int bit, int now) {
  static vector memo(1 << 16, vector<int>(26, -1));
  if (now != -1 && memo.at(bit).at(now) != -1) return memo.at(bit).at(now) == 1;
  bool res = false;
  rep(i, s.size()) {
    if ((bit & (1 << i)) != 0) continue;
    int nxbit = (bit | (1 << i));
    auto [f, b] = s.at(i);
    if (now != -1 && now != f) continue;
    res |= !rc(nxbit, b);
  }
  if (now == -1) return res;
  if (res == true)
    memo.at(bit).at(now) = 1;
  else
    memo.at(bit).at(now) = 0;
  return memo.at(bit).at(now) == 1;
}

int main() {
  int n;
  cin >> n;
  s.resize(n);
  rep(i, n) {
    string in;
    cin >> in;
    s.at(i).first = in.front() - 'a';
    s.at(i).second = in.back() - 'a';
    // cerr << i << " " << s.at(i).first << " " << s.at(i).second << endl;
  }
  bool ans = rc(0, -1);
  if (ans)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}