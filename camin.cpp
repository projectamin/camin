#include <iostream>
#include <getopt.h>
#include "libamin/src/amin.h"

void parseStdIn(std::istream &profile) {
    Amin::Amin::parse(profile);
}

int main(int argc, char **argv) {

    std::cout << "Welcome to Amin version 1.0" << std::endl;
    std::cout << "I am working with this and jamming to Primus(tm)..." << std::endl;

    std::string uri;
    // TODO This is ass needs to pass fd to parser.
    std::string profile;

    int c ;

    // Please do not change, __MACH__ is hit with GNU Hurd etc and __OSX__ is not always defined.
#ifdef __APPLE__
    while( ( c = getopt (argc, argv, "uph:") ) != -1 )
#else
    while( ( c = getopt (argc, argv, "u:p::h:") ) != -1 )
#endif /* __APPLE__ */
    {
        switch(c)
        {
            case 'u':
                if(optarg) uri = optarg;
                std::cout << uri << std::endl;
                break;
            case 'p':
                parseStdIn(std::cin);
                break;
            case 'h':
                std::cout << "Trying to help!" << std::endl;
                break;
            default:
                std::cout << "Unknown option" << std::endl;
                break;
        }
    }



    return 0;
}
