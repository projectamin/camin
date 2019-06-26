//
// Created by dale on 25/06/19.
//

#include <iostream>
#include "document.h"

void Amin::Machine::Spec::Document::on_start_document() {
    this->filters.clear();
}

void Amin::Machine::Spec::Document::on_start_element(const Glib::ustring &name,
                                                     const xmlpp::SaxParser::AttributeList &properties) {

    std::map<ustring, ustring> attributes = get_attribute_map(properties);

    // TODO Currently only wiring up filters.
    if(name == "filter") {
        std::cout << "We have a filter." << std::endl;
        Filter newFilter = Filter();
        newFilter.name = attributes["name"];
        this->current_filter = &newFilter;

        std::cout << "Filter Name: " << this->current_filter->name << std::endl;
    }

    this->current_element = &name;
}

void Amin::Machine::Spec::Document::on_characters(const ustring &characters) {

    if(strcmp(this->current_element->c_str(), "element") == 0) {
        this->current_filter->element = characters;
    }
    if(strcmp(this->current_element->c_str(), "namespace") == 0) {
        this->current_filter->filter_namespace = characters;
    }
    if(strcmp(this->current_element->c_str(), "name") == 0) {
        this->current_filter->name = characters;
    }
    if(strcmp(this->current_element->c_str(), "position") == 0) {
        this->current_filter->position = characters;
    }
    if(strcmp(this->current_element->c_str(), "download") == 0) {
        this->current_filter->download = characters;
    }
    if(strcmp(this->current_element->c_str(), "version") == 0) {
        this->current_filter->version = characters;
    }
}

void Amin::Machine::Spec::Document::on_end_element(const ustring &name) {
    if(name == "filter") {
        this->filters[this->current_filter->name] = this->current_filter;
    }
}

void Amin::Machine::Spec::Document::on_end_document() {
    std::cout << "Filters Count: " << this->filters.size() << std::endl;
}
