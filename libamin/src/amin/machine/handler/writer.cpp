//
// Created by Dale Anderson on 2019-07-28.
//

#include "writer.h"

void Amin::Machine::Handler::Writer::on_start_element(const Glib::ustring &name,
                                                      const xmlpp::SaxParser::AttributeList &properties) {
    Elt::on_start_element(name, properties);
}
