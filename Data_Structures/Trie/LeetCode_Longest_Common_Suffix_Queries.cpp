//Problem Link: https://leetcode.com/problems/longest-common-suffix-queries/description/
//Difficulty: Hard
//Memory Optimized Trie Implementation

struct Node{
    int link[26];
    int len;
    int idx;

    Node(int i = 0, int l = 1e9){
        idx = i;
        len = l;
        memset(link, -1, sizeof(link));
    }
};

class Trie {
public:
    vector<Node> trie;

    Trie(int ind, int mnLen){
        trie.push_back(Node(ind, mnLen));
    }

    void insert(string &s, int ind){
        int node = 0;
        for(char ch : s){
            int c = ch - 'a';
            if(trie[node].link[c] == -1){
                trie[node].link[c] = trie.size();
                trie.push_back(Node(ind, s.size()));
            }

            node = trie[node].link[c];
            if(trie[node].len > s.size()){
                trie[node].len = s.size();
                trie[node].idx = ind;
            }
        }
    }

    int query(string &s){
        int node = 0;

        for(char ch : s){
            int c = ch - 'a';

            if(trie[node].link[c] == -1) return trie[node].idx;
            node = trie[node].link[c];
        }
        return trie[node].idx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        int n = wc.size();
        int ind = -1, mnLen = 1e9+7;

        for(int i=0; i<n; i++){
            if(wc[i].size() < mnLen){
                mnLen = wc[i].size();
                ind = i;
            }
        }

        Trie trie(ind, mnLen);
        for(int i=0; i<n; i++){
            reverse(wc[i].begin(), wc[i].end());
            trie.insert(wc[i], i);
        }

        int m = wq.size();
        vector<int> result(m, 0);
        for(int i=0; i<m; i++){
            reverse(wq[i].begin(), wq[i].end());
            result[i] = trie.query(wq[i]);
        }
        return result;
    }
};
