#include "pch.h"
#include "print.h"

bool init( )
{
	logF = reinterpret_cast<LogType>( logOffset );

	if ( !logF )
	{
		std::cout << "Failed to cast to function. Incorrect offset?" << std::endl;
		return false;
	}
	
	return true;
}

/* Doesn't handle variadic args... yet. Will look into it later. */
void print( char *message )
{
	if (!logF )
	{
		std::cout << "function pointer no longer valid." << std::endl;
		return;
	}

	logF( message );
	std::cout << "[debug] called log @ 0x" << std::hex << logF << std::dec << std::endl;

	return;
}

void getInputAndPrint( FILE *ptr )
{
	std::cout << "Init retuned success!" << std::endl;
	std::cout << "Message (256 characters max) -> ";

	char str[256];
	fgets( str, sizeof( str ), stdin );
	std::cout << std::endl;

	str[strlen( str )] = '\n';
	str[strlen( str ) + 1] = '\0';

	print( str );
	fflush( ptr );
}