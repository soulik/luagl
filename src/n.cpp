#include "main.h"

namespace LuaGL {
	int gl_NewList(State& state){
		glNewList((GLuint) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2));
		return 0;
	}
	int glu_NewNurbsRenderer(State& state){
		return 0;
	}
	int glu_NewQuadric(State& state){
		GLUquadric * result = gluNewQuadric();
		state.stack->push<void*>(result);
		return 1;
	}
	int glu_NewTess(State& state){
		GLUtesselator * result = gluNewTess();
		state.stack->push<void*>(result);
		return 1;
	}
	int glu_NextContour(State& state){
		return 0;
	}
	int gl_Normal3f(State& state){
		glNormal3f((GLfloat) state.stack->to<LUA_NUMBER>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3));
		return 0;
	}
	int gl_Normal3d(State& state){
		glNormal3d((GLdouble) state.stack->to<LUA_NUMBER>(1), (GLdouble) state.stack->to<LUA_NUMBER>(2), (GLdouble) state.stack->to<LUA_NUMBER>(3));
		return 0;
	}
	int gl_NormalPointer(State& state){
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
				glNormalPointer(GL_FLOAT, 0, data);
			}
		}
		return 0;
	}

	int gl_NurbsCallback(State& state){
		return 0;
	}
	int gl_NurbsCurve(State& state){
		return 0;
	}
	int gl_NurbsProperty(State& state){
		return 0;
	}
	int gl_NurbsSurface(State& state){
		return 0;
	}

}