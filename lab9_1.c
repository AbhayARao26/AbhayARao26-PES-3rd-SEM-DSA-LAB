/*
 TRIE DATA STRUCTURE
 
Create a Trie data structure in c, which can add strings into trie, delete strings from trie, search for strings
in trie, search for longest word stored in trie, obtain longest prefix matched given the string. You need to 
solve q queries

Input Format:
    First line has q Next q lines is of the format a,b or a

Constraints: 
    1<=q<=10000

Output Format:
    If a=1 , insert b into trie If a=2, delete b from trie If a=3 , print True if b is in trie, 
    else false If a=4, print the longest word of the trie If a=5, print the longest prefix matched 
    in trie with the string b Do print each in new lines

Sample Input:
    10
    1 hello
    1 world
    1 hi
    3 hello
    3 world
    3 hi
    4
    2 world
    3 world
    5 hel

Sample Output:
    True
    True
    True
    hello
    False
    hel
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode* alphabets[26];
    bool isEOW; // is end of word
} TNODE;

TNODE* createNode() {
    TNODE* newNode = (TNODE*) malloc (sizeof(TNODE));
    newNode->isEOW = false;
    
    for (int i = 0; i < 26; ++i) {
        newNode->alphabets[i] = NULL;
    }
    
    return newNode;
}

void insert(TNODE* root, char* word) {
    TNODE* tnode = root;
    int len = strlen(word);
    
    for (int i = 0; i < len; ++i) {
        int index = word[i] - 'a';
        
        if (!tnode->alphabets[index]) {
            tnode->alphabets[index] = createNode();
        }
        
        tnode = tnode->alphabets[index];
    }
    
    tnode->isEOW = true;
}


bool search(TNODE* root, char* word) {
    TNODE* tnode = root;
    int len = strlen(word);
    
    for (int i = 0; i < len; ++i) {
        int index = word[i] - 'a';
        
        if (!tnode->alphabets[index]) {
            return false; 
        }
        
        tnode = tnode->alphabets[index];
    }
    
    return tnode != NULL && tnode->isEOW;
}

void delete(TNODE* root, char* word) {
    TNODE* tnode = root;
    int len = strlen(word);
    
    for (int i = 0; i < len; ++i) {
        int index = word[i] - 'a';
        
        if (!tnode->alphabets[index]) {
            return; 
        }
        
        tnode = tnode->alphabets[index];
    }
    
    tnode->isEOW = false;
}

void findMaxlenWord(TNODE* root, char* currWord, char* maxlen) {
    if (!root) {
        return;
    }
    
    if (root->isEOW) {
        if (strlen(currWord) > strlen(maxlen)) {
            strcpy(maxlen, currWord);
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        if (root->alphabets[i]) {
            char nxtChar = 'a' + i;
            char nxtWord[100];
            strcpy(nxtWord, currWord);
            strncat(nxtWord, &nxtChar, 1);
            findMaxlenWord(root->alphabets[i], nxtWord, maxlen);
        }
    }
}

void MaxlenPrefixMatch(TNODE* root, char* prefix, char* matchedPrefix) {
    TNODE* tnode = root;
    int len = strlen(prefix);
    int matchedLen = 0;

    for (int i = 0; i < len; ++i) {
        int index = prefix[i] - 'a';
        
        if (!tnode->alphabets[index]) {
            break;
        }
        
        tnode = tnode->alphabets[index];
        matchedPrefix[matchedLen++] = prefix[i];
    }

    matchedPrefix[matchedLen] = '\0';
}

int main() {
    int n;
    scanf("%d", &n);

    TNODE* root = createNode();
    char MaxlenWord[100] = "";

    while (n--) {
        int a;
        char b[100];
        scanf("%d", &a);

        switch (a) {
            case 1:
                scanf("%s", b);
                insert(root, b);
                break;
                
            case 2:
                scanf("%s", b);
                delete(root, b);
                break;
                
            case 3:
                scanf("%s", b);
                printf("%s\n", search(root, b) ? "True" : "False");
                break;
                
            case 4:
                findMaxlenWord(root, "", MaxlenWord);
                printf("%s\n", MaxlenWord);
                break;
                
            case 5:
                scanf("%s", b);
                char matchedPrefix[100];
                MaxlenPrefixMatch(root, b, matchedPrefix);
                printf("%s\n", matchedPrefix);
                break;
                
            default:
                break;
        }
    }

    return 0;
}
