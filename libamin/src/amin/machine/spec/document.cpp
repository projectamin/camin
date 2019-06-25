//
// Created by dale on 25/06/19.
//

#include <iostream>
#include "document.h"

void Amin::Machine::Spec::Document::on_start_document() {
    this->filters.clear();
    std::cout << "DOCUMENT ON START" << std::endl;
}

void Amin::Machine::Spec::Document::on_start_element(const Glib::ustring &name,
                                                     const xmlpp::SaxParser::AttributeList &properties) {

    std::map<ustring, ustring> attributes = get_attribute_map(properties);

    if(name == "filter") {
        std::cout << "We have a filter." << std::endl;
        this->currentFilter = Filter();
        this->currentFilter.name = attributes.at("name");

        std::cout << "Filter Name: " << this->currentFilter.name << std::endl;
    }

    if(name == "machine") {
        std::cout << "We have a machine." << std::endl;
    }

    ustring prefix = get_prefix(name);
    // ustring localname = get_localname(name);
}
