//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(212)
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            auto result = vector<string>();
            auto root = TrieNode(words);
            for (auto i = 0; i < board.size(); ++i)
                for (auto j = 0; j < board[0].size(); ++j)
                    dfs(board, i, j, words, result, &root);
            return result;
        };

    private:

        struct TrieNode {
            TrieNode* children[26];
            int wordIndex = -1;
            TrieNode() {
                for (auto i = 0; i < 26; ++i) children[i] = nullptr;
            }
            TrieNode(const vector<string>& words) {
                TrieNode* p = nullptr;
                for (auto i = 0; i < 26; ++i) children[i] = nullptr;
                for (auto i = 0; i < words.size(); ++i) {
                    p = this;
                    for (auto j = 0; j < words[i].length(); ++j) {
                        int c = words[i][j] - 'a';
                        if (nullptr == p->children[c]) p->children[c] = new TrieNode();
                        p = p->children[c];
                    }
                    p->wordIndex = i;
                }
            }
        };

        void dfs(vector<vector<char>>& board, int i, int j, const vector<string>& words, vector<string>& result, TrieNode* p) {
            char c = board[i][j];
            if (c == '#' || p->children[c - 'a'] == nullptr) return;
            p = p->children[c - 'a'];

            if (-1 != p->wordIndex) {
                result.push_back(words[p->wordIndex]);
                p->wordIndex = -1;
            }

            board[i][j] = '#';
            if (i > 0) dfs(board, i - 1, j, words, result, p);
            if (j > 0) dfs(board, i, j - 1, words, result, p);
            if (i < board.size() - 1) dfs(board, i + 1, j, words, result, p);
            if (j < board[0].size() - 1) dfs(board, i, j + 1, words, result, p);
            board[i][j] = c;

        }

SOLUTION_END

TEST_BEGIN(212)
    void test(const vector<string>& board, const vector<string>& words, const vector<string>& expected) {
        auto board_ = vector<vector<char>>(board.size());
        for (auto i = 0; i < board.size(); ++i) {
            board_[i].assign(board[i].begin(), board[i].end());
        }
        auto words_ = words;
        EXPECT_THAT(Solution().findWords(board_, words_), ::testing::UnorderedElementsAreArray(expected));
    }

TEST_END

MYTEST_F(212, Example) {
    test({
            "oaan",
            "etae",
            "ihkr",
            "iflv"
         }, { "oath", "pea", "eat", "rain"},
         { "eat", "oath" }
    );
}

MYTEST_F(212, Case1) {
    test({"a"}, {"a"}, {"a"});
}

MYTEST_F(212, Case2) {
    test({"ab", "cd"}, {"abcd"}, {});
}
