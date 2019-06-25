#include <iostream>
#include <cstring>
#include "amin.h"
#include <libxml/parser.h>

Amin::Amin() {
    std::cout << "Constructor called!" << std::endl;
    this->setupSaxHandler();
}

void Amin::parse(const std::string& profile) {

    std::string xmlIn =
            "<test:Plan xmlns:test='http://test.org/schema'>"
            "<test:Case name='test1' emptyAttribute='' test:ns_id='auio'>"
            "</test:Case>"
            "</test:Plan>";

    int result = xmlSAXUserParseMemory( &saxHandler, this, profile.c_str(), int(profile.length()));
    if ( result != 0 )
    {
        printf("Result : %d\n", result);
        printf("Failed to parse document.\n" );
    }

    /*
     * Cleanup function for the XML library.
     */
    xmlCleanupParser();
}

void Amin::setupSaxHandler() {
    memset(&saxHandler, 0, sizeof(xmlSAXHandler));

    saxHandler.initialized = XML_SAX2_MAGIC;
    saxHandler.startElementNs = onStartElement;
    saxHandler.endElementNs = onEndElement;
    saxHandler.characters = onCharacters;
    saxHandler.error = error;
}

void Amin::onStartElement(void *ctx, const xmlChar *localname, const xmlChar *prefix, const xmlChar *URI,
                              int nb_namespaces, const xmlChar **namespaces, int nb_attributes, int nb_defaulted,
                              const xmlChar **attributes) {
    // TODO ctx will be Amin instance.
    std::cout << "onStartElement invoked." << std::endl;
}

void Amin::onCharacters(void *ctx, const xmlChar *ch, int len) {
    std::cout << "onCharacters invoked." << std::endl;
}

void Amin::onEndElement(void *ctx, const xmlChar *localname, const xmlChar *prefix, const xmlChar *URI) {
    std::cout << "onEndElement invoked." << std::endl;
}

void Amin::error( void * ctx,
                              const char * msg,
                              ... ) {
    va_list args;
    va_start(args, msg);
    vprintf( msg, args );
    va_end(args);
}
