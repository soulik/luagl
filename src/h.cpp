#include "main.h"

namespace LuaGL {
	int gl_Hint(State& state){
		glHint((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2));
		return 0;
	}

}