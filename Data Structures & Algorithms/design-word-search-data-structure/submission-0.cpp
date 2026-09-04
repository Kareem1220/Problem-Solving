class WordDictionary 
{
    struct TrieNode 
    {
        TrieNode* children[26];
        bool isEnd;
        TrieNode()
        {
            for(int i = 0 ; i < 26 ; i++) children[i] = nullptr;
            isEnd = false;
        }
    };

TrieNode* trie;
public:
    WordDictionary() 
    {
        trie = new TrieNode();
    }
    
    void addWord(string word) 
    {
        TrieNode* current = trie;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(current->children[word[i] - 'a'] == nullptr)
            {
                TrieNode* temp = new TrieNode();
                current->children[word[i] - 'a'] = temp;
            }
            current = current->children[word[i] - 'a'];
        }
        current->isEnd = true;
    }
    
    bool search(string word) 
    {
        return backtrack(trie, word, 0);
    }

    bool backtrack(TrieNode* current, string word , int index)
    {
        if(index == word.size()) return current->isEnd;
        if(word[index] == '.')
        {
            for(int j = 0 ; j < 26 ; j++)
            {
                if(current->children[j] != nullptr) 
                { 
                    if(backtrack(current->children[j],word,index + 1) == true) return true;
                }
            }
            return false;
        }
        else if(current->children[word[index] - 'a'] == nullptr) return false;
        current = current->children[word[index] - 'a'];
    
        return backtrack(current,word,index + 1);
    }
};
