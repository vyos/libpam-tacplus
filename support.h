/* support.h - support functions for pam_tacplus.c
 *
 * Copyright (C) 2010, Pawel Krawczyk <pawel.krawczyk@hush.com> and
 * Jeroen Nijhof <jeroen@jeroennijhof.nl>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program - see the file COPYING.
 *
 * See `CHANGES' file for revision history.
 */

#ifndef PAM_TACPLUS_SUPPORT_H
#define PAM_TACPLUS_SUPPORT_H

#include "libtac.h"

#include <security/pam_modules.h>
#include <security/pam_ext.h>

#include <tacplus/map_tacplus_user.h>


typedef struct {
    struct addrinfo *addr;
    char *key;
    unsigned not_resp;
} tacplus_server_t;

extern tacplus_server_t tac_srv[TAC_PLUS_MAXSERVERS];
extern int tac_srv_no;

extern char tac_service[64];
extern char tac_protocol[64];
extern char tac_prompt[64];
extern struct addrinfo *tac_src_addr_info;
extern unsigned tac_use_tachome;

int _pam_parse (pam_handle_t *, int, const char **);
unsigned long _resolve_name (char *);
unsigned long _getserveraddr (char *serv);
int tacacs_get_password (pam_handle_t *, int, int, char **);
int converse (pam_handle_t *, int, const struct pam_message *, struct pam_response **);
void _pam_log (int, const char *, ...);
void *_xcalloc (size_t);
void _pam_get_user(pam_handle_t *, char **);
void _pam_get_terminal(pam_handle_t *, char **);
void _pam_get_rhost(pam_handle_t *, char **);
void _reset_saved_user(pam_handle_t *, int);
void update_mapped(pam_handle_t *, char *, unsigned, char *);

#endif  /* PAM_TACPLUS_SUPPORT_H */

