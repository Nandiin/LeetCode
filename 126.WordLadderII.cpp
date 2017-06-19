//
// Created by Nandiin Borjigin on 12/04/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(126)
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {

        auto size = wordList.size();
        vector<GraphNode*> adjacentTable(size, nullptr);
        size_t beginIndex = size;
        size_t endIndex = size;
        for (size_t i = 0; i < size; ++i) {
            if (wordList[i] == beginWord) beginIndex = i;
            else if (wordList[i] == endWord) endIndex = i;
            setupAdjacent(wordList, i, &adjacentTable[i]);
        }

        vector<vector<string>> ret;
        if (size == endIndex) return ret;
        if (size == beginIndex) {
            wordList.push_back(beginWord);
            adjacentTable.push_back(nullptr);
            setupAdjacent(wordList, size, &adjacentTable[size]);
            ++size;
        }

        TreeNode root(beginIndex);
        queue<TreeNode*> q;
        queue<TreeNode*> childQueue;
        set<size_t> traveled;
        q.push(&root);
        traveled.insert(beginIndex);
        const auto isTraveled = [&traveled](size_t x) -> bool { return traveled.end() != traveled.find(x); };
        bool found = false;
        while(!q.empty()) {
            auto aTreeNode = q.front();
            q.pop();
            auto aGraphNode = adjacentTable[aTreeNode->index];
            while (nullptr != aGraphNode) {
                size_t index = aGraphNode->index;
                if (!isTraveled(index)) {
                    auto newTreeNode = new TreeNode(index);
                    aTreeNode->children.push_back(newTreeNode);
                    if (!found) {
                        childQueue.push(newTreeNode);
                        found = index == endIndex;
                    }
                }
                aGraphNode = aGraphNode->next;
            }

            if (q.empty() && !found) {
                while(!childQueue.empty()) {
                    auto aChildNode = childQueue.front();
                    childQueue.pop();
                    q.push(aChildNode);
                    traveled.insert(aChildNode->index);
                }
            }
        }

        if (!constructLadder(&root, wordList, endWord, ret)) ret.clear();
        return ret;
    }

private:
    struct GraphNode {
        size_t index;
        GraphNode* next;
        GraphNode(size_t x) : index(x), next(nullptr) {}
    };

    struct TreeNode {
        size_t index;
        vector<TreeNode*> children;
        TreeNode(size_t x) : index(x), children(vector<TreeNode*>()) {}
    };

    void setupAdjacent(const vector<string> &wordList, size_t i, GraphNode **phead) {
        for (size_t j = 0; j < wordList.size(); ++j) {
            if (i == j) continue;
            if (transformable(wordList[i], wordList[j])) {
                *phead = new GraphNode(j);
                phead = &((*phead)->next);
            }
        }
    }

    bool constructLadder(TreeNode* node, const vector<string>& wordList, string& endWord, vector<vector<string>>& output) {
        auto word = wordList[node->index];
        if (0 == node->children.size()) {
            output = vector<vector<string>>({ vector<string>({ word })});
            return word == endWord;
        }
        for (auto child : node->children) {
            vector<vector<string>> tmp;
            if (constructLadder(child, wordList, endWord, tmp)) {
                for (auto &t : tmp) {
                    t.insert(t.begin(), wordList[node->index]);
                    output.push_back(t);
                }
            }
        }
        return true;
    }


    bool transformable(const string& a, const string& b) {
        int distance = 0;
        for (auto i = 0; i < a.size(); ++i) {
            distance += (a[i] != b[i] ? 1 : 0);
            if (distance > 1) return false;
        }
        return distance == 1;
    }
SOLUTION_END

TEST_BEGIN(126)
    template<size_t s1, size_t s2, size_t s3>
    void test(string beginWord, string endWord, const string* wordList, string expected[][s3]) {
        vector<string> wordListVec(wordList, wordList + s1);
        vector<vector<string>> expectedVec(s2);
        for (auto i = 0; i < s2; ++i) {
            expectedVec[i] = vector<string>(expected[i], expected[i] + s3);
        }
        auto output = Solution().findLadders(beginWord, endWord, wordListVec);
        EXPECT_THAT(output, ::testing::UnorderedElementsAreArray(expectedVec));
    }
TEST_END

MYTEST_F(126, Case1) {
    string wordList[] = { "hot","dot","dog","lot","log","cog" };
    string expected[][5] = {
            { "hit","hot","dot","dog","cog" },
            { "hit","hot","lot","log","cog" },
    };
    test<6, 2, 5>("hit", "cog", wordList, expected);
}

MYTEST_F(126, Case2) {
    string wordList[] = { "ted","tex","red","tax","tad","den","rex","pee" };
    string expected[][4] = {
            { "red","ted","tad","tax" },
            { "red","ted","tex","tax" },
            { "red","rex","tex","tax" },
    };
    test<8, 3, 4>("red", "tax", wordList, expected);
}

MYTEST_F(126, Case3) {
    vector<string> wordlist({ "hot", "dog" });
    EXPECT_TRUE(Solution().findLadders("hot", "dog", wordlist).empty());
}

MYTEST_F(126, Case4) {
    string wordList[] = { "hot", "dot", "dog" };
    string expected[][2] = {
            { "hot","dot" }
    };
    test<3, 1, 2>("hot", "dot", wordList, expected);
}
