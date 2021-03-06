/* -*- C -*-
 *
 * Copyright 2011 Sandia Corporation. Under the terms of Contract
 * DE-AC04-94AL85000 with Sandia Corporation, the U.S.  Government
 * retains certain rights in this software.
 *
 * Copyright (c) 2017 Intel Corporation. All rights reserved.
 * This software is available to you under the BSD license.
 *
 * This file is part of the Sandia OpenSHMEM software package. For license
 * information, see the LICENSE file in the top level directory of the
 * distribution.
 *
 */

#ifndef TRANSPORT_NONE_H
#define TRANSPORT_NONE_H

#include "shmem_internal.h"

/* Datatypes */
#define SHM_INTERNAL_FLOAT           -1
#define SHM_INTERNAL_DOUBLE          -2
#define SHM_INTERNAL_LONG_DOUBLE     -3
#define SHM_INTERNAL_FLOAT_COMPLEX   -4
#define SHM_INTERNAL_DOUBLE_COMPLEX  -5
#define SHM_INTERNAL_SIGNED_BYTE     -6
#define SHM_INTERNAL_INT8            -7
#define SHM_INTERNAL_INT16           -8
#define SHM_INTERNAL_INT32           -9
#define SHM_INTERNAL_INT64           -10
#define SHM_INTERNAL_SHORT           DTYPE_SHORT
#define SHM_INTERNAL_INT             DTYPE_INT
#define SHM_INTERNAL_LONG            DTYPE_LONG
#define SHM_INTERNAL_LONG_LONG       DTYPE_LONG_LONG
#define SHM_INTERNAL_FORTRAN_INTEGER DTYPE_FORTRAN_INTEGER
#define SHM_INTERNAL_UINT            DTYPE_UNSIGNED_INT
#define SHM_INTERNAL_ULONG           DTYPE_UNSIGNED_LONG
#define SHM_INTERNAL_ULONG_LONG      DTYPE_UNSIGNED_LONG_LONG
#define SHM_INTERNAL_SIZE_T          DTYPE_SIZE_T
#define SHM_INTERNAL_PTRDIFF_T       DTYPE_PTRDIFF_T
#define SHM_INTERNAL_UINT32          -13
#define SHM_INTERNAL_UINT64          -14

/* Operations */
#define SHM_INTERNAL_BAND            -1
#define SHM_INTERNAL_BOR             -2
#define SHM_INTERNAL_BXOR            -3
#define SHM_INTERNAL_MIN             -4
#define SHM_INTERNAL_MAX             -5
#define SHM_INTERNAL_SUM             -6
#define SHM_INTERNAL_PROD            -7

typedef int shm_internal_datatype_t;
typedef int shm_internal_op_t;
typedef int shmem_transport_ct_t;

struct shmem_transport_ctx_t{ int dummy; };

typedef struct shmem_transport_ctx_t shmem_transport_ctx_t;

static inline
int
shmem_transport_init(void)
{
    return 0;
}

static inline
int
shmem_transport_startup(void)
{
    return 0;
}

static inline
int
shmem_transport_fini(void)
{
    return 0;
}

static inline
void
shmem_transport_probe(void)
{
    return;
}

static inline
int
shmem_transport_ctx_create(long options, shmem_transport_ctx_t **ctx)
{
    *ctx = NULL;
    return 0;
}

static inline
void
shmem_transport_ctx_destroy(shmem_transport_ctx_t *ctx)
{
    if (ctx != NULL) {
        RAISE_ERROR_STR("Invalid context handle");
    }
    return;
}

static inline
int
shmem_transport_quiet(shmem_transport_ctx_t* ctx)
{
    return 0;
}

static inline
int
shmem_transport_fence(shmem_transport_ctx_t* ctx)
{
    return 0;
}

static inline
void
shmem_transport_put_small(shmem_transport_ctx_t* ctx, void *target, const void *source, size_t len, int pe)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_put_nb(shmem_transport_ctx_t* ctx, void *target, const void *source, size_t len,
                       int pe, long *completion)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_put_wait(shmem_transport_ctx_t* ctx, long *completion)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_put_nbi(shmem_transport_ctx_t* ctx, void *target, const void *source, size_t len,
                       int pe)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_get(shmem_transport_ctx_t* ctx, void *target, const void *source, size_t len, int pe)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_get_wait(shmem_transport_ctx_t* ctx)
{
    RAISE_ERROR_STR("No path to peer");
}


static inline
void
shmem_transport_swap(shmem_transport_ctx_t* ctx, void *target, const void *source, void *dest,
                     size_t len, int pe, shm_internal_datatype_t datatype)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_cswap(shmem_transport_ctx_t* ctx, void *target, const void *source, void *dest,
                      const void *operand, size_t len, int pe,
                      shm_internal_datatype_t datatype)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_mswap(shmem_transport_ctx_t* ctx, void *target, const void *source, void *dest,
                      const void *mask, size_t len, int pe,
                      shm_internal_datatype_t datatype)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_atomic_small(shmem_transport_ctx_t* ctx, void *target, const void *source, size_t len,
                             int pe, shm_internal_op_t op, shm_internal_datatype_t datatype)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_atomic_nb(shmem_transport_ctx_t* ctx, void *target, const void *source, size_t len,
                          int pe, shm_internal_op_t op, shm_internal_datatype_t datatype,
                          long *completion)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_fetch_atomic(shmem_transport_ctx_t* ctx, void *target, const void *source, void *dest, size_t len,
                             int pe, shm_internal_op_t op, shm_internal_datatype_t datatype)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_atomic_fetch(shmem_transport_ctx_t* ctx, void *target, const void *source, size_t len,
                             int pe, shm_internal_datatype_t datatype)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_atomic_set(shmem_transport_ctx_t* ctx, void *target, const void *source, size_t len,
                             int pe, shm_internal_datatype_t datatype)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
int shmem_transport_atomic_supported(shm_internal_op_t op, shm_internal_datatype_t datatype)
{
    return 0;
}

static inline
void shmem_transport_ct_create(shmem_transport_ct_t **ct_ptr)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void shmem_transport_ct_free(shmem_transport_ct_t **ct_ptr)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
long shmem_transport_ct_get(shmem_transport_ct_t *ct)
{
    RAISE_ERROR_STR("No path to peer");
    return 0;
}

static inline
void shmem_transport_ct_set(shmem_transport_ct_t *ct, long value)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void shmem_transport_ct_wait(shmem_transport_ct_t *ct, long wait_for)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void
shmem_transport_put_ct_nb(shmem_transport_ct_t *ct, void *target, const void
                          *source, size_t len, int pe, long *completion)
{
    RAISE_ERROR_STR("No path to peer");
}

static inline
void shmem_transport_get_ct(shmem_transport_ct_t *ct, void
                            *target, const void *source, size_t len, int pe)
{
    RAISE_ERROR_STR("No path to peer");
}

/**
 * Query the value of the transport's received messages counter.
 */
static inline
uint64_t shmem_transport_received_cntr_get(void)
{
    RAISE_ERROR_STR("No remote peers");
    return 0;
}

/**
 * Wait for the transport's received messages counter to be greater than or
 * equal to the given value.
 *
 * @param ge_val Function returns when received messages >= ge_val
 */
static inline
void shmem_transport_received_cntr_wait(uint64_t ge_val)
{
    RAISE_ERROR_STR("No remote peers");
}

static inline
void shmem_transport_syncmem(void)
{
    return;
}

#endif /* TRANSPORT_NONE_H */
