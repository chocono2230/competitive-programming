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

const int INF = 1000000000;
const double limTime = 5.5;
int n, m, d, k, elim;
vector base_gr(0, vector<int>());
vector base_list_gr(0, vector<pair<int, int>>());
vector<tuple<int, int, int>> in;
vector<pair<int, int>> in_wi;

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 202301302,
                       w = 64813216;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

double xor_shift() { return (double)(xor128() % LLONG_MAX) / LLONG_MAX; }

const clock_t start_time = clock();
double time_from_clock() {
  return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

void massert(bool f, string msg = "") {
  if (!f) {
    cerr << "Error : " << msg << endl;
    exit(1);
  }
}

void vShuffle(vector<int> &p) {
  rrep(i, p.size()) {
    int x = xor128() % (i + 1);
    if (x == i) continue;
    swap(p.at(x), p.at(i));
  }
}

void dijkstra(vector<vector<pair<int, int>>> &gr, vector<int> &d,
              vector<vector<bool>> &nouse, int st) {
  int n = d.size();
  vector<bool> chk(n, false);
  rep(i, d.size()) d.at(i) = INF;
  priority_queue<pair<ll, int>> q;
  q.push({0, st});
  int co = 0;
  while (!q.empty()) {
    auto [cost, now] = q.top();
    q.pop();
    if (chk.at(now) == true) continue;
    cost *= -1;
    d.at(now) = cost;
    chk.at(now) = true;
    co++;
    if (co == n) break;
    for (auto [nx, nxcost] : gr.at(now)) {
      if (chk.at(nx) == true || d.at(nx) <= (cost + nxcost)) continue;
      if (nouse.at(nx).at(now)) continue;
      q.push({-1 * (cost + nxcost), nx});
      d.at(nx) = cost + nxcost;
    }
  }
}

pair<ll, int> calc_point(vector<int> &ans, vector<vector<int>> &mn_gr) {
  vector er(d, vector<int>());
  rep(i, m) {
    er.at(ans.at(i)).push_back(i);
    massert((int)er.at(ans.at(i)).size() <= k);
  }
  double res = 0;
  int inf_co = 0;
  rep(z, d) {
    auto gr = base_gr;
    for (auto x : er.at(z)) {
      auto [p, q, r] = in.at(x);
      gr.at(p).at(q) = gr.at(q).at(p) = INF;
    }
    rep(k, n) rep(i, n) rep(j, n) {
      gr.at(i).at(j) = min(gr.at(i).at(j), gr.at(i).at(k) + gr.at(k).at(j));
    }

    double add = 0;
    rep(i, n) rep2(j, i + 1, n) {
      if (gr.at(i).at(j) == INF) {
        inf_co++;
      }
      add += gr.at(i).at(j) - mn_gr.at(i).at(j);
    }
    add *= 2;
    add /= n * (n - 1);
    res += add;
  }
  res /= d;
  return {round(res * 1e3), inf_co};
}

void input() {
  cin >> n >> m >> d >> k;
  base_gr.resize(n);
  base_list_gr.resize(n);
  rep(i, n) base_gr.at(i).resize(n);
  rep(i, n) rep(j, n) {
    base_gr.at(i).at(j) = INF;
    if (i == j) base_gr.at(i).at(j) = 0;
  }
  rep(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    base_gr.at(u).at(v) = w;
    base_gr.at(v).at(u) = w;
    base_list_gr.at(u).push_back({v, w});
    base_list_gr.at(v).push_back({u, w});
    in.push_back({u, v, w});
    in_wi.push_back({w, i});
  }
  sort(ALL(in_wi));
  elim = n / 20;
}

pair<vector<ll>, int> calc_djscore(vector<int> &edEdges, vector<int> &ans,
                                   vector<int> &days) {
  vector nouse_table(d, vector(n, vector<bool>(n, false)));
  vector<int> dist(n, INF);
  vector<ll> ress;
  int ires = 0;
  rep(i, ans.size()) {
    int day = ans.at(i);
    auto [x, y, z] = in.at(i);
    nouse_table.at(day).at(x).at(y) = nouse_table.at(day).at(y).at(x) = true;
  }
  for (auto day : days) {
    ll res = 0;
    rep(i, elim) {
      int idx = edEdges.at(i);
      dijkstra(base_list_gr, dist, nouse_table.at(day), idx);
      rep(i, dist.size()) {
        if (dist.at(i) == INF) ires++;
        res += dist.at(i);
      }
    }
    ress.push_back(res);
  }
  return {ress, ires};
}

pair<vector<ll>, int> calc_djscore(vector<int> &edEdges, vector<int> &ans) {
  vector<int> days;
  rep(i, d) days.push_back(i);
  return calc_djscore(edEdges, ans, days);
}

int make_tree(int z, int db, vector<vector<bool>> &res) {
  vector<dsu> ufs(z, dsu(n));
  vector<int> co(z, 0);
  vector<int> cd(z, 0);
  rep(i, z) cd.at(i) = i;
  for (auto [w, idx] : in_wi) {
    auto [u, v, _] = in.at(idx);
    vShuffle(cd);
    int tmp = -1;
    int tt = 0;
    for (auto ufs_idx : cd) {
      if (ufs.at(ufs_idx).same(u, v)) continue;
      ufs.at(ufs_idx).merge(u, v);
      res.at(idx).at(ufs_idx) = true;
      co.at(ufs_idx)++;
      if (co.at(ufs_idx) == n - 1) {
        tmp = ufs_idx;
      }
      tt++;
      if (tt == db) break;
    }
    if (tmp != -1) {
      auto itr = find(ALL(cd), tmp);
      cd.erase(itr);
    }
    if (cd.empty()) break;
  }
  int r = 0;
  for (auto &&t : ufs) {
    r += t.groups().size() - 1;
  }
  return r;
}

int main() {
  input();
  auto mn_gr = base_gr;
  rep(k, n) rep(i, n) rep(j, n) mn_gr.at(i).at(j) =
      min(mn_gr.at(i).at(j), mn_gr.at(i).at(k) + mn_gr.at(k).at(j));
  vector<pair<ll, int>> v;
  rep(i, n) { v.push_back({reduce(ALL(mn_gr.at(i)), 0LL), i}); }
  sort(ALL(v), greater<pair<ll, int>>());
  vector<int> edEdges(elim);
  rep(i, elim) edEdges.at(i) = v.at(i).second;

  ll mn = (ll)INF * INF;
  vector<int> ans(m);
  int dbg_co = 0, ex_end_co = 0;
  vector<int> mp_array(m);
  rep(i, m) mp_array.at(i) = i;
  int tree_co = n;
  int dbg_tree_co = 0;
  int tree_z = 1, tree_db = 2, tree_z_sz_mx = d;
  vector min_tree_num(m, vector<bool>(tree_z, false));
  double nt = time_from_clock();
  while (time_from_clock() < nt + 1.0) {
    tree_z++;
    if (tree_z > tree_z_sz_mx) tree_z = 2;
    tree_db = tree_z - 1;
    dbg_tree_co++;
    vector min_tree_add(m, vector<bool>(tree_z, false));
    auto r = make_tree(tree_z, tree_db, min_tree_add);
    if (r < tree_co) {
      tree_co = r;
      min_tree_num = min_tree_add;
    }
    if (tree_co == 0) break;
  }
  tree_z = min_tree_num.front().size();
  double tt = time_from_clock();
  auto cleanup = [&]() -> void { tt = time_from_clock(); };
  while (tt < limTime) {
    dbg_co++;
    vector<int> add(m, -1);
    vector<int> co(d, 0);
    vector<int> ss(d);
    rep(i, d) ss.at(i) = i;
    vector nouse_v(d, vector<int>());

    vShuffle(mp_array);
    bool ex_end = false;
    bool ex_ex = (tt > 3.0 && mn == (ll)INF * INF);
    rep(cc, m) {
      int i = mp_array.at(cc);
      vector<int> mss;
      for (auto ad : ss) {
        if (!ex_ex && min_tree_num.at(i).at(ad % tree_z)) continue;
        mss.push_back(ad);
      }
      if (mss.empty()) {
        ex_end = true;
        break;
      }
      int x = xor128() % mss.size();
      add.at(i) = mss.at(x);
      co.at(mss.at(x))++;
      nouse_v.at(mss.at(x)).push_back(i);
      if (co.at(mss.at(x)) == k) {
        auto itr = find(ALL(ss), mss.at(x));
        ss.erase(itr);
      }
    }
    if (ex_end) {
      ex_end_co++;
      cleanup();
      continue;
    }
    auto [pov, ii] = calc_djscore(edEdges, add);
    ll po = reduce(ALL(pov));
    if (po < mn) {
      mn = po;
      ans = add;
      if (ii == 0) break;
    }
    cleanup();
  }

  const double st_time = time_from_clock();
  const double sa_time = limTime - st_time;
  auto [mnsv, mnsi] = calc_djscore(edEdges, ans);
  vector<int> uk(d, 0);
  for (auto now : ans) uk.at(now)++;
  tt = st_time;
  vector<int> dbg_sac_up(2, 0);
  vector<int> dbg_sac_inf(2, 0);
  vector<int> dbg_sac_co(2, 0);
  while (tt < limTime) {
    auto sa_sw = [&](vector<ll> &mnsv) -> void {
      int x = xor128() % m;
      int y = xor128() % m;
      if (x == y || ans.at(x) == ans.at(y)) return;
      swap(ans.at(x), ans.at(y));
      vector<int> dd;
      dd.push_back(ans.at(x));
      dd.push_back(ans.at(y));
      auto [ps, ii] = calc_djscore(edEdges, ans, dd);
      bool sw = false;
      if (ii == 0) {
        ll dist = 0;
        int idx = 0;
        for (auto pd : dd) {
          dist += mnsv.at(pd) - ps.at(idx++);
        }
        if (dist > 0) {
          idx = 0;
          for (auto pd : dd) {
            // cerr << pd << "\t" << mnsv.at(pd) << "\t" << ps.at(idx) << "\t"
            //      << mnsv.at(pd) - ps.at(idx) << endl;
            mnsv.at(pd) = ps.at(idx++);
          }
          // cerr << endl;
          sw = true;
        }
      } else {
        dbg_sac_inf.at(0)++;
      }
      if (!sw) {
        swap(ans.at(x), ans.at(y));
      } else {
        dbg_sac_up.at(0)++;
      }
      dbg_sac_co.at(0)++;
    };
    auto sa_rd = [&](vector<ll> &mnsv) -> void {
      int x = xor128() % m;
      int rd = xor128() % d;
      if (ans.at(x) == rd) return;
      if (uk.at(rd) + 1 > k) return;
      int bf = ans.at(x);
      uk.at(bf)--;
      ans.at(x) = rd;
      uk.at(rd)++;
      vector<int> dd;
      dd.push_back(bf);
      dd.push_back(rd);
      auto [ps, ii] = calc_djscore(edEdges, ans, dd);
      bool sw = false;
      if (ii == 0) {
        ll dist = 0;
        int idx = 0;
        for (auto pd : dd) {
          dist += mnsv.at(pd) - ps.at(idx++);
        }
        if (dist > 0) {
          idx = 0;
          for (auto pd : dd) {
            mnsv.at(pd) = ps.at(idx++);
          }
          sw = true;
        }
      } else {
        dbg_sac_inf.at(1)++;
      }
      if (!sw) {
        uk.at(rd)--;
        ans.at(x) = bf;
        uk.at(bf)++;
      } else {
        dbg_sac_up.at(1)++;
      }
      dbg_sac_co.at(1)++;
    };
    if (xor128() % 2 == 0)
      sa_rd(mnsv);
    else
      sa_sw(mnsv);
    cleanup();
  }

  rep(i, m) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  cerr << "N:" << n << " M:" << m << " D:" << d << " K:" << k << endl;
  cerr << "時間：" << time_from_clock() << endl;
  cerr << "ループ数：" << dbg_co << endl;
  cerr << "木作成失敗数：" << ex_end_co << endl;
  cerr << "基木作成スコア：" << tree_co << endl;
  cerr << "基木作成回数：" << dbg_tree_co << endl;
  cerr << "基木サイズ：" << tree_z << endl;
  cerr << "焼きなまし時間：" << sa_time << endl;
  cerr << "焼きなまし合計回数：" << reduce(ALL(dbg_sac_co)) << endl;
  cerr << "焼きなまし回数：";
  rep(i, dbg_sac_up.size()) { cerr << i << ":" << dbg_sac_co.at(i) << "  "; }
  cerr << endl;
  cerr << "焼きなまし増加回数：";
  rep(i, dbg_sac_up.size()) { cerr << i << ":" << dbg_sac_up.at(i) << "  "; }
  cerr << endl;
  cerr << "焼きなまし無限回数：";
  rep(i, dbg_sac_up.size()) { cerr << i << ":" << dbg_sac_inf.at(i) << "  "; }
  cerr << endl;
  auto r = calc_point(ans, mn_gr);
  cerr << "スコア：" << r.first << endl;
  cerr << "INFペア数：" << r.second << endl;
  cerr << r.first << endl;
  return 0;
}