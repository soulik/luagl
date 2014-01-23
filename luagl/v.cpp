#include "main.h"

namespace GLex {
	int gl_Vertex2f(lutok::state& state){
		glVertex2f((GLfloat) state.to_number(1), (GLfloat) state.to_number(2));
		return 0;
	}
	int gl_Vertex2i(lutok::state& state){
		glVertex2i((GLint) state.to_integer(1), (GLint) state.to_integer(2));
		return 0;
	}
	int gl_Vertex3f(lutok::state& state){
		glVertex3f((GLfloat) state.to_number(1), (GLfloat) state.to_number(2), (GLfloat) state.to_number(3));
		return 0;
	}
	int gl_VertexPointer(lutok::state& state){
		GLint size = 0;
		GLdouble * data;
		vector<double> _data;

		if (state.is_number(1)){
			data = (GLdouble *) state.to_integer(1);
		}else{
			if (state.is_table(1)){
				size = getArray<double>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glVertexPointer(size, GL_DOUBLE, 0, data);
		return 0;
	}

	int gl_Viewport(lutok::state& state){
		glViewport((GLuint) state.to_integer(1), (GLuint) state.to_integer(2), (GLuint) state.to_integer(3), (GLuint) state.to_integer(4));
		return 0;
	}
	int gl_VertexAttribd(lutok::state& state){
		int argc = state.get_top();
		switch (argc){
		case 5:
			glVertexAttrib4d((GLint) state.to_integer(1), (GLdouble) state.to_number(2), (GLdouble) state.to_number(3), (GLdouble) state.to_number(4), (GLdouble) state.to_number(5));
			break;
		case 4:
			glVertexAttrib3d((GLint) state.to_integer(1), (GLdouble) state.to_number(2), (GLdouble) state.to_number(3), (GLdouble) state.to_number(4));
			break;
		case 3:
			glVertexAttrib2d((GLint) state.to_integer(1), (GLdouble) state.to_number(2), (GLdouble) state.to_number(3));
			break;
		case 2:
			glVertexAttrib1d((GLint) state.to_integer(1), (GLdouble) state.to_number(2));
			break;
		default:
			break;
		}
		return 0;
	}

	int gl_VertexAttribs(lutok::state& state){
		int argc = state.get_top();
		switch (argc){
		case 5:
			glVertexAttrib4s((GLint) state.to_integer(1), (GLshort) state.to_integer(2), (GLshort) state.to_integer(3), (GLshort) state.to_integer(4), (GLshort) state.to_integer(5));
			break;
		case 4:
			glVertexAttrib3s((GLint) state.to_integer(1), (GLshort) state.to_integer(2), (GLshort) state.to_integer(3), (GLshort) state.to_integer(4));
			break;
		case 3:
			glVertexAttrib2s((GLint) state.to_integer(1), (GLshort) state.to_integer(2), (GLshort) state.to_integer(3));
			break;
		case 2:
			glVertexAttrib1s((GLint) state.to_integer(1), (GLshort) state.to_integer(2));
			break;
		default:
			break;
		}
		return 0;
	}

	/*
		vertexAttribPointer(index, size, normalized, stride, type)
		vertexAttribPointer(index, table, normalized, stride, type)
	*/
	int gl_VertexAttribPointer(lutok::state& state){
		GLint size = 0;
		GLfloat * data;
		vector<float> _data;
		GLsizei stride = 0;
		GLenum type = GL_FLOAT;

		if (state.is_number(2)){
			data = NULL;
			size = state.to_integer(2);
		}else{
			if (state.is_table(2)){
				size = getArray<float>(state, 2, _data);
				if (size>4){
					size = 4;
				}
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		if (state.is_number(4)){
			stride = state.to_integer(4);
		}
		if (state.is_number(5)){
			type = state.to_integer(5);
		}
		glVertexAttribPointer(
			(GLuint) state.to_integer(1),
			(GLint) size,
			(GLenum) type,
			(GLboolean) state.to_boolean(3),
			(GLsizei) stride,
			(GLvoid*) data);
		return 0;
	}

}