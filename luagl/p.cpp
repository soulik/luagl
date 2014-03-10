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
	int gl_ProgramUniformf(lutok::state& state){
		int argc = state.get_top();
		switch (argc){
		case 6:
			glProgramUniform4f(
				(GLuint) state.to_integer(1),
				(GLint) state.to_integer(2),
				(GLfloat) state.to_number(3),
				(GLfloat) state.to_number(4),
				(GLfloat) state.to_number(5),
				(GLfloat) state.to_number(6)
			);
			break;
		case 5:
			glProgramUniform3f(
				(GLuint) state.to_integer(1),
				(GLint) state.to_integer(2),
				(GLfloat) state.to_number(3),
				(GLfloat) state.to_number(4),
				(GLfloat) state.to_number(5)
			);
			break;
		case 4:
			glProgramUniform2f(
				(GLuint) state.to_integer(1),
				(GLint) state.to_integer(2),
				(GLfloat) state.to_number(3),
				(GLfloat) state.to_number(4)
			);
			break;
		case 3:
			if (state.is_table(3)){
				size_t size = 0;
				GLfloat * data = nullptr;
				vector<float> _data;

				size = getArray<float>(state, 3, _data);
				data = _data.data();
				glProgramUniform1fv(
					(GLuint) state.to_integer(1),
					(GLint) state.to_integer(2),
					(GLsizei) size,
					(GLfloat*) data
				);
			}else if (state.is_number(3)){
				GLfloat value = state.to_number(3);
				glProgramUniform1f(
					(GLuint) state.to_integer(1),
					(GLint) state.to_integer(1),
					(GLfloat) value
				);
			}
			break;
		default:
			break;
		}
		return 0;
	}
	int gl_ProgramUniformi(lutok::state& state){
		int argc = state.get_top();
		switch (argc){
		case 6:
			glProgramUniform4i(
				(GLuint) state.to_integer(1),
				(GLint) state.to_integer(2),
				(GLint) state.to_integer(3),
				(GLint) state.to_integer(4),
				(GLint) state.to_integer(5),
				(GLint) state.to_integer(6)
			);
			break;
		case 5:
			glProgramUniform3i(
				(GLuint) state.to_integer(1),
				(GLint) state.to_integer(2),
				(GLint) state.to_integer(3),
				(GLint) state.to_integer(4),
				(GLint) state.to_integer(5)
			);
			break;
		case 4:
			glProgramUniform2i(
				(GLuint) state.to_integer(1),
				(GLint) state.to_integer(2),
				(GLint) state.to_integer(3),
				(GLint) state.to_integer(4)
			);
			break;
		case 3:
			if (state.is_table(3)){
				size_t size = 0;
				GLint * data;
				vector<int> _data;

				size = getArray<int>(state, 3, _data);
				data = _data.data();
				glProgramUniform1iv(
					(GLuint) state.to_integer(1),
					(GLint) state.to_integer(2),
					(GLsizei) size,
					(GLint *) data);
			}else if (state.is_number(3)){
				glProgramUniform1i(
					(GLuint) state.to_integer(1),
					(GLint) state.to_integer(2),
					(GLint) state.to_integer(3)
				);
			}			
			break;
		default:
			break;
		}
		return 0;
	}
	/*
		uniformMatrix(program, location, matrixTable, rows, cols, transpose)
	*/
	int gl_ProgramUniformMatrix(lutok::state& state){
		size_t count = 0;
		size_t size = 0;
		GLfloat * data = nullptr;
		vector<float> _data;
		GLuint programID = state.to_integer(1);

		int rows = state.to_integer(4), cols = state.to_integer(5);

		//supported sizes are: 2x2, 3x3, 4x4, 2x3, 3x2, 2x4, 4x2, 3x4, 4x3
		if ((rows >= 2) && (cols >= 2) && (rows <= 4) && (cols <= 4) && state.is_table(3)){
			count = state.obj_len(3);
			if (count > 0){
				
				//is this a table of matrices?
				state.push_integer(1);
				state.get_table(3);
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
						state.get_table(3);
						size = getArray<float>(state, 3, _data);
						memcpy(
							data + (rows * cols * sizeof(GLfloat) * i),
							_data.data(),
							size * sizeof(float)
						);
						state.pop(1);
					}
				}

				GLboolean transpose = false;
				if (state.is_boolean(6)){
					transpose = state.to_boolean(6);
				}

				if (rows == 2){
					if (cols == 2){
						glProgramUniformMatrix2fv(programID, (GLint) state.to_integer(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glProgramUniformMatrix2x3fv(programID, (GLint) state.to_integer(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glProgramUniformMatrix2x4fv(programID, (GLint) state.to_integer(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}else if (rows == 3){
					if (cols == 2){
						glProgramUniformMatrix3x2fv(programID, (GLint) state.to_integer(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glProgramUniformMatrix3fv(programID, (GLint) state.to_integer(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glProgramUniformMatrix3x4fv(programID, (GLint) state.to_integer(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}else{
					if (cols == 2){
						glProgramUniformMatrix4x2fv(programID, (GLint) state.to_integer(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glProgramUniformMatrix4x3fv(programID, (GLint) state.to_integer(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glProgramUniformMatrix4fv(programID, (GLint) state.to_integer(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}
				delete[] data;
			}
		}
		return 0;
	}

}