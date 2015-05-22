#include "main.h"

namespace LuaGL {
	int gl_Index(State& state){
		glIndexf((GLfloat) state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
	int gl_IndexMask(State& state){
		glIndexMask((GLuint) state.stack->to<int>(1));
		return 0;
	}
	int gl_InitNames(State& state){
		glInitNames();
		return 0;
	}
	int gl_InterleavedArrays(State& state){
		return 0;
	}
	int gl_IsEnabled(State& state){
		GLboolean ret = glIsEnabled((GLenum) state.stack->to<int>(1));
		state.stack->push<bool>(ret);
		return 1;
	}
	int gl_IsList(State& state){
		GLboolean ret = glIsList((GLuint) state.stack->to<int>(1));
		state.stack->push<bool>(ret);
		return 1;
	}
	int gl_IsTexture(State& state){
		//glIsTexure((GLuint)lua_tonumber(L,1));
		return 0;
	}
	int gl_IndexPointer(State& state){
		if (state.stack->is<LUA_TNUMBER>(1)){
			GLint size = 0;
			GLint nsize = state.stack->to<int>(1);
			GLfloat * data;
			vector<float> _data;

			if (state.stack->is<LUA_TNUMBER>(2)){
				data = (GLfloat *) state.stack->to<int>(2);
			}else{
				if (state.stack->is<LUA_TTABLE>(2)){
					size = getArray<float>(state, 2, _data);
					data = _data.data();
				}else{
					data = NULL;
				}
			}
			if ((data && (nsize<=size)) || (nsize>=1 && nsize <= 4)){
				/* call opengl function */
				glIndexPointer(GL_FLOAT, 0, data);
			}
		}
		return 0;
	}

}