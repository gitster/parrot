/*
 * $Id$
 * Copyright (C) 2002-2007, The Perl Foundation.
 */

#ifndef PARROT_IMCC_SETS_H_GUARD
#define PARROT_IMCC_SETS_H_GUARD

typedef struct _Set {
   int length;
   unsigned char* bmp;
} Set;

/* HEADERIZER BEGIN: compilers/imcc/sets.c */

void set_add(ARGINOUT(Set *s), int element);
void set_clear(ARGINOUT(Set *s));
PARROT_WARN_UNUSED_RESULT
PARROT_PURE_FUNCTION
int set_contains(ARGIN(const Set *s), int element)
        __attribute__nonnull__(1);

PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Set* set_copy(ARGIN(const Set *s))
        __attribute__nonnull__(1);

int set_equal(ARGIN(const Set *s1), ARGIN(const Set *s2))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2);

PARROT_WARN_UNUSED_RESULT
PARROT_PURE_FUNCTION
int set_first_zero(ARGIN(const Set *s))
        __attribute__nonnull__(1);

void set_free(ARGINOUT(Set *s));
PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Set * set_intersec(ARGIN(const Set *s1), ARGIN(const Set *s2))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2);

void set_intersec_inplace(ARGINOUT(Set *s1), ARGIN(const Set *s2))
        __attribute__nonnull__(2);

PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Set* set_make(int length);

PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Set* set_make_full(int length);

PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Set * set_union(ARGIN(const Set *s1), ARGIN(const Set *s2))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2);

/* HEADERIZER END: compilers/imcc/sets.c */

#endif /* PARROT_IMCC_SETS_H_GUARD */


/*
 * Local variables:
 *   c-file-style: "parrot"
 * End:
 * vim: expandtab shiftwidth=4:
 */

