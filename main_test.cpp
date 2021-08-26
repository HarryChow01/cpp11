
#include <iostream>
#include <string>
#include <regex>

void test1() {
    std::string str1 = "ctr0|ctr1|ctr2|ctr3|ctr4|ctr5|ctr6|ctr7|ctr8|ctr9";
    const std::regex pieces_regex("ctr([0-9]+).*");
    std::smatch pieces_match;
    if (std::regex_match(str1, pieces_match, pieces_regex)) {
        int aa;
        for (size_t i = 0; i < pieces_match.size(); ++i) {
            std::ssub_match sub_match = pieces_match[i];
            std::string piece = sub_match.str();
            std::cout << "  submatch " << i << ": " << piece << '\n';
        }
    }

}
void test2() {
    const std::regex pieces_regex("([a-z]+)\\.([a-z]+)");
    std::smatch pieces_match;
    std::string str1 = "abc.efg";
    if (std::regex_match(str1, pieces_match, pieces_regex)) {
        for (size_t i = 0; i < pieces_match.size(); ++i) {
            std::ssub_match sub_match = pieces_match[i];
            std::string piece = sub_match.str();
            std::cout << "  submatch " << i << ": " << piece << '\n';
        }
    }
}
int main() {
    //test_regex_search2();
    test1();

}



