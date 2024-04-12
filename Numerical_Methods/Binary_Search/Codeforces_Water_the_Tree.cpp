#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool ok(vector<ll>& a, ll maxHeight, ll day){
    ll one=(day+1)/2;
    ll two=(day/2)*2;  //what a equation
    ll n=a.size();

    bool firstCase=true;
    for(ll i=0; i<n; i++){
        ll hDiff=maxHeight-a[i];
        if(one+two<hDiff){
            firstCase=false;
            break;
        }
        else{
            if(hDiff%2){
                if(one==0){
                    firstCase=false;
                    break;
                }
                else{
                    hDiff--;
                    one--;
                }
            }
            ll tc=min(hDiff,two);
            hDiff-=tc;
            two-=tc;
            if(hDiff){
                one-=hDiff;
                hDiff=0;
            }
        }
    }
    if(firstCase) return true;

    one=(day+1)/2;
    two=(day/2)*2;
    bool secondCase=true;
    for(ll i=0; i<n; i++){
        ll hDiff=maxHeight+1-a[i];
        if(one+two<hDiff){
            secondCase=false;
            break;
        }
        else{
            if(hDiff%2){
                if(one==0){
                    secondCase=false;
                    break;
                }
                else{
                    hDiff--;
                    one--;
                }
            }
            ll tc=min(hDiff,two);
            hDiff-=tc;
            two-=tc;
            if(hDiff){
                one-=hDiff;
                hDiff=0;
            }
        }
    }
    if(secondCase) return true;

    one=(day+1)/2;
    two=(day/2)*2;
    bool thirdCase=true;
    for(ll i=0; i<n; i++){
        ll hDiff=maxHeight+2-a[i];
        if(one+two<hDiff){
            thirdCase=false;
            break;
        }
        else{
            if(hDiff%2){
                if(one==0){
                    thirdCase=false;
                    break;
                }
                else{
                    hDiff--;
                    one--;
                }
            }
            ll tc=min(hDiff,two);
            hDiff-=tc;
            two-=tc;
            if(hDiff){
                one-=hDiff;
                hDiff=0;
            }
        }
    }
    if(thirdCase) return true;
    return false;
}
ll binarySearch(ll left, ll right, vector<ll>& a, ll maxHeight){
    while(right-left>1){
        ll mid=left+(right-left)/2;
        if(ok(a,maxHeight,mid)) right=mid;
        else left=mid+1;
    }
    if(ok(a,maxHeight,left)) return left;
    else return right;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll maxHeight=0;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        maxHeight=max(maxHeight,a[i]);
    }
    ll maxDay=0;
    for(ll i=0; i<n; i++){
        maxDay+=(maxHeight-a[i]);
    }
    maxDay*=2;
    
    ll result=binarySearch(0,maxDay,a,maxHeight);
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve();
    }
    return 0;
}