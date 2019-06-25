//
// Created by dale on 25/06/19.
//

#ifndef CAMIN_ELT_H
#define CAMIN_ELT_H
#include <libxml++/libxml++.h>
#include "../xml/sax/xml_base.h"
using Glib::ustring;
using Xml::Sax::Base;
namespace Amin {
    class Elt : public Base {
        ustring dir;
        ustring target;
        ustring flag[1];
        ustring source[1];
        ustring param[1];
        ustring command;
        ustring command_name;
        xmlpp::SaxParser::AttributeList attributes;
        ustring environment_variables[1];
        ustring element;
    public:
        void on_start_element(const Glib::ustring& name,
                              const xmlpp::SaxParser::AttributeList& properties) override;
    };
}



#endif //CAMIN_ELT_H
