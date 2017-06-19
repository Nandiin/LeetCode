//
// Created by Nandiin Borjigin on 17/04/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(37)
        void solveSudoku(vector<vector<char>> &board) {
            initiate(board);
            solve(0);
            board = this->board;
        }

    private:
        vector<vector<char>> board;
        vector<vector<char>> rows;
        vector<vector<char>> columns;
        vector<vector<char>> sections;
        int solved;

        void initiate(vector<vector<char>> &board) {
            rows.resize(9, vector<char>());
            columns.resize(9, vector<char>());
            sections.resize(9, vector<char>());
            solved = 0;

            for (auto i = 0; i < 9; ++i) {
                for (auto j = 0; j < 9; ++j) {
                    const auto c = board[i][j];
                    if ('.' == c) continue;
                    const auto secNo = i / 3 * 3 + j / 3;
                    const auto cellNo = i % 3 * 3 + j % 3;
                    rows[i].push_back(c);
                    columns[j].push_back(c);
                    sections[secNo].push_back(c);
                    ++ solved;
                }
            }
            this->board = board;
        }

        void solve(int pos) {

            if (pos > 80) return;

            const auto row = pos / 9;
            const auto col = pos % 9;
            const auto secNo = row / 3 * 3 + col / 3;
            const auto cellNo = row % 3 * 3 + col % 3;

            if (fixed(row, col)) solve(pos + 1);
            else {
                for (char value = '1'; value <= '9'; ++value) {
                    if (find(rows[row], value)) continue;
                    if (find(columns[col], value)) continue;
                    if (find(sections[secNo], value)) continue;
                    rows[row].push_back(value);
                    columns[col].push_back(value);
                    sections[secNo].push_back(value);
                    board[row][col] = value;
                    ++ solved;
                    solve(pos + 1);
                    if (solved == 81) return;
                    rows[row].pop_back();
                    columns[col].pop_back();
                    sections[secNo].pop_back();
                    board[row][col] = '.';
                    -- solved;
                }
            }
        }

        bool fixed(int row, int col) {
            return board[row][col] != '.';
        }

        bool find(vector<char> cells, char target) {
            for (auto cell : cells) {
                if (cell == target) {
                    return true;
                }
            }
            return false;
        }
SOLUTION_END

TEST_BEGIN(37)
    void test(char input[][10], char expected[][10]) {
        vector<vector<char>> inputVec;
        vector<vector<char>> expectedVec;

        for (auto i = 0; i < 9; ++i) {
            inputVec.push_back(vector<char>(input[i], input[i] + 9));
            expectedVec.push_back(vector<char>(expected[i], expected[i] + 9));
        }

        Solution().solveSudoku(inputVec);

        EXPECT_EQ(inputVec, expectedVec);
    }
TEST_END


MYTEST_F(37, Case1) {
char input[9][10] = {
        "..9748...",
        "7........",
        ".2.1.9...",
        "..7...24.",
        ".64.1.59.",
        ".98...3..",
        "...8.3.2.",
        "........6",
        "...2759.."
};

char expected[9][10] = {
        "519748632",
        "783652419",
        "426139875",
        "357986241",
        "264317598",
        "198524367",
        "975863124",
        "832491756",
        "641275983"
};

test(input, expected);
}

MYTEST_F(37, Case2) {
char input[9][10] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
};

char expected[9][10] = {
        "534678912",
        "672195348",
        "198342567",
        "859761423",
        "426853791",
        "713924856",
        "961537284",
        "287419635",
        "345286179"
};
test(input, expected);
}
