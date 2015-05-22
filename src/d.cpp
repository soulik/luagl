#include "main.h"

namespace LuaGL {
	int gl_Disable(State& state){
		glDisable((GLuint)state.stack->to<int>(1));
		return 0;
	}
	int gl_DeleteBuffers(State& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.stack->is<LUA_TNUMBER>(1)){
			data = (GLuint *) state.stack->to<int>(1);
		}else{
			if (state.stack->is<LUA_TTABLE>(1)){
				count = getArray<unsigned int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDeleteBuffers(count, data);
		return 0;
	}
	int gl_DeleteFrameBuffers(State& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.stack->is<LUA_TNUMBER>(1)){
			data = (GLuint *) state.stack->to<int>(1);
		}else{
			if (state.stack->is<LUA_TTABLE>(1)){
				count = getArray<unsigned int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDeleteFramebuffers(count,data);
		return 0;
	}
	int gl_DeleteRenderBuffers(State& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.stack->is<LUA_TNUMBER>(1)){
			data = (GLuint *) state.stack->to<int>(1);
		}else{
			if (state.stack->is<LUA_TTABLE>(1)){
				count = getArray<unsigned int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDeleteRenderbuffers(count,data);
		return 0;
	}
	int gl_DeleteVertexArrays(State& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.stack->is<LUA_TNUMBER>(1)){
			data = (GLuint *) state.stack->to<int>(1);
		}else{
			if (state.stack->is<LUA_TTABLE>(1)){
				count = getArray<unsigned int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDeleteVertexArrays(count,data);
		return 0;
	}
	int gl_DeleteLists(State& state){
		glDeleteLists((GLuint)state.stack->to<int>(1),(GLsizei)state.stack->to<int>(2));
		return 0;
	}
	int gl_DeleteProgram(State& state){
		glDeleteProgram((GLenum)state.stack->to<int>(1));
		return 0;
	}
	int glu_DeleteQuadric(State& state){
		if (state.stack->is<LUA_TUSERDATA>(1)){
			GLUquadric * q = (GLUquadric *)state.stack->to<void*>(1);
			gluDeleteQuadric((GLUquadric*)q);
		}
		return 0;
	}
	int gl_DeleteShader(State& state){
		glDeleteShader((GLenum)state.stack->to<int>(1));
		return 0;
	}
	int gl_DeleteTextures(State& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.stack->is<LUA_TNUMBER>(1)){
			data = (GLuint *) state.stack->to<int>(1);
		}else{
			if (state.stack->is<LUA_TTABLE>(1)){
				count = getArray<unsigned int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDeleteTextures(count, data);
		return 0;
	}
	int gl_DepthFunc(State& state){
		glDepthFunc((GLenum) state.stack->to<int>(1));
		return 0;
	}
	int gl_DepthMask(State& state){
		//__RENDER->dprintf("Stub(%s)","glDepthMask()");
		glDepthMask((GLboolean) state.stack->to<bool>(1));
		return 0;
	}
	int gl_DepthRange(State& state){
		glDepthRange((GLclampd) state.stack->to<LUA_NUMBER>(1),(GLclampd) state.stack->to<LUA_NUMBER>(2));
		return 0;
	}
	int gl_DepthTextures(State& state){
		//__RENDER->dprintf("Stub(%s)","glDepthTextures()");
		//glDepthTextures(
		return 0;
	}
	int gl_DetachShader(State& state){
		glDetachShader((GLuint) state.stack->to<int>(1), (GLuint) state.stack->to<int>(2));
		return 0;
	}
	int gl_DisableClientState(State& state){
		glDisableClientState((GLenum) state.stack->to<int>(1));
		return 0;
	}
	int gl_DisableVertexArray(State& state){
		glDisableVertexAttribArray((GLuint) state.stack->to<int>(1));
		return 0;
	}

	int gl_DrawArrays(State& state){
		//__RENDER->dprintf("Stub(%s)","glDrawArrays()");
		GLenum mode = state.stack->to<int>(1);
		GLint first = state.stack->to<int>(2);
		GLsizei count = state.stack->to<int>(3);
		glDrawArrays((GLenum) mode, (GLint) first, (GLsizei) count);
		return 0;
	}
	int gl_DrawBuffer(State& state){
		glDrawBuffer((GLenum)state.stack->to<int>(1));
		return 0;
	}
	int gl_DrawBuffers(State& state){
		const GLenum * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.stack->is<LUA_TTABLE>(1)){
			count = getArray<unsigned int>(state, 1, _data);
			data = _data.data();
			glDrawBuffers(count, data);
		}
		return 0;
	}
	/*
	DrawElements(mode, indices_table)
	DrawElements(mode, count, offset)
	*/
	int gl_DrawElements(State& state){
		const GLuint * data;
		vector<unsigned int> _data;
		size_t count=0;

		if (state.stack->is<LUA_TNUMBER>(2)){
			count = state.stack->to<int>(2);
			if (state.stack->is<LUA_TNUMBER>(3)){
				data = (GLuint *) state.stack->to<int>(3);
			}else{
				data = (GLuint *)0;
			}
		}else{
			if (state.stack->is<LUA_TTABLE>(2)){
				count = getArray<unsigned int>(state, 2, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glDrawElements(state.stack->to<int>(1), count, GL_UNSIGNED_INT, data);
		return 0;
	}
	int gl_DrawPixels(State& state){
		//__RENDER->dprintf("Stub(%s)","glDrawPixels()");
		return 0;
	}

}