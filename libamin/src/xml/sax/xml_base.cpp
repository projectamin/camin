//
// Replicating XML::SAX::BASE in Perl land.
//

#include <iostream>
#include <cstring>
#include "xml_base.h"

namespace Xml {
    namespace Sax {

        Base::Base() {

        }

        Base::Base(Xml::Sax::Base *handler) {
            this->handler = handler;
        }

        void Base::on_start_document() {
            std::cout << "start document" << std::endl;
            SaxParser::on_start_document();
        }

        void Base::on_end_document() {
            std::cout << "end document" << std::endl;
            SaxParser::on_end_document();
        }

        void Base::on_start_element(const Glib::ustring &name, const xmlpp::SaxParser::AttributeList &properties) {
            std::cout << "start element" << std::endl;
            SaxParser::on_start_element(name, properties);
        }

        void Base::on_end_element(const Glib::ustring &name) {
            std::cout << "end element" << std::endl;
            SaxParser::on_end_element(name);
        }

        void Base::on_characters(const Glib::ustring &characters) {
            std::cout << "chars" << std::endl;
            SaxParser::on_characters(characters);
        }

        void Base::on_comment(const Glib::ustring &text) {
            std::cout << "comment" << std::endl;
            SaxParser::on_comment(text);
        }

        void Base::on_warning(const Glib::ustring &text) {
            std::cout << "warning" << std::endl;
            SaxParser::on_warning(text);
        }

        void Base::on_error(const Glib::ustring &text) {
            std::cout << "error" << std::endl;
            SaxParser::on_error(text);
        }

        void Base::on_fatal_error(const Glib::ustring &text) {
            std::cout << "fatal error" << std::endl;
            SaxParser::on_fatal_error(text);
        }

    }
}
