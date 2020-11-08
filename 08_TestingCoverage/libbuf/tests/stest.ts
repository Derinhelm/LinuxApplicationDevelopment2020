#include "buf.h"

#suite Fixed
#test capacity_init
	float *a = 0;
	ck_assert_int_eq(buf_capacity(a), 0);
