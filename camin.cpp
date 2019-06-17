#include <iostream>
#include <getopt.h>
#include "libamin/src/amin.h"

void parseStdIn(std::string profile) {
    Amin amin;
    amin.parse(profile.c_str());
}

int main(int argc, char **argv) {

    std::cout << "Welcome to Amin version 1.0" << std::endl;
    std::cout << "Today brought to you by Learning and Phish(tm) @ Bonnaroo..." << std::endl;

    std::string uri;
    // TODO This is ass needs to pass fd to parser.
    std::string profile;

    int c ;
    while( ( c = getopt (argc, argv, "u:p::h:") ) != -1 )
    {
        switch(c)
        {
            case 'u':
                if(optarg) uri = optarg;
                std::cout << uri << std::endl;
                break;
            case 'p':
                while (std::cin >> profile) {
                    std::cout << profile;
                }
                parseStdIn(profile);
                break;
            case 'h':
                std::cout << "Help is here!" << std::endl;
                break;
            default:
                std::cout << "Unknown option" << std::endl;
                break;
        }
    }



    return 0;
}
