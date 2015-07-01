#include "main.h"

namespace LuaGL {
	int gl_Scalef(State& state){
		glScalef((GLfloat) state.stack->to<LUA_NUMBER>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3));
		return 0;
	}
	int glu_ScaleImage(State& state){
		//gluScaleImage(
		return 0;
	}
	int gl_Scissor(State& state){
		glScissor((GLint) state.stack->to<int>(1), (GLint) state.stack->to<int>(2), (GLsizei) state.stack->to<int>(3), (GLsizei) state.stack->to<int>(4));
		return 0;
	}
	int gl_SelectBuffer(State& state){
		size_t maxElements = state.stack->to<int>(1);
		unsigned int * data = new unsigned int[maxElements];
		glSelectBuffer(maxElements, (GLuint *) data);
		setArray<unsigned int>(state, data, maxElements);
		delete[] data;
		return 1;
	}
	int gl_ShadeModel(State& state){
		glShadeModel((GLenum) state.stack->to<int>(1));
		return 0;
	}
	int gl_ShaderSource(State& state){
		if (state.stack->is<LUA_TSTRING>(2)){
			const std::string & shader_source = state.stack->to<const string>(2);
			const char * src_lines = {shader_source.c_str()};
			glShaderSource((GLuint) state.stack->to<int>(1), 1, (const char **) & src_lines, NULL);
		}else if(state.stack->is<LUA_TTABLE>(2)){
			std::vector<string> lines;
			size_t lines_count = getArray<string>(state, 2, lines);
			const char ** src_lines = new const char * [lines_count];
			for (size_t i=0; i<lines_count; i++){
				src_lines[i] = lines[i].c_str();
			}
			glShaderSource((GLuint) state.stack->to<int>(1), lines_count, src_lines, NULL);
			delete[] src_lines;
		}
		return 0;
	}

	int gl_ShaderBinary(State& state){
		if (state.stack->is<LUA_TTABLE>(1) && state.stack->is<LUA_TNUMBER>(2) && state.stack->is<LUA_TSTRING>(3)){
			vector<unsigned int> shaders;
			size_t count = getArray<unsigned int>(state, 1, shaders);
			GLenum binaryFormat = state.stack->to<int>(2);
			string binary = state.stack->toLString(3);

			glShaderBinary(count, shaders.data(), binaryFormat, binary.c_str(), binary.length());
		}
		return 0;
	}

	int glu_Sphere(State& state){
		gluSphere((GLUquadric*) state.stack->to<void*>(1), (GLdouble) state.stack->to<LUA_NUMBER>(2), (GLint) state.stack->to<int>(3), (GLint) state.stack->to<int>(4));
		return 0;
	}
	int gl_StencilFunc(State& state){
		glStencilFunc((GLenum) state.stack->to<int>(1), (GLint) state.stack->to<int>(2), (GLuint) state.stack->to<int>(3));
		return 0;
	}
	int gl_StencilMask(State& state){
		glStencilMask((GLuint) state.stack->to<int>(1));
		return 0;
	}
	int gl_StencilOp(State& state){
		glStencilOp((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2), (GLenum) state.stack->to<int>(3));
		return 0;
	}
	int gl_SwapInterval(State& state){
#ifdef __WGLEW_H__
		wglSwapIntervalEXT((int) state.stack->to<int>(1));
#else
#ifdef __GLXEW_H__
		glXSwapIntervalMESA((int) state.stack->to<int>(1));
#endif
#endif
		return 0;
	}

}