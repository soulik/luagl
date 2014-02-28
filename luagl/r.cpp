#include "main.h"

namespace GLex {
	int gl_Rotatef(lutok::state& state){
		glRotatef((GLfloat) state.to_number(1), (GLfloat) state.to_number(2), (GLfloat) state.to_number(3), (GLfloat) state.to_number(4));
		return 0;
	}
	int gl_RasterPos(lutok::state& state){
		return 0;
	}
	int gl_ReadBuffer(lutok::state& state){
		glReadBuffer((GLenum) state.to_integer(1));
		return 0;
	}
	int gl_ReadPixels(lutok::state& state){
		GLint x,y,w,h;

		x = state.to_integer(1);
		y = state.to_integer(2);
		w = state.to_integer(3);
		h = state.to_integer(4);

		GLenum format = state.to_integer(5);
		GLenum type = state.to_integer(6);
		
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
	int gl_ReadPixel(lutok::state& state){
		unsigned long color=0;
		glReadPixels(state.to_integer(1), state.to_integer(2), 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) &color);
		state.push_integer(color);
		return 1;
	}
	int gl_Rect(lutok::state& state){
		glRectd((GLdouble) state.to_number(1), (GLdouble) state.to_number(2), (GLdouble) state.to_number(3), (GLdouble) state.to_number(4));
		return 0;
	}
	int gl_RenderMode(lutok::state& state){
		GLint result = glRenderMode((GLenum) state.to_integer(1));
		state.push_integer(result);
		return 1;
	}
	/*
		RenderBufferStorage(target, internal_format, width, height)
	*/
	int gl_RenderBufferStorage(lutok::state& state){
		 glRenderbufferStorage(
			 (GLenum) state.to_integer(1),
			 (GLenum) state.to_integer(2),
			 (GLsizei) state.to_integer(3),
			 (GLsizei) state.to_integer(4)
		);
		return 0;
	}

}