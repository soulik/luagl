#include "main.h"

namespace GLex {
	int gl_MatrixMode(lutok::state& state){
		glMatrixMode((GLuint) state.to_integer(1));
		return 0;
	}
	int gl_Map1(lutok::state& state){
		//glMap1f(
		return 0;
	}
	int gl_Map2(lutok::state& state){
		return 0;
	}
	int gl_MapBuffer(lutok::state& state){
		void * ptr = glMapBuffer((GLenum) state.to_integer(1), (GLenum) state.to_integer(2));
		state.push_lightuserdata(ptr);
		return 1;
	}
	int gl_MapGrid(lutok::state& state){
		return 0;
	}
	int gl_Materialf(lutok::state& state){
		glMaterialf((GLenum) state.to_integer(1), (GLenum) state.to_integer(2), (GLfloat) state.to_number(3));
		return 0;
	}

	int gl_Materialfv(lutok::state& state){
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
		glMaterialfv((GLenum) state.to_integer(1), (GLenum) state.to_integer(2), data);
		return 0;
	}

	int gl_MultMatrix(lutok::state& state){
		GLdouble * data;
		vector<double> _data;

		if (state.is_table(1) && state.obj_len(1) >= 16){
			getArray<double>(state, 1, _data, 0, 16);
			data = _data.data();
			glMultMatrixd(data);
		}

		return 0;
	}
	int gl_MultTransposeMatrix(lutok::state& state){
		GLdouble * data;
		vector<double> _data;

		if (state.is_table(1) && state.obj_len(1) >= 16){
			getArray<double>(state, 1, _data, 0, 16);
			data = _data.data();
			glMultTransposeMatrixd(data);
		}

		return 0;
	}
	int gl_MultitexCoord2f(lutok::state& state){
		glMultiTexCoord2f((GLenum) state.to_integer(1), (GLfloat) state.to_number(2), (GLfloat) state.to_number(2));
		return 0;
	}

}