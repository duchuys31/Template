#include<bits/stdc++.h>
using namespace std;

const int SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[SIZE];
    int f[SIZE];
    bool isEnd;
};

struct TrieNode *getNode(void) // Tao mot nut moi
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isEnd = false;
    for (int i = 0; i < SIZE; i++)
    {
        pNode->children[i] = NULL;
        pNode->f[i] = 0;
    }
    return pNode;
}

void Insert(struct TrieNode *root, string key) // Chen xau vao
{
    struct TrieNode *parent = root;
    for (int i = 0; i < key.size(); i++)
    {
        int id = key[i] - 'a';
        if (!parent->children[id])
            parent->children[id] = getNode();
        parent->f[id]++;
        parent = parent->children[id];
    }
    parent->isEnd = true;
}

int search(struct TrieNode *root, string key) // Tim kiem
{
    int res;
    struct TrieNode *parent = root;
    for (int i = 0; i < key.size(); i++)
    {
        int id = key[i] - 'a';
        if (!parent->children[id])
            return false;
        res = parent->f[id];
        parent = parent->children[id];
    }
    return res;
}

void PrintWords(struct TrieNode *root, char str[], int id)
{
    if (root->isEnd)
    {
        str[id] = '\0';
        cout << str << '\n';
    }

    for (int i = 0; i < SIZE; i++)
        if (root->children[i])
        {
            str[id] = i + 'a';
            PrintWords(root->children[i], str, id + 1);
        }
}

bool isEmpty(struct TrieNode *root)
{
    for (int i = 0; i < SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

void Del(struct TrieNode *root, string key, int level)
{
    if (level == key.length())
        return;
    int id = key[level] - 'a';
    Del(root->children[id], key, level + 1);
    if (isEmpty(root->children[id]))
    {
        delete root->children[id];
        root->children[id] = NULL;
    }
}

struct TrieNode *root = getNode();
