struct TrieNode{
    vector<TrieNode*> children;
    bool isWord;
    TrieNode(): children(26), isWord(false){}
};


class WordDictionary {
private:
    TrieNode* root;

    bool searchTrie(string word, TrieNode* node){
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(auto child : node->children){
                    if(child != nullptr && searchTrie(word.substr(i + 1), child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(node->children[c - 'a'] == nullptr){
                    return false;
                }
                node = node->children[c - 'a'];
            }
        }
        return node->isWord;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        Trie* node = this->root;

        for(auto c : word){
            if(node->children[c - 'a'] == nullptr){
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return searchTrie(word, this->root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */