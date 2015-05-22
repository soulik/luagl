#include "main.h"

namespace LuaGL {
	int gl_Begin(State& state){
		glBegin((GLuint)state.stack->to<int>(1));
		return 0;
	}
	int gl_BeginConditionalRender(State& state){
		glBeginConditionalRender(
			(GLuint) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2)
			);
		return 0;
	}
	int gl_BeginQuery(State& state){
		glBeginQuery(
			(GLenum) state.stack->to<int>(1),
			(GLuint) state.stack->to<int>(2)
			);
		return 0;
	}
	int gl_BeginCurve(State& state){
		//glBeginCurve(
		//__RENDER->dprintf("Stub(%s)","glBeginCurve()");
		return 0;
	}
	int gl_BeginPolygon(State& state){
		//__RENDER->dprintf("Stub(%s)","glBeginPolygon()");
		return 0;
	}
	int gl_BeginSurface(State& state){
		//__RENDER->dprintf("Stub(%s)","glBeginSurface()");
		return 0;
	}
	int gl_BeginTrim(State& state){
		//__RENDER->dprintf("Stub(%s)","glBeginTrim()");
		return 0;
	}
	int gl_BindAttribLocation(State& state){
		GLuint shader = (GLuint) state.stack->to<int>(1);
		GLuint index = state.stack->to<int>(2);
		const string name = state.stack->to<const string>(3);
		glBindAttribLocation(shader, index, name.c_str());
		return 0;
	}
	int gl_BindFragDataLocation(State& state){
		GLuint program = (GLuint) state.stack->to<int>(1);
		GLuint colorNumber = state.stack->to<int>(2);
		const string name = state.stack->to<const string>(3);
		glBindFragDataLocation(program, colorNumber, name.c_str());
		return 0;
	}
	int gl_BindFragDataLocationIndexed(State& state){
		GLuint program = (GLuint) state.stack->to<int>(1);
		GLuint colorNumber = state.stack->to<int>(2);
		GLuint index = state.stack->to<LUA_NUMBER>(3);
		const string name = state.stack->to<const string>(4);
		glBindFragDataLocationIndexed(program, colorNumber, index, name.c_str());
		return 0;
	}
	int gl_BindBuffer(State& state){
		GLenum target = state.stack->to<int>(1);
		GLuint buffer = state.stack->to<int>(2);
		glBindBuffer(target, buffer);
		return 0;
	}
	int gl_BindRenderBuffer(State& state){
		GLenum target = state.stack->to<int>(1);
		GLuint buffer = state.stack->to<int>(2);
		glBindRenderbuffer(target, buffer);
		return 0;
	}
	int gl_BindFrameBuffer(State& state){
		glBindFramebuffer(state.stack->to<int>(1), state.stack->to<int>(2));
		return 0;
	}
	int gl_BindVertexArray(State& state){
		glBindVertexArray(state.stack->to<int>(1));
		return 0;
	}
	int gl_BindTexture(State& state){
		glBindTexture((GLuint)state.stack->to<int>(1), (GLuint)state.stack->to<int>(2));
		return 0;
	}
	int gl_Bitmap(State& state){
		//glBitmap(
		//__RENDER->dprintf("Stub(%s)","glBeginBitmap()");
		return 0;
	}
	int gl_BlendColor(State& state){
		glBlendColor((GLfloat)state.stack->to<LUA_NUMBER>(1),(GLfloat)state.stack->to<LUA_NUMBER>(2),(GLfloat)state.stack->to<LUA_NUMBER>(3),(GLfloat)state.stack->to<LUA_NUMBER>(4));
		return 0;
	}
	int gl_BlendFunc(State& state){
		glBlendFunc((GLuint)state.stack->to<int>(1), (GLuint)state.stack->to<int>(2));
		return 0;
	}
	int gl_BlendEquation(State& state){
		glBlendEquation((GLuint)state.stack->to<int>(1));
		return 0;
	}
	/*
		BlitFramebuffer(src_X0, src_Y0, src_X1, src_Y1, dest_X0, dest_Y0, dest_X1, dest_Y1, mask, filter)
	*/
	int gl_BlitFramebuffer (State& state){
		glBlitFramebuffer(
			(GLint) state.stack->to<int>(1),
			(GLint) state.stack->to<int>(2),
			(GLint) state.stack->to<int>(3),
			(GLint) state.stack->to<int>(4),
			(GLint) state.stack->to<int>(5),
			(GLint) state.stack->to<int>(6),
			(GLint) state.stack->to<int>(7),
			(GLint) state.stack->to<int>(8),
			(GLbitfield) state.stack->to<int>(9),
			(GLenum) state.stack->to<int>(10)
		);
		return 0;
	}

	int glu_Build1DMipmaps(State& state){
		//__RENDER->dprintf("Stub(%s)","glBuild1DMipmaps()");
		return 0;
	}
	int glu_Build2DMipmaps(State& state){
		int ret = gluBuild2DMipmaps(
			(GLenum)state.stack->to<int>(1),
			(GLint)state.stack->to<int>(2),
			(GLint)state.stack->to<int>(3),
			(GLint)state.stack->to<int>(4),
			(GLenum)state.stack->to<int>(5),
			(GLenum)state.stack->to<int>(6),
			(const void*)state.stack->to<void*>(7)
		);
		state.stack->push<int>(ret);
		return 1;
	}

}