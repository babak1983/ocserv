/*
 *  PCL by Davide Libenzi (Portable Coroutine Library)
 *  Copyright (C) 2003..2010  Davide Libenzi
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Davide Libenzi <davidel@xmailserver.org>
 *
 */

#if !defined(PCL_H)
#define PCL_H

#ifdef __cplusplus
#define PCLXC extern "C"
#else
#define PCLXC
#endif

typedef void *coroutine_t;

PCLXC int co_thread_init(void);
PCLXC void co_thread_cleanup(void);

PCLXC coroutine_t co_create(void (*func)(void *), void *data, void *stack,
			    int size);
PCLXC void co_delete(coroutine_t coro);
PCLXC void co_call(coroutine_t coro);
PCLXC void co_resume(void);
PCLXC void co_exit_to(coroutine_t coro);
PCLXC void co_exit(void);
PCLXC coroutine_t co_current(void);
PCLXC void *co_get_data(coroutine_t coro);
PCLXC void *co_set_data(coroutine_t coro, void *data);

#endif

