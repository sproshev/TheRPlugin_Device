#ifndef COMMON_H
#define COMMON_H

#include <boost/current_function.hpp>
#include <iostream>

#ifndef NDEBUG
#define DEVICE_TRACE do { std::cerr << BOOST_CURRENT_FUNCTION << std::endl; } while(0)
#else
#define DEVICE_TRACE
#endif

#endif // COMMON_H
