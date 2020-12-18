#include <bits/stdc++.h>
using namespace std;
#define int long long int
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=100005;
#define M 998244353
#define double long double
#define BINF 100000000000000
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 17500001
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;

int power(int x,int y,int m){
    int res = 1;
    while(y > 0){
        if(y & 1) res = (res * x) % M;
        y /= 2;
        x = (x * x) % M;
    }
    return res;
}


int fact[N], ifact[N];

void proecss(){
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % M;
    for(int i = 0; i < N; i++)
        ifact[i] = power(fact[i], M - 2, M);
}

int nCr(int n, int r){
    if(r > n) return 0;
    if(r == n) return 1;
    int ans = (ifact[n - r] * ifact[r]) % M;
    ans = (ans * fact[n]) % M;
    return ans;
}


void solve(){
    int n;
    cin >> n;
    int up = 2;
    int down = 0;
    //1 3 5 7 9 ..
    for(int i = 1; i <= n; i++){
        int x = (2 * i - 1 + M) % M;
        down = (down + power(x, M - 2, M));
    }
    int ans = (up * down) % M;
    cout << ans << "\n";

    //int ans1 = (2 * power(2 * n + 1, M - 2, M)) % M;
    //assert(ans == ans1)
    //deb(ans1)
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
    while(t--){
        solve();
    }

return 0;  
} 



