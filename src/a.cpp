#include "main.h"

namespace LuaGL {
	int gl_Accum(State& state){
		glAccum((GLuint)state.stack->to<int>(1),(GLfloat)state.stack->to<LUA_NUMBER>(2));
		return 0;
	}
	int gl_ActiveTexture(State& state){
		glActiveTexture((GLenum) state.stack->to<int>(1));
		return 0;
	}
	int gl_AlphaFunc(State& state){
		glAlphaFunc((GLenum)state.stack->to<int>(1),(GLclampf)state.stack->to<LUA_NUMBER>(2));
		return 0;
	}
	int gl_ArrayElement(State& state){
		glArrayElement((GLint)state.stack->to<int>(1));
		return 0;
	}
	int gl_AttachShader(State& state){
		glAttachShader((GLuint) state.stack->to<int>(1), (GLuint) state.stack->to<int>(2));
		return 0;
	}
};