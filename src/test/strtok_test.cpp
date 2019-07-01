#include <iostream>
#include <string>
#include <cstring>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    std::string line;
    //getline(std::cin, line);
    //std::cout << "Length of line : " << line.size() << std::endl;

    std::string testStr = "abc";
    for (auto &ch : testStr)
    {
        ch = std::toupper(ch);
        //std::cout << ch << " ";
    }
    std::cout << testStr << std::endl;

    char str2[] = "abc\t123,abc 123";
    char * p = std::strtok(str2, " ,\t");
    while (p!=0)
    {
        std::cout << p << '\n';
        //p = std::strtok(NULL," ,\t");
        p = std::strtok(NULL," ,\t");
    }

    return 0;
}


