#include <iostream>
#include "amin.h"

Amin::Amin() {
    std::cout << "Constructor called!" << std::endl;
    this->setupSaxHandler();
}

void Amin::parse(const char *profile) {
    std::cout << profile << std::endl;
}

void Amin::setupSaxHandler() {
    memset(&saxHandler, 0, sizeof(xmlSAXHandler));

    saxHandler.initialized = XML_SAX2_MAGIC;
    saxHandler.startElementNs = onStartElement;
    saxHandler.endElementNs = onEndElement;
    saxHandler.characters = onCharacters;
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
