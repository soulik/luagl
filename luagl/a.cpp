#include "main.h"

namespace GLex {
	int gl_Accum(lutok::state& state){
		glAccum((GLuint)state.to_integer(1),(GLfloat)state.to_number(2));
		return 0;
	}
	int gl_ActiveTexture(lutok::state& state){
		glActiveTexture((GLenum) state.to_integer(1));
		return 0;
	}
	int gl_AlphaFunc(lutok::state& state){
		glAlphaFunc((GLenum)state.to_integer(1),(GLclampf)state.to_number(2));
		return 0;
	}
	int gl_ArrayElement(lutok::state& state){
		glArrayElement((GLint)state.to_integer(1));
		return 0;
	}
	int gl_AttachShader(lutok::state& state){
		glAttachShader((GLuint) state.to_integer(1), (GLuint) state.to_integer(2));
		return 0;
	}
};