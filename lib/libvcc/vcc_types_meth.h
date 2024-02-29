/*-
 * Copyright (c) 2006 Verdens Gang AS
 * Copyright (c) 2006-2024 Varnish Software AS
 * All rights reserved.
 *
 * Author: Walid BOUDEBOUDA <walid.boudebouda@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */


struct vcc_method {
	unsigned		magic;
#define VCC_METHOD_MAGIC	0x594108cd
	vcc_type_t		type;
	const char		*name;
	const char		*impl;
	int			func;
};

static const struct vcc_method backend_method_resolve =
	{ VCC_METHOD_MAGIC, BACKEND, "resolve",
	    "VRT_DirectorResolve(ctx, \v1)", 1 };

#define VRTSTVVAR(nm, vtype, ctype, dval) \
static const struct vcc_method stevedore_method_##nm = \
	{ VCC_METHOD_MAGIC, vtype, #nm, "VRT_stevedore_" #nm "(\v1)", 0};
#include "tbl/vrt_stv_var.h"

static const struct vcc_method strings_method_upper =
	{ VCC_METHOD_MAGIC, STRING, "upper",
	    "VRT_UpperLowerStrands(ctx, \vT, 1)", 1 };
static const struct vcc_method strings_method_lower =
	{ VCC_METHOD_MAGIC, STRING, "lower",
	    "VRT_UpperLowerStrands(ctx, \vT, 0)", 1 };

static const struct vcc_method vcc_method_null = { VCC_METHOD_MAGIC, NULL };
