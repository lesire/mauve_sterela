
# Use LTTng
option(USE_LTTNG "Use LTTng traces" "OFF" )
if( USE_LTTNG )
  add_definitions( -DUSE_LTTNG )
endif()
if( TARGET sterela-codels )
  file( GLOB TRACING_FILES *.cpp )
  add_library( sterela-lttng SHARED ${TRACING_FILES} )
  target_link_libraries( sterela-lttng sterela-codels )
endif()
