add_executable(synchronous_timer
    synchronous_timer.cpp
)

target_link_libraries(synchronous_timer
  PUBLIC
    boost::boost
)