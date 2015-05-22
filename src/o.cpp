#include "main.h"

namespace LuaGL {
	int gl_Ortho(State& state){
		glOrtho(
			(GLdouble) state.stack->to<LUA_NUMBER>(1),
			(GLdouble) state.stack->to<LUA_NUMBER>(2),
			(GLdouble) state.stack->to<LUA_NUMBER>(3),
			(GLdouble) state.stack->to<LUA_NUMBER>(4),
			(GLdouble) state.stack->to<LUA_NUMBER>(5),
			(GLdouble) state.stack->to<LUA_NUMBER>(6));
		return 0;
	}
	int glu_Ortho2D(State& state){
		gluOrtho2D(
			(GLdouble) state.stack->to<LUA_NUMBER>(1),
			(GLdouble) state.stack->to<LUA_NUMBER>(2),
			(GLdouble) state.stack->to<LUA_NUMBER>(3),
			(GLdouble) state.stack->to<LUA_NUMBER>(4));
		return 0;
	}

}