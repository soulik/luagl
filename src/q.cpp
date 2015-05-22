#include "main.h"

namespace LuaGL {
	int glu_QuadricCallback(State& state){
		//gluQuadricCallback(
		return 0;
	}
	int glu_QuadricDrawStyle(State& state){
		gluQuadricDrawStyle((GLUquadric*) state.stack->to<void*>(1), (GLenum) state.stack->to<int>(2));
		return 0;
	}
	int glu_QuadricNormals(State& state){
		gluQuadricNormals((GLUquadric*) state.stack->to<void*>(1), (GLenum) state.stack->to<int>(2));
		return 0;
	}
	int glu_QuadricOrientation(State& state){
		gluQuadricOrientation((GLUquadric*) state.stack->to<void*>(1), (GLenum) state.stack->to<int>(2));
		return 0;
	}
	int glu_QuadricTexture(State& state){
		gluQuadricTexture((GLUquadric*) state.stack->to<void*>(1), (GLboolean) state.stack->to<int>(2));
		return 0;
	}

}