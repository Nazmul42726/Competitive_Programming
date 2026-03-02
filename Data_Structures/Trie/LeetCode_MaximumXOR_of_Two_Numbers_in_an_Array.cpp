struct Node{
    Node* links[2];

    bool containsBit(int bit){
        return (links[bit] != NULL);
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
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
        for(int i=32; i>=0; i--){
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
                result += (1<<i);
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
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(auto it: nums){
            trie->insert(it);
        }
        int result = 0;
        for(auto it: nums){
            result = max(result, trie->mxXor(it));
        }
        return result;
    }
};
