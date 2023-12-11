//
// Created by Fawzy on 11/10/2023.
//
#include <iostream>
#include "Trie.h"
using namespace std;

Trie::Trie()
{
    root= new trieNode();

}

//string for the node building
//
void Trie::insert(string room, string location, string t) const

{
    trieNode* n=root;


    for (int i = 0; i < room.length(); i++)
    {
        char c = room[i];
        if (!n->children[c])
            n->children[c] = new trieNode();

        n = n->children[c];
    }
    n->word = true;
    n->building=location;
    n->type=t;

}



bool Trie:: search(const string room, trieNode*&pointer) const{
    trieNode* n=root;

    for (int i = 0; i < room.length(); i++)
    {
        char c=room[i];
        if (!n->children[c])
            return false;

        n = n->children[c];
    }
    pointer = n;
    return n->word;
}

