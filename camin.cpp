#include <iostream>
#include <getopt.h>
#include "libamin/src/amin.h"

void parseStdIn(std::string *profile) {
    Amin::Amin amin;
    amin.parse(profile);
}

int main(int argc, char **argv) {

    std::cout << "Welcome to Amin version 1.0" << std::endl;
    std::cout << "I am working with this and jamming to Primus(tm)..." << std::endl;

    std::string uri;
    // TODO This is ass needs to pass fd to parser.
    std::string profile;

    int c ;
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
                while (std::getline(std::cin, profile)) {
                    std::cout << profile;
                }
                parseStdIn(&profile);
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
