#include "main.h"

namespace GLex {
	int gl_Index(lutok::state& state){
		glIndexf((GLfloat) state.to_number(1));
		return 0;
	}
	int gl_IndexMask(lutok::state& state){
		glIndexMask((GLuint) state.to_integer(1));
		return 0;
	}
	int gl_IndexPointer(lutok::state& state){
		return 0;
	}
	int gl_InitNames(lutok::state& state){
		glInitNames();
		return 0;
	}
	int gl_InterleavedArrays(lutok::state& state){
		return 0;
	}
	int gl_IsEnabled(lutok::state& state){
		GLboolean ret = glIsEnabled((GLenum) state.to_integer(1));
		state.push_boolean(ret);
		return 1;
	}
	int gl_IsList(lutok::state& state){
		GLboolean ret = glIsList((GLuint) state.to_integer(1));
		state.push_boolean(ret);
		return 1;
	}
	int gl_IsTexture(lutok::state& state){
		//glIsTexure((GLuint)lua_tonumber(L,1));
		return 0;
	}

}