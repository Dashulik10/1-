#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include "Merkle.h"
using namespace std;

string HashFunk(const string& data) 
{
    unsigned long hash = 0;
    for (char c : data)
    {
        hash += static_cast<unsigned char>(c);
        hash = (hash << 5) | (hash >> (32 - 5));
    }
    stringstream ss;
    ss << hex << setw(8) << setfill('0') << hash;
    return ss.str();
}

MerkleNode::MerkleNode(const string& data) : left(nullptr), right(nullptr)
{
    hash = HashFunk(data);
}
MerkleNode::MerkleNode(MerkleNode* left, MerkleNode* right) : left(left), right(right)
{
    hash = HashFunk(left->hash + right->hash);
}

string MerkleTree::GetRootHash()
{
    return root->hash;
}

MerkleTree::MerkleTree(const vector<string>& leavesData)
{
    vector<MerkleNode*> nodes;
    for (const auto& leaf : leavesData)
    {
        MerkleNode* newLeaf = new MerkleNode(leaf);
        nodes.push_back(newLeaf);
        leaves.push_back(newLeaf);
    }

    while (nodes.size() > 1)
    {
        vector<MerkleNode*> nextLevel;
        for (size_t i = 0; i < nodes.size(); i += 2)
        {
            if (i + 1 < nodes.size())
            {
                nextLevel.push_back(new MerkleNode(nodes[i], nodes[i + 1]));
            }
            else
            {
                nextLevel.push_back(nodes[i]);
            }
        }
        nodes = nextLevel;
    }
    root = nodes[0];
}

string MerkleTree::GetLeafHash(size_t index)
{
    if (index >= leaves.size())
    {
        throw out_of_range("Index out of range");
    }
    return leaves[index]->hash;
}
