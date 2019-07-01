#include <map>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <boost/algorithm/string/regex.hpp>

#if 0
int main() {
    std::map<std::string, int> test_map;
    test_map["aa"] = 1;
    int b = test_map["bb"];
    std::cout << "b: " << b << std::endl;

}
#endif

#if 0
int main() {
    std::string str = "http://dingyue.nosdn.127.net/acDKfYZqMZYxqzbjX28Vm2TrNdDWDe4mq9mybx6ggrLUi1516118747898.jpeg||http://dingyue.nosdn.127.net/t4YEVvGLY=M1SSH9JzemoOwM1p8xQ74Py0M9GVnHONUof1516118754134.jpeg||http://dingyue.nosdn.127.net/oGBLyxNFiTzoxOP4tC8bobY7J8LvInuxrjLrs3GBhMp8Y1516118764936.jpeg";
    std::vector<std::string> vec_img_url;
    boost::split_regex(vec_img_url, str, boost::regex("||"));
    //boost::split(vec_img_url, str, boost::is_any_of("|"));
    std::cout << "vector size: " << vec_img_url.size() << std::endl;
    for (const auto& url : vec_img_url) {
        std::cout << "url: " << url << std::endl;
    }
}
#endif

void split_by_milti_char(std::vector<std::string>& strVec,
        const std::string& sourceStr, const std::string& subStr) {
    if (subStr.empty()) {
        strVec.emplace_back(sourceStr);
        return;
    }
    std::vector<size_t> posVec;
    size_t pos = sourceStr.find(subStr);
    while(pos != std::string::npos) {
        posVec.emplace_back(pos);
        pos = sourceStr.find(subStr, pos + subStr.size());
    }

    if (posVec.empty()) {
        strVec.emplace_back(sourceStr);
        return;
    }
    size_t lastPos = 0;
    for (size_t pos : posVec) {
        std::string tmpStr = sourceStr.substr(lastPos, pos - lastPos);
        if (!tmpStr.empty()) {
            strVec.emplace_back(tmpStr);
        }
        lastPos = pos + subStr.size();
    }
    std::string tmpStr = sourceStr.substr(lastPos);
    if (!tmpStr.empty()) {
        strVec.emplace_back(tmpStr);
    }
}

int main() {
    //std::string str = "http://dingyue.nosdn.127.net/acDKfYZqMZYxqzbjX28Vm2TrNdDWDe4mq9mybx6ggrLUi1516118747898.jpeg||http://dingyue.nosdn.127.net/t4YEVvGLY=M1SSH9JzemoOwM1p8xQ74Py0M9GVnHONUof1516118754134.jpeg||http://dingyue.nosdn.127.net/oGBLyxNFiTzoxOP4tC8bobY7J8LvInuxrjLrs3GBhMp8Y1516118764936.jpeg";
    //std::string str = "aaa";
    //std::string str = "||";
    //std::string str = "a||";
    std::string str = "||||a||";
    long long b;
    std::cout << "long long size: " << sizeof(long long) << std::endl;
    std::vector<std::string> strVec;
    split_by_milti_char(strVec, str, "||");
    for (const auto& url : strVec) {
        std::cout << "url: " << url << std::endl;
    }
}


