#ifndef MERKLE
#define MERKLE

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

string HashFunk(const string& data);

class MerkleNode 
{
public:
    string hash;
    MerkleNode* left;
    MerkleNode* right;

    MerkleNode(const string& data);
    MerkleNode(MerkleNode* left, MerkleNode* right);
};

class MerkleTree
{
public:
    MerkleNode* root;
    vector<MerkleNode*> leaves;

    MerkleTree(const vector<string>& leaves);
    string GetRootHash();
    string GetLeafHash(size_t index);
};



#endif
