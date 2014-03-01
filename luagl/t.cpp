#include "main.h"

namespace GLex {
	int gl_TexCoord2f(lutok::state& state){
		glTexCoord2f((GLfloat) state.to_number(1), (GLfloat) state.to_number(2));
		return 0;
	}
	int gl_TexCoord3f(lutok::state& state){
		glTexCoord3f((GLfloat) state.to_number(1), (GLfloat) state.to_number(2), (GLfloat) state.to_number(3));
		return 0;
	}
	int gl_TexParameteri(lutok::state& state){
		glTexParameteri((GLuint) state.to_integer(1), (GLuint) state.to_integer(2), (GLint) state.to_integer(3));
		return 0;
	}
	int gl_Translatef(lutok::state& state){
		glTranslatef((GLfloat) state.to_number(1), (GLfloat) state.to_number(2), (GLfloat) state.to_number(3));
		return 0;
	}
	int glu_TessBeginContour(lutok::state& state){
		return 0;
	}
	int glu_TessBeginPolygon(lutok::state& state){
		return 0;
	}
	int glu_TessCallback(lutok::state& state){
		return 0;
	}
	int glu_TessEndPolygon(lutok::state& state){
		return 0;
	}
	int glu_TessNormal(lutok::state& state){
		return 0;
	}
	int glu_TessProperty(lutok::state& state){
		return 0;
	}
	int glu_TessVertex(lutok::state& state){
		return 0;
	}
	int gl_TexCoordPointer(lutok::state& state){
		if (state.is_number(1)){
			size_t size = 0;
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
				glTexCoordPointer((GLint) nsize, (GLenum) GL_FLOAT, (GLsizei) 0, (GLvoid*) data);
			}
		}
		return 0;
	}
	int gl_TexEnvi(lutok::state& state){
		glTexEnvi((GLenum) state.to_integer(1), (GLenum) state.to_integer(2),(GLint) state.to_integer(3));
		return 0;
	}

	int gl_TexEnvf(lutok::state& state){
		glTexEnvf((GLenum) state.to_integer(1), (GLenum) state.to_integer(2), (GLfloat) state.to_number(3));
		return 0;
	}

	int gl_TexGen(lutok::state& state){
		//glTexGen(
		return 0;
	}
	/*
		TexImage1D(target, level, internal_format, width, border, format, type, pixels)
	*/
	int gl_TexImage1D(lutok::state& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.is_userdata(7)){
			data = (unsigned char *) state.to_lightuserdata(7);
		}else{
			if (state.is_table(7)){
				size = getArray<unsigned char>(state, 7, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexImage1D(
			(GLenum) state.to_integer(1),
			(GLint) state.to_integer(2),
			(GLint) state.to_integer(3),
			(GLsizei) state.to_integer(4),
			(GLint) state.to_integer(5),
			(GLenum) state.to_integer(6),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
		);
		return 0;
	}
	/*
		TexImage2D(target, level, internal_format, width, height, border, format, type, pixels)
	*/
	int gl_TexImage2D(lutok::state& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.is_userdata(8)){
			data = (unsigned char *) state.to_lightuserdata(8);
		}else{
			if (state.is_table(8)){
				size = getArray<unsigned char>(state, 8, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexImage2D(
			(GLenum) state.to_integer(1),
			(GLint) state.to_integer(2),
			(GLint) state.to_integer(3),
			(GLsizei) state.to_integer(4),
			(GLsizei) state.to_integer(5),
			(GLint) state.to_integer(6),
			(GLenum) state.to_integer(7),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
			);
		return 0;
	}
	/*
		TexImage3D(target, level, internal_format, width, height, depth, border, format, type, pixels)
	*/
	int gl_TexImage3D(lutok::state& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.is_userdata(9)){
			data = (unsigned char *) state.to_lightuserdata(9);
		}else{
			if (state.is_table(9)){
				size = getArray<unsigned char>(state, 9, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexImage3D(
			(GLenum) state.to_integer(1),
			(GLint) state.to_integer(2),
			(GLint) state.to_integer(3),
			(GLsizei) state.to_integer(4),
			(GLsizei) state.to_integer(5),
			(GLsizei) state.to_integer(6),
			(GLint) state.to_integer(7),
			(GLenum) state.to_integer(8),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
		);
		return 0;
	}
	int gl_TexParameter(lutok::state& state){
		GLenum target = state.to_integer(1);
		GLenum pname = state.to_integer(2);
		//if forth parameter is true, consider that the value is integer
		if (state.is_boolean(4) && state.to_boolean(4)){
			GLint value = state.to_integer(3);
			glTexParameteri(target, pname, value);

		}else{
			GLfloat value = (GLfloat) state.to_number(3);
			glTexParameterf(target, pname, value);
		}
		return 0;
	}
	int gl_TexSubImage1D(lutok::state& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.is_userdata(6)){
			data = (unsigned char *) state.to_lightuserdata(6);
		}else{
			if (state.is_table(6)){
				size = getArray<unsigned char>(state, 6, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexSubImage1D(
			(GLenum) state.to_integer(1),
			(GLint) state.to_integer(2),
			(GLint) state.to_integer(3),
			(GLsizei) state.to_integer(4),
			(GLenum) state.to_integer(5),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
			);
		return 0;
	}
	int gl_TexSubImage2D(lutok::state& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.is_userdata(8)){
			data = (unsigned char *) state.to_lightuserdata(8);
		}else{
			if (state.is_table(8)){
				size = getArray<unsigned char>(state, 8, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexSubImage2D(
			(GLenum) state.to_integer(1),
			(GLint) state.to_integer(2),
			(GLint) state.to_integer(3),
			(GLint) state.to_integer(4),
			(GLsizei) state.to_integer(5),
			(GLsizei) state.to_integer(6),
			(GLint) state.to_integer(7),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
			);
		return 0;
	}
	int gl_TexSubImage3D(lutok::state& state){
		size_t size = 0;
		unsigned char * data;
		vector<unsigned char> _data;

		if (state.is_userdata(10)){
			data = (unsigned char *) state.to_lightuserdata(10);
		}else{
			if (state.is_table(10)){
				size = getArray<unsigned char>(state, 10, _data);
				data = _data.data();
			}else{
				data = nullptr;
			}
		}

		glTexSubImage3D(
			(GLenum) state.to_integer(1),
			(GLint) state.to_integer(2),
			(GLint) state.to_integer(3),
			(GLint) state.to_integer(4),
			(GLint) state.to_integer(5),
			(GLsizei) state.to_integer(6),
			(GLsizei) state.to_integer(7),
			(GLsizei) state.to_integer(8),
			(GLenum) state.to_integer(9),
			(GLenum) GL_UNSIGNED_BYTE,
			(GLvoid*) data
			);
		return 0;
	}

	int gl_TexBuffer(lutok::state& state){
		glTexBuffer(
			(GLenum) state.to_integer(1),
			(GLenum) state.to_integer(2),
			(GLuint) state.to_integer(3)
		);
		return 0;
	}
	int gl_TexBufferRange(lutok::state& state){
		glTexBufferRange(
			(GLenum) state.to_integer(1),
			(GLenum) state.to_integer(2),
			(GLuint) state.to_integer(3),
			(GLintptr) state.to_integer(4),
			(GLsizeiptr) state.to_integer(5)
		);
		return 0;
	}

}