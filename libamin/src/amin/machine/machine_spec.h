//
// Created by dale on 25/06/19.
//

#ifndef CAMIN_MACHINE_SPEC_H
#define CAMIN_MACHINE_SPEC_H

#include "../../xml/sax/xml_base.h"
#include "spec/filter.h"

using Xml::Sax::Base;
using Amin::Machine::Spec::Filter;
namespace Amin {
    namespace Machine {
        class MachineSpec : public Base {
        public:
            ustring uri;
            std::map<std::string, Filter*> filters;
            void on_start_document() override;

        };
    }
}



#endif //CAMIN_MACHINE_SPEC_H
