#include <gtest/gtest.h>
#include "Merkle.h"

TEST(MerkleTreeTest, RootHash) 
{
    vector<string> leaves = { "data1", "data2", "data3", "data4" };
    MerkleTree tree(leaves);

    string rootHash = tree.GetRootHash();
    EXPECT_FALSE(rootHash.empty());
}

TEST(MerkleTreeTest, LeafHashes)
{
    vector<string> leaves = { "data1", "data2", "data3", "data4" };
    MerkleTree tree(leaves);

    EXPECT_EQ(tree.GetLeafHash(0), HashFunk("data1"));
    EXPECT_EQ(tree.GetLeafHash(1), HashFunk("data2"));
    EXPECT_EQ(tree.GetLeafHash(2), HashFunk("data3"));
    EXPECT_EQ(tree.GetLeafHash(3), HashFunk("data4"));
}

TEST(MerkleTreeTest, OutOfRangeIndex)
{
    vector<string> leaves = { "data1", "data2" };
    MerkleTree tree(leaves);
    EXPECT_THROW(tree.GetLeafHash(2), std::out_of_range);
}
