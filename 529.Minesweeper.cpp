//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(529)
        vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
            auto row = click[0];
            auto column = click[1];

            if (board[row][column] == 'M') {
                board[row][column] = 'X';
                return board;
            }


            auto width = board[0].size();
            auto height = board.size();
            vector<vector<char>> markedBoard(height, vector<char>(width, '0'));
            vector<vector<vector<pair<int, int>>>> sur(height, vector<vector<pair<int, int>>>(width, {}));

            for (auto i = 0; i < board.size(); ++i) {
                for (auto j = 0; j < board[0].size(); ++j) {
                    sur[i][j] = surroundings(width, height, make_pair(i, j));
                    if (board[i][j] == 'M') {
                        markedBoard[i][j] = 'M';
                        for (auto c: sur[i][j]) {
                            if (markedBoard[c.first][c.second] != 'M') ++(markedBoard[c.first][c.second]);
                        }
                    }
                }
            }

            queue<pair<int, int>> q;
            q.push(make_pair(row, column));

            while(!q.empty()) {
                auto coord = q.front();
                q.pop();
                auto ref = markedBoard[coord.first][coord.second];
                if (ref > '0') {
                    board[coord.first][coord.second] = ref;
                } else {
                    board[coord.first][coord.second] = 'B';
                    for (auto c: sur[coord.first][coord.second]) {
                        if (board[c.first][c.second] == 'E') {
                            q.push(c);
                            board[c.first][c.second] = 'B';
                            // Important: prevent adding same coord multiple times
                            // board[c.first][c.second] is not necessarily 'B',
                            // it will be changed to correct value in the future iteration.
                        }
                    }
                }
            }

            return board;

        }
    private:
        vector<pair<int, int>> surroundings(int width , int height, pair<int, int> coord) {
            auto rowMin = std::max(coord.first - 1, 0);
            auto rowMax = std::min(coord.first + 1, height - 1);
            auto columnMin = std::max(coord.second - 1, 0);
            auto columnMax = std::min(coord.second + 1, width - 1);

            vector<pair<int, int>> result;

            for (auto i = rowMin; i <= rowMax; ++i) {
                for (auto j  = columnMin; j <= columnMax; ++j) {
                    if (i == coord.first && j == coord.second) continue;
                    result.push_back(std::make_pair(i, j));
                }
            }

            return result;
        };
SOLUTION_END

TEST_BEGIN(529)
    void test(const vector<vector<char>>& board, const vector<int>& click, const vector<vector<char>>& expected) {
        auto boardCpy = board;
        auto clickCpy = click;
        EXPECT_EQ(Solution().updateBoard(boardCpy, clickCpy), expected);
    }
TEST_END

MYTEST_F(529, Example) {
    test(
        { {'E', 'E', 'E', 'E', 'E'},
          {'E', 'E', 'M', 'E', 'E'},
          {'E', 'E', 'E', 'E', 'E'},
          {'E', 'E', 'E', 'E', 'E'} },
        { 3, 0 },
        { {'B', '1', 'E', '1', 'B'},
          {'B', '1', 'M', '1', 'B'},
          {'B', '1', '1', '1', 'B'},
          {'B', 'B', 'B', 'B', 'B'} }
    );
}

MYTEST_F(529, Case2) {
    test(
        { {'B', '1', 'E', '1', 'B'},
          {'B', '1', 'M', '1', 'B'},
          {'B', '1', '1', '1', 'B'},
          {'B', 'B', 'B', 'B', 'B'} },
        { 1, 2 },
        { {'B', '1', 'E', '1', 'B'},
          {'B', '1', 'X', '1', 'B'},
          {'B', '1', '1', '1', 'B'},
          {'B', 'B', 'B', 'B', 'B'} }
    );
}


