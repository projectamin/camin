//
// Created by Dale Anderson on 2019-07-28.
//

#ifndef CAMIN_WRITER_H
#define CAMIN_WRITER_H

#include "../../elt.h"

namespace Amin {
    namespace Machine {
        namespace Handler {
            class Writer: public Elt {
            public:
                void on_start_element(const Glib::ustring& name,
                                      const xmlpp::SaxParser::AttributeList& properties) override;
            };
        }
    }
}



#endif //CAMIN_WRITER_H
