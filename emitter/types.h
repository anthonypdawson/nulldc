#pragma once

//basic types
#ifdef WIN32
typedef signed __int8  s8;
typedef signed __int16 s16;
typedef signed __int32 s32;
typedef signed __int64 s64;

typedef unsigned __int8  u8;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;
#else
#include <stdint.h>
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#endif

typedef float f32;
typedef double f64;

#ifdef __x86_64__
#define X64 1
#endif

#if defined(i386) || defined(_X86_)
#define X86 1
#endif

#ifdef X86
typedef u32 unat;
#endif

#ifdef X64
typedef u64 unat;
#endif

#ifdef WIN32
//Do not complain when i use enum::member
#pragma warning( disable : 4482)

//unnamed struncts/unions
#pragma warning( disable : 4201)

//unused parameters
#pragma warning( disable : 4100)
#endif // WIN32

//basic includes from runtime lib
#include <stdlib.h>
#include <stdio.h>
#include <string.h> // for memset()

#include <vector>
using namespace std;

#ifndef dbgbreak
#ifdef WIN32
#define dbgbreak __asm {int 3}
#else
#include <signal.h>
#define dbgbreak raise(SIGTRAP);
#endif // WIN32
#endif

#ifndef verify
#define verify(x) if((x)==false){ printf("Verify Failed  : " #x "\n in %s -> %s : %d \n",__FUNCTION__,__FILE__,__LINE__); dbgbreak;}
#endif

#ifndef die
#define die(reason) { printf("Fatal error : %s\n in %s -> %s : %d \n",reason,__FUNCTION__,__FILE__,__LINE__); dbgbreak;}
#endif
