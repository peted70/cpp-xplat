#include "SharedObject.h"

const char *GetTemplateInfo2() 
{
#ifdef __ANDROID__
	return "Hello from Android C++!"; 
#else
	return "Hello from Windows C++!";
#endif
}
