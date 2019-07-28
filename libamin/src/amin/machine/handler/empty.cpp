//
// Created by Dale Anderson on 2019-07-28.
//

#include <iostream>
#include "empty.h"

void Amin::Machine::Handler::Empty::on_start_document() {

    std::cout << "start document Empty Handler" << std::endl;
    this->attributes.clear();

}
