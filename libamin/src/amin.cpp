#include <iostream>
#include <cstring>
#include "amin.h"
#include "amin/elt.h"
#include "amin/machine/machine_spec.h"
#include <libxml++/libxml++.h>

using xmlpp::SaxParser;
using Glib::ustring;
using Amin::Elt;
using Amin::Machine::MachineSpec;
namespace Amin {
    Amin::Amin() {
        std::cout << "Constructor called!" << std::endl;

    }

    void Amin::parse(const std::string *profile) {

        std::cout << profile << std::endl;

        std::string aminXml =
                "<amin:profile xmlns:amin='http://projectamin.org/ns/'>"
                "<amin:command name='mkdir'>"
                "<amin:flag name='m'>0755</amin:flag>"
                "<amin:param name='target'>/tmp/test_ashell</amin:param>"
                "</amin:command></amin:profile>";


        // Wire up parser - Just testing atm.
        try {
            MachineSpec machine_spec_handler;
            Elt elt;
            elt.handler = &machine_spec_handler;
            elt.parse_memory(ustring(aminXml));
        }
        catch(const xmlpp::exception& ex)
        {
            std::cerr << "libxml++ exception: " << ex.what() << std::endl;
        }

    }
}



