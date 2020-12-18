#include <bits/stdc++.h>
using namespace std;
#define int long long int
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


vector<int>adj[55];
int vis[55];
set<int>pos;

void dfs(int u){
    vis[u] = 1;
    pos.insert(u);
    for(auto j : adj[u]){
        if(!vis[j])
            dfs(j);
    }
}


void solve(){

    string s;
    cin >> s;
    int n = s.length();

    for(int i = 0; i <= n; i++){
        adj[i].clear();
        vis[i] = 0;
    }
    vector<vector<int>> ok(n, vector<int>(n, 0));

    

    for(int i = 0; i + 1 < n; i++){
        int l = i, r = i + 1;
        while(l >= 0 and r < n and s[l] == s[r]){
            ok[l][r] = 1;
            l--, r++;
        }
    } 
    for(int i = 1; i + 1 < n; i++){
        int l = i - 1, r = i + 1;
        while(l >= 0 and r < n and s[l] == s[r]){
            ok[l][r] = 1;
            l--, r++;
        }
    }  

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(ok[i][j]){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    

    int ans = 0;
    for(int ii = 0; ii < (1 << n); ii++){
        string str = s;
        int f = 0;

        for(int j = 0; j < n; j++){
            if(ii & (1 << j)) str[j] = '#';
        }

        for(int i = 0; i <= n; i++)
            vis[i] = 0;

        pos.clear();
        
        

        for(int i = 0; i < n; i++)
            if(str[i] == '#') dfs(i);


        for(auto i : pos)
            str[i] = '#';



        for(int i = 0; i + 1 < n; i++){
            int l = i, r = i + 1;
            while(l >= 0 and r < n and str[l] == str[r]){
                if(ok[l][r] == 0){
                    f = 1;
                    break;
                }
                l--, r++;
            }

        }

        for(int i = 1; i + 1 < n; i++){
            int l = i - 1, r = i + 1;
            while(l >= 0 and r < n and str[l] == str[r]){
                if(ok[l][r] == 0){
                    f = 1;
                    break;
                }
                l--, r++;
            }
        } 

        if(!f) ans++;

    }

    cout << ans << endl;

        

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
     
    int t;
    cin >> t;
    while(t--){
        solve();
    }


return 0;  
} 



