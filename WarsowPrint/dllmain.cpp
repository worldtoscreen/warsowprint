#include "pch.h"

void ThreadMain( HMODULE hModule )
{
    AllocConsole( );
    FILE *Dummy;
    freopen_s( &Dummy, "CONOUT$", "w", stdout );
    freopen_s( &Dummy, "CONIN$", "r", stdin );

    if ( init( ) && Dummy )
    {
        std::cout << "init called, functions read. F1=print F2=quit" << std::endl;
    }
    else { FreeLibraryAndExitThread( hModule, 0 ); }

    while ( true )
    {
        if ( GetAsyncKeyState( VK_F2 ) & 1 )
        {
            fclose( stdout );
            if ( Dummy ) fclose( Dummy );
            FreeConsole( );

            FreeLibraryAndExitThread( hModule, 0 );
        }

        if ( GetAsyncKeyState( VK_F1 ) & 1 )
        {
            getInputAndPrint( Dummy );
        }
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread( 0, 0, (LPTHREAD_START_ROUTINE)ThreadMain, hModule, 0, 0 );
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

