/// This is leetCode medium problem for Trie
/// Link is : https://leetcode.com/problems/implement-trie-prefix-tree/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        bool is_word;
        TrieNode *child[26];
        TrieNode(){
            is_word = false;
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
        }
};

class Trie{
    private:
        TrieNode *root;
    public:
        Trie(){
            root = new TrieNode();
        }
        void insert(string s);
        bool search(string s);
        bool startsWith(string s);
};

void Trie::insert(string s){
    TrieNode *cur = root;
    for(int i=0;i<s.size();i++){
        int k = s[i]-'a';
        if(cur->child[k]==NULL)
            cur->child[k] = new TrieNode();
        cur = cur->child[k];
    }
    cur->is_word = true;
}

bool Trie::search(string s){
    TrieNode *cur = root;
    for(int i=0;i<s.size();i++){
        int k = s[i]-'a';
        if(cur->child[k]==NULL)
            return false;
        cur = cur->child[k];
    }
    return cur->is_word;
}

bool Trie::startsWith(string s){
    TrieNode *cur = root;
    for(int i=0;i<s.size();i++){
        int k = s[i]-'a';
        if(cur->child[k]==NULL)
            return false;
        cur = cur->child[k];
    }
    return true;
}

int main()
{
    Trie *t = new Trie();
    t->insert("abc");
    cout<<t->search("abc")<<endl;
    cout<<t->startsWith("ab")<<endl;
    return 0;
}