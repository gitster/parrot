/* string.h
 *  Copyright: (When this is determined...it will go here)
 *  CVS Info
 *     $Id$
 *  Overview:
 *     This is the api header for the string subsystem
 *  Data Structure and Algorithms:
 *  History:
 *  Notes:
 *  References:
 */

#if !defined(PARROT_STRING_H_GUARD)
#define PARROT_STRING_H_GUARD

#include "parrot/config.h"
#include "parrot/encoding.h"
#include "parrot/chartype.h"
#include "parrot/pobj.h"

struct parrot_string_t;

#ifdef PARROT_IN_CORE

#include "parrot/parrot.h"

typedef struct parrot_string_t String;


/* Tail added to end of string buffers; used for COW GC */
struct Buffer_Tail {
    unsigned char flags;
};
typedef enum TAIL_flag {
    TAIL_moved_FLAG = 1 << 0
} TAIL_flags;


/* stringinfo parameters */

/* &gen_from_def(stringinfo.pasm) */

#define STRINGINFO_HEADER   1
#define STRINGINFO_STRSTART 2
#define STRINGINFO_BUFLEN   3
#define STRINGINFO_FLAGS    4
#define STRINGINFO_BUFUSED  5
#define STRINGINFO_STRLEN   6

/* &end_gen */
#define STRING struct parrot_string_t

#endif

#endif

/*
 * Local variables:
 * c-indentation-style: bsd
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 *
 * vim: expandtab shiftwidth=4:
*/
