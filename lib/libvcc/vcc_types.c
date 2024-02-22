/*-
 * Copyright (c) 2006 Verdens Gang AS
 * Copyright (c) 2006-2011 Varnish Software AS
 * All rights reserved.
 *
 * Author: Poul-Henning Kamp <phk@phk.freebsd.dk>
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

#include "config.h"

#include <string.h>

#include "vcc_compile.h"

/*
 * A type attribute is information already existing, requiring no processing
 * or resource usage.
 *
 * A type method is a call and may do significant processing, change things,
 * eat workspace etc.
 *
 * XXX: type methods might move in a more comprehensive direction.
 */

#include "vcc_types_meth.h"

const struct type ACL[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"ACL",
	.global_pfx =		"vrt_acl",
	.tostring =		"((\v1)->name)",
}};

const struct type BACKEND[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"BACKEND",
	.methods =		backend_methods,
	.global_pfx =		"vgc_backend",
	.tostring =		"VRT_BACKEND_string(\v1)",
}};

const struct type BLOB[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"BLOB",
	.bodyform =		1,
	.tostring =		"VRT_BLOB_string(ctx, \v1)",
}};

const struct type BODY[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"BODY",
	.noindent =		1,
}};

const struct type BOOL[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"BOOL",
	.tostring =		"VRT_BOOL_string(\v1)",
}};

const struct type BYTES[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"BYTES",
	.tostring =		"VRT_INT_string(ctx, \v1)",
	.multype =		REAL,	// XXX: wrong
}};

const struct type DURATION[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"DURATION",
	.tostring =		"VRT_REAL_string(ctx, \v1)", // XXX 's' suff?
	.multype =		REAL,
}};

const struct type ENUM[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"ENUM",
	.tostring =		"",
}};

const struct type HEADER[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"HEADER",
	.tostring =		"VRT_GetHdr(ctx, \v1)",
}};

const struct type HTTP[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"HTTP",
}};

const struct type INSTANCE[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"INSTANCE",
	.global_pfx =		"vo",
}};

const struct type INT[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"INT",
	.multype =		INT,
	.tostring =		"VRT_INT_string(ctx, \v1)",
}};

const struct type IP[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"IP",
	.tostring =		"VRT_IP_string(ctx, \v1)",
}};

const struct type PROBE[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"PROBE",
	.global_pfx =		"vgc_probe",
}};

const struct type REAL[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"REAL",
	.tostring =		"VRT_REAL_string(ctx, \v1)",
	.multype =		REAL,
}};

const struct type REGEX[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"REGEX",
}};

const struct type STEVEDORE[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"STEVEDORE",
	.methods =		stevedore_methods,
	.tostring =		"VRT_STEVEDORE_string(\v1)",
}};

const struct type STRING[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"STRING",
	.stringform =		1,
}};

const struct type STRANDS[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"STRANDS",
	.stringform =		1,
	.tostring =		"VRT_STRANDS_string(ctx,\v+\n\v1\v-\n)",
}};

const struct type STRINGS[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"STRINGS",
	.methods =		strings_methods,
	.bodyform =		1,
	.tostring =		"",
}};

const struct type SUB[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"SUB",
	.global_pfx =		"VGC_function",
}};

const struct type TIME[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"TIME",
	.tostring =		"VRT_TIME_string(ctx, \v1)",
}};

const struct type VCL[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"VCL",
}};

const struct type VOID[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"VOID",
}};

#include "vcc_types_static.h"
