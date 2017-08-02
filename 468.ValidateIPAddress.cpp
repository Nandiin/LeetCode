
#include <gtest/gtest.h>

#include <utility>
#include "header.h"

SOLUTION_BEGIN(468)
        string validIPAddress(string IP) {
            return isIPv4(IP) ? "IPv4" : isIPv6(IP) ? "IPv6" : "Neither";
        }
    private:
        class Scanner {
        public:
            explicit Scanner(string str) : str(std::move(str)) {}
            inline bool isFinished() const { return pos == str.size(); }
            string scan(string candidates, bool greedy = true) {
                auto start = pos;
                while (std::find(candidates.begin(), candidates.end(), str[pos]) != candidates.end()) {
                    pos++;
                    if (!greedy) break;
                }
                return str.substr(start, pos - start);
            }
            static const string range(char begin, char end) {
                string ret;
                for (auto c = begin; c <= end; ++c) ret.push_back(c);
                return ret;
            }
        private:
            string str;
            size_t pos = 0;
        };
        const string digits = Scanner::range('0', '9');
        const string hexLetters = digits + Scanner::range('a', 'f') + Scanner::range('A', 'F');

        bool match(const string& str, const string& candidates, int count, const string& separator, bool(*predicate)(const string&)) {
            auto scanner = Scanner(str);
            for (auto i = 0; i < count; ++i) {
                auto numStr = scanner.scan(candidates);
                if (!predicate(numStr)) return false;
                if (i != count - 1) {
                    if (scanner.scan(separator, false).empty()) return false;
                }
            }
            return scanner.isFinished();
        };
        bool isIPv4(const string& ip) {
            return match(ip, digits, 4, ".", [](const string& str) -> bool {
                if (str.empty() || (str.length() > 1 && str[0] == '0')) return false;
                try {
                    if (std::stoi(str) > 255) return false;
                } catch(std::exception& e) {
                    return false;
                }
                return true;
            });
        }
        bool isIPv6(const string &ip) {
            return match(ip, hexLetters, 8, ":", [](const string& str) -> bool {
                if (str.empty() || str.length() > 4) return false;
                try { std::stoi(str, nullptr, 16); } catch (std::exception& e) { return false; }
                return true;
            });
        }
SOLUTION_END

TEST_BEGIN(468)
    void test(const string &input, const string &expected) {
        EXPECT_EQ(Solution().validIPAddress(input), expected);
    }
TEST_END

MYTEST_F(468, Example1) {
    test("172.16.254.1", "IPv4");
}

MYTEST_F(468, Example2) {
    test("2001:0db8:85a3:0:0:8A2E:0370:7334", "IPv6");
}

MYTEST_F(468, Example3) {
    test("256.256.256.256", "Neither");
}

MYTEST_F(468, InvalidIPv4_leadingZero) {
    test("172.16.254.01", "Neither");
}

MYTEST_F(468, InvalidIPv6_succesiveColons) {
    test("2001:db8:85a3:0:0::8a2E:0370:7334", "Neither");
}