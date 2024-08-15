#include <iostream>
#include <vector>
using namespace std;

string commonPrefixUtil(string str1, string str2){
    string word;
    int str1_len = str1.length();
    int str2_len = str2.length();

    for (int i = 0, j = 0; i < str1_len && j < str2_len; i++, j++){
        if(str1[i] != str2[j]){
            break;
        }
        word.push_back(str1[i]);
    }

    return word;
}


void noPrefix(vector<string> words){

    int length = words.size();
    string prefix = words[0];
    string badWord = "";
    bool found = false;

    for (int i = 1; i < length; i++)
    {
        string result = commonPrefixUtil(prefix, words[i]);

        if(result == prefix) {
            found = true;
            badWord = words[i];
            break;
        }
    }

    if(found){
        cout << "BAD SET" << endl;
        cout << badWord << endl;
    } else {
        cout << "GOOD SET";
    }

}


int main() {
    vector<string> words;
    words.push_back("aab");
    words.push_back("defgab");
    words.push_back("abcde");
    words.push_back("aabcde");
    words.push_back("bbbbbbbbbb");
    words.push_back("jabjjjad");

    vector<string> words2;
    words2.push_back("abcd");
    words2.push_back("bc");
    words2.push_back("abcde");
    words2.push_back("bcde");


    noPrefix(words);


    return 0;
}

class Trie {
    bool word;
    vector<Trie*> child;
    
    public:
    Trie(char c) {
        word = false;
        child = vector<Trie*>(10, NULL);
    }
    
    Trie* add(char c) {
        if (!this->child[c-'a'])
            this->child[c-'a'] = new Trie(c);
            
        return this->child[c-'a'];
    }
    
    bool exist(char c) {
        if (this->child[c-'a'])
            return true;
        return false;
    }
    
    void markWord() {
        this->word = true;
    }
    
    bool isWord() {
        return this->word;
    }
};

void nonoPrefix(vector<string> words) {
    Trie* root = new Trie('*');
    Trie* p = root;
    for (int i = 0;i < words.size();i++) {
        int lastIdx = words[i].length()-1;
        for (int j = 0;j < lastIdx;j++) {
            p = p->add(words[i][j]);
            if (p->isWord()) {
                cout << "BAD SET" << endl;
                cout << words[i] << endl;
                return;
            }
        }
        if (p->exist(words[i][lastIdx])) {
            cout << "BAD SET" << endl;
            cout << words[i] << endl;
            return;
        }
        p = p->add(words[i][lastIdx]);
        p->markWord();
        p = root;
    }
    
    cout << "GOOD SET" << endl;
}