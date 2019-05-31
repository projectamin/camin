set ( SRC_FILES src/amin.cpp)

add_library(amin SHARED ${SRC_FILES})
target_link_libraries(amin)
set_target_properties(amin PROPERTIES VERSION ${CAMIN_VERSION_STRING} SOVERSION ${CAMIN_VERSION_MAJOR})
install(TARGETS amin DESTINATION lib)