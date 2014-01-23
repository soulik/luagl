#include "main.h"

namespace GLex {
	int gl_Ortho(lutok::state& state){
		glOrtho(
			(GLdouble) state.to_number(1),
			(GLdouble) state.to_number(2),
			(GLdouble) state.to_number(3),
			(GLdouble) state.to_number(4),
			(GLdouble) state.to_number(5),
			(GLdouble) state.to_number(6));
		return 0;
	}
	int glu_Ortho2D(lutok::state& state){
		gluOrtho2D(
			(GLdouble) state.to_number(1),
			(GLdouble) state.to_number(2),
			(GLdouble) state.to_number(3),
			(GLdouble) state.to_number(4));
		return 0;
	}

}