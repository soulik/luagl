#include "main.h"

namespace LuaGL {
	int gl_MatrixMode(State& state){
		glMatrixMode((GLuint) state.stack->to<int>(1));
		return 0;
	}
	int gl_Map1(State& state){
		//glMap1f(
		return 0;
	}
	int gl_Map2(State& state){
		return 0;
	}
	int gl_MapBuffer(State& state){
		void * ptr = glMapBuffer((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2));
		state.stack->push<void*>(ptr);
		return 1;
	}
	int gl_MapGrid(State& state){
		return 0;
	}
	int gl_Materialf(State& state){
		glMaterialf((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3));
		return 0;
	}

	int gl_Materialfv(State& state){
		GLfloat * data;
		vector<float> _data;

		if (state.stack->is<LUA_TNUMBER>(3)){
			data = (GLfloat *) state.stack->to<int>(3);
		}else{
			if (state.stack->is<LUA_TTABLE>(3)){
				getArray<float>(state, 3, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		glMaterialfv((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2), data);
		return 0;
	}

	int gl_MultMatrix(State& state){
		GLdouble * data;
		vector<double> _data;

		if (state.stack->is<LUA_TTABLE>(1) && state.stack->objLen(1) >= 16){
			getArray<double>(state, 1, _data, 0, 16);
			data = _data.data();
			glMultMatrixd(data);
		}

		return 0;
	}
	int gl_MultTransposeMatrix(State& state){
		GLdouble * data;
		vector<double> _data;

		if (state.stack->is<LUA_TTABLE>(1) && state.stack->objLen(1) >= 16){
			getArray<double>(state, 1, _data, 0, 16);
			data = _data.data();
			glMultTransposeMatrixd(data);
		}

		return 0;
	}
	int gl_MultitexCoord2f(State& state){
		glMultiTexCoord2f((GLenum) state.stack->to<int>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2), (GLfloat) state.stack->to<LUA_NUMBER>(2));
		return 0;
	}

}