struct Node{
    Node* link[26];
    bool flag = false;

    bool containsKey(char ch){
        return (link[ch - 'a'] != NULL);
    }

    Node* get(char ch){
        return link[ch - 'a'];
    }

    void put(char ch, Node* node){
        link[ch - 'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }
    void insert(string s){
        Node* node = root;
        for(int i=0; i<s.size(); i++){
            if(!node->containsKey(s[i])){
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->setEnd();
    }
    bool isComplete(string s){
        Node* node = root;
        for(int i=0; i<s.size(); i++){
            node = node->get(s[i]);
            if(!node->isEnd()) return false;
        }
        return node->isEnd();
    }
};

class Solution {
  public:
    string longestString(vector<string> &a) {
        Trie trie;
        for(auto it: a){
            trie.insert(it);
        }
        string result;

        for(auto it: a){
            if(trie.isComplete(it)){
                if(result.size() < it.size()) result = it;
                else if(result.size() == it.size() and result > it) result = it;
            }
        }
        
        return result;
    }
};
