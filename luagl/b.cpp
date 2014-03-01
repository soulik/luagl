#include "main.h"

namespace GLex {
	int gl_Begin(lutok::state& state){
		glBegin((GLuint)state.to_integer(1));
		return 0;
	}
	int gl_BeginCurve(lutok::state& state){
		//glBeginCurve(
		//__RENDER->dprintf("Stub(%s)","glBeginCurve()");
		return 0;
	}
	int gl_BeginPolygon(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glBeginPolygon()");
		return 0;
	}
	int gl_BeginSurface(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glBeginSurface()");
		return 0;
	}
	int gl_BeginTrim(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glBeginTrim()");
		return 0;
	}
	int gl_BindAttribLocation(lutok::state& state){
		GLuint shader = (GLuint) state.to_integer(1);
		GLuint index = state.to_integer(2);
		string & name = state.to_string(3);
		glBindAttribLocation(shader, index, name.c_str());
		return 0;
	}
	int gl_BindBuffer(lutok::state& state){
		GLenum target = state.to_integer(1);
		GLuint buffer = state.to_integer(2);
		glBindBuffer(target, buffer);
		return 0;
	}
	int gl_BindRenderBuffer(lutok::state& state){
		GLenum target = state.to_integer(1);
		GLuint buffer = state.to_integer(2);
		glBindRenderbuffer(target, buffer);
		return 0;
	}
	int gl_BindFrameBuffer(lutok::state& state){
		glBindFramebuffer(state.to_integer(1), state.to_integer(2));
		return 0;
	}
	int gl_BindVertexArray(lutok::state& state){
		glBindVertexArray(state.to_integer(1));
		return 0;
	}
	int gl_BindTexture(lutok::state& state){
		glBindTexture((GLuint)state.to_integer(1), (GLuint)state.to_integer(2));
		return 0;
	}
	int gl_Bitmap(lutok::state& state){
		//glBitmap(
		//__RENDER->dprintf("Stub(%s)","glBeginBitmap()");
		return 0;
	}
	int gl_BlendColor(lutok::state& state){
		glBlendColor((GLfloat)state.to_number(1),(GLfloat)state.to_number(2),(GLfloat)state.to_number(3),(GLfloat)state.to_number(4));
		return 0;
	}
	int gl_BlendFunc(lutok::state& state){
		glBlendFunc((GLuint)state.to_integer(1), (GLuint)state.to_integer(2));
		return 0;
	}
	int gl_BlendEquation(lutok::state& state){
		glBlendEquation((GLuint)state.to_integer(1));
		return 0;
	}
	/*
		BlitFramebuffer(src_X0, src_Y0, src_X1, src_Y1, dest_X0, dest_Y0, dest_X1, dest_Y1, mask, filter)
	*/
	int gl_BlitFramebuffer (lutok::state& state){
		glBlitFramebuffer(
			(GLint) state.to_integer(1),
			(GLint) state.to_integer(2),
			(GLint) state.to_integer(3),
			(GLint) state.to_integer(4),
			(GLint) state.to_integer(5),
			(GLint) state.to_integer(6),
			(GLint) state.to_integer(7),
			(GLint) state.to_integer(8),
			(GLbitfield) state.to_integer(9),
			(GLenum) state.to_integer(10)
		);
		return 0;
	}
	int gl_BufferData(lutok::state& state){
		GLenum target = state.to_integer(1);
		GLsizei size = 0;

		GLfloat * data;
		vector<float> _data;

		if (state.is_number(2)){
			size = (GLsizei) state.to_integer(2);
			data = NULL;
		}else{
			if (state.is_table(2)){
				size = getArray<float>(state, 2, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		GLenum usage = state.to_integer(3);
		GLsizeiptr data_size = size * sizeof(GLfloat);
		glBufferData(target, data_size, data, usage);
		return 0;
	}

	int gl_BufferSubData(lutok::state& state){
		GLenum target = state.to_integer(1);
		GLint offset = state.to_integer(2);
		GLsizei size = 0;
		GLfloat * data;
		vector<float> _data;

		if (state.is_number(3)){
			data = (GLfloat *) state.to_integer(3);
		}else{
			if (state.is_table(3)){
				size = getArray<float>(state, 3, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		GLintptr data_offset = offset * sizeof(GLfloat);
		GLsizeiptr data_size = size * sizeof(GLfloat);
		glBufferSubData(target, data_offset, data_size, data);
		return 0;
	}
	int glu_Build1DMipmaps(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glBuild1DMipmaps()");
		return 0;
	}
	int glu_Build2DMipmaps(lutok::state& state){
		int ret = gluBuild2DMipmaps(
			(GLenum)state.to_integer(1),
			(GLint)state.to_integer(2),
			(GLint)state.to_integer(3),
			(GLint)state.to_integer(4),
			(GLenum)state.to_integer(5),
			(GLenum)state.to_integer(6),
			(const void*)state.to_userdata<void>(7)
		);
		state.push_integer(ret);
		return 1;
	}

}