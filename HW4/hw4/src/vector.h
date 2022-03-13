#ifndef HW4_VECTOR_H__
#define HW4_VECTOR_H__

// This specifies the data type of the vector.
// Note: this _must_ be a numeric type (e.g, float, double, int, etc.)
typedef float data_t;

struct Vector {
  data_t* data;
  long size;
};

typedef struct Vector* vec_ptr;

// Returns a pointer to the start of the vector's elements
data_t* get_vec_start(vec_ptr p);

// Returns the vector's length
long vec_length(vec_ptr p);

// Returns a vector of the given size with random elements.
//
// Note: this function assumes the vector element type data_t
// is a numeric type.
struct Vector random_vec(long size);

// Pretty-prints the vector to stdout
void print_vector(vec_ptr v);

// Reference implementation of the inner product.
void inner(vec_ptr u, vec_ptr v, data_t* dest);

// Problem 5.14
void inner6x1(vec_ptr u, vec_ptr v, data_t* dest);

// Problem 5.15
void inner6x6(vec_ptr u, vec_ptr v, data_t* dest);

// Problem 5.16
void inner6x1a(vec_ptr u, vec_ptr v, data_t* dest);

#endif // HW4_VECTOR_H__
