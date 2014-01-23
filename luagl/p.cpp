#include "main.h"

namespace GLex {
	int glu_PartialDisk(lutok::state& state){
		gluPartialDisk(
			(GLUquadric*) state.to_lightuserdata(1),
			(GLdouble) state.to_number(2),
			(GLdouble) state.to_number(3),
			(GLint) state.to_integer(4),
			(GLint) state.to_integer(5),
			(GLdouble) state.to_number(6),
			(GLdouble) state.to_number(7)
		);
		return 0;
	}
	int gl_PassThrough(lutok::state& state){
		glPassThrough((GLfloat) state.to_number(1));
		return 0;
	}
	int glu_Perspective(lutok::state& state){
		gluPerspective(
			(GLdouble) state.to_number(1),
			(GLdouble) state.to_number(2),
			(GLdouble) state.to_number(3),
			(GLdouble) state.to_number(4)
		);
		return 0;
	}
	int glu_PickMatrix(lutok::state& state){
		//gluPickMatrix(
		return 0;
	}
	int gl_PixelMap(lutok::state& state){
		return 0;
	}
	int gl_PixelStore(lutok::state& state){
		//glPixelStore(
		return 0;
	}
	int gl_PixelTransfer(lutok::state& state){
		//glPixelTransfer(
		return 0;
	}
	int gl_PixelZoom(lutok::state& state){
		glPixelZoom((GLfloat) state.to_number(1), (GLfloat) state.to_number(2));
		return 0;
	}
	int gl_PointSize(lutok::state& state){
		glPointSize((GLfloat) state.to_number(1));
		return 0;
	}
	int gl_PolygonMode(lutok::state& state){
		glPolygonMode((GLenum) state.to_integer(1), (GLenum) state.to_integer(2));
		return 0;
	}
	int gl_PolygonOffset(lutok::state& state){
		glPolygonOffset((GLfloat) state.to_number(1), (GLfloat) state.to_number(2));
		return 0;
	}
	int gl_PolygonStipple(lutok::state& state){
		//glPolygonStipple(
		return 0;
	}
	int gl_PrioritizeTextures(lutok::state& state){
		//glPrioritizeTextures(
		return 0;
	}
	int glu_Project(lutok::state& state){
		//gluProject(
		return 0;
	}
	int gl_PopAttrib(lutok::state& state){
		glPopAttrib();
		return 0;
	}
	int gl_PopClientAttrib(lutok::state& state){
		glPopClientAttrib();
		return 0;
	}
	int gl_PopMatrix(lutok::state& state){
		glPopMatrix();
		return 0;
	}
	int gl_PopName(lutok::state& state){
		glPopName();
		return 0;
	}

	int gl_PushAttrib(lutok::state& state){
		glPushAttrib((GLbitfield) state.to_number(1));
		return 0;
	}
	int gl_PushClientAttrib(lutok::state& state){
		glPushClientAttrib((GLbitfield) state.to_number(1));
		return 0;
	}
	int gl_PushMatrix(lutok::state& state){
		glPushMatrix();
		return 0;
	}
	int gl_PushName(lutok::state& state){
		glPushName((GLuint) state.to_number(1));
		return 0;
	}
	int glu_PwlCurve(lutok::state& state){
		//gluPwlCurve(
		return 0;
	}

}