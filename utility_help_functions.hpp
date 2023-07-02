#ifndef __UTILITY_HELPER_FUNCTIONS_HEADER_GUARD__
#define __UTILITY_HELPER_FUNCTIONS_HEADER_GUARD__
/*
 *use this for the MACROS otherwise just include the header to use the functions by default
 #define MACRO_DEBUG_MEMORY_HELPER
 #include "utility_help_functions.hpp"
*/

#ifndef _DEBUG
int Release_Mode_Warning = []() -> int { std::cerr << "Error: Release mode enabled. Debugging features are disabled Make sure to Exclude the utility_help_functions Header."; return 0; }();
#endif // DEBUG MODE CHECK CALL LAMBDA

#ifdef _DEBUG

#ifdef MACRO_DEBUG_MEMORY_HELPER
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/crtsetreportfile?view=msvc-170 ONLY DEBUG MODE
#define MEMORY_LEAK_DUMP _CrtSetReportMode(_CRT_WARN,_CRTDBG_MODE_FILE);\
						 _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);\
						 _CrtDumpMemoryLeaks();
// ONLY DEBUG MODE this Macro is for if statements
#define MEMORY_LEAK_INT _CrtDumpMemoryLeaks();
// ONLY DEBUG MODE this Macro is only used to satisfy std::boolalpha 
#define MEMORY_LEAK_BOOL static_cast<bool>(_CrtDumpMemoryLeaks());
// Breakpoint on the Location where the memory leak occurred
#define LEAK_WHERE(LOCATION_ID) _CrtSetBreakAlloc(LOCATION_ID);

#else
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/crtsetreportfile?view=msvc-170 ONLY DEBUG MODE
void MEMORY_LEAK_DUMP()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();
}
// ONLY DEBUG MODE this Function is for if statements
int MEMORY_LEAK_INT()
{
	return _CrtDumpMemoryLeaks();
}
// ONLY DEBUG MODE this Function is is only used to satisfy std::boolalpha 
bool MEMORY_LEAK_BOOL()
{
	return static_cast<bool>(_CrtDumpMemoryLeaks());
}
// Breakpoint on the Location where the memory leak occurred
void LEAK_WHERE(int LOCATION_ID)
{
	_CrtSetBreakAlloc(LOCATION_ID);
}

#endif // MACRO FUNCTION TOGGLE
#endif // DEBUG MODE CHECK
#endif // HEADER GUARD
