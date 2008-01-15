/*
 * Copyright (c) 1993-1996, 1998-2005, 2007
 *	Todd C. Miller <Todd.Miller@courtesan.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Sponsored in part by the Defense Advanced Research Projects
 * Agency (DARPA) and Air Force Research Laboratory, Air Force
 * Materiel Command, USAF, under agreement number F39502-99-1-0512.
 *
 * $Sudo$
 */

#ifndef _SUDO_SUDO_H
#define _SUDO_SUDO_H

#include <pathnames.h>
#include <limits.h>
#include "compat.h"
#include "defaults.h"
#include "error.h"
#include "list.h"
#include "logging.h"
#include "sudo_nss.h"

/*
 * Info pertaining to the invoking user.
 */
struct sudo_user {
    struct passwd *pw;
    struct passwd *_runas_pw;
    struct group *_runas_gr;
    struct stat *cmnd_stat;
    char *path;
    char *shell;
    char *tty;
    char *ttypath;
    char *host;
    char *shost;
    char *prompt;
    char *cmnd;
    char *cmnd_args;
    char *cmnd_base;
    char *cmnd_safe;
    char *class_name;
    char *krb5_ccname;
    int   ngroups;
    GETGROUPS_T *groups;
    struct list_member *env_vars;
    char  cwd[PATH_MAX];
};

/*
 * Return values for sudoers_lookup(), also used as arguments for log_auth()
 * Note: cannot use '0' as a value here.
 */
/* XXX - VALIDATE_SUCCESS and VALIDATE_FAILURE instead? */
#define VALIDATE_ERROR          0x001
#define VALIDATE_OK		0x002
#define VALIDATE_NOT_OK		0x004
#define FLAG_CHECK_USER		0x010
#define FLAG_NO_USER		0x020
#define FLAG_NO_HOST		0x040
#define FLAG_NO_CHECK		0x080

/*
 * Pseudo-boolean values
 */
#undef TRUE
#define TRUE                     1
#undef FALSE
#define FALSE                    0

/*
 * find_path()/load_cmnd() return values
 */
#define FOUND                    1
#define NOT_FOUND                0
#define NOT_FOUND_DOT		-1

/*
 * Various modes sudo can be in (based on arguments) in hex
 */
#define MODE_RUN		0x00001
#define MODE_EDIT		0x00002
#define MODE_VALIDATE		0x00004
#define MODE_INVALIDATE		0x00008
#define MODE_KILL		0x00010
#define MODE_VERSION		0x00020
#define MODE_HELP		0x00040
#define MODE_LIST		0x00080
#define MODE_CHECK		0x00100
#define MODE_LISTDEFS		0x00200
#define MODE_BACKGROUND		0x00400
#define MODE_SHELL		0x00800
#define MODE_LOGIN_SHELL	0x01000
#define MODE_IMPLIED_SHELL	0x02000
#define MODE_RESET_HOME		0x04000
#define MODE_PRESERVE_GROUPS	0x08000
#define MODE_PRESERVE_ENV	0x10000

/*
 * Used with set_perms()
 */
#define PERM_ROOT                0x00
#define PERM_USER                0x01
#define PERM_FULL_USER           0x02
#define PERM_SUDOERS             0x03
#define PERM_RUNAS               0x04
#define PERM_FULL_RUNAS          0x05
#define PERM_TIMESTAMP           0x06

/*
 * Shortcuts for sudo_user contents.
 */
#define user_name		(sudo_user.pw->pw_name)
#define user_passwd		(sudo_user.pw->pw_passwd)
#define user_uid		(sudo_user.pw->pw_uid)
#define user_gid		(sudo_user.pw->pw_gid)
#define user_dir		(sudo_user.pw->pw_dir)
#define user_shell		(sudo_user.shell)
#define user_ngroups		(sudo_user.ngroups)
#define user_groups		(sudo_user.groups)
#define user_tty		(sudo_user.tty)
#define user_ttypath		(sudo_user.ttypath)
#define user_cwd		(sudo_user.cwd)
#define user_cmnd		(sudo_user.cmnd)
#define user_args		(sudo_user.cmnd_args)
#define user_base		(sudo_user.cmnd_base)
#define user_stat		(sudo_user.cmnd_stat)
#define user_path		(sudo_user.path)
#define user_prompt		(sudo_user.prompt)
#define user_host		(sudo_user.host)
#define user_shost		(sudo_user.shost)
#define user_ccname		(sudo_user.krb5_ccname)
#define safe_cmnd		(sudo_user.cmnd_safe)
#define login_class		(sudo_user.class_name)
#define runas_pw		(sudo_user._runas_pw)
#define runas_gr		(sudo_user._runas_gr)

/*
 * We used to use the system definition of PASS_MAX or _PASSWD_LEN,
 * but that caused problems with various alternate authentication
 * methods.  So, we just define our own and assume that it is >= the
 * system max.
 */
#define SUDO_PASS_MAX	256

/*
 * Flags for lock_file()
 */
#define SUDO_LOCK	1		/* lock a file */
#define SUDO_TLOCK	2		/* test & lock a file (non-blocking) */
#define SUDO_UNLOCK	4		/* unlock a file */

/*
 * Flags for tgetpass()
 */
#define TGP_ECHO	0x01		/* leave echo on when reading passwd */
#define TGP_STDIN	0x02		/* read from stdin, not /dev/tty */

struct passwd;
struct timespec;
struct timeval;

/*
 * Function prototypes
 */
#define YY_DECL int yylex __P((void))

#ifndef HAVE_CLOSEFROM
void closefrom		__P((int));
#endif
#ifndef HAVE_GETCWD
char *getcwd		__P((char *, size_t size));
#endif
#ifndef HAVE_UTIMES
int utimes		__P((const char *, const struct timeval *));
#endif
#ifdef HAVE_FUTIME
int futimes		__P((int, const struct timeval *));
#endif
#ifndef HAVE_SNPRINTF
int snprintf		__P((char *, size_t, const char *, ...))
			    __printflike(3, 4);
#endif
#ifndef HAVE_VSNPRINTF
int vsnprintf		__P((char *, size_t, const char *, va_list))
			    __printflike(3, 0);
#endif
#ifndef HAVE_ASPRINTF
int asprintf		__P((char **, const char *, ...))
			    __printflike(2, 3);
#endif
#ifndef HAVE_VASPRINTF
int vasprintf		__P((char **, const char *, va_list))
			    __printflike(2, 0);
#endif
#ifndef HAVE_STRCASECMP
int strcasecmp		__P((const char *, const char *));
#endif
#ifndef HAVE_STRLCAT
size_t strlcat		__P((char *, const char *, size_t));
#endif
#ifndef HAVE_STRLCPY
size_t strlcpy		__P((char *, const char *, size_t));
#endif
#ifndef HAVE_MEMRCHR
void *memrchr		__P((const void *, int, size_t));
#endif
#ifndef HAVE_MKSTEMP
int mkstemp		__P((char *));
#endif
char *sudo_goodpath	__P((const char *, struct stat *));
char *tgetpass		__P((const char *, int, int));
int find_path		__P((char *, char **, struct stat *, char *));
void check_user		__P((int));
void verify_user	__P((struct passwd *, char *));
#ifdef HAVE_LDAP
int sudo_ldap_open	__P((struct sudo_nss *));
int sudo_ldap_close	__P((struct sudo_nss *));
int sudo_ldap_setdefs	__P((struct sudo_nss *));
int sudo_ldap_lookup	__P((struct sudo_nss *, int, int));
int sudo_ldap_parse	__P((struct sudo_nss *));
void sudo_ldap_display_privs __P((struct sudo_nss *, struct passwd *));
int sudo_ldap_display_cmnd __P((struct sudo_nss *, struct passwd *));
#endif
#if 1
int sudo_file_open	__P((struct sudo_nss *));
int sudo_file_close	__P((struct sudo_nss *));
int sudo_file_setdefs	__P((struct sudo_nss *));
int sudo_file_lookup	__P((struct sudo_nss *, int, int));
int sudo_file_parse	__P((struct sudo_nss *));
void sudo_file_display_privs __P((struct sudo_nss *, struct passwd *));
int sudo_file_display_cmnd __P((struct sudo_nss *, struct passwd *));
#endif
void set_perms		__P((int));
void remove_timestamp	__P((int));
int check_secureware	__P((char *));
void sia_attempt_auth	__P((void));
void pam_attempt_auth	__P((void));
int yyparse		__P((void));
void pass_warn		__P((FILE *));
void *emalloc		__P((size_t));
void *emalloc2		__P((size_t, size_t));
void *erealloc		__P((void *, size_t));
void *erealloc3		__P((void *, size_t, size_t));
char *estrdup		__P((const char *));
int easprintf		__P((char **, const char *, ...))
			    __printflike(2, 3);
int evasprintf		__P((char **, const char *, va_list))
			    __printflike(2, 0);
void efree		__P((void *));
void dump_defaults	__P((void));
void dump_auth_methods	__P((void));
void init_envtables	__P((void));
void read_env_file	__P((const char *));
int lock_file		__P((int, int));
int touch		__P((int, char *, struct timespec *));
int user_is_exempt	__P((void));
void set_fqdn		__P((void));
char *sudo_getepw	__P((const struct passwd *));
int pam_prep_user	__P((struct passwd *));
void zero_bytes		__P((volatile void *, size_t));
int gettime		__P((struct timespec *));
FILE *open_sudoers	__P((const char *, int *));
void display_privs	__P((struct sudo_nss_list *, struct passwd *));
int display_cmnd	__P((struct sudo_nss_list *, struct passwd *));
int get_ttycols		__P((void));
char *sudo_parseln	__P((FILE *));
void sudo_setenv	__P((const char *, const char *, int));
void sudo_unsetenv	__P((const char *));
void sudo_setgrent	__P((void));
void sudo_endgrent	__P((void));
void sudo_setpwent	__P((void));
void sudo_endpwent	__P((void));
void sudo_setspent	__P((void));
void sudo_endspent	__P((void));
void cleanup		__P((int));
struct passwd *sudo_getpwnam __P((const char *));
struct passwd *sudo_fakepwnam __P((const char *));
struct passwd *sudo_getpwuid __P((uid_t));
struct passwd *sudo_fakepwuid __P((uid_t));
struct group *sudo_getgrnam __P((const char *));
struct group *sudo_fakegrnam __P((const char *));
struct group *sudo_getgrgid __P((gid_t));
YY_DECL;

/* Only provide extern declarations outside of sudo.c. */
#ifndef _SUDO_MAIN
extern struct sudo_user sudo_user;
extern struct passwd *auth_pw, *list_pw;

extern int tgetpass_flags;
extern uid_t timestamp_uid;
#endif
#ifndef errno
extern int errno;
#endif

#endif /* _SUDO_SUDO_H */
