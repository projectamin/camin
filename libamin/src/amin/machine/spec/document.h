//
// Created by dale on 25/06/19.
//

#ifndef CAMIN_DOCUMENT_H
#define CAMIN_DOCUMENT_H

#include "../../../xml/sax/xml_base.h"
using Glib::ustring;
using Xml::Sax::Base;

namespace Amin {
    namespace Machine {
        namespace Spec {
            class Document: public Base {
            public:
                ustring name;
                ustring generator;
                ustring handler;
                ustring log;
                void on_start_document() override;
            };
        }
    }
}



#endif //CAMIN_DOCUMENT_H
