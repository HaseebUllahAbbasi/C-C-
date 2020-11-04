
#include "huffTree.h"
class HuffmanTreeNode
{
    public:
    // Stores character
    char data;

    // Stores frequency of
    // the character
    int freq;

    // Left child of the
    // current node
    HuffmanTreeNode* left;

    // Right child of the
    // current node
    HuffmanTreeNode* right;

    // Initializing the
    // current node
    HuffmanTreeNode(char character,
                    int frequency)
    {
        data = character;
        freq = frequency;
        left = right = NULL;
    }
};
