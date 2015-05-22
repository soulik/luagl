#include "main.h"

namespace LuaGL {
	int gl_Rotatef(State& state){
		glRotatef((GLfloat) state.stack->to<LUA_NUMBER>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3), (GLfloat) state.stack->to<LUA_NUMBER>(4));
		return 0;
	}
	int gl_RasterPos(State& state){
		return 0;
	}
	int gl_ReadBuffer(State& state){
		glReadBuffer((GLenum) state.stack->to<int>(1));
		return 0;
	}
	int gl_ReadPixels(State& state){
		GLint x,y,w,h;

		x = state.stack->to<int>(1);
		y = state.stack->to<int>(2);
		w = state.stack->to<int>(3);
		h = state.stack->to<int>(4);

		GLenum format = state.stack->to<int>(5);
		GLenum type = state.stack->to<int>(6);
		
		if ((type == GL_UNSIGNED_BYTE) || (type == GL_UNSIGNED_INT || (type == GL_FLOAT))){
			GLvoid * pixels = nullptr;
			unsigned char components = 1;

			if ((format == GL_RGB) || (format == GL_BGR)){
				components = 3;
			} else if ((format == GL_RGBA) || (format == GL_BGRA)){
				components = 4;
			} else if (format == GL_LUMINANCE_ALPHA){
				components = 2;
			}

			size_t elements = w * h * components;

			switch (type){
			case GL_UNSIGNED_BYTE:
				pixels = new unsigned char[elements];
				break;
			case GL_UNSIGNED_INT:
				pixels = new unsigned int[elements];
				break;
			case GL_FLOAT:
				pixels = new float[elements];
				break;
			}

			glReadPixels(x, y, w, h, format, type, pixels);

			switch (type){
			case GL_UNSIGNED_BYTE:
				setArray<unsigned char>(state, static_cast<unsigned char *>(pixels), elements);
				break;
			case GL_UNSIGNED_INT:
				setArray<int>(state, static_cast<int *>(pixels), elements);
				break;
			case GL_FLOAT:
				setArray<float>(state, static_cast<float *>(pixels), elements);
				break;
			}

			delete[] pixels;
			return 1;
		}else{
			return 0;
		}
	}
	int gl_ReadPixel(State& state){
		unsigned long color=0;
		glReadPixels(state.stack->to<int>(1), state.stack->to<int>(2), 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) &color);
		state.stack->push<int>(color);
		return 1;
	}
	int gl_Rect(State& state){
		glRectd((GLdouble) state.stack->to<LUA_NUMBER>(1), (GLdouble) state.stack->to<LUA_NUMBER>(2), (GLdouble) state.stack->to<LUA_NUMBER>(3), (GLdouble) state.stack->to<LUA_NUMBER>(4));
		return 0;
	}
	int gl_RenderMode(State& state){
		GLint result = glRenderMode((GLenum) state.stack->to<int>(1));
		state.stack->push<int>(result);
		return 1;
	}
	/*
		RenderBufferStorage(target, internal_format, width, height)
	*/
	int gl_RenderBufferStorage(State& state){
		 glRenderbufferStorage(
			 (GLenum) state.stack->to<int>(1),
			 (GLenum) state.stack->to<int>(2),
			 (GLsizei) state.stack->to<int>(3),
			 (GLsizei) state.stack->to<int>(4)
		);
		return 0;
	}

}