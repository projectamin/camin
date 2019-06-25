//
// Created by dale on 25/06/19.
//

#ifndef CAMIN_DOCUMENT_H
#define CAMIN_DOCUMENT_H

#include "../../../xml/sax/xml_base.h"
#include "filter.h"

using Glib::ustring;
using Xml::Sax::Base;
using Amin::Machine::Spec::Filter;

namespace Amin {
    namespace Machine {
        namespace Spec {
            class Document: public Base {
            public:
                std::map<std::string, Filter> filters;
                Filter currentFilter;
                ustring machine_name;
                ustring generator;
                ustring handler;
                ustring log;
                void on_start_document() override;
                void on_start_element(const Glib::ustring& name,
                                      const AttributeList& properties) override;
            };
        }
    }
}



#endif //CAMIN_DOCUMENT_H
