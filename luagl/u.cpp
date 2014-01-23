#include "main.h"

namespace GLex {
	int glu_UnloadProject(lutok::state& state){
		return 0;
	}
	int gl_UseProgram(lutok::state& state){
		glUseProgram((GLuint) state.to_integer(1));
		return 0;
	}
	int gl_Uniformf(lutok::state& state){
		int argc = state.get_top();
		switch (argc){
		case 5:
			glUniform4f((GLint) state.to_integer(1), (GLfloat) state.to_number(2), (GLfloat) state.to_number(3), (GLfloat) state.to_number(4), (GLfloat) state.to_number(5));
			break;
		case 4:
			glUniform3f((GLint) state.to_integer(1), (GLfloat) state.to_number(2), (GLfloat) state.to_number(3), (GLfloat) state.to_number(4));
			break;
		case 3:
			glUniform2f((GLint) state.to_integer(1), (GLfloat) state.to_number(2), (GLfloat) state.to_number(3));
			break;
		case 2:
			if (state.is_table(2)){
				size_t size = 0;
				GLfloat * data = nullptr;
				vector<float> _data;

				size = getArray<float>(state, 2, _data);
				data = _data.data();
				glUniform1fv((GLint) state.to_integer(1), (GLsizei) size, (GLfloat*) data);
			}else if (state.is_number(2)){
				glUniform1f((GLint) state.to_integer(1), (GLfloat) state.to_number(2));
			}
			break;
		default:
			break;
		}
		return 0;
	}

	int gl_Uniformi(lutok::state& state){
		int argc = state.get_top();
		switch (argc){
		case 5:
			glUniform4i((GLint) state.to_integer(1), (GLint) state.to_integer(2), (GLint) state.to_integer(3), (GLint) state.to_integer(4), (GLint) state.to_integer(5));
			break;
		case 4:
			glUniform3i((GLint) state.to_integer(1), (GLint) state.to_integer(2), (GLint) state.to_integer(3), (GLint) state.to_integer(4));
			break;
		case 3:
			glUniform2i((GLint) state.to_integer(1), (GLint) state.to_integer(2), (GLint) state.to_integer(3));
			break;
		case 2:
			if (state.is_table(2)){
				size_t size = 0;
				GLint * data;
				vector<int> _data;

				size = getArray<int>(state, 2, _data);
				data = _data.data();
				glUniform1iv((GLint) state.to_integer(1), (GLsizei) size, (GLint *) data);
			}else if (state.is_number(2)){
				glUniform1i((GLint) state.to_integer(1), (GLint) state.to_integer(2));
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
	int gl_UniformMatrix(lutok::state& state){
		size_t count = 0;
		size_t size = 0;
		GLfloat * data = nullptr;
		vector<float> _data;
		int rows = state.to_integer(3), cols = state.to_integer(4);

		//supported sizes are: 2x2, 3x3, 4x4, 2x3, 3x2, 2x4, 4x2, 3x4, 4x3
		if ((rows >= 2) && (cols >= 2) && (rows <= 4) && (cols <= 4) && state.is_table(2)){
			count = state.obj_len(2);
			if (count > 0){
				
				//is this a table of matrices?
				state.push_integer(1);
				state.get_table(2);
				bool isTable = state.is_table();
				state.pop(1);

				if (!isTable){
					count = 1;
					size = getArray<float>(state, 2, _data);
					data = new GLfloat[rows * cols];
					memcpy(data, _data.data(), size * sizeof(float));
				}else{
					data = new GLfloat[rows * cols * count];
					for (size_t i=0; i < count; i++){
						state.push_integer(i+1);
						state.get_table(2);
						size = getArray<float>(state, 2, _data);
						memcpy(
							data + (rows * cols * sizeof(GLfloat) * i),
							_data.data(),
							size * sizeof(float)
						);
						state.pop(1);
					}
				}

				GLboolean transpose = false;
				if (state.is_boolean(5)){
					transpose = state.to_boolean(5);
				}

				if (rows == 2){
					if (cols == 2){
						glUniformMatrix2fv((GLint) state.to_integer(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glUniformMatrix2x3fv((GLint) state.to_integer(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glUniformMatrix2x4fv((GLint) state.to_integer(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}else if (rows == 3){
					if (cols == 2){
						glUniformMatrix3x2fv((GLint) state.to_integer(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glUniformMatrix3fv((GLint) state.to_integer(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glUniformMatrix3x4fv((GLint) state.to_integer(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}else{
					if (cols == 2){
						glUniformMatrix4x2fv((GLint) state.to_integer(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glUniformMatrix4x3fv((GLint) state.to_integer(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glUniformMatrix4fv((GLint) state.to_integer(1), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}
				delete[] data;
			}
		}
		return 0;
	}
	int gl_UnmapBuffer(lutok::state& state){
		state.push_boolean(
			(GLboolean) glUnmapBuffer(
				(GLenum) state.to_integer(1)
			)
		);
		return 1;
	}

}