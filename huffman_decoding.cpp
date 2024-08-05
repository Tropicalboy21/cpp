#include <iostream>
using namespace std;

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;


void decode_huff(node * root, string s) {
    string decodedWord = "";
    node* current = root;
    int length = s.size();

    for (int i = 0; i < length; i++)
    {
        if(s[i] == '0'){
            current = current->left;
        } else if (s[i] == '1') {
            current = current->right;
        }

        if(current->left == NULL && current->right == NULL){

            decodedWord += current->data;
            current = root;
        }

    }

    cout << decodedWord;
}
