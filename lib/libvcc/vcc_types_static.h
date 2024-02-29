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

/* We don't want this to appear in the docs */

const struct type INSTANCE[1] = {{
	.magic =		TYPE_MAGIC,
	.name =			"INSTANCE",
	.global_pfx =		"vo",
}};

vcc_type_t
VCC_Type(const char *p)
{

#define VCC_TYPE(UC, lc)	if (!strcmp(p, #UC)) return (UC);
#include "vcc_types.h"
	return (NULL);
}

static void
vcc_type_init(struct vcc *tl, vcc_type_t type)
{
	const struct vcc_method *vm;
	struct symbol *sym;
	struct vsb *buf;

	/* NB: Don't bother even creating a type symbol if there are no
	 * methods attached to it.
	 */
	if (type->methods == NULL)
		return;

	buf = VSB_new_auto();
	AN(buf);
	AN(VCC_MkSym(tl, type->name, SYM_TYPE, SYM_NONE, VCL_LOW, VCL_HIGH));

	for (vm = type->methods; vm->type != NULL; vm++) {
		VSB_printf(buf, "%s.%s", type->name, vm->name);
		AZ(VSB_finish(buf));
		sym = VCC_MkSym(tl, VSB_data(buf), SYM_TYPE, SYM_METHOD,
		    VCL_LOW, VCL_HIGH);
		VSB_clear(buf);
		if (tl->err)
			break;
		AN(sym);
		sym->type = vm->type;
		sym->eval = vcc_Eval_TypeMethod;
		sym->eval_priv = vm;
	}

	VSB_destroy(&buf);
}

const char *
VCC_Type_EvalMethod(struct vcc *tl, const struct symbol *sym)
{
	const struct vcc_method *vm;

	AN(sym);
	AN(sym->kind == SYM_METHOD);
	CAST_OBJ_NOTNULL(vm, sym->eval_priv, VCC_METHOD_MAGIC);

	vcc_NextToken(tl);
	if (vm->func) {
		Expect(tl, '(');
		if (tl->err)
			return (NULL);
		vcc_NextToken(tl);
		Expect(tl, ')');
		if (tl->err)
			return (NULL);
		vcc_NextToken(tl);
	}

	return (vm->impl);
}

void
vcc_Type_Init(struct vcc *tl)
{

#define VCC_TYPE(UC, lc)	vcc_type_init(tl, UC);
#include "vcc_types.h"
}
