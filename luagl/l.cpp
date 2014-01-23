#include "main.h"

namespace GLex {
	int gl_LoadIdentity(lutok::state& state){
		glLoadIdentity();
		return 0;
	}
	int gl_Lighti(lutok::state& state){
		glLighti((GLenum) state.to_integer(1), (GLenum) state.to_integer(2), (GLint) state.to_integer(3));
		return 0;
	}
	int gl_Lightf(lutok::state& state){
		glLightf((GLenum) state.to_integer(1), (GLenum) state.to_integer(2), (GLfloat) state.to_integer(3));
		return 0;
	}
	int gl_Lightfv(lutok::state& state){
		GLfloat * data;
		vector<float> _data;

		if (state.is_number(3)){
			data = (GLfloat *) state.to_integer(3);
		}else{
			if (state.is_table(3)){
				getArray<float>(state, 3, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glLightfv((GLenum) state.to_integer(1), (GLenum) state.to_integer(2), data);
		return 0;
	}
	int gl_LightModelf(lutok::state& state){
		glLightModelf((GLenum) state.to_integer(1), (GLfloat) state.to_number(2));
		return 0;
	}
	int gl_LightModelfv(lutok::state& state){
		GLfloat param [4];
		if (state.is_table(2)){
			param[0] = state.get_array<float>(2, 1);
			param[1] = state.get_array<float>(2, 2);
			param[2] = state.get_array<float>(2, 3);
			param[3] = state.get_array<float>(2, 4);
		}
		glLightModelfv((GLenum) state.to_integer(1), param);
		return 0;
	}
	int gl_LineStipple(lutok::state& state){
		glLineStipple((GLint) state.to_integer(1), (GLushort) state.to_integer(2));
		return 0;
	}
	int gl_LineWidth(lutok::state& state){
		glLineWidth((GLfloat) state.to_number(1));
		return 0;
	}
	int gl_LinkProgram(lutok::state& state){
		glLinkProgram((GLuint) state.to_integer(1));
		return 0;
	}
	int gl_ListBase(lutok::state& state){
		glListBase((GLuint) state.to_integer(1));
		return 0;
	}
	int gl_LoadMatrix(lutok::state& state){
		GLdouble * data;
		vector<double> _data;

		if (state.is_number(3)){
			data = (GLdouble *) state.to_integer(3);
		}else{
			if (state.is_table(3)){
				getArray<double>(state, 3, _data, 0, 16);
				data = _data.data();
			}else{
				data = NULL;
			}
		}

		glLoadMatrixd((const GLdouble *) data);
		return 0;
	}
	int gl_LoadName(lutok::state& state){
		glLoadName((GLuint) state.to_integer(1));
		return 0;
	}
	int glu_LoadSamplingMatrices(lutok::state& state){
		return 0;
	}
	int glu_LookAt(lutok::state& state){
		gluLookAt(
			(GLdouble) state.to_number(1),
			(GLdouble) state.to_number(2),
			(GLdouble) state.to_number(3),
			(GLdouble) state.to_number(4),
			(GLdouble) state.to_number(5),
			(GLdouble) state.to_number(6),
			(GLdouble) state.to_number(7),
			(GLdouble) state.to_number(8),
			(GLdouble) state.to_number(9));
		return 0;
	}

}