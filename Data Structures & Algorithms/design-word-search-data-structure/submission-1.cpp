struct Node{
    array<Node*, 26> children{};
    bool terminal = false;
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* it = root;
        for(char c: word){
            if(it->children[c-'a'] == NULL){
                it->children[c-'a'] = new Node;
            }
            it = it->children[c-'a'];
        }
        // cout<<"Added: "<<word<<'\n';
        it->terminal = true;
    }
    
    bool search(string word) {
        // cout<<"Searching: "<<word<<'\n';
        vector<Node*> search_space;
        Node* it = root;
        for(char c: word){
            if(search_space.size()==0){
                if(c=='.'){
                    int cnt = 0;
                    for(int i=0;i<26;i++){
                        search_space.push_back(it->children[i]);
                        if(it->children[i])cnt++;
                    }
                    // cout<<"    first letters: "<<c<<" found: "<<cnt<<'\n';
                }
                else{
                    it = it->children[c-'a'];
                    search_space.push_back(it);
                    // cout<<"    first letter: "<<c<<" found: "<<(it!=NULL)<<'\n';
                }
                continue;
            }
            
            if(c=='.'){
                int len = search_space.size();
                int cnt = 0;
                for(int i=0;i<len;i++){
                    if(search_space[i] != NULL){
                        for(int c=0;c<26;c++){
                            if(search_space[i]->children[c]){
                                cnt++;
                                search_space.push_back(search_space[i]->children[c]);
                            }
                        }
                        search_space[i] = nullptr; // removes duplication of same word above
                    }
                }
                // cout<<"    next letters: "<<c<<" progressed: "<<cnt<<'\n';
            }
            else{
                // progress all searchable words forward
                int cnt = 0;
                for(auto& ptr: search_space){
                    if(ptr != NULL){ 
                        // iterator based for-loop can be used to remove nullptr while running the loop - next improvement
                        ptr = ptr->children[c-'a'];
                        cnt++;
                    }
                }
                // cout<<"    next letters: "<<c<<" progressed: "<<cnt<<'\n';
            }
        }
        // cout<<"    search_space: "<<search_space.size()<<'\n';
        for(auto ptr: search_space){
            if(ptr != NULL){
                if(ptr->terminal)return true;
            }
        }
        return false;
    }
};
