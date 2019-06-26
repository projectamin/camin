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
                Filter *current_filter;
                const ustring *current_element;
            public:
                // TODO create class / struct to wrap these and leave filter to do such.
                std::map<std::string, Filter*> filters;
                ustring machine_name;
                ustring generator;
                ustring handler;
                ustring log;
                void on_start_document() override;
                void on_start_element(const Glib::ustring& name,
                                      const AttributeList& properties) override;
                void on_characters(const ustring& characters) override;
                void on_end_element(const ustring& name) override;
                void on_end_document() override;
            };
        }
    }
}



#endif //CAMIN_DOCUMENT_H
