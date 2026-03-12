#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct Node{
    Node* links[2];
    int cnt;

    Node(){
        links[0] = links[1] = NULL;
        cnt = 0;
    }

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
private: Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int x){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = ((x>>i)&1);
            if(!node->containsBit(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
            node->cnt++;
        }
    }

    void remove(int x){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = ((x>>i)&1);
            if(!node->containsBit(bit)) return;
            node = node->get(bit);
            node->cnt--;
        }
    }

    int cntArmy(int p, int l){
        Node* node = root;
        int result = 0;
        for(int i=31; i>=0; i--){
            int bitP = ((p>>i)&1);
            int bitL = ((l>>i)&1);

            if(bitL == 0){
                if(!node->containsBit(bitP)) return result;
                node = node->get(bitP);
            }
            else{
                if(node->containsBit(bitP)){
                    result += node->get(bitP)->cnt;
                }
                int choice = 1 - bitP;
                if(!node->containsBit(choice)) return result;
                node = node->get(choice);
            }
        }
        return result;
    }
};

void solve(){
    int q;
    cin>>q;

    Trie trie;

    while(q--){
        int type; cin>>type;
        if(type == 1){
            int x; cin>>x;
            trie.insert(x);
        }
        else if(type == 2){
            int x; cin>>x;
            trie.remove(x);
        }
        else{
            int p, l;
            cin>>p>>l;
            cout<<trie.cntArmy(p, l)<<endl;
        }
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}
