
#include "echo.h"

void
Amin::Command::Echo::on_start_element(const Glib::ustring &name, const xmlpp::SaxParser::AttributeList &properties) {
    Elt::on_start_element(name, properties);
}

void Amin::Command::Echo::on_characters(const ustring &characters) {
    Base::on_characters(characters);
}

void Amin::Command::Echo::on_end_element(const ustring &name) {
    Base::on_end_element(name);
}
