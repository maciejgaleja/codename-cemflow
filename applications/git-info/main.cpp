/* @file          main.cpp                                                    */

#include <git2.h>
#include <iostream>

int main(int argc, char** argv)
{
    git_libgit2_init();
    std::cout << "Hello, world\n";
    git_libgit2_shutdown();
    return 0;
}
