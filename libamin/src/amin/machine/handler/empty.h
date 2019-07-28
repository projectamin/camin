//
// Created by Dale Anderson on 2019-07-28.
//

#ifndef CAMIN_EMPTY_H
#define CAMIN_EMPTY_H

#include "../../elt.h"

namespace Amin {
    namespace Machine {
        namespace Handler {
            class Empty: public Elt {
            private:
                std::map<std::string, std::string> attributes;
            public:
                void on_start_document() override;
            };
        }
    }
}



#endif //CAMIN_EMPTY_H
