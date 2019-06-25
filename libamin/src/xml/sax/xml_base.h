//
// Created by swishy on 6/1/19.
//

#ifndef CAMIN_XML_BASE_H
#define CAMIN_XML_BASE_H
#include <string>
#include <libxml++/libxml++.h>

using Glib::ustring;

namespace Xml {
    namespace Sax {
        class Base : public xmlpp::SaxParser {
        public:
            Xml::Sax::Base *handler;
            explicit Base(Xml::Sax::Base *handler);
            //overrides:
            static ustring get_prefix(const ustring &name);
            static ustring get_localname(const ustring &name);
            static std::map<ustring, ustring> get_attribute_map(const AttributeList &attributes);
            void on_start_document() override;
            void on_end_document() override;
            void on_start_element(const ustring& name,
                                  const AttributeList& properties) override;
            void on_end_element(const ustring& name) override;
            void on_characters(const ustring& characters) override;
            void on_comment(const ustring& text) override;
            void on_warning(const ustring& text) override;
            void on_error(const ustring& text) override;
            void on_fatal_error(const ustring& text) override;

            Base();
        };
    }
}


#endif //CAMIN_XML_BASE_H
