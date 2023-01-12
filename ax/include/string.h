/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_string)
#define __ax_hdr_string

#include <ax/bs.h>

#define __STDC_VERSION_STRING_H__ (202311l)

#define NULL nullptr

typedef ax_i02 size_t;

void * memcpy( void * restrict s1,void const * restrict s2,size_t n);
void * memccpy(void * restrict s1,void const * restrict s2,int    c,size_t n);
void * memmove(void * restrict s1,void const * restrict s2,size_t n);
char * strcpy( char * restrict s1,char const * restrict s2);
char * strncpy(char * restrict s1,char const * restrict s2,size_t n);
/* strdup not required. */
/* strndup not required. */

char * strcat( char * restrict s1,char const * restrict s2);
char * strncat(char * restrict s1,char const * restrict s2,size_t n);

int memcmp( void const * s1,void const * s2,size_t n);
int strcmp( char const * s1,char const * s2);
/* strcoll not required. */
int strncmp(char const * s1,char const * s2);
/* strxfrm not required. */

/* We're missing the generic variants of the following functions: */
void * memchr( void const *    s, int             c, size_t n);
char * strchr( char const *    s, int             c);
size_t strcspn(char const *    s1,char const *    s2);
char * strpbrk(char const *    s1,char const *    s2);
char * strrchr(char const *    s1,int             c);
size_t strspn( char const *    s1,char const *    s2);
char * strstr( char const *    s1,char const *    s2);
char * strtok( char * restrict s1,char * restrict s2);

void * memset(         void *       s,int c,size_t n);
void * memset_explicit(void *       s,int c,size_t n);
/* strerror is not required. */
size_t strlen(         char const * s);

#endif
