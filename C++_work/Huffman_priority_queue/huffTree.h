#ifndef huffTree_H
#define huffTree_H
#include <iostream>
using namespace std;

class huffTree{
public:
    char data;
    int freq;
    HuffmanTreeNode* left;
    HuffmanTreeNode* right;

    HuffmanTreeNode(char character,
                    int frequency);s
};

#include "huffTree.cpp"

#endif
