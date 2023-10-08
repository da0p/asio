#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>

void
print(
  boost::system::error_code const& e,
  boost::asio::steady_timer* t,
  int* count
)
{
  if(*count < 5) {
    std::cout << *count << "\n";
    ++(*count);
    t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
    t->async_wait(boost::bind(print, boost::asio::placeholders::error, t, count)
    );
  }
}

int
main()
{
  boost::asio::io_context io;
  int count = 0;
  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
  t.async_wait(boost::bind(print, boost::asio::placeholders::error, &t, &count)
  );

  io.run();
}