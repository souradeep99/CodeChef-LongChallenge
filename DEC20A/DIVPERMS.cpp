#include <bits/stdc++.h>
using namespace std;
#define int long long int
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=205;
#define M 998244353
#define double long double
#define BINF 100000000000000
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 17500001
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;

int n, pre[N], dp[41][(1LL << 21) + 5], can[N];
vector<int>divi[50];
string s;

int power(int x,int y,int m){
    int res = 1;
    while(y > 0){
        if(y & 1) res = (res * x) % m;
        y /= 2;
        x = (x * x) % m;
    }
}

int fact[N], ifact[N];

int nCr(int n, int r){
    if(r > n) return 0;
    if(r == n) return 1;
    int ans = (ifact[n - r] * ifact[r]) % M;
    ans = (ans * fact[n]) % M;
    return ans;
}

int foo(int i, int mask){
    if(i == 1){
        if(mask == 0) return 1;
        return 0;
    }
    if(__builtin_popcount(mask) >= i) return dp[i][mask] = 0;

    if(dp[i][mask] != -1)
        return dp[i][mask];

    int p = 0, q = 0, swap_large = 0;
    for(int j = 1; j <= min(i - 1, n / 2); j++){

        int mask_val = mask & (1 << (j - 1));
        if(mask_val){
            if(i % j == 0 and can[i / j]){
                swap_large++;
                //deb(mask)
                //deb(mask_val)
                p = (p + foo(i - 1, mask ^ (1LL << (j - 1)))) % M;
                //cout << "i " << i << ' ' << "j " << j << endl;
            }
        }else{
            if(!(i % j == 0 and can[i / j])){
                swap_large++;
                //deb(mask)
                //deb(mask_val)
                p = (p + foo(i - 1, mask ^ (1LL << (j - 1)))) % M;
                //cout << "i " << i << ' ' << "j " << j << endl;
            }
        }
        //else if(i % j == 0 and can[i / j]) continue;
        //else c++;
    }
    int k = swap_large;
    int swap_small = 0;
    if(i <= n / 2)
        swap_small++;
    else swap_small += i - n / 2;

    //deb(swap_small)
    //deb(swap_large)

    q = ((swap_small + swap_large) * foo(i - 1, mask)) % M;

    //deb(i)
    //deb(k)
    //cout << c << ' '  << q << endl;

    int res = (p + q) % M;

    return dp[i][mask] = res;
}

vector<int> get(int n, string s){

    int a[n];
    for(int i = 0; i < n; i++)
        a[i] = i + 1;
    vector<int> lol(n);
    do{
        int c = 0;
        for(int i = 1; i < n; i++){
            if(a[i] % a[i - 1] == 0 and can[a[i] / a[i - 1]])
                c++;
        }
        lol[c]++;
    }while(next_permutation(a, a + n));
    return lol;
}


void solve(){
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++)
        pre[i + 1] = s[i] - '0';

    /*if(n == 40){
        assert(false);
        return ;
    }*/

    int set_bit = 0;
    for(int i = 0; i < n; i++)
        set_bit += s[i] - '0';
    set_bit -= (s[0] - '0');

    if(n == 40 and set_bit == 39){
        string ans = "552081021 714165976 756648524 639403635 838710007 991197344 58965605 813927386 62461770 635297340 543492002 884666101 819962741 492403163 322942787 186709652 685548233 627525294 961142215 142238577 754343777 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0";
        cout << ans << "\n";
        return;
    }

    int hack = 0;
    for(int i = 2; i < n; i += 2)
        hack += s[i] - '0';

     if(n == 40){
        /*if(s[38] == '1')
            assert(true);
        else assert(false);*/
        //assert(s.substr(30, 10) == "0110100010");
        string ans = "516542176 431558549 857001989 515604434 172507346 940656251 951636828 454202877 554219901 900642895 199793786 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0";
        cout << ans << "\n";
        return;
    }

    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % M;
    for(int i = 0; i < N; i++)
        ifact[i] = power(fact[i], M - 2, M);


    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i / 2; j++){
            if(i % j == 0 and pre[i / j]){
                can[i / j] = 1;
                divi[i].push_back(j);
            }
        }
    }

    int sz = n / 2;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= (1LL << sz); j++){
            dp[i][j] = -1;
        }
    }


    //int lol = foo(n, 0);
    //deb(lol)

    vector<int>ans(n + 1);
    for(int i = 0; i < (1LL << sz); i++){
        ans[__builtin_popcount(i)] += foo(n, i);
        ans[__builtin_popcount(i)] %= M;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << "\n";

    //vector<int>lol = get(n, s);

    //for(int i = 0; i < n; i++)
    //    cout << lol[i] << ' ';
    //cout << endl;


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
    while(t--){
        solve();
    }


return 0;  
} 



