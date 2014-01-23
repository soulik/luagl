#include "main.h"

namespace GLex {
	int glu_QuadricCallback(lutok::state& state){
		//gluQuadricCallback(
		return 0;
	}
	int glu_QuadricDrawStyle(lutok::state& state){
		gluQuadricDrawStyle((GLUquadric*) state.to_lightuserdata(1), (GLenum) state.to_integer(2));
		return 0;
	}
	int glu_QuadricNormals(lutok::state& state){
		gluQuadricNormals((GLUquadric*) state.to_lightuserdata(1), (GLenum) state.to_integer(2));
		return 0;
	}
	int glu_QuadricOrientation(lutok::state& state){
		gluQuadricOrientation((GLUquadric*) state.to_lightuserdata(1), (GLenum) state.to_integer(2));
		return 0;
	}
	int glu_QuadricTexture(lutok::state& state){
		gluQuadricTexture((GLUquadric*) state.to_lightuserdata(1), (GLboolean) state.to_integer(2));
		return 0;
	}

}