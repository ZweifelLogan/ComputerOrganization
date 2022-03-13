#ifndef HW4_PERF_H__
#define HW4_PERF_H__

#include "vector.h"

enum ProductType { INNER, INNER6x1, INNER6x6, INNER6x1a };

// Times the given inner product and returns the time in nanoseconds;
long time_product_nanos(vec_ptr u, vec_ptr v, data_t* dest, enum ProductType type);

#endif // HW4_PERF_H__
