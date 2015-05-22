#define WIN32_LEAN_AND_MEAN

#include <lua.hpp>
#include <GL/glew.h>
#if defined(_WIN32)
	#include <GL/wglew.h>
#else
	#include <GL/glxew.h>
#endif

#include <lutok2/lutok2.hpp>

//#include <GL/gl.h>
//#include <GL/glu.h>
#include <sdl/SDL.h>

#include <math.h>
#include <string>
#include <vector>

using namespace std;
using namespace lutok2;
typedef unsigned int uint;

#if (BUILDING_LIBLUAGL || luagl_EXPORTS) && HAVE_VISIBILITY
#define LIBLUAGL_DLL_EXPORTED __attribute__((visibility("default")))
#elif (BUILDING_LIBLUAGL || luagl_EXPORTS) && defined _MSC_VER
#define LIBLUAGL_DLL_EXPORTED __declspec(dllexport)
#elif defined _MSC_VER
#define LIBLUAGL_DLL_EXPORTED __declspec(dllimport)
#else
#define LIBLUAGL_DLL_EXPORTED
#endif

#define FN_GL_GetProcAddress wglGetProcAddress
#define LOCAL_BUFFER_SIZE	256

#define GL_DEF_FN(FN_NAME)	int FN_NAME(State &)

#include "utils.h"
