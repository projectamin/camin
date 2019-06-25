set ( SRC_FILES src/amin.cpp src/xml/sax/xml_base.cpp src/xml/sax/xml_base.h src/amin/elt.cpp src/amin/elt.h src/amin/machine/machine_spec.cpp src/amin/machine/machine_spec.h src/amin/machine/spec/document.cpp src/amin/machine/spec/document.h src/amin/machine/spec/filter.cpp src/amin/machine/spec/filter.h)

add_library(amin SHARED ${SRC_FILES})

link_directories(
        ${LIBXML2_LIBRARY_DIRS}
)

include_directories(
        ${LIBXML2_INCLUDE_DIRS}
)

include_directories(amin PUBLIC ${LIBXML2_INCLUDE_DIRS})
target_link_libraries(amin ${LIBXML2_LIBRARIES})
set_target_properties(amin PROPERTIES VERSION ${CAMIN_VERSION_STRING} SOVERSION ${CAMIN_VERSION_MAJOR})
install(TARGETS amin DESTINATION lib)