add_executable(asynchronous_timer
    asynchronous_timer.cpp
)

target_link_libraries(asynchronous_timer
  PRIVATE
    boost::boost
)