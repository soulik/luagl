#include "main.h"

namespace LuaGL {
	int gl_FeedbackBuffer(State& state){
		//__RENDER->dprintf("Stub(%s)","glFeedbackBuffer()");
		//glFeedbackBuffer((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,1));
		return 0;
	}
	int gl_Finish(State& state){
		glFinish();
		return 0;
	}
	int gl_Flush(State& state){
		glFlush();
		return 0;
	}
	int gl_Fog(State& state){
		glFogf((GLenum) state.stack->to<int>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2));
		return 0;
	}
	int gl_FogCoordPointer(State& state){
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
				glFogCoordPointer(GL_FLOAT, 0, data);
			}
		}
		return 0;
	}
	/*
		FramebufferParameter(target, name, value)
	*/
	int gl_FramebufferParameter(State& state){
		glFramebufferParameteri(
			(GLenum) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2),
			(GLint) state.stack->to<int>(3)
		);
		return 0;
	}
	/*
		FramebufferParameter(target, attachment, renderbuffer_target, renderbuffer)
	*/
	int gl_FramebufferRenderbuffer(State& state){
		glFramebufferRenderbuffer(
			(GLenum) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2),
			(GLenum) state.stack->to<int>(3),
			(GLuint) state.stack->to<int>(4)
		);
		return 0;
	}
	/*
		FramebufferTexture(target, attachment, texture, level)
	*/
	int gl_FramebufferTexture(State& state){
		glFramebufferTexture(
			(GLenum) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2),
			(GLuint) state.stack->to<int>(3),
			(GLint) state.stack->to<int>(4)
		);
		return 0;
	}
	/*
		FramebufferTexture1D(target, attachment, texture_target, texture, level)
	*/
	int gl_FramebufferTexture1D(State& state){
		glFramebufferTexture1D(
			(GLenum) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2),
			(GLenum) state.stack->to<int>(3),
			(GLuint) state.stack->to<int>(4),
			(GLint) state.stack->to<int>(5)
		);
		return 0;
	}
	/*
		FramebufferTexture2D(target, attachment, texture_target, texture, level)
	*/
	int gl_FramebufferTexture2D(State& state){
		glFramebufferTexture2D(
			(GLenum) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2),
			(GLenum) state.stack->to<int>(3),
			(GLuint) state.stack->to<int>(4),
			(GLint) state.stack->to<int>(5)
		);
		return 0;
	}
	/*
		FramebufferTexture3D(target, attachment, texture_target, texture, level, layer)
	*/
	int gl_FramebufferTexture3D(State& state){
		glFramebufferTexture3D(
			(GLenum) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2),
			(GLenum) state.stack->to<int>(3),
			(GLuint) state.stack->to<int>(4),
			(GLint) state.stack->to<int>(5),
			(GLint) state.stack->to<int>(6)
		);
		return 0;
	}
	/*
		FramebufferTextureLayer(target, attachment, texture, level, layer)
	*/
	int gl_FramebufferTextureLayer(State& state){
		glFramebufferTextureLayer(
			(GLenum) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2),
			(GLuint) state.stack->to<int>(3),
			(GLint) state.stack->to<int>(4),
			(GLint) state.stack->to<int>(5)
			);
		return 0;
	}
	int gl_FrontFace(State& state){
		glFrontFace((GLuint)state.stack->to<int>(1));
		return 0;
	}
	int gl_Frustum(State& state){
		glFrustum((GLdouble) state.stack->to<LUA_NUMBER>(1), (GLdouble) state.stack->to<LUA_NUMBER>(2), (GLdouble) state.stack->to<LUA_NUMBER>(3), (GLdouble) state.stack->to<LUA_NUMBER>(4), (GLdouble) state.stack->to<LUA_NUMBER>(5), (GLdouble) state.stack->to<LUA_NUMBER>(6));
		return 0;
	}

}