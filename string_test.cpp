
#include <string>
#include <sstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iostream>

using namespace std;

void splitByDelim(const string& str, char delim, vector<string>& outStrs) {
    size_t prev_pos = 0;
    size_t pos = str.find(delim);
    while (pos != string::npos) {
        string token = str.substr(prev_pos, pos - prev_pos);
        outStrs.emplace_back(token);
        prev_pos = pos + 1;
        pos = str.find(delim, prev_pos);
    }
    if (prev_pos < str.size()) {
        string token = str.substr(prev_pos);
        outStrs.emplace_back(token);
    }

    cout << "token numbers: " << outStrs.size() << endl;
    for (auto& str : outStrs) {
        cout << " " << str;
    }
    cout << endl;
}

void splitBySpace(const string& str, vector<string>& outStrs) {
    outStrs.clear();
    string buffer;
    stringstream ss(str);
    while (ss >> buffer) {
        outStrs.emplace_back(buffer);
    }

    cout << "token numbers: " << outStrs.size() << endl;
    for (auto& str : outStrs) {
        cout << " " << str;
    }
    cout << endl;
}

void testSplitString() {
    string str("aa  bb  cc,dd  ");
    vector<string> outStrs;
    splitBySpace(str, outStrs);

    string str2("aa,,bb,cc,dd");
    vector<string> outStrs2;
    splitByDelim(str2, ',', outStrs2);

    vector<string> outStrs3;
    boost::split(outStrs3, "string to split", boost::is_any_of("\t "));
    cout << "outStrs3 token numbers: " << outStrs3.size() << endl;
    for (auto& str : outStrs3) {
        cout << str << endl;
    }
}

// 字符串拼接效率比较，https://www.cnblogs.com/james6176/p/3222671.html
// 临时对象问题：https://blog.csdn.net/xiaobaismiley/article/details/25962483
void stringTest1() {

    std::string str;
    std::string str2 = "Writing ";
    std::string str3 = "print 10 and then 5 more";

    // used in the same order as described above:
    str.append(str2);                       // "Writing "
    str.append(str3,6,3);                   // "10 "
    str.append("dots are cool",5);          // "dots "
    str.append("here: ");                   // "here: "
    str.append(10u,'.');                    // ".........."
    str.append(str3.begin()+8,str3.end());  // " and then 5 more"
    str.append<int>(5,0x2E);                // "....."

    cout << "str: " << str << endl;
}

void stringTest2() {
    std::string base="this is a test string.";
    std::string str2="n example";
    std::string str3="sample phrase";
    std::string str4="useful.";

    // replace signatures used in the same order as described above:

    // Using positions:                 0123456789*123456789*12345
    std::string str=base;           // "this is a test string."
    str.replace(9,5,str2);          // "this is an example string." (1)
    str.replace(19,6,str3,7,6);     // "this is an example phrase." (2)
    str.replace(8,10,"just a");     // "this is just a phrase."     (3)
    str.replace(8,6,"a shorty",7);  // "this is a short phrase."    (4)
    str.replace(22,1,3,'!');        // "this is a short phrase!!!"  (5)
    std::cout << str << '\n';

    // Using iterators:                                               0123456789*123456789*
    str.replace(str.begin(),str.end()-3,str3);                    // "sample phrase!!!"      (1)
    str.replace(str.begin(),str.begin()+6,"replace");             // "replace phrase!!!"     (3)
    str.replace(str.begin()+8,str.begin()+14,"is coolness",7);    // "replace is cool!!!"    (4)
    str.replace(str.begin()+12,str.end()-4,4,'o');                // "replace is cooool!!!"  (5)
    str.replace(str.begin()+11,str.end(),str4.begin(),str4.end());// "replace is useful."    (6)
    std::cout << str << '\n';
}

int main() {
    //testSplitString();
    //stringTest1();
    stringTest2();

    return 0;
}


