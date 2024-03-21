#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int base=1000*1000*1000;

vector<int> convert(string s){
    vector<int> a;
    for(int i=(int)(s.length()); i>0; i-=9){
        if(i<9) a.push_back(atoi(s.substr(0,i).c_str()));
        else a.push_back(atoi(s.substr(i-9,9).c_str()));
    }
    while(a.size()>1 and a.back()==0) a.pop_back();
    return a;
}
vector<int> addition(vector<int> a, vector<int> b){
    int carry=0;
    for(int i=0; i<(int)max(a.size(),b.size()) or carry; i++){
        if(i==a.size()) a.push_back(0);
        a[i]=carry+a[i]+(i<(int)(b.size())?b[i]:0);

        carry=a[i]>=base;
        if(carry) a[i]-=base;
    }
    return a;
}
bool isSmaller(vector<int> a, vector<int> b){
    if(a.size()<b.size()) return true;
    if(a.size()==b.size()){
        for(int i=(int)(a.size())-1; i>=0; i--){
            if(a[i]!=b[i]) return a[i]<b[i];
        }
    }
    return false;
}
bool isSmallerOrEqual(vector<int> a, vector<int> b){
    if(a.size()<b.size()) return true;
    if(a.size()==b.size()){
        for(int i=(int)(a.size())-1; i>=0; i--){
            if(a[i]!=b[i]) return a[i]<b[i];
        }
        return true;
    }
    return false;
}
void printNumber(vector<int> a){
    printf("%d", a.empty() ? 0 : a.back());

    for(int i=(int)(a.size())-2; i>=0; i--)
        printf("%09d", a[i]);
    
    printf("\n");
}
void solve(string a, string b){
    vector<int> num1=convert(a);
    vector<int> num2=convert(b);

    vector<int> f1,f2;
    f1.push_back(1);
    f2.push_back(2);

    int cnt1=0,cnt2=0;

    if(isSmaller(f1,num1)) cnt1++,cnt2++;
    else if(isSmallerOrEqual(f1, num2)) cnt2++;
    if(isSmaller(f2,num1)) cnt1++,cnt2++;
    else if(isSmallerOrEqual(f2,num2)) cnt2++;

    while(isSmaller(f2,num2)){
        vector<int> temp=f2;
        f2=addition(f1,f2);
        f1=temp;

        if(isSmaller(f2,num1)) cnt1++;
        if(isSmallerOrEqual(f2,num2)) cnt2++;
    }
    cout<<cnt2-cnt1<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    string a,b;
    string terminate="0";
    while(1){
        cin>>a>>b;
        if(a==terminate and b==terminate) break;
        solve(a,b);
    }
    return 0;
}