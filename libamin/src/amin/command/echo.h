#ifndef CAMIN_EMPTY_H
#define CAMIN_EMPTY_H

#include "../elt.h"

namespace Amin {
    namespace Command {
        class Echo: public Elt {
        private:
            std::map<std::string, std::string> attributes;
        public:
            void on_start_element(const Glib::ustring& name,
                                  const xmlpp::SaxParser::AttributeList& properties) override;
            void on_end_element(const ustring& name) override;
            void on_characters(const ustring& characters) override;
        };
    }
}



#endif //CAMIN_EMPTY_H