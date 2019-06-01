// amin.h
#ifndef Amin_H
#define Amin_H
#include <libxml/SAX.h>

class Amin
{
    xmlSAXHandler saxHandler;
public:
    Amin();
    void parse(const char *profile);
private:
    void setupSaxHandler();
    static void onStartElement(
            void *ctx,
            const xmlChar *localname,
            const xmlChar *prefix,
            const xmlChar *URI,
            int nb_namespaces,
            const xmlChar **namespaces,
            int nb_attributes,
            int nb_defaulted,
            const xmlChar **attributes
    );
    static void onEndElement(
            void* ctx,
            const xmlChar* localname,
            const xmlChar* prefix,
            const xmlChar* URI
    );
    static void onCharacters(void *ctx, const xmlChar *ch, int len);
};

#endif