#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <malloc.h>

#include <lua/lua.hpp>

#include <GL/glew.h>

#if defined(_WIN32)
	#include <GL/wglew.h>
#else
	#include <GL/glxew.h>
#endif


//#include <GL/gl.h>
//#include <GL/glu.h>
#include <sdl/SDL.h>

#include <lutok/lutok.hpp>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

#define LUAGLEX_API extern "C" __declspec(dllexport)

typedef unsigned int uint;

//#define FN_GL_GetProcAddress SDL_GL_GetProcAddress
#define FN_GL_GetProcAddress wglGetProcAddress
#define LOCAL_BUFFER_SIZE	256

#define GL_DEF_FN(FN_NAME)	int FN_NAME(lutok::state &)

#include "utils.h"
