//
// Created by dale on 25/06/19.
//

#ifndef CAMIN_FILTER_H
#define CAMIN_FILTER_H

#include <glibmm/ustring.h>

using Glib::ustring;

namespace Amin {
    namespace Machine {
        namespace Spec {
            class Filter {
            public:
                ustring prefix;
                ustring localname;
                ustring name;
                ustring element;
                ustring filter_namespace;
                ustring position;
                ustring download;
                ustring version;
            };
        }
    }
}



#endif //CAMIN_FILTER_H
