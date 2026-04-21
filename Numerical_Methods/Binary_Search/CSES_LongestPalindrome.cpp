#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mxN = 1e6+10;
const int p1 = 29, p2 = 31;
const int mod1 = 1e9+7, mod2 = 1e9+7;

vector<int> pw1(mxN), pw2(mxN);
vector<int> invPw1(mxN), invPw2(mxN);

int n;
vector<pair<int,int>> hf, hr;

int modularInverse(int x, int mod){
    int exp = mod-2;
    int result = 1;

    while(exp){
        if(exp % 2) result = (x*result) % mod;
        x = (x*x)%mod;
        exp /= 2;
    }
    return result;
}

vector<pair<int,int>> hashing(string s){
    vector<pair<int,int>> hsh(n);

    for(int i=0; i<n; i++){
        int cur1 = ((s[i] - 'a' + 1) * pw1[i]) % mod1;
        int cur2 = ((s[i] - 'a' + 1) * pw2[i]) % mod2;

        if(i){
            cur1 = (cur1 + hsh[i-1].first) % mod1;
            cur2 = (cur2 + hsh[i-1].second) % mod2;
        }
        hsh[i] = {cur1, cur2};
    }
    return hsh;
}

bool f(int x){
    for(int i = x-1; i<n; i++){
        int cut1 = i+1-x;
        int cut2 = n-1-i;

        pair<int,int> h1 = hf[i];
        if(cut1 > 0){
            h1.first = (h1.first - hf[cut1-1].first + mod1) % mod1;
            h1.second = (h1.second - hf[cut1-1].second + mod2) % mod2;

            h1.first = (h1.first * invPw1[cut1]) % mod1;
            h1.second = (h1.second * invPw2[cut1]) % mod2;
        }

        int j = n-1-cut1;
        pair<int,int> h2 = hr[j];
        if(cut2 > 0){
            h2.first = (h2.first - hr[cut2-1].first + mod1) % mod1;
            h2.second = (h2.second - hr[cut2-1].second + mod2) % mod2;

            h2.first = (h2.first * invPw1[cut2]) % mod1;
            h2.second = (h2.second * invPw2[cut2]) % mod2;
        }

        if(h1 == h2) return true;
    }
    return false;
}

void solve(){
    string s; cin>>s;
    n = s.size();

    hf = hashing(s);
    reverse(s.begin(), s.end());
    hr = hashing(s);

    int result = 0;

    int low = 0, high = n/2;
    while(high - low > 1){
        int mid = (high + low) / 2;
        if(2*mid + 1 <= n and f(2*mid + 1)) low = mid;
        else high = mid-1;
    }
    if(f(2*high + 1)) result = max(result, 2*high + 1);
    else result = max(result, 2*low + 1);

    low = 0, high = n/2;
    while(high - low > 1){
        int mid = (high + low) / 2;
        if(2*mid <= n and f(2*mid)) low = mid;
        else high = mid-1;
    }
    if(f(2*high)) result = max(result, 2*high);
    else result = max(result, 2*low);

    string ans;

    for(int i = result-1; i<n; i++){
        int cut1 = i+1-result;
        int cut2 = n-1-i;

        pair<int,int> h1 = hf[i];
        if(cut1 > 0){
            h1.first = (h1.first - hf[cut1-1].first + mod1) % mod1;
            h1.second = (h1.second - hf[cut1-1].second + mod2) % mod2;

            h1.first = (h1.first * invPw1[cut1]) % mod1;
            h1.second = (h1.second * invPw2[cut1]) % mod2;
        }

        int j = n-1-cut1;
        pair<int,int> h2 = hr[j];
        if(cut2 > 0){
            h2.first = (h2.first - hr[cut2-1].first + mod1) % mod1;
            h2.second = (h2.second - hr[cut2-1].second + mod2) % mod2;

            h2.first = (h2.first * invPw1[cut2]) % mod1;
            h2.second = (h2.second * invPw2[cut2]) % mod2;
        }

        if(h1 == h2){
            ans = s.substr(cut2, result);
            break;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    pw1[0] = pw2[0] = 1;
    invPw1[0] = invPw2[0] = 1;
    for(int i=1; i<mxN; i++){
        pw1[i] = (pw1[i-1] * p1) % mod1;
        pw2[i] = (pw2[i-1] * p2) % mod2;

        invPw1[i] = modularInverse(pw1[i], mod1);
        invPw2[i] = modularInverse(pw2[i], mod2);
    }
    solve();
    return 0;
}
