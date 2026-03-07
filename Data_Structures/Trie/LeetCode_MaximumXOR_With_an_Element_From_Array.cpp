struct Node{
    Node* links[2];

    bool containsBit(int bit){
        return (links[bit] != NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }
    void insert(long long n){
        Node* node = root;
        for(int i = 32; i>=0; i--){
            int curBit = ((n>>i)&1);
            if(!node->containsBit(curBit)){
                node->put(curBit, new Node());
            }
            node = node->get(curBit);
        }
    }

    int mxXor(long long n){
        Node* node = root;
        int result = 0;
        for(int i=32; i>=0; i--){
            int curBit = ((n>>i)&1);
            int neededBit = 1-curBit;

            if(node->containsBit(neededBit)){
                result += (1LL<<i);
                node = node->get(neededBit);
            }
            else{
                node = node->get(curBit);
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        Trie* trie = new Trie();
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int m = q.size();
        vector<pair<int,pair<int,int>>> offQueries(m);

        for(int i=0; i<m; i++){
            offQueries[i] = {q[i][1], {q[i][0], i}};
        }
        vector<int> result(m,-1);
        sort(offQueries.begin(), offQueries.end());

        int idx = 0;
        for(auto it: offQueries){
            int curX = it.second.first;
            int curLimit = it.first;
            int ind = it.second.second;

            while(idx < n and nums[idx] <= curLimit){
                trie->insert(nums[idx]);
                idx++;
            }
            if(idx == 0) continue;

            int ans = trie->mxXor(curX);
            result[ind] = ans;
        }
        return result;
    }
};
