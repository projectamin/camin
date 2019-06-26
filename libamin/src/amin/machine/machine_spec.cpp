//
// Created by dale on 25/06/19.
//

#include <fcntl.h>
#include <zconf.h>
#include <iostream>
#include <fstream>
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

    // TODO wire this up in base.
    try {
        std::ifstream is(current_uri.c_str());
        if (!is)
            throw xmlpp::exception("Could not open file " + current_uri);

        char buffer[64];
        const size_t buffer_size = sizeof(buffer) / sizeof(char);

        documentHandler.set_substitute_entities(true);

        do
        {
            memset(buffer, 0, buffer_size);
            is.read(buffer, buffer_size-1);
            if(is.gcount())
            {
                // We use Glib::ustring::ustring(InputIterator begin, InputIterator end)
                // instead of Glib::ustring::ustring( const char*, size_type ) because it
                // expects the length of the string in characters, not in bytes.
                Glib::ustring input(buffer, buffer+is.gcount());
                documentHandler.parse_chunk(input);
            }
        }
        while(is);

        documentHandler.finish_chunk_parsing();
        this->filters = documentHandler.filters;
    }
    catch(const xmlpp::exception& ex)
    {
        std::cerr << "libxml++ exception: " << ex.what() << std::endl;
        std::cerr << "Failed to process machine spec." << std::endl;
    }
}
