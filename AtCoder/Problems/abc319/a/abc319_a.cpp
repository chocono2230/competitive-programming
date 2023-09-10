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
  map<string, int> mp = {{"tourist", 3858},   {"ksun48", 3679},
                         {"Benq", 3658},      {"Um_nik", 3648},
                         {"apiad", 3638},     {"Stonefeang", 3630},
                         {"ecnerwala", 3613}, {"mnbvmar", 3555},
                         {"newbiedmy", 3516}, {"semiexp", 3481}};
  string s;
  cin >> s;
  cout << mp[s] << endl;
  return 0;
}