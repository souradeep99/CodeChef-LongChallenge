#include <bits/stdc++.h>
using namespace std;
#define int long long int
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=500005;
#define M 998244353
#define double long double
#define BINF 100000000000000
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 17500001
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;

//https://www.codechef.com/wiki/tutorial-quadratic-equations
//https://www.codechef.com/viewsolution/51283

int extendedGCD(int a, int b){
  int x = 0, y = 1; 
  int lastx = 1, lasty = 0;
  while(b != 0){
      int q = a/b;
      int temp = b; b = a % b; a = temp;
      temp = x; x = lastx - q*x; lastx = temp;
      temp = y; y = lasty-q*y; lasty = temp;
  }
  return lastx;
}

//Calculate b^s mod p
int powermodulo(int b, int s, int p){
    int res = 1;
    while(s > 0){
        if(s & 1){
            res = (res * b) % p;
        }
        s /= 2;
        b = (b * b) % p;
    }
    return res;
}

int quadnon(int p)
{
  int pow = (p-1)/2;
  for (int i=2;i<p;i++)
  {
    int x = powermodulo(i,pow,p);
    if (x == p-1)
      return i;
  }
  return -1;
}

//solves x * x == a (mod p)
int solvequadratic(int n, int p){
  n %= p;
  if(n == 0)
    return 0;
  int ex = powermodulo(n,(p-1)/2,p);
  if (ex != 1)
    return -1;
  int inv = powermodulo(n,p-2,p);
  int q = p-1;
  int s = 0;
  while(q%2 == 0)
  {
    q /= 2;
    s++;
  }
  int w = quadnon(p);
  int v = powermodulo(w,q,p);
  int r = powermodulo(n,(q+1)/2,p);
  while(1)
  {
    int r1 = r;
    r1 *= r1;
    r1 %= p;
    r1 = (r1*inv)%p;
    int i = 0;
    while (r1 != 1)
    {
      r1 = (r1*r1)%p;
      i++;
    }
    if (i == 0)
      return r;
    int pow = s-i-1;
    int x = 1;
    while(pow > 0)
    {
      x *= 2;
      pow--;
    }
    int mul = powermodulo(v,x,p);
    r = (r*mul)%p;
  }
  return -1;
}


vector<int>v[N];
int par[N], vis[N], ans[N], c[N], sub[N], root[N], way = 1, never = 0;
int n, PP;

void clear(){
    for(int i = 0; i <= n; i++){
        v[i].clear();
        par[i] = 0, vis[i] = 0, ans[i] = 0, c[i] = 0, sub[i] = 0, root[i] = 0;
    }
    way = 1, never = 0;
}

void dfs(int u, int p){
    vis[u] = 1;
    sub[u] = c[u];
    for(auto i : v[u]){
        if(!vis[i]){
            dfs(i, u);
            sub[u] += sub[i];
        }
    }
}

void dfs1(int u, int p){
    for(auto i : v[u]){
        if(i != p){
            dfs1(i, u);
        }
    }
    int sq = solvequadratic(sub[u] % PP, PP);

    if(never or sq == -1){
        way = 0, never |= 1;
        return ;
    }

    ans[u] = root[u] = sq;
    for(auto i : v[u]){
        if(i != p){
            ans[u] = (ans[u] - root[i] + PP) % PP;
        }
    }

    if(sq > 0) way = (way * 2) % M;
}

//Verify value
//int lvl[N], P[N][LG];
//
//int lca(int u, int v){
//    int i, lg;
//    if (lvl[u] < lvl[v]) swap(u, v);
// 
//    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
//    lg--;
// 
//    for(i=lg; i>=0; i--){
//        if (lvl[u] - (1<<i) >= lvl[v])
//            u = P[u][i];
//    }
// 
//    if (u == v) 
//        return u;
// 
//    for(i=lg; i>=0; i--){
//        if (P[u][i] != -1 and P[u][i] != P[v][i])
//            u = P[u][i], v = P[v][i];
//    }
// 
//    return P[u][0];
//}
 
//void pre(int u, int p){
//    lvl[u] = 1 + lvl[p];
//    P[u][0] = p;
//    for(int i = 1; i < LG; i++)
//        P[u][i] = P[P[u][i-1]][i-1];
// 
//    for(auto i: v[u])
//        if(i != p)
//            pre(i, u);
//}

//void check_clear(){
//    for(int i = 0; i <= n; i++)
//        for(int j = 0; j < LG; j++)
//            P[i][j] = -1;
//
//    for(int i = 0; i <= n; i++)
//        lvl[i] = 0;
//}

void solve(){

    scanf("%lld%lld", &n, &PP);
    clear();

    //check_clear();

    for(int i = 2; i <= n; i++){
        int x;
        //cin >> x;
        scanf("%lld", &x);
        v[x].push_back(i);
        v[i].push_back(x);
        par[i] = x;
    }
    for(int i = 1; i <= n; i++){
        scanf("%lld", &c[i]);
        //cin >> c[i];
    }

    //pre(1, 0);

    dfs(1, 0);
    dfs1(1, 0);

    if(never){
        //cout << 0 << "\n";
        //cout << "-1\n";
        printf("0\n-1\n");
        return ;
    }

    //cout << way << "\n";
    //for(int i = 1; i <= n; i++)
    //    cout << ans[i] << ' ';
    //cout << "\n";

    printf("%lld\n", way);
    for(int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    printf("\n");

    //vector<int>verify(n + 1, 0);
    //for(int i = 1; i <= n; i++){
    //    for(int j = 1; j <= n; j++){
    //        int z = lca(i, j);
    //        verify[z] += (ans[i] * ans[j]) % PP;
    //        verify[z] %= PP;
    //    }
    //}

    //for(int i = 1; i <= n; i++){
    //    assert(verify[i] == c[i]);
    //}

}



#undef int 
int main() {
#define int long long int
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("optput.txt", "w", stdout); 
#endif
     
    int t = 1;
    //cin >> t;
    scanf("%lld", &t);
    while(t--){
        solve();
    }

    // deb(solvequadratic(0, 113))

return 0;  
} 




