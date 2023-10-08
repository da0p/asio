add_executable(limited_counter
    limited_counter.cpp
)

target_link_libraries(limited_counter
  PRIVATE
    boost::boost
)