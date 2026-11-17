struct Node {
    vector<Node*> children = vector<Node*> (26, nullptr);
    bool terminal = false;
};

class PrefixTree {
    // nodes () - all lower case english letters
    // terminal
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* it = root;
        for(char c: word){
            if(it->children[c-'a']==NULL){
                it->children[c-'a'] = new Node;
            }
            it = it->children[c-'a'];
        }
        it->terminal = true;
    }
    
    bool search(string word) {
        Node* it = root;
        for(char c:word){
            if(it->children[c-'a']==NULL)return false;
            it = it->children[c-'a'];
        }
        return it->terminal;
    }
    
    bool startsWith(string prefix) {
        Node* it = root;
        for(char c: prefix){
            if(it->children[c-'a']==NULL)return false;
            it = it->children[c-'a'];
        }
        return true;
    }
};
