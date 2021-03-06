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

#ifndef SHMEM_ENV_H
#define SHMEM_ENV_H

#include <stdbool.h>
#include <stddef.h>
#include "config.h"

typedef long   shmem_internal_env_long;
typedef size_t shmem_internal_env_size;
typedef bool   shmem_internal_env_bool;
typedef char*  shmem_internal_env_string;

#define SHPRI_long "ld"
#define SHPRI_size "zd"
#define SHPRI_bool "d"
#define SHPRI_string "s"

enum shmem_internal_env_categories {
    SHMEM_INTERNAL_ENV_CAT_OPENSHMEM, SHMEM_INTERNAL_ENV_CAT_COLLECTIVES,
    SHMEM_INTERNAL_ENV_CAT_TRANSPORT, SHMEM_INTERNAL_ENV_CAT_INTRANODE,
    SHMEM_INTERNAL_ENV_CAT_OTHER
};


struct shmem_internal_params_s {
#define SHMEM_INTERNAL_ENV_DEF(NAME, KIND, DEFAULT, CATEGORY, SHORT_DESC) \
  shmem_internal_env_##KIND NAME;
#include "shmem_env_defs.h"
#undef SHMEM_INTERNAL_ENV_DEF

#define SHMEM_INTERNAL_ENV_DEF(NAME, KIND, DEFAULT, CATEGORY, SHORT_DESC) \
  bool NAME##_provided;
#include "shmem_env_defs.h"
#undef SHMEM_INTERNAL_ENV_DEF
};


extern struct shmem_internal_params_s shmem_internal_params;

void shmem_internal_parse_env(void);
void shmem_internal_print_env(void);

#endif /* SHMEM_ENV_H */
