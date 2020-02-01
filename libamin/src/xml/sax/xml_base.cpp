//
// Replicating XML::SAX::BASE in Perl land.
//

#include <iostream>
#include <cstring>
#include "xml_base.h"

namespace Xml {
    namespace Sax {

        Base::Base() = default;

        Base::Base(Xml::Sax::Base *handler) {
            this->handler = handler;
        }

        void Base::on_start_document() {
            //std::cout << "start document" << std::endl;
            if(this->handler != nullptr) {
                this->handler->on_start_document();
            }
            SaxParser::on_start_document();
        }

        void Base::on_end_document() {
            //std::cout << "end document" << std::endl;
            if(this->handler != nullptr) {
                this->handler->on_end_document();
            }
            SaxParser::on_end_document();
        }

        void Base::on_start_element(const Glib::ustring &name, const xmlpp::SaxParser::AttributeList &properties) {
            //std::cout << "start element" << std::endl;
            if(this->handler != nullptr) {
                this->handler->on_start_element(name, properties);
            }
            SaxParser::on_start_element(name, properties);
        }

        void Base::on_end_element(const Glib::ustring &name) {
            //std::cout << "end element" << std::endl;
            if(this->handler != nullptr) {
                this->handler->on_end_element(name);
            }
            SaxParser::on_end_element(name);
        }

        void Base::on_characters(const Glib::ustring &characters) {
            //std::cout << "chars" << std::endl;
            if(this->handler != nullptr) {
                this->handler->on_characters(characters);
            }
            SaxParser::on_characters(characters);
        }

        void Base::on_comment(const Glib::ustring &text) {
            //std::cout << "comment" << std::endl;
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

        ustring Base::get_prefix(const ustring &name) {
            size_type position = name.find(":", size_type(1));
            ustring prefix = name.substr(size_type(0), position);
            //std::cout << "Prefix: " << prefix << std::endl;
            return prefix;
        }

        ustring Base::get_localname(const ustring &name) {
            size_type position = name.find(":", size_type(1));
            if(position == name.length()) {
                return ustring();
            }
            ustring localname = name.substr(position, name.length());
            //std::cout << "LocalName: " << localname << std::endl;
            return localname;
        }

        std::map<ustring, ustring> Base::get_attribute_map(const AttributeList &attributes) {
            std::map<ustring, ustring> attribute_map;
            for(const auto& attribute : attributes) {
                attribute_map.insert({attribute.name.c_str(), attribute.value.c_str()});
            }
            return attribute_map;
        }

    }
}
