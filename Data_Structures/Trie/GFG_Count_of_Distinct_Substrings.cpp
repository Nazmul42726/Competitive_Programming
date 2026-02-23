struct Node{
    Node* links[26];
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
};

class Trie{
    private:
        Node* root;
    
    public:
        int count;
        Trie(){
            root = new Node();
            count = 0;
        }
        
        void insert(string s){
            Node* node = root;
            for(int i=0; i<s.size(); i++){
                if(!node->containsKey(s[i])){
                    count++;
                    node->put(s[i], new Node());
                }
                node = node->get(s[i]);
            }
        }
};

class Solution {
  public:
    int countSubs(string& s) {
        Trie* trie = new Trie();
        
        int n = s.size();
        for(int i=0; i<n; i++){
            trie->insert(s.substr(i, n-i));
        }
        return trie->count;
    }
};
