#include "main.h"

namespace LuaGL {
	int gl_Vertex2f(State& state){
		glVertex2f((GLfloat) state.stack->to<LUA_NUMBER>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2));
		return 0;
	}
	int gl_Vertex2i(State& state){
		glVertex2i((GLint) state.stack->to<int>(1), (GLint) state.stack->to<int>(2));
		return 0;
	}
	int gl_Vertex3f(State& state){
		glVertex3f((GLfloat) state.stack->to<LUA_NUMBER>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3));
		return 0;
	}
	int gl_VertexPointer(State& state){
		if (state.stack->is<LUA_TNUMBER>(1)){
			GLint size = 0;
			GLint nsize = state.stack->to<int>(1);
			GLfloat * data;
			vector<float> _data;

			if (state.stack->is<LUA_TNUMBER>(2)){
				data = (GLfloat *) state.stack->to<int>(2);
			}else{
				if (state.stack->is<LUA_TTABLE>(2)){
					size = getArray<float>(state, 2, _data);
					data = _data.data();
				}else{
					data = NULL;
				}
			}
			if ((data && (nsize<=size)) || (nsize>=1 && nsize <= 4)){
				glVertexPointer(nsize, GL_FLOAT, 0, data);
			}
		}
		return 0;
	}

	int gl_Viewport(State& state){
		glViewport((GLuint) state.stack->to<int>(1), (GLuint) state.stack->to<int>(2), (GLuint) state.stack->to<int>(3), (GLuint) state.stack->to<int>(4));
		return 0;
	}
	int gl_VertexAttribd(State& state){
		int argc = state.stack->getTop();
		switch (argc){
		case 5:
			glVertexAttrib4d((GLint) state.stack->to<int>(1), (GLdouble) state.stack->to<LUA_NUMBER>(2), (GLdouble) state.stack->to<LUA_NUMBER>(3), (GLdouble) state.stack->to<LUA_NUMBER>(4), (GLdouble) state.stack->to<LUA_NUMBER>(5));
			break;
		case 4:
			glVertexAttrib3d((GLint) state.stack->to<int>(1), (GLdouble) state.stack->to<LUA_NUMBER>(2), (GLdouble) state.stack->to<LUA_NUMBER>(3), (GLdouble) state.stack->to<LUA_NUMBER>(4));
			break;
		case 3:
			glVertexAttrib2d((GLint) state.stack->to<int>(1), (GLdouble) state.stack->to<LUA_NUMBER>(2), (GLdouble) state.stack->to<LUA_NUMBER>(3));
			break;
		case 2:
			glVertexAttrib1d((GLint) state.stack->to<int>(1), (GLdouble) state.stack->to<LUA_NUMBER>(2));
			break;
		default:
			break;
		}
		return 0;
	}

	int gl_VertexAttribs(State& state){
		int argc = state.stack->getTop();
		switch (argc){
		case 5:
			glVertexAttrib4s((GLint) state.stack->to<int>(1), (GLshort) state.stack->to<int>(2), (GLshort) state.stack->to<int>(3), (GLshort) state.stack->to<int>(4), (GLshort) state.stack->to<int>(5));
			break;
		case 4:
			glVertexAttrib3s((GLint) state.stack->to<int>(1), (GLshort) state.stack->to<int>(2), (GLshort) state.stack->to<int>(3), (GLshort) state.stack->to<int>(4));
			break;
		case 3:
			glVertexAttrib2s((GLint) state.stack->to<int>(1), (GLshort) state.stack->to<int>(2), (GLshort) state.stack->to<int>(3));
			break;
		case 2:
			glVertexAttrib1s((GLint) state.stack->to<int>(1), (GLshort) state.stack->to<int>(2));
			break;
		default:
			break;
		}
		return 0;
	}

	/*
		vertexAttribPointer(index, size, normalized, stride, type)
		vertexAttribPointer(index, table, normalized, stride, type)
	*/
	int gl_VertexAttribPointer(State& state){
		GLint size = 0;
		GLfloat * data;
		vector<float> _data;
		GLsizei stride = 0;
		GLenum type = GL_FLOAT;

		if (state.stack->is<LUA_TNUMBER>(2)){
			data = NULL;
			size = state.stack->to<int>(2);
		}else{
			if (state.stack->is<LUA_TTABLE>(2)){
				size = getArray<float>(state, 2, _data);
				if (size>4){
					size = 4;
				}
				data = _data.data();
			}else{
				data = NULL;
			}
		}
		if (state.stack->is<LUA_TNUMBER>(4)){
			stride = state.stack->to<int>(4);
		}
		if (state.stack->is<LUA_TNUMBER>(5)){
			type = state.stack->to<int>(5);
		}
		glVertexAttribPointer(
			(GLuint) state.stack->to<int>(1),
			(GLint) size,
			(GLenum) type,
			(GLboolean) state.stack->to<bool>(3),
			(GLsizei) stride,
			(GLvoid*) data);
		return 0;
	}

}