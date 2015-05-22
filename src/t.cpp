#include "main.h"

namespace LuaGL {
	int gl_TexCoord2f(State& state){
		glTexCoord2f((GLfloat) state.stack->to<LUA_NUMBER>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2));
		return 0;
	}
	int gl_TexCoord3f(State& state){
		glTexCoord3f((GLfloat) state.stack->to<LUA_NUMBER>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3));
		return 0;
	}
	int gl_TexParameteri(State& state){
		glTexParameteri((GLuint) state.stack->to<int>(1), (GLuint) state.stack->to<int>(2), (GLint) state.stack->to<int>(3));
		return 0;
	}
	int gl_Translatef(State& state){
		glTranslatef((GLfloat) state.stack->to<LUA_NUMBER>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3));
		return 0;
	}
	int glu_TessBeginContour(State& state){
		return 0;
	}
	int glu_TessBeginPolygon(State& state){
		return 0;
	}
	int glu_TessCallback(State& state){
		return 0;
	}
	int glu_TessEndPolygon(State& state){
		return 0;
	}
	int glu_TessNormal(State& state){
		return 0;
	}
	int glu_TessProperty(State& state){
		return 0;
	}
	int glu_TessVertex(State& state){
		return 0;
	}
	int gl_TexCoordPointer(State& state){
		if (state.stack->is<LUA_TNUMBER>(1)){
			size_t size = 0;
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
				glTexCoordPointer((GLint) nsize, (GLenum) GL_FLOAT, (GLsizei) 0, (GLvoid*) data);
			}
		}
		return 0;
	}
	int gl_TexEnvi(State& state){
		glTexEnvi((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2),(GLint) state.stack->to<int>(3));
		return 0;
	}

	int gl_TexEnvf(State& state){
		glTexEnvf((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3));
		return 0;
	}

	int gl_TexGen(State& state){
		//glTexGen(
		return 0;
	}
	/*
		TexImage1D(target, level, internal_format, width, border, format, type, pixels)
	*/
	int gl_TexImage1D(State& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.stack->is<LUA_TUSERDATA>(7)){
			data = (unsigned char *) state.stack->to<void*>(7);
		}else{
			if (state.stack->is<LUA_TTABLE>(7)){
				size = getArray<unsigned char>(state, 7, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexImage1D(
			(GLenum) state.stack->to<int>(1),
			(GLint) state.stack->to<int>(2),
			(GLint) state.stack->to<int>(3),
			(GLsizei) state.stack->to<int>(4),
			(GLint) state.stack->to<int>(5),
			(GLenum) state.stack->to<int>(6),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
		);
		return 0;
	}
	/*
		TexImage2D(target, level, internal_format, width, height, border, format, type, pixels)
	*/
	int gl_TexImage2D(State& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.stack->is<LUA_TUSERDATA>(8)){
			data = (unsigned char *) state.stack->to<void*>(8);
		}else{
			if (state.stack->is<LUA_TTABLE>(8)){
				size = getArray<unsigned char>(state, 8, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexImage2D(
			(GLenum) state.stack->to<int>(1),
			(GLint) state.stack->to<int>(2),
			(GLint) state.stack->to<int>(3),
			(GLsizei) state.stack->to<int>(4),
			(GLsizei) state.stack->to<int>(5),
			(GLint) state.stack->to<int>(6),
			(GLenum) state.stack->to<int>(7),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
			);
		return 0;
	}
	/*
		TexImage3D(target, level, internal_format, width, height, depth, border, format, type, pixels)
	*/
	int gl_TexImage3D(State& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.stack->is<LUA_TUSERDATA>(9)){
			data = (unsigned char *) state.stack->to<void*>(9);
		}else{
			if (state.stack->is<LUA_TTABLE>(9)){
				size = getArray<unsigned char>(state, 9, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexImage3D(
			(GLenum) state.stack->to<int>(1),
			(GLint) state.stack->to<int>(2),
			(GLint) state.stack->to<int>(3),
			(GLsizei) state.stack->to<int>(4),
			(GLsizei) state.stack->to<int>(5),
			(GLsizei) state.stack->to<int>(6),
			(GLint) state.stack->to<int>(7),
			(GLenum) state.stack->to<int>(8),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
		);
		return 0;
	}
	int gl_TexParameter(State& state){
		GLenum target = state.stack->to<int>(1);
		GLenum pname = state.stack->to<int>(2);
		//if forth parameter is true, consider that the value is integer
		if (state.stack->is<LUA_TBOOLEAN>(4) && state.stack->to<bool>(4)){
			GLint value = state.stack->to<int>(3);
			glTexParameteri(target, pname, value);

		}else{
			GLfloat value = (GLfloat) state.stack->to<LUA_NUMBER>(3);
			glTexParameterf(target, pname, value);
		}
		return 0;
	}
	int gl_TexSubImage1D(State& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.stack->is<LUA_TUSERDATA>(6)){
			data = (unsigned char *) state.stack->to<void*>(6);
		}else{
			if (state.stack->is<LUA_TTABLE>(6)){
				size = getArray<unsigned char>(state, 6, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexSubImage1D(
			(GLenum) state.stack->to<int>(1),
			(GLint) state.stack->to<int>(2),
			(GLint) state.stack->to<int>(3),
			(GLsizei) state.stack->to<int>(4),
			(GLenum) state.stack->to<int>(5),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
			);
		return 0;
	}
	int gl_TexSubImage2D(State& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.stack->is<LUA_TUSERDATA>(8)){
			data = (unsigned char *) state.stack->to<void*>(8);
		}else{
			if (state.stack->is<LUA_TTABLE>(8)){
				size = getArray<unsigned char>(state, 8, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexSubImage2D(
			(GLenum) state.stack->to<int>(1),
			(GLint) state.stack->to<int>(2),
			(GLint) state.stack->to<int>(3),
			(GLint) state.stack->to<int>(4),
			(GLsizei) state.stack->to<int>(5),
			(GLsizei) state.stack->to<int>(6),
			(GLint) state.stack->to<int>(7),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
			);
		return 0;
	}
	int gl_TexSubImage3D(State& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.stack->is<LUA_TUSERDATA>(10)){
			data = (unsigned char *) state.stack->to<void*>(10);
		}else{
			if (state.stack->is<LUA_TTABLE>(10)){
				size = getArray<unsigned char>(state, 10, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexSubImage3D(
			(GLenum) state.stack->to<int>(1),
			(GLint) state.stack->to<int>(2),
			(GLint) state.stack->to<int>(3),
			(GLint) state.stack->to<int>(4),
			(GLint) state.stack->to<int>(5),
			(GLsizei) state.stack->to<int>(6),
			(GLsizei) state.stack->to<int>(7),
			(GLsizei) state.stack->to<int>(8),
			(GLenum) state.stack->to<int>(9),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
			);
		return 0;
	}

	int gl_TexBuffer(State& state){
		glTexBuffer(
			(GLenum) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2),
			(GLuint) state.stack->to<int>(3)
		);
		return 0;
	}
	int gl_TexBufferRange(State& state){
		glTexBufferRange(
			(GLenum) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2),
			(GLuint) state.stack->to<int>(3),
			(GLintptr) state.stack->to<int>(4),
			(GLsizeiptr) state.stack->to<int>(5)
		);
		return 0;
	}

}