//
// Created by dale on 25/06/19.
//

#include <iostream>
#include <libxml++/libxml++.h>
#include <glibmm.h>
#include "elt.h"
#include "../xml/sax/xml_base.h"
using Xml::Sax::Base;
namespace Amin {
    void Elt::on_start_element(const Glib::ustring &name, const xmlpp::SaxParser::AttributeList &properties) {
        this->element = name;
        this->attributes = properties;
        std::cout << "Elt start element : " << this->element << std::endl;
        for(const auto& attr_pair : this->attributes) {
            try {
                std::cout << "Attribute Name : " << attr_pair.name << std::endl;
            }
            catch(const Glib::ConvertError& exception) {

            }

            try {
                std::cout << "Attribute Value : " << attr_pair.value << std::endl;
            }
            catch(const Glib::ConvertError& exception) {

            }
        }
        Base::on_start_element(name, properties);
    }
}
