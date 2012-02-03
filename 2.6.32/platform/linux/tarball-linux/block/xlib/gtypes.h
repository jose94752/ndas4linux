/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.     See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/. 
 */
 
#ifndef __G_TYPES_H__
#define __G_TYPES_H__

//#include "glibconfig.h"

//G_BEGIN_DECLS

/* Provide type definitions for commonly used types.
 *  These are useful because a "int8" can be adjusted
 *  to be 1 byte (8 bits) on all platforms. Similarly and
 *  more importantly, "int32" can be adjusted to be
 *  4 bytes (32 bits) on all platforms.
 */

#if 0

typedef char   gchar;
typedef short  gshort;
typedef long   long;
typedef int    int;
typedef bool   bool;

typedef unsigned char   guchar;
typedef unsigned short  gushort;
typedef unsigned long   gulong;
typedef unsigned int    unsigned int;

typedef float   float;
typedef double  double;


/* Define min and max constants for the fixed size numerical types */
#define G_MININT8    ((int8)  0x80)
#define G_MAXINT8    ((int8)  0x7f)
#define G_MAXUINT8    ((unsigned int8) 0xff)

#define G_MININT16    ((int16)  0x8000)
#define G_MAXINT16    ((int16)  0x7fff)
#define G_MAXUINT16    ((unsigned int16) 0xffff)

#define G_MININT32    ((int32)  0x80000000)
#define G_MAXINT32    ((int32)  0x7fffffff)
#define G_MAXUINT32    ((unsigned int32) 0xffffffff)

#define G_MININT64    G_GINT64_CONSTANT(0x8000000000000000)
#define G_MAXINT64    G_GINT64_CONSTANT(0x7fffffffffffffff)
#define G_MAXUINT64    G_GINT64_CONSTANT(0xffffffffffffffffU)

typedef void *void*;
typedef const void *const void*;

#endif

typedef int            (*GCompareFunc)         (const void*  a,
                                                 const void*  b);
typedef int            (*GCompareDataFunc)     (const void*  a,
                                                 const void*  b,
                         void*       user_data);
typedef bool        (*GEqualFunc)           (const void*  a,
                                                 const void*  b);
typedef void            (*GDestroyNotify)       (void*       data);
typedef void            (*GFunc)                (void*       data,
                                                 void*       user_data);
typedef unsigned int           (*GHashFunc)            (const void*  key);
typedef void            (*GHFunc)               (void*       key,
                                                 void*       value,
                                                 void*       user_data);
typedef void            (*GFreeFunc)            (void*       data);

#if 0

/* Define some mathematical constants that aren't available
 * symbolically in some strict ISO C implementations.
 */
#define G_E     2.7182818284590452354E0
#define G_LN2   6.9314718055994530942E-1
#define G_LN10  2.3025850929940456840E0
#define G_PI    3.14159265358979323846E0
#define G_PI_2  1.57079632679489661923E0
#define G_PI_4  0.78539816339744830962E0
#define G_SQRT2 1.4142135623730950488E0

/* Portable endian checks and conversions
 *
 * glibconfig.h defines G_BYTE_ORDER which expands to one of
 * the below macros.
 */
#define G_LITTLE_ENDIAN 1234
#define G_BIG_ENDIAN    4321
#define G_PDP_ENDIAN    3412        /* unused, need specific PDP check */    


/* Basic bit swapping functions
 */
#define GUINT16_SWAP_LE_BE_CONSTANT(val)    ((unsigned int16) ( \
    (unsigned int16) ((unsigned int16) (val) >> 8) |    \
    (unsigned int16) ((unsigned int16) (val) << 8)))

#define GUINT32_SWAP_LE_BE_CONSTANT(val)    ((unsigned int32) ( \
    (((unsigned int32) (val) & (unsigned int32) 0x000000ffU) << 24) | \
    (((unsigned int32) (val) & (unsigned int32) 0x0000ff00U) <<  8) | \
    (((unsigned int32) (val) & (unsigned int32) 0x00ff0000U) >>  8) | \
    (((unsigned int32) (val) & (unsigned int32) 0xff000000U) >> 24)))

#define GUINT64_SWAP_LE_BE_CONSTANT(val)    ((unsigned int64) ( \
      (((unsigned int64) (val) &                        \
    (unsigned int64) G_GINT64_CONSTANT (0x00000000000000ffU)) << 56) |    \
      (((unsigned int64) (val) &                        \
    (unsigned int64) G_GINT64_CONSTANT (0x000000000000ff00U)) << 40) |    \
      (((unsigned int64) (val) &                        \
    (unsigned int64) G_GINT64_CONSTANT (0x0000000000ff0000U)) << 24) |    \
      (((unsigned int64) (val) &                        \
    (unsigned int64) G_GINT64_CONSTANT (0x00000000ff000000U)) <<  8) |    \
      (((unsigned int64) (val) &                        \
    (unsigned int64) G_GINT64_CONSTANT (0x000000ff00000000U)) >>  8) |    \
      (((unsigned int64) (val) &                        \
    (unsigned int64) G_GINT64_CONSTANT (0x0000ff0000000000U)) >> 24) |    \
      (((unsigned int64) (val) &                        \
    (unsigned int64) G_GINT64_CONSTANT (0x00ff000000000000U)) >> 40) |    \
      (((unsigned int64) (val) &                        \
    (unsigned int64) G_GINT64_CONSTANT (0xff00000000000000U)) >> 56)))

/* Arch specific stuff for speed
 */
#if defined (__GNUC__) && (__GNUC__ >= 2) && defined (__OPTIMIZE__)
#  if defined (__i386__)
#    define GUINT16_SWAP_LE_BE_IA32(val) \
       (__extension__                        \
    ({ register unsigned int16 __v, __x = ((unsigned int16) (val));    \
       if (__builtin_constant_p (__x))            \
         __v = GUINT16_SWAP_LE_BE_CONSTANT (__x);        \
       else                            \
         __asm__ ("rorw $8, %w0"                \
              : "=r" (__v)                \
              : "0" (__x)                \
              : "cc");                    \
        __v; }))
#    if !defined (__i486__) && !defined (__i586__) \
    && !defined (__pentium__) && !defined (__i686__) \
    && !defined (__pentiumpro__) && !defined (__pentium4__)
#       define GUINT32_SWAP_LE_BE_IA32(val) \
      (__extension__                    \
       ({ register unsigned int32 __v, __x = ((unsigned int32) (val));    \
          if (__builtin_constant_p (__x))            \
        __v = GUINT32_SWAP_LE_BE_CONSTANT (__x);    \
          else                        \
        __asm__ ("rorw $8, %w0\n\t"            \
             "rorl $16, %0\n\t"            \
             "rorw $8, %w0"                \
             : "=r" (__v)                \
             : "0" (__x)                \
             : "cc");                \
          __v; }))
#    else /* 486 and higher has bswap */
#       define GUINT32_SWAP_LE_BE_IA32(val) \
      (__extension__                    \
       ({ register unsigned int32 __v, __x = ((unsigned int32) (val));    \
          if (__builtin_constant_p (__x))            \
        __v = GUINT32_SWAP_LE_BE_CONSTANT (__x);    \
          else                        \
        __asm__ ("bswap %0"                \
             : "=r" (__v)                \
             : "0" (__x));                \
          __v; }))
#    endif /* processor specific 32-bit stuff */
#    define GUINT64_SWAP_LE_BE_IA32(val) \
       (__extension__                            \
    ({ union { unsigned int64 __ll;                    \
           unsigned int32 __l[2]; } __w, __r;                \
       __w.__ll = ((unsigned int64) (val));                \
       if (__builtin_constant_p (__w.__ll))                \
         __r.__ll = GUINT64_SWAP_LE_BE_CONSTANT (__w.__ll);        \
       else                                \
         {                                \
           __r.__l[0] = GUINT32_SWAP_LE_BE (__w.__l[1]);        \
           __r.__l[1] = GUINT32_SWAP_LE_BE (__w.__l[0]);        \
         }                                \
       __r.__ll; }))
     /* Possibly just use the constant version and let gcc figure it out? */
#    define GUINT16_SWAP_LE_BE(val) (GUINT16_SWAP_LE_BE_IA32 (val))
#    define GUINT32_SWAP_LE_BE(val) (GUINT32_SWAP_LE_BE_IA32 (val))
#    define GUINT64_SWAP_LE_BE(val) (GUINT64_SWAP_LE_BE_IA32 (val))
#  elif defined (__ia64__)
#    define GUINT16_SWAP_LE_BE_IA64(val) \
       (__extension__                        \
    ({ register unsigned int16 __v, __x = ((unsigned int16) (val));    \
       if (__builtin_constant_p (__x))            \
         __v = GUINT16_SWAP_LE_BE_CONSTANT (__x);        \
       else                            \
         __asm__ __volatile__ ("shl %0 = %1, 48 ;;"        \
                   "mux1 %0 = %0, @rev ;;"    \
                    : "=r" (__v)        \
                    : "r" (__x));        \
        __v; }))
#    define GUINT32_SWAP_LE_BE_IA64(val) \
       (__extension__                        \
     ({ register unsigned int32 __v, __x = ((unsigned int32) (val));    \
        if (__builtin_constant_p (__x))            \
          __v = GUINT32_SWAP_LE_BE_CONSTANT (__x);        \
        else                        \
         __asm__ __volatile__ ("shl %0 = %1, 32 ;;"        \
                   "mux1 %0 = %0, @rev ;;"    \
                    : "=r" (__v)        \
                    : "r" (__x));        \
        __v; }))
#    define GUINT64_SWAP_LE_BE_IA64(val) \
       (__extension__                        \
    ({ register unsigned int64 __v, __x = ((unsigned int64) (val));    \
       if (__builtin_constant_p (__x))            \
         __v = GUINT64_SWAP_LE_BE_CONSTANT (__x);        \
       else                            \
         __asm__ __volatile__ ("mux1 %0 = %1, @rev ;;"    \
                   : "=r" (__v)            \
                   : "r" (__x));        \
       __v; }))
#    define GUINT16_SWAP_LE_BE(val) (GUINT16_SWAP_LE_BE_IA64 (val))
#    define GUINT32_SWAP_LE_BE(val) (GUINT32_SWAP_LE_BE_IA64 (val))
#    define GUINT64_SWAP_LE_BE(val) (GUINT64_SWAP_LE_BE_IA64 (val))
#  elif defined (__x86_64__)
#    define GUINT32_SWAP_LE_BE_X86_64(val) \
       (__extension__                        \
     ({ register unsigned int32 __v, __x = ((unsigned int32) (val));    \
        if (__builtin_constant_p (__x))            \
          __v = GUINT32_SWAP_LE_BE_CONSTANT (__x);        \
        else                        \
         __asm__ ("bswapl %0"                \
              : "=r" (__v)                \
              : "0" (__x));                \
        __v; }))
#    define GUINT64_SWAP_LE_BE_X86_64(val) \
       (__extension__                        \
    ({ register unsigned int64 __v, __x = ((unsigned int64) (val));    \
       if (__builtin_constant_p (__x))            \
         __v = GUINT64_SWAP_LE_BE_CONSTANT (__x);        \
       else                            \
         __asm__ ("bswapq %0"                \
              : "=r" (__v)                \
              : "0" (__x));                \
       __v; }))
     /* gcc seems to figure out optimal code for this on its own */
#    define GUINT16_SWAP_LE_BE(val) (GUINT16_SWAP_LE_BE_CONSTANT (val))
#    define GUINT32_SWAP_LE_BE(val) (GUINT32_SWAP_LE_BE_X86_64 (val))
#    define GUINT64_SWAP_LE_BE(val) (GUINT64_SWAP_LE_BE_X86_64 (val))
#  else /* generic gcc */
#    define GUINT16_SWAP_LE_BE(val) (GUINT16_SWAP_LE_BE_CONSTANT (val))
#    define GUINT32_SWAP_LE_BE(val) (GUINT32_SWAP_LE_BE_CONSTANT (val))
#    define GUINT64_SWAP_LE_BE(val) (GUINT64_SWAP_LE_BE_CONSTANT (val))
#  endif
#else /* generic */
#  define GUINT16_SWAP_LE_BE(val) (GUINT16_SWAP_LE_BE_CONSTANT (val))
#  define GUINT32_SWAP_LE_BE(val) (GUINT32_SWAP_LE_BE_CONSTANT (val))
#  define GUINT64_SWAP_LE_BE(val) (GUINT64_SWAP_LE_BE_CONSTANT (val))
#endif /* generic */

#define GUINT16_SWAP_LE_PDP(val)    ((unsigned int16) (val))
#define GUINT16_SWAP_BE_PDP(val)    (GUINT16_SWAP_LE_BE (val))
#define GUINT32_SWAP_LE_PDP(val)    ((unsigned int32) ( \
    (((unsigned int32) (val) & (unsigned int32) 0x0000ffffU) << 16) | \
    (((unsigned int32) (val) & (unsigned int32) 0xffff0000U) >> 16)))
#define GUINT32_SWAP_BE_PDP(val)    ((unsigned int32) ( \
    (((unsigned int32) (val) & (unsigned int32) 0x00ff00ffU) << 8) | \
    (((unsigned int32) (val) & (unsigned int32) 0xff00ff00U) >> 8)))

/* The G*_TO_?E() macros are defined in glibconfig.h.
 * The transformation is symmetric, so the FROM just maps to the TO.
 */
#define GINT16_FROM_LE(val)    (GINT16_TO_LE (val))
#define GUINT16_FROM_LE(val)    (GUINT16_TO_LE (val))
#define GINT16_FROM_BE(val)    (GINT16_TO_BE (val))
#define GUINT16_FROM_BE(val)    (GUINT16_TO_BE (val))
#define GINT32_FROM_LE(val)    (GINT32_TO_LE (val))
#define GUINT32_FROM_LE(val)    (GUINT32_TO_LE (val))
#define GINT32_FROM_BE(val)    (GINT32_TO_BE (val))
#define GUINT32_FROM_BE(val)    (GUINT32_TO_BE (val))

#define GINT64_FROM_LE(val)    (GINT64_TO_LE (val))
#define GUINT64_FROM_LE(val)    (GUINT64_TO_LE (val))
#define GINT64_FROM_BE(val)    (GINT64_TO_BE (val))
#define GUINT64_FROM_BE(val)    (GUINT64_TO_BE (val))

#define GLONG_FROM_LE(val)    (GLONG_TO_LE (val))
#define GULONG_FROM_LE(val)    (GULONG_TO_LE (val))
#define GLONG_FROM_BE(val)    (GLONG_TO_BE (val))
#define GULONG_FROM_BE(val)    (GULONG_TO_BE (val))

#define GINT_FROM_LE(val)    (GINT_TO_LE (val))
#define GUINT_FROM_LE(val)    (GUINT_TO_LE (val))
#define GINT_FROM_BE(val)    (GINT_TO_BE (val))
#define GUINT_FROM_BE(val)    (GUINT_TO_BE (val))


/* Portable versions of host-network order stuff
 */
#define g_ntohl(val) (GUINT32_FROM_BE (val))
#define g_ntohs(val) (GUINT16_FROM_BE (val))
#define g_htonl(val) (GUINT32_TO_BE (val))
#define g_htons(val) (GUINT16_TO_BE (val))

/* Little endian to host endian short */
#define g_ltohs(val) (GUINT16_FROM_LE(val))
#define g_letohel(val) (GUINT32_FROM_LE(val))

#define g_betohes(val) (GUINT16_FROM_BE(val))
#define g_betohel(val) (GUINT32_FROM_BE(val))

/* IEEE Standard 754 Single Precision Storage Format (float):
 *
 *        31 30           23 22            0
 * +--------+---------------+---------------+
 * | s 1bit | e[30:23] 8bit | f[22:0] 23bit |
 * +--------+---------------+---------------+
 * B0------------------->B1------->B2-->B3-->
 *
 * IEEE Standard 754 Double Precision Storage Format (double):
 *
 *        63 62            52 51            32   31            0
 * +--------+----------------+----------------+ +---------------+
 * | s 1bit | e[62:52] 11bit | f[51:32] 20bit | | f[31:0] 32bit |
 * +--------+----------------+----------------+ +---------------+
 * B0--------------->B1---------->B2--->B3---->  B4->B5->B6->B7->
 */
/* subtract from biased_exponent to form base2 exponent (normal numbers) */
typedef union  _GDoubleIEEE754    GDoubleIEEE754;
typedef union  _GFloatIEEE754    GFloatIEEE754;
#define G_IEEE754_FLOAT_BIAS    (127)
#define G_IEEE754_DOUBLE_BIAS    (1023)
/* multiply with base2 exponent to get base10 exponent (normal numbers) */
#define G_LOG_2_BASE_10        (0.30102999566398119521)

#if   defined(__LITTLE_ENDIAN)
union _GFloatIEEE754
{
  float v_float;
  struct {
    unsigned int mantissa : 23;
    unsigned int biased_exponent : 8;
    unsigned int sign : 1;
  } mpn;
};
union _GDoubleIEEE754
{
  double v_double;
  struct {
    unsigned int mantissa_low : 32;
    unsigned int mantissa_high : 20;
    unsigned int biased_exponent : 11;
    unsigned int sign : 1;
  } mpn;
};
#elif defined(__BIG_ENDIAN)
union _GFloatIEEE754
{
  float v_float;
  struct {
    unsigned int sign : 1;
    unsigned int biased_exponent : 8;
    unsigned int mantissa : 23;
  } mpn;
};
union _GDoubleIEEE754
{
  double v_double;
  struct {
    unsigned int sign : 1;
    unsigned int biased_exponent : 11;
    unsigned int mantissa_high : 20;
    unsigned int mantissa_low : 32;
  } mpn;
};
#else /* !G_LITTLE_ENDIAN && !G_BIG_ENDIAN */
#error unknown ENDIAN type
#endif /* !G_LITTLE_ENDIAN && !G_BIG_ENDIAN */

typedef struct _GTimeVal                GTimeVal;

struct _GTimeVal
{
  long tv_sec;
  long tv_usec;
};

//G_END_DECLS

/* We prefix variable declarations so they can
 * properly get exported in windows dlls.
 */
#ifndef GLIB_VAR
#  ifdef G_PLATFORM_WIN32
#    ifdef GLIB_STATIC_COMPILATION
#      define GLIB_VAR extern
#    else /* !GLIB_STATIC_COMPILATION */
#      ifdef GLIB_COMPILATION
#        ifdef DLL_EXPORT
#          define GLIB_VAR __declspec(dllexport)
#        else /* !DLL_EXPORT */
#          define GLIB_VAR extern
#        endif /* !DLL_EXPORT */
#      else /* !GLIB_COMPILATION */
#        define GLIB_VAR extern __declspec(dllimport)
#      endif /* !GLIB_COMPILATION */
#    endif /* !GLIB_STATIC_COMPILATION */
#  else /* !G_PLATFORM_WIN32 */
#    define GLIB_VAR extern
#  endif /* !G_PLATFORM_WIN32 */
#endif /* GLIB_VAR */

#endif

#endif /* __G_TYPES_H__ */

