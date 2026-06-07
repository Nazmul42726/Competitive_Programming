//Problem Link: https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/description/

class Solution {
    using ll = long long;
    
    ll cnt[16][10][10];
    ll sum[16][10][10];

    string s;
    int n;

    pair<ll, ll> dfs(int pos, int cur, int prev, bool isLimit, bool isLeading){
        if(pos == n) return {1, 0};

        if(!isLimit and !isLeading and cur>=0 and prev>=0){
            if(cnt[pos][cur][prev] != -1){
                return {cnt[pos][cur][prev], sum[pos][cur][prev]};
            }
        }

        ll curCnt = 0, curSum = 0;
        int up = isLimit ? s[pos] - '0' : 9;
        for(int d=0; d<=up; d++){
            bool newLeading = isLeading and (d==0);
            int newPrev = cur;
            int newCur = newLeading? -1: d;

            pair<ll,ll> subResult = dfs(pos+1, newCur, newPrev, isLimit && (d==up), newLeading);

            if(!newLeading and cur >=0 and prev >=0){
                if((prev > cur and d > cur) or (prev < cur and d < cur)){
                    curSum += subResult.first;
                }
            }
            curCnt += subResult.first;
            curSum += subResult.second;
        }

        if(!isLimit and !isLeading and cur>=0 and prev>=0){
            cnt[pos][cur][prev] = curCnt;
            sum[pos][cur][prev] = curSum;
        }
        return {curCnt, curSum};
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        long long x=0, y=0;
        if(num2 >= 100){
            s = to_string(num2);
            n = s.size();
            memset(cnt, -1, sizeof(cnt));
            memset(sum, -1, sizeof(sum));
            pair<long long,long long> tmp = dfs(0, -1, -1, true, true);
            x = tmp.second;
        }
        if(num1 > 100){
            s = to_string(num1-1);
            n = s.size();
            memset(cnt, -1, sizeof(cnt));
            memset(sum, -1, sizeof(sum));
            pair<long long,long long> tmp = dfs(0, -1, -1, true, true);
            y = tmp.second;
        }
        return (x-y);
    }
};
