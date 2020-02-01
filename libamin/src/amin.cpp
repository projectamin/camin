#include <iostream>
#include <cstring>
#include "amin.h"
#include "amin/elt.h"
#include "amin/machine/machine_spec.h"
#include "amin/machine/spec/document.h"
#include <libxml++/libxml++.h>

using xmlpp::SaxParser;
using Glib::ustring;
using Amin::Elt;
using Amin::Machine::MachineSpec;
namespace Amin {
    Amin::Amin() {
        std::cout << "Constructor called!" << std::endl;

    }

    void Amin::parse(std::istream &profile) {

        Machine::Spec::Document documentHandler;


        // Wire up parser - Just testing atm.
        try {
            MachineSpec machine_spec_handler;
            machine_spec_handler.handler = &documentHandler;
            Elt elt;
            elt.handler = &machine_spec_handler;
            elt.parse_stream(profile);
        }
        catch(const xmlpp::exception& ex)
        {
            std::cerr << "libxml++ exception: " << ex.what() << std::endl;
        }

    }
}



