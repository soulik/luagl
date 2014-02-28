#include "main.h"

namespace GLex {
	int gl_NewList(lutok::state& state){
		glNewList((GLuint) state.to_integer(1), (GLenum) state.to_integer(2));
		return 0;
	}
	int glu_NewNurbsRenderer(lutok::state& state){
		return 0;
	}
	int glu_NewQuadric(lutok::state& state){
		GLUquadric * result = gluNewQuadric();
		state.push_lightuserdata(result);
		return 1;
	}
	int glu_NewTess(lutok::state& state){
		GLUtesselator * result = gluNewTess();
		state.push_lightuserdata(result);
		return 1;
	}
	int glu_NextContour(lutok::state& state){
		return 0;
	}
	int gl_Normal3f(lutok::state& state){
		glNormal3f((GLfloat) state.to_number(1), (GLfloat) state.to_number(2), (GLfloat) state.to_number(3));
		return 0;
	}
	int gl_Normal3d(lutok::state& state){
		glNormal3d((GLdouble) state.to_number(1), (GLdouble) state.to_number(2), (GLdouble) state.to_number(3));
		return 0;
	}
	int gl_NormalPointer(lutok::state& state){
		if (state.is_number(1)){
			GLint size = 0;
			GLint nsize = state.to_integer(1);
			GLfloat * data;
			vector<float> _data;

			if (state.is_number(2)){
				data = (GLfloat *) state.to_integer(2);
			}else{
				if (state.is_table(2)){
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

	int gl_NurbsCallback(lutok::state& state){
		return 0;
	}
	int gl_NurbsCurve(lutok::state& state){
		return 0;
	}
	int gl_NurbsProperty(lutok::state& state){
		return 0;
	}
	int gl_NurbsSurface(lutok::state& state){
		return 0;
	}

}