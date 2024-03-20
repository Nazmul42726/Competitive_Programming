#include<bits/stdc++.h>
using namespace std;

const int base=1000*1000*1000;

vector<int> convertStringtoDigit(string s){
    vector<int> a;

    for(int i=(int)(s.length()); i>0; i-=9){
        if(i<9)
            a.push_back(atoi(s.substr(0,i).c_str()));
        else
            a.push_back(atoi(s.substr(i-9,9).c_str()));
    }

    while(a.size()>1 and a.back()==0) a.pop_back();
    return a;
}

void printNumber(vector<int> a){
    printf("%d", a.empty() ? 0 : a.back());

    for(int i=(int)(a.size())-2; i>=0; i--)
        printf("%09d", a[i]);
}

vector<int> addition(vector<int> a, vector<int> b){
    int carry=0;

    for(int i=0; i<(int)max(a.size(),b.size()) or carry; i++){
        if(i==a.size()) a.push_back(0);

        a[i]=carry+a[i]+((i<(int)b.size())?b[i]:0);

        carry=(a[i]>=base);
        if(carry) a[i]-=base;
    }
    return a;
}

vector<int> subtraction(vector<int> a, vector<int> b){
    int carry=0;
    for(int i=0; i<(int)(b.size()) or carry; i++){
        a[i]-=carry+(i<((int)b.size())?b[i]:0);

        carry=a[i]<0;

        if(carry) a[i]+=base;
    }
    while(a.size()> 1 and a.back()==0) a.pop_back();
    return a;
}

vector<int> multiplyByShortInteger(vector<int> a, int b){
    int carry=0;
    for(int i=0; i<(int)(a.size()) or carry; i++){
        if(i==a.size()) a.push_back(0);

        long long current=carry+(a[i]*b*1ll);

        a[i]=(int)(current%base);
        carry=(int)(current/base);
    }
    while(a.size()>1 and a.back()==0) a.pop_back();
    return a;
}

vector<int> multiplyByLongInteger(vector<int> a, vector<int> b){
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

vector<int> divideByShortInteger(vector<int> a, int b){
    int carry=0;
    for(int i=(int)a.size()-1; i>=0; i--){
        long long current=a[i]+carry*base*1ll;
        a[i]=(int)(current/b);
        carry=(int)(current%b);
    }
    while(a.size()>1 and a.back()==0) a.pop_back();
    return a;
}

int main(){
    string longNumberString1,longNumberString2;
    int shortInt;
    cin>>longNumberString1>>longNumberString2>>shortInt;

    vector<int> number1 = convertStringtoDigit(longNumberString1);
    vector<int> number2 = convertStringtoDigit(longNumberString2);

    vector<int> sum=addition(number1,number2);

    vector<int> subtract=(longNumberString1>=longNumberString2)?subtraction(number1,number2):subtraction(number2,number1);

    vector<int> multipleOfShortInt=multiplyByShortInteger(number1,shortInt);

    vector<int> multipleOfLongInt=multiplyByLongInteger(number1,number2);

    vector<int> dividedByShortInt=divideByShortInteger(number1,shortInt);

    cout<<longNumberString1<<endl;
    cout<<longNumberString2<<endl;
    
    printNumber(number1);
    cout<<endl;
    printNumber(number2);
    cout<<endl;
    printNumber(sum);
    cout<<endl;
    printNumber(subtract);
    cout<<endl;
    printNumber(multipleOfShortInt);
    cout<<endl;
    printNumber(multipleOfLongInt);
    cout<<endl;
    printNumber(dividedByShortInt);
    cout<<endl;
}