#include "main.h"

namespace GLex {
	int gl_Scalef(lutok::state& state){
		glScalef((GLfloat) state.to_number(1), (GLfloat) state.to_number(2), (GLfloat) state.to_number(3));
		return 0;
	}
	int glu_ScaleImage(lutok::state& state){
		//gluScaleImage(
		return 0;
	}
	int gl_Scissor(lutok::state& state){
		glScissor((GLint) state.to_integer(1), (GLint) state.to_integer(2), (GLsizei) state.to_integer(3), (GLsizei) state.to_integer(4));
		return 0;
	}
	int gl_SelectBuffer(lutok::state& state){
		size_t maxElements = state.to_integer(1);
		unsigned int * data = new unsigned int[maxElements];
		glSelectBuffer(maxElements, (GLuint *) data);
		setArray<unsigned int>(state, data, maxElements);
		delete[] data;
		return 1;
	}
	int gl_ShadeModel(lutok::state& state){
		glShadeModel((GLenum) state.to_integer(1));
		return 0;
	}
	int gl_ShaderSource(lutok::state& state){
		if (state.is_string(2)){
			const std::string & shader_source = state.to_string(2);
			const char * src_lines = {shader_source.c_str()};
			glShaderSource((GLuint) state.to_integer(1), 1, (const char **) & src_lines, NULL);
		}else if(state.is_table(2)){
			std::vector<string> lines;
			size_t lines_count = getArray<string>(state, 2, lines);
			const char ** src_lines = new const char * [lines_count];
			for (size_t i=0; i<lines_count; i++){
				src_lines[i] = lines[i].c_str();
			}
			glShaderSource((GLuint) state.to_integer(1), lines_count, src_lines, NULL);
			delete[] src_lines;
		}
		return 0;
	}

	int glu_Sphere(lutok::state& state){
		gluSphere((GLUquadric*) state.to_lightuserdata(1), (GLdouble) state.to_number(2), (GLint) state.to_integer(3), (GLint) state.to_integer(4));
		return 0;
	}
	int gl_StencilFunc(lutok::state& state){
		glStencilFunc((GLenum) state.to_integer(1), (GLint) state.to_integer(2), (GLuint) state.to_integer(3));
		return 0;
	}
	int gl_StencilMask(lutok::state& state){
		glStencilMask((GLuint) state.to_integer(1));
		return 0;
	}
	int gl_StencilOp(lutok::state& state){
		glStencilOp((GLenum) state.to_integer(1), (GLenum) state.to_integer(2), (GLenum) state.to_integer(3));
		return 0;
	}
	int gl_SwapInterval(lutok::state& state){
#ifdef __WGLEW_H__
		wglSwapIntervalEXT((int) state.to_integer(1));
#else
#ifdef __GLXEW_H__
		glXSwapIntervalEXT((int) state.to_integer(1));
#endif
#endif
		return 0;
	}

}