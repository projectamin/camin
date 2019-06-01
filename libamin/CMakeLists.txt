set ( SRC_FILES src/amin.cpp src/xml/xml_base.cpp src/xml/xml_base.h)

add_library(amin SHARED ${SRC_FILES})

link_directories(
        ${LIBXML2_LIBRARY_DIRS}
)

include_directories(
        ${LIBXML2_INCLUDE_DIRS}
)

include_directories(amin PUBLIC ${LIBXML2_INCLUDE_DIRS})
link_libraries(amin ${LIBXML2_LIBRARIES})
set_target_properties(amin PROPERTIES VERSION ${CAMIN_VERSION_STRING} SOVERSION ${CAMIN_VERSION_MAJOR})
install(TARGETS amin DESTINATION lib)