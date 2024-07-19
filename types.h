#ifndef _TYPES_H_
#define _TYPES_H_

#ifndef NULL
#define NULL (void *)0
#endif // NULL

typedef signed char        i8;
typedef signed short       i16;
typedef signed int         i32;
typedef signed long long   i64;
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef float              f32;
typedef double             f64;
typedef long double        f128;

typedef struct arr_t {
	void *begin;
	u64 length;
	u64 capacity;
} arr_t;

typedef struct node_t node_t;
struct node_t {
	void *data;
	node_t *prev, *next;
};

typedef struct list_t {
	node_t *begin, *end;
	u64 length;
} list_t;

void *
arena_alloc(arr_t *a, u64 bytes);

#define TYPES_IMPLEMENTATION
#ifdef TYPES_IMPLEMENTATION

void *
arena_alloc(arr_t *a, u64 bytes) {
	if (a != NULL &&  a->begin != NULL) {
		u64 offset = a->length + bytes;

		if (((offset >= a->length) || (offset >= bytes))
		&&  (offset <= a->capacity)) {
			void *res = a->begin + a->length;
			a->length = offset;

			return res;
		}
	}

	return NULL;
}


#endif // TYPES_IMPLEMENTATION

#endif //_TYPES_H_
