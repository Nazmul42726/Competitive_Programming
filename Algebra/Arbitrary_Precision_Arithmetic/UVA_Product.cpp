#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int base = 1000*1000*1000;

vector<int> convert(string s){
    vector<int> a;
    for(int i=(int)(s.length()); i>0; i-=9){
        if(i<9) a.push_back(atoi(s.substr(0,i).c_str()));
        else a.push_back(atoi(s.substr(i-9,9).c_str()));
    }
    while(a.size()>1 and a.back()==0) a.pop_back();
    return a;
}
vector<int> multiply(vector<int> a, vector<int> b){
    vector<int> result(a.size()+b.size(),0);
    for(int i=0; i<(int)(a.size()); i++){
        int carry=0;
        for(int j=0; j<(int)(b.size()) or carry; j++){
            long long current=result[i+j]+1ll*a[i]*(j<(int)(b.size())?b[j]:0)+carry;
            result[i+j]=(int)(current%base);
            carry=(int)(current/base);
        }
    }
    while(result.size()>1 and result.back()==0) result.pop_back();
    return result;
}
void printNumber(vector<int> a){
    printf("%d", a.empty()?0:a.back());
    for(int i=(int)(a.size())-2; i>=0; i--)
        printf("%09d",a[i]);
    printf("\n");
}
void solve(string num1, string num2){
    vector<int> n1=convert(num1);
    vector<int> n2=convert(num2);

    vector<int> result=multiply(n1,n2);

    printNumber(result);
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    string num1,num2;
    while((cin>>num1) and (cin>>num2)){
        solve(num1,num2);
    }
    return 0;
}