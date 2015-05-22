#include "main.h"

namespace LuaGL {
	int gl_LoadIdentity(State& state){
		glLoadIdentity();
		return 0;
	}
	int gl_Lighti(State& state){
		glLighti((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2), (GLint) state.stack->to<int>(3));
		return 0;
	}
	int gl_Lightf(State& state){
		glLightf((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2), (GLfloat) state.stack->to<int>(3));
		return 0;
	}
	int gl_Lightfv(State& state){
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
		glLightfv((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2), data);
		return 0;
	}
	int gl_LightModelf(State& state){
		glLightModelf((GLenum) state.stack->to<int>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2));
		return 0;
	}
	int gl_LightModelfv(State& state){
		GLfloat param [4];
		if (state.stack->is<LUA_TTABLE>(2)){
			
			state.stack->getField(1, 2);
			state.stack->getField(2, 2);
			state.stack->getField(3, 2);
			state.stack->getField(4, 2);

			param[0] = state.stack->to<LUA_NUMBER>(-4);
			param[1] = state.stack->to<LUA_NUMBER>(-3);
			param[2] = state.stack->to<LUA_NUMBER>(-2);
			param[3] = state.stack->to<LUA_NUMBER>(-1);

			state.stack->pop(4);
		}
		glLightModelfv((GLenum) state.stack->to<int>(1), param);
		return 0;
	}
	int gl_LineStipple(State& state){
		glLineStipple((GLint) state.stack->to<int>(1), (GLushort) state.stack->to<int>(2));
		return 0;
	}
	int gl_LineWidth(State& state){
		glLineWidth((GLfloat) state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
	int gl_LinkProgram(State& state){
		glLinkProgram((GLuint) state.stack->to<int>(1));
		return 0;
	}
	int gl_ListBase(State& state){
		glListBase((GLuint) state.stack->to<int>(1));
		return 0;
	}
	int gl_LoadMatrix(State& state){
		GLdouble * data;
		vector<double> _data;

		if (state.stack->is<LUA_TTABLE>(1) && state.stack->objLen(1) >= 16){
			getArray<double>(state, 1, _data, 0, 16);
			data = _data.data();
			glLoadMatrixd((const GLdouble *) data);
		}
		return 0;
	}
	int gl_LoadTransposeMatrix(State& state){
		GLdouble * data;
		vector<double> _data;

		if (state.stack->is<LUA_TTABLE>(1) && state.stack->objLen(1) >= 16){
			getArray<double>(state, 1, _data, 0, 16);
			data = _data.data();
			glLoadTransposeMatrixd((const GLdouble *) data);
		}
		return 0;
	}
	int gl_LoadName(State& state){
		glLoadName((GLuint) state.stack->to<int>(1));
		return 0;
	}
	int glu_LoadSamplingMatrices(State& state){
		return 0;
	}
	int glu_LookAt(State& state){
		gluLookAt(
			(GLdouble) state.stack->to<LUA_NUMBER>(1),
			(GLdouble) state.stack->to<LUA_NUMBER>(2),
			(GLdouble) state.stack->to<LUA_NUMBER>(3),
			(GLdouble) state.stack->to<LUA_NUMBER>(4),
			(GLdouble) state.stack->to<LUA_NUMBER>(5),
			(GLdouble) state.stack->to<LUA_NUMBER>(6),
			(GLdouble) state.stack->to<LUA_NUMBER>(7),
			(GLdouble) state.stack->to<LUA_NUMBER>(8),
			(GLdouble) state.stack->to<LUA_NUMBER>(9));
		return 0;
	}

}