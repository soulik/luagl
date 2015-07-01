#include "main.h"
#include <string.h>

namespace LuaGL {
	int glu_UnloadProject(State& state){
		return 0;
	}
	int gl_UseProgram(State& state){
		glUseProgram((GLuint) state.stack->to<int>(1));
		return 0;
	}
	int gl_Uniformf(State& state){
		int argc = state.stack->getTop();
		switch (argc){
		case 5:
			glUniform4f((GLint) state.stack->to<int>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3), (GLfloat) state.stack->to<LUA_NUMBER>(4), (GLfloat) state.stack->to<LUA_NUMBER>(5));
			break;
		case 4:
			glUniform3f((GLint) state.stack->to<int>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3), (GLfloat) state.stack->to<LUA_NUMBER>(4));
			break;
		case 3:
			glUniform2f((GLint) state.stack->to<int>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2), (GLfloat) state.stack->to<LUA_NUMBER>(3));
			break;
		case 2:
			if (state.stack->is<LUA_TTABLE>(2)){
				size_t size = 0;
				GLfloat * data = nullptr;
				vector<float> _data;

				size = getArray<float>(state, 2, _data);
				data = _data.data();
				glUniform1fv((GLint) state.stack->to<int>(1), (GLsizei) size, (GLfloat*) data);
			}else if (state.stack->is<LUA_TNUMBER>(2)){
				GLfloat value = state.stack->to<LUA_NUMBER>(2);
				glUniform1f((GLint) state.stack->to<int>(1), (GLfloat) value);
			}
			break;
		default:
			break;
		}
		return 0;
	}

	int gl_Uniformi(State& state){
		int argc = state.stack->getTop();
		switch (argc){
		case 5:
			glUniform4i((GLint) state.stack->to<int>(1), (GLint) state.stack->to<int>(2), (GLint) state.stack->to<int>(3), (GLint) state.stack->to<int>(4), (GLint) state.stack->to<int>(5));
			break;
		case 4:
			glUniform3i((GLint) state.stack->to<int>(1), (GLint) state.stack->to<int>(2), (GLint) state.stack->to<int>(3), (GLint) state.stack->to<int>(4));
			break;
		case 3:
			glUniform2i((GLint) state.stack->to<int>(1), (GLint) state.stack->to<int>(2), (GLint) state.stack->to<int>(3));
			break;
		case 2:
			if (state.stack->is<LUA_TTABLE>(2)){
				size_t size = 0;
				GLint * data;
				vector<int> _data;

				size = getArray<int>(state, 2, _data);
				data = _data.data();
				glUniform1iv((GLint) state.stack->to<int>(1), (GLsizei) size, (GLint *) data);
			}else if (state.stack->is<LUA_TNUMBER>(2)){
				glUniform1i((GLint) state.stack->to<int>(1), (GLint) state.stack->to<int>(2));
			}			
			break;
		default:
			break;
		}
		return 0;
	}

	int gl_Uniformui(State& state){
		int argc = state.stack->getTop();
		switch (argc){
		case 5:
			glUniform4ui((GLint)state.stack->to<int>(1), (GLuint)state.stack->to<int>(2), (GLuint)state.stack->to<int>(3), (GLuint)state.stack->to<int>(4), (GLuint)state.stack->to<int>(5));
			break;
		case 4:
			glUniform3ui((GLint)state.stack->to<int>(1), (GLuint)state.stack->to<int>(2), (GLuint)state.stack->to<int>(3), (GLuint)state.stack->to<int>(4));
			break;
		case 3:
			glUniform2ui((GLint)state.stack->to<int>(1), (GLuint)state.stack->to<int>(2), (GLuint)state.stack->to<int>(3));
			break;
		case 2:
			if (state.stack->is<LUA_TTABLE>(2)){
				size_t size = 0;
				GLuint * data;
				vector<unsigned int> _data;

				size = getArray<unsigned int>(state, 2, _data);
				data = _data.data();
				glUniform1uiv((GLint)state.stack->to<int>(1), (GLsizei)size, (GLuint *)data);
			}
			else if (state.stack->is<LUA_TNUMBER>(2)){
				glUniform1ui((GLint)state.stack->to<int>(1), (GLuint)state.stack->to<int>(2));
			}
			break;
		default:
			break;
		}
		return 0;
	}

	/*
		uniformMatrix(location, matrixTable, rows, cols, transpose)
	*/
	int gl_UniformMatrix(State& state){
		size_t count = 0;
		size_t size = 0;
		GLfloat * data = nullptr;
		vector<float> _data;
		int rows = state.stack->to<int>(3), cols = state.stack->to<int>(4);

		//supported sizes are: 2x2, 3x3, 4x4, 2x3, 3x2, 2x4, 4x2, 3x4, 4x3
		if ((rows >= 2) && (cols >= 2) && (rows <= 4) && (cols <= 4) && state.stack->is<LUA_TTABLE>(2)){
			count = state.stack->objLen(2);
			if (count > 0){
				
				//is this a table of matrices?
				state.stack->push<int>(1);
				state.stack->getTable(2);
				bool isTable = state.stack->is<LUA_TTABLE>();
				state.stack->pop(1);

				if (!isTable){
					count = 1;
					size = getArray<float>(state, 2, _data);
					data = new GLfloat[rows * cols];
					memcpy(data, _data.data(), size * sizeof(float));
				}else{
					data = new GLfloat[rows * cols * count];
					for (size_t i=0; i < count; i++){
						state.stack->push<int>(i+1);
						state.stack->getTable(2);
						size = getArray<float>(state, 2, _data);
						memcpy(
							data + (rows * cols * sizeof(GLfloat) * i),
							_data.data(),
							size * sizeof(float)
						);
						state.stack->pop(1);
					}
				}

				GLboolean transpose = false;
				if (state.stack->is<LUA_TBOOLEAN>(5)){
					transpose = state.stack->to<bool>(5);
				}

				if (rows == 2){
					if (cols == 2){
						glUniformMatrix2fv((GLint) state.stack->to<int>(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glUniformMatrix2x3fv((GLint) state.stack->to<int>(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glUniformMatrix2x4fv((GLint) state.stack->to<int>(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}else if (rows == 3){
					if (cols == 2){
						glUniformMatrix3x2fv((GLint) state.stack->to<int>(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glUniformMatrix3fv((GLint) state.stack->to<int>(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glUniformMatrix3x4fv((GLint) state.stack->to<int>(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}else{
					if (cols == 2){
						glUniformMatrix4x2fv((GLint) state.stack->to<int>(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glUniformMatrix4x3fv((GLint) state.stack->to<int>(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glUniformMatrix4fv((GLint) state.stack->to<int>(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}
				delete[] data;
			}
		}
		return 0;
	}
	int gl_UnmapBuffer(State& state){
		state.stack->push<bool>(
			(GLboolean) glUnmapBuffer(
				(GLenum) state.stack->to<int>(1)
			)
		);
		return 1;
	}

}