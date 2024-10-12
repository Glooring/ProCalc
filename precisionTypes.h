#ifndef PRECISIONTYPES_H
#define PRECISIONTYPES_H

#include <boost/multiprecision/cpp_dec_float.hpp>

// Define a high-precision floating-point type
typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<15>> double_mp;

#endif // PRECISIONTYPES_H
