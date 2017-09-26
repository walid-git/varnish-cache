/*-
 * Copyright (c) 2006 Verdens Gang AS
 * Copyright (c) 2006-2011 Varnish Software AS
 * All rights reserved.
 *
 * Author: Poul-Henning Kamp <phk@phk.freebsd.dk>
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
 * This file contains the heritage passed when mgt forks cache
 */

struct vsmw;
struct suckaddr;
struct listen_sock;
struct transport;
struct VCLS;

struct listen_arg {
	unsigned			magic;
#define LISTEN_ARG_MAGIC		0xbb2fc333
	VTAILQ_ENTRY(listen_arg)	list;
	const char			*endpoint;
	const char			*name;
	VTAILQ_HEAD(,listen_sock)	socks;
	const struct transport		*transport;
};

struct listen_sock {
	unsigned			magic;
#define LISTEN_SOCK_MAGIC		0x999e4b57
	VTAILQ_ENTRY(listen_sock)	list;
	VTAILQ_ENTRY(listen_sock)	arglist;
	int				sock;
	char				*endpoint;
	const char			*name;
	struct suckaddr			*addr;
	const struct transport		*transport;
};

VTAILQ_HEAD(listen_sock_head, listen_sock);

struct heritage {

	/* Two pipe(2)'s for CLI connection between cache and mgt.  */
	int				cli_in;
	int				cli_out;

	/* File descriptor for stdout/stderr */
	int				std_fd;

	int				vsm_fd;

	/* Sockets from which to accept connections */
	struct listen_sock_head		socks;

	/* Hash method */
	const struct hash_slinger	*hash;

	struct params			*param;

	const char			*identity;

	char				*panic_str;
	ssize_t				panic_str_len;

	struct VCLS			*cls;

	const char			*ident;
};

extern struct heritage heritage;

void child_main(void);
