// amin.h
#ifndef Amin_H
#define Amin_H
#include <libxml/SAX.h>

namespace Amin {
    class Amin
    {
        xmlSAXHandler saxHandler{};
    public:
        Amin();
        void parse(const std::string *profile);
    private:

    };
}

#endif