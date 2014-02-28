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
	int gl_IndexPointer(lutok::state& state){
		if (state.is_number(1)){
			GLint size = 0;
			GLint nsize = state.to_integer(1);
			GLfloat * data;
			vector<float> _data;

			if (state.is_number(2)){
				data = (GLfloat *) state.to_integer(2);
			}else{
				if (state.is_table(2)){
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