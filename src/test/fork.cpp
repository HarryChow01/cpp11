#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    fork();
    fork() && fork() || fork();
    fork();
    printf("+++++++\n");

    return 0;
}
