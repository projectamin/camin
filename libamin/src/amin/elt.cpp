//
// Created by dale on 25/06/19.
//

#include <iostream>
#include <libxml++/libxml++.h>
#include "elt.h"
#include "../xml/sax/xml_base.h"
using Xml::Sax::Base;
namespace Amin {
    void Elt::on_start_element(const Glib::ustring &name, const xmlpp::SaxParser::AttributeList &properties) {
        this->attributes = properties;
        std::cout << "Elt start element" << std::endl;
        Base::on_start_element(name, properties);
    }
}
