#ifndef TYPE_DEFINES_H
#define TYPE_DEFINES_H

#ifndef WIN32
#include <inttypes.h>
#endif //WIN32

typedef char                CHAR;
typedef signed char         INT8;
typedef unsigned char       UCHAR;
typedef unsigned char       UINT8;
typedef unsigned char       BYTE;
typedef short               SHORT;
typedef signed short        INT16;
typedef unsigned short      USHORT;
typedef unsigned short      UINT16;
typedef unsigned short      WORD;
typedef int                 INT;
typedef signed int          INT32;
typedef unsigned int        UINT;
typedef unsigned int        UINT32;
typedef long                LONG;
typedef unsigned long       ULONG;
typedef unsigned long       DWORD;

#ifndef WIN32
typedef int64_t             INT64;
typedef uint64_t            UINT64;
#else
typedef unsigned __int64    UINT64;
typedef signed __int64      INT64;
#endif//

typedef INT64               LONGLONG;
typedef INT64               LONG64;

#ifdef WIN32
typedef UINT64              ULONGLONG;
typedef UINT64              DWORDLONG;
typedef UINT64              ULONG64;
typedef UINT64              DWORD64;
#else
typedef UINT64              ULONGLONG;
typedef UINT64              DWORDLONG;
typedef UINT64              ULONG64;
typedef UINT64              DWORD64;
typedef UINT64              UINT64;
#endif//WIN32

#endif //TYPE_DEFINES_H
