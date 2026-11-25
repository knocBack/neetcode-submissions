struct Node{
    array<Node*, 26> children{};
    bool terminal = false;
};

class Solution {
    Node* root = new Node();

    vector<vector<int>> DIRS = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };

    void insertTrie(string word){
        Node* it = root;
        for(char c: word){
            if(it->children[c-'a'] == NULL){
                it->children[c-'a'] = new Node();
            }
            it = it->children[c-'a'];
        }
        it->terminal = true;
    }

    bool searchTrie(string word){
        Node* it = root;
        for(char c:word){
            if(it == NULL)return false;
            it = it->children[c-'a'];
        }
        return it && it->terminal;
    }

    Node* children(string word){
        Node* it = root;
        for(char c:word){
            if(it==NULL)return NULL;
            it = it->children[c-'a'];
        }
        return it;
    }

    bool validate(const pair<int,int>& p1, const int& x, const int& y){
        if(p1.first < 0 || p1.first >= x)return false;
        if(p1.second < 0 || p1.second >= y)return false;
        return true;
    }

    // traverse all paths from one point to other
    void dfs_trie(pair<int,int> p1, pair<int, int> p2, const int& m, const int& n, vector<vector<char>>& board, string prefix, vector<vector<bool>>& visited){
        if(!validate(p1, m, n) || !validate(p2, m, n))return;
        if(visited[p1.first][p1.second])return;

        prefix += board[p1.first][p1.second];
        visited[p1.first][p1.second] = true;
        // cout<<prefix<<'\n';
        insertTrie(prefix);

        if(p1 == p2){visited[p1.first][p1.second] = false; return;}

        pair<int,int> p3;
        for(vector<int> next: DIRS){
            p3=p1;
            p3.first += next[0];
            p3.second += next[1];
            dfs_trie(p3, p2, m, n, board, prefix, visited);
        }

        visited[p1.first][p1.second] = false;
    }

    void dfs(pair<int,int> cur, const int& m, const int& n, vector<vector<char>>& board, string prefix, vector<vector<bool>>& visited, set<string>& ans){
        if(!validate(cur, m, n))return;
        if(visited[cur.first][cur.second])return;

        // am I ending any words now?
        prefix += board[cur.first][cur.second]; // added current letter
        if(searchTrie(prefix)){
            ans.insert(prefix);
        }
        visited[cur.first][cur.second] = true;

        // get all for this prefix children
        Node* child = children(prefix);
        
        // traverse through children
        pair<int,int> next;
        char nextChar = 'a';
        for(auto d: DIRS){
            next = {cur.first+d[0], cur.second+d[1]};
            if(validate(next, m, n)){
                nextChar = board[next.first][next.second];

                if(child->children[nextChar-'a'] != NULL)
                    dfs(next, m, n, board, prefix, visited, ans);   
            }
        }

        visited[cur.first][cur.second] = false;

        return;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        for(string s: words){
            insertTrie(s);
        }

        set<string> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<bool>> visited (m, vector<bool>(n, false));
                if(root->children[board[i][j]-'a'] != NULL){
                    // cout<<"Start: "<<i<<' '<<j<<'\n';
                    dfs({i,j}, m, n, board, "", visited, ans);
                }
            }
        }

        return vector<string>(ans.begin(), ans.end());
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         for(int x=0;x<m;x++){
        //             for(int y=0;y<n;y++){
        //                 // if(i==x && j==y)continue;
        //                 vector<vector<bool>> visited (m, vector<bool>(n, false));
        //                 cout<<"Start: "<<i<<' '<<j<<" End: "<<x<<' '<<y<<'\n';
        //                 dfs_trie({i,j}, {x,y}, m, n, board, "", visited);
        //             }
        //         }
        //     }
        // }

        // return ans;

        // for(string s: words){
        //     insertTrie(s);
        // }
        // cout<<"Found: "<<words[0]<<" "<<searchTrie(words[0])<<'\n';
        // cout<<"Found: test "<<searchTrie("test")<<'\n';
        // return {};
    }
};
