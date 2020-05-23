class Trie {
    
    struct TrieNode {
        bool isWordEnd;
        TrieNode* next[26];
        
        TrieNode() {
            isWordEnd = false;
            for(int i=0;i<26;i++) 
                next[i] = NULL;
        }
    };
    
    TrieNode* root;
    
    bool _search(string s, int idx, TrieNode* curr, bool prefixSearch) {
        if(idx==s.length()) {
            return (curr->isWordEnd || prefixSearch);
        }    
        if(curr->next[s[idx]-'a'] == NULL) {
            return false;  
        }
        return _search(s, idx+1, curr->next[s[idx]-'a'], prefixSearch);
    }

    
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++) {
            if(curr->next[word[i]-'a'] == NULL)
                curr->next[word[i]-'a'] = new TrieNode();
            curr = curr->next[word[i]-'a'];
        } 
        curr->isWordEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return _search(word,0,root,false); 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {    
        return _search(prefix,0,root,true); 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
