//
// Created by dale on 25/06/19.
//

#include <fcntl.h>
#include <zconf.h>
#include <iostream>
#include "machine_spec.h"
#include "spec/document.h"

using Amin::Machine::Spec::Document;

void Amin::Machine::MachineSpec::on_start_document() {
    // Empty out the filters.
    this->filters.clear();

    // TODO Cater for cross platform.
    const char *home_spec = ustring(getenv("HOME")).append("/.amin/machine_spec.xml").c_str();

    // TODO nasty should use install translation ie BSD's prefix etc.
    ustring global_spec = ustring("/etc/amin/machine_spec.xml");

    // TODO Check URI in spec?
    ustring current_uri;

    // Machine spec path passed in.
    if(this->uri != nullptr) {
        std::cout << "URI PASSED IN!?" << std::endl;
        current_uri = this->uri;
    } else if(access(home_spec, R_OK) == 0) {
        std::cout << "USING HOME DIRECTORY SPEC" << std::endl;
        current_uri = ustring(home_spec);
    } else {
        std::cout << "USING GLOBAL SPEC" << std::endl;
        current_uri = global_spec;
    }

    std::cout << "Current Uri: " << current_uri << std::endl;
    Document documentHandler;

    try {
        documentHandler.parse_file(current_uri);
    }
    catch(const xmlpp::exception& ex)
    {
        std::cerr << "libxml++ exception: " << ex.what() << std::endl;
        std::cerr << "Failed to process machine spec." << std::endl;
    }
}
