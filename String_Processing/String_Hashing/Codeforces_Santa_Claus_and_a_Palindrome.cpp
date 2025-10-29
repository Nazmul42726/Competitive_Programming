#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll p1 = 31, p2 = 37;
const ll mod1 = 1e9+7, mod2 = 1e9+9;
const ll mxN = 1e5+10;

vector<ll> pp1(mxN), pp2(mxN);

pair<ll,ll> calHash(string s){
    ll n = s.size();
    ll h1 = 0, h2 = 0;

    for(ll i=0; i<n; i++){
        h1 = (h1 + ((ll)(s[i]-'a'+1) * pp1[i])) % mod1;
        h2 = (h2 + ((ll)(s[i]-'a'+1) * pp2[i])) % mod2;
    }
    return {h1,h2};
}

void solve(){
    pp1[0] = pp2[0] = 1;
    for(ll i=1; i<mxN; i++){
        pp1[i] = (pp1[i-1]*p1)%mod1;
        pp2[i] = (pp2[i-1]*p2)%mod2;
    }

    ll n,k;
    cin>>n>>k;

    map<pair<ll,ll>, ll> m;
    map<pair<ll,ll>, pair<ll,ll>> revHash;
    vector<priority_queue<ll>> pqs;

    map<pair<ll,ll>, string> ms;

    for(ll i=0; i<n; i++){
        string s;
        ll beauty;
        cin>>s>>beauty;

        pair<ll,ll> hsh = calHash(s);
        reverse(s.begin(),s.end());
        pair<ll,ll> revHsh = calHash(s);

        if(m.find(hsh) == m.end()){
            priority_queue<ll> pq;
            pq.push(beauty);
            pqs.push_back(pq);
            ll ind = pqs.size();
            m[hsh] = ind-1;
        }
        else{
            pqs[m[hsh]].push(beauty);
        }
        revHash[hsh] = revHsh;

        ms[hsh] = s;
    }

    ll result = 0, cost = 0;

    for(auto it: m){
        pair<ll,ll> cur = it.first;
        pair<ll,ll> rev = revHash[cur];

        if(m.find(rev) == m.end()) continue;

        if(cur != rev){
            ll ind1 = m[cur];
            ll ind2 = m[rev];
            
            while(!pqs[ind1].empty() and !pqs[ind2].empty()){
                ll toAdd = pqs[ind1].top() + pqs[ind2].top();

                if(toAdd < 0){
                    while(!pqs[ind1].empty() and pqs[ind1].top()<0) pqs[ind1].pop();
                    while(!pqs[ind2].empty() and pqs[ind2].top()<0) pqs[ind2].pop();
                    break;
                }
                // cout<<ms[cur]<<" "<<ms[rev]<<" ";
                // cout<<toAdd<<endl;
                result += toAdd;
                pqs[ind1].pop();
                pqs[ind2].pop();
            }
        }
        else{
            ll ind = m[cur];
            while(pqs[ind].size() > 1){
                ll toAdd = pqs[ind].top();
                pqs[ind].pop();
                
                if(toAdd < 0){
                    while(!pqs[ind].empty()) pqs[ind].pop();
                    break;
                }
                if(toAdd + pqs[ind].top() < 0){
                    pqs[ind].push(toAdd);
                    break;
                }
                if(pqs[ind].top() < 0){
                    cost = max(cost, abs(pqs[ind].top()));
                }
                toAdd += pqs[ind].top();
                // cout<<ms[cur]<<" "<<ms[rev]<<" ";
                // cout<<toAdd<<endl;
                result += toAdd;
                pqs[ind].pop();
            }
        }
    }

    ll ext = 0;
    for(auto it: m){
        if(it.first == revHash[it.first] and pqs[it.second].size() and pqs[it.second].top() > 0){
            ext = max(ext, pqs[it.second].top());
        }
    }
    result += max(ext, cost);

    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}
