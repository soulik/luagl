#include "main.h"

namespace GLex {
	int gl_Hint(lutok::state& state){
		glHint((GLenum) state.to_integer(1), (GLenum) state.to_integer(2));
		return 0;
	}

}