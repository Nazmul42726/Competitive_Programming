// Problem Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/description/

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
        using pii = pair<int,int>;
        vector<pii> a(n);

        for(int i=0; i<n; i++) a[i] = {nums[i], i};
        sort(a.begin(), a.end());

        vector<int> pos(n);
        for(int i=0; i<n; i++) pos[a[i].second] = i;

        int lg = ceil(log2(n)) + 1;
        vector<vector<int>> spTree(lg+1, vector<int>(n));

        int r = 0;
        for(int l = 0; l<n; l++){
            while(r+1 < n and abs(a[r+1].first - a[l].first) <= maxDiff) r++;
            spTree[0][l] = r;
        }

        for(int i=1; i<lg; i++){
            for(int j=0; j<n; j++){
                spTree[i][j] = spTree[i-1][spTree[i-1][j]];
            }
        }

        int m = q.size();
        vector<int> result(m, -1);

        for(int i=0; i<m; i++){
            int x = pos[q[i][0]];
            int y = pos[q[i][1]];
            if(x > y) swap(x, y);
            if(x == y){
                result[i] = 0;
                continue;
            }

            int cur = x, jmp = 0;
            for(int j=lg-1; j>=0; j--){
                if(spTree[j][cur] < y){
                    cur = spTree[j][cur];
                    jmp += (1<<j);
                }
            }
            if(spTree[0][cur] >= y) result[i] = jmp + 1;
        }
        return result;
    }
};
