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
        for(int i=0;i<word.size();i++){
            if(it->children[word[i]-'a']==NULL){
                it->children[word[i]-'a'] = new Node;
            }
            it = it->children[word[i]-'a'];
        }
        it->terminal = true;
    }
    
    bool search(string word) {
        Node* it = root;
        for(int i=0;i<word.size();i++){
            if(it->children[word[i]-'a']==NULL)return false;
            it = it->children[word[i]-'a'];
        }
        return it->terminal;
    }
    
    bool startsWith(string prefix) {
        Node* it = root;
        for(int i=0;i<prefix.size();i++){
            if(it->children[prefix[i]-'a']==NULL)return false;
            it = it->children[prefix[i]-'a'];
        }
        return true;
    }
};
