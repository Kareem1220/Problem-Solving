class PrefixTree 
{
public:
    struct TrieNode 
    {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() 
        {
            for(int i = 0; i < 26; i++) children[i] = nullptr;
            isEnd = false;
        }
    };
    TrieNode* trie;

    PrefixTree() 
    {
        trie = new TrieNode();
    }
    void insert(string word) // fix the unnecessary second if statement
    {
        TrieNode* current = trie;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(current->children[word[i] - 'a'] == nullptr)
            {
                TrieNode* branch = new TrieNode();
                current->children[word[i] - 'a'] = branch;
            }
            current = current->children[word[i] - 'a'];
            if(i == word.size() - 1) current->isEnd = true;
        }
    }
    
    bool search(string word) 
    {
        TrieNode* current = trie;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(current->children[word[i] - 'a'] == nullptr) return false;
            current = current->children[word[i] - 'a'];
        }
        return current->isEnd;
    }

    bool startsWith(string prefix) 
    {
        TrieNode* current = trie;
        for(int i = 0 ; i < prefix.size() ; i++)
        {
            if(current->children[prefix[i] - 'a'] == nullptr) return false;
            current = current->children[prefix[i] - 'a'];
        }
        return true;
    }
};
