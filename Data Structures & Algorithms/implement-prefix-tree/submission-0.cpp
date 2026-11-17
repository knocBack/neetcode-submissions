struct Node {
    vector<Node*> children = vector<Node*>(26, nullptr);
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
        int idx = 0;
        for(int i=0;i<word.size();i++){
            idx = word[i]-'a';
            if(it->children[idx]==NULL){
                it->children[idx] = new Node;
            }
            it = it->children[idx];
        }
        it->terminal = true;
    }
    
    bool search(string word) {
        Node* it = root;
        int idx = 0;
        for(int i=0;i<word.size();i++){
            idx = word[i]-'a';
            if(it->children[idx]==NULL)return false;
            it = it->children[idx];
        }
        return it->terminal;
    }
    
    bool startsWith(string prefix) {
        Node* it = root;
        int idx = 0;
        for(int i=0;i<prefix.size();i++){
            idx = prefix[i]-'a';
            if(it->children[idx]==NULL)return false;
            it = it->children[idx];
        }
        return true;
    }
};
