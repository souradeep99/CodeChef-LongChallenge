#include <bits/stdc++.h>
using namespace std;
//#define int long long int
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=200005;
#define M 998244353
#define double long double
#define BINF 100000000000000
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 17500001
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;

long int dp[1024][240][240];
int sett[1024];
int n, x[N];
vector<int>pos[1024];
int val[N];

int foo(int mask, int last, int mod){
    if(dp[mask][last][mod] != -1) return dp[mask][last][mod];
    //if(last > 239) return 0;
    
        
    if(239 - last < sett[mask]) return dp[mask][last][mod] = 0;
    if(mask == 0){
        if(mod == 0)
            return dp[mask][last][mod] = 1;
        return dp[mask][last][mod] = 0;
    }

    
    int res = 0;
    if(last + sett[mask] <= 239){
        res = foo(mask, last + 1, mod);
        for(auto i : pos[mask]){
            //if(mask & (1 << i)){
                res = (res + foo(mask - val[i], last + 1, (mod + x[i] * last) % 239)) % M;
            //}
        }
    }

    return dp[mask][last][mod] = res;

}

void solve(){

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &x[i]);
        
    for(int i = 0; i < (1 << n); i++) sett[i] = __builtin_popcount(i);
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) pos[i].pb(j);
        }
    }
    
    for(int i = 0; i < n; i++)
        val[i] = (1 << i);

    int lol = 0;
    for(int i = 0; i < (1 << n); i++)
        for(int j = 0; j < 240; j++)
            for(int k = 0; k < 240; k++)
                dp[i][j][k] = -1;
            

    int all = (1 << n) - 1;
    int ans = foo(all, 0, 0);

    printf("%d", ans);

}




//#undef int 
int main() {
//#define int long long int
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
 

     
    //int t = 1;
    //cin >> t;
    //while(t--){
        solve();
    //}


return 0;  
} 



