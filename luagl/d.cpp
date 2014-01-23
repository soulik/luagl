#include "main.h"

namespace GLex {
	int gl_Disable(lutok::state& state){
		glDisable((GLuint)state.to_integer(1));
		return 0;
	}
	int gl_DeleteBuffers(lutok::state& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.is_number(1)){
			data = (GLuint *) state.to_integer(1);
		}else{
			if (state.is_table(1)){
				count = getArray<unsigned int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDeleteBuffers(count, data);
		return 0;
	}
	int gl_DeleteFrameBuffers(lutok::state& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.is_number(1)){
			data = (GLuint *) state.to_integer(1);
		}else{
			if (state.is_table(1)){
				count = getArray<unsigned int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDeleteFramebuffers(count,data);
		return 0;
	}
	int gl_DeleteVertexArrays(lutok::state& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.is_number(1)){
			data = (GLuint *) state.to_integer(1);
		}else{
			if (state.is_table(1)){
				count = getArray<unsigned int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDeleteVertexArrays(count,data);
		return 0;
	}
	int gl_DeleteLists(lutok::state& state){
		glDeleteLists((GLuint)state.to_integer(1),(GLsizei)state.to_integer(2));
		return 0;
	}
	int gl_DeleteProgram(lutok::state& state){
		glDeleteProgram((GLenum)state.to_integer(1));
		return 0;
	}
	int gl_DeleteShader(lutok::state& state){
		glDeleteShader((GLenum)state.to_integer(1));
		return 0;
	}
	int gl_DeleteTextures(lutok::state& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.is_number(1)){
			data = (GLuint *) state.to_integer(1);
		}else{
			if (state.is_table(1)){
				count = getArray<unsigned int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDeleteTextures(count, data);
		return 0;
	}
	int gl_DepthFunc(lutok::state& state){
		glDepthFunc((GLenum) state.to_integer(1));
		return 0;
	}
	int gl_DepthMask(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glDepthMask()");
		glDepthMask((GLboolean) state.to_boolean(1));
		return 0;
	}
	int gl_DepthRange(lutok::state& state){
		glDepthRange((GLclampd) state.to_number(1),(GLclampd) state.to_number(2));
		return 0;
	}
	int gl_DepthTextures(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glDepthTextures()");
		//glDepthTextures(
		return 0;
	}
	int gl_DetachShader(lutok::state& state){
		glDetachShader((GLuint) state.to_integer(1), (GLuint) state.to_integer(2));
		return 0;
	}
	int gl_DisableClientState(lutok::state& state){
		glDisableClientState((GLenum) state.to_integer(1));
		return 0;
	}
	int gl_DisableVertexArray(lutok::state& state){
		glDisableVertexAttribArray((GLuint) state.to_integer(1));
		return 0;
	}

	int gl_DrawArrays(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glDrawArrays()");
		glDrawArrays((GLenum) state.to_integer(1), (GLint)state.to_integer(2), (GLsizei) state.to_integer(3));
		return 0;
	}
	int gl_DrawBuffer(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glDrawBuffer()");
		glDrawBuffer((GLenum)state.to_integer(1));
		return 0;
	}
	int gl_DrawElements(lutok::state& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.is_number(2)){
			data = (GLuint *) state.to_integer(2);
		}else{
			if (state.is_table(1)){
				count = getArray<unsigned int>(state, 2, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDrawElements(state.to_integer(1), count, GL_UNSIGNED_INT, data);
		return 0;
	}
	int gl_DrawPixels(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glDrawPixels()");
		return 0;
	}

}