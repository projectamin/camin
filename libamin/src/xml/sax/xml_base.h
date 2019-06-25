//
// Created by swishy on 6/1/19.
//

#ifndef CAMIN_XML_BASE_H
#define CAMIN_XML_BASE_H
#include <libxml++/libxml++.h>

namespace Xml {
    namespace Sax {
        class Base : public xmlpp::SaxParser {
        public:
            Xml::Sax::Base *handler;
            explicit Base(Xml::Sax::Base *handler);
            //overrides:
            void on_start_document() override;
            void on_end_document() override;
            void on_start_element(const Glib::ustring& name,
                                  const AttributeList& properties) override;
            void on_end_element(const Glib::ustring& name) override;
            void on_characters(const Glib::ustring& characters) override;
            void on_comment(const Glib::ustring& text) override;
            void on_warning(const Glib::ustring& text) override;
            void on_error(const Glib::ustring& text) override;
            void on_fatal_error(const Glib::ustring& text) override;

            Base();
        };
    }
}


#endif //CAMIN_XML_BASE_H
