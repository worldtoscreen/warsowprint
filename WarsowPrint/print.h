#pragma once
#include <cstdarg>

#include <Windows.h>
#include <iostream>

typedef double( __cdecl *LogType )( const char *, ... );
static uintptr_t logOffset = 0x41A8A0;
static LogType logF = nullptr;

bool init( );
void print( char *message );
void getInputAndPrint( FILE *ptr );