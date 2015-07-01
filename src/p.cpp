#include "main.h"
#include <string.h>

namespace LuaGL {
	int glu_PartialDisk(State& state){
		gluPartialDisk(
			(GLUquadric*) state.stack->to<void*>(1),
			(GLdouble) state.stack->to<LUA_NUMBER>(2),
			(GLdouble) state.stack->to<LUA_NUMBER>(3),
			(GLint) state.stack->to<int>(4),
			(GLint) state.stack->to<int>(5),
			(GLdouble) state.stack->to<LUA_NUMBER>(6),
			(GLdouble) state.stack->to<LUA_NUMBER>(7)
		);
		return 0;
	}
	int gl_PassThrough(State& state){
		glPassThrough((GLfloat) state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
	int glu_Perspective(State& state){
		gluPerspective(
			(GLdouble) state.stack->to<LUA_NUMBER>(1),
			(GLdouble) state.stack->to<LUA_NUMBER>(2),
			(GLdouble) state.stack->to<LUA_NUMBER>(3),
			(GLdouble) state.stack->to<LUA_NUMBER>(4)
		);
		return 0;
	}
	int glu_PickMatrix(State& state){
		//gluPickMatrix(
		return 0;
	}
	int gl_PixelMap(State& state){
		return 0;
	}
	int gl_PixelStore(State& state){
		//glPixelStore(
		return 0;
	}
	int gl_PixelTransfer(State& state){
		//glPixelTransfer(
		return 0;
	}
	int gl_PixelZoom(State& state){
		glPixelZoom((GLfloat) state.stack->to<LUA_NUMBER>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2));
		return 0;
	}
	int gl_PointSize(State& state){
		glPointSize((GLfloat) state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
	int gl_PolygonMode(State& state){
		glPolygonMode((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2));
		return 0;
	}
	int gl_PolygonOffset(State& state){
		glPolygonOffset((GLfloat) state.stack->to<LUA_NUMBER>(1), (GLfloat) state.stack->to<LUA_NUMBER>(2));
		return 0;
	}
	int gl_PolygonStipple(State& state){
		//glPolygonStipple(
		return 0;
	}
	int gl_PrioritizeTextures(State& state){
		//glPrioritizeTextures(
		return 0;
	}
	int gl_PrimitiveRestartIndex(State& state){
		glPrimitiveRestartIndex((GLuint) state.stack->to<int>(1));
		return 0;
	} 
	int glu_Project(State& state){
		//gluProject(
		return 0;
	}
	int gl_PopAttrib(State& state){
		glPopAttrib();
		return 0;
	}
	int gl_PopClientAttrib(State& state){
		glPopClientAttrib();
		return 0;
	}
	int gl_PopMatrix(State& state){
		glPopMatrix();
		return 0;
	}
	int gl_PopName(State& state){
		glPopName();
		return 0;
	}

	int gl_PushAttrib(State& state){
		glPushAttrib((GLbitfield) state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
	int gl_PushClientAttrib(State& state){
		glPushClientAttrib((GLbitfield) state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
	int gl_PushMatrix(State& state){
		glPushMatrix();
		return 0;
	}
	int gl_PushName(State& state){
		glPushName((GLuint) state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
	int glu_PwlCurve(State& state){
		//gluPwlCurve(
		return 0;
	}
	int gl_ProgramUniformf(State& state){
		int argc = state.stack->getTop();
		switch (argc){
		case 6:
			glProgramUniform4f(
				(GLuint) state.stack->to<int>(1),
				(GLint) state.stack->to<int>(2),
				(GLfloat) state.stack->to<LUA_NUMBER>(3),
				(GLfloat) state.stack->to<LUA_NUMBER>(4),
				(GLfloat) state.stack->to<LUA_NUMBER>(5),
				(GLfloat) state.stack->to<LUA_NUMBER>(6)
			);
			break;
		case 5:
			glProgramUniform3f(
				(GLuint) state.stack->to<int>(1),
				(GLint) state.stack->to<int>(2),
				(GLfloat) state.stack->to<LUA_NUMBER>(3),
				(GLfloat) state.stack->to<LUA_NUMBER>(4),
				(GLfloat) state.stack->to<LUA_NUMBER>(5)
			);
			break;
		case 4:
			glProgramUniform2f(
				(GLuint) state.stack->to<int>(1),
				(GLint) state.stack->to<int>(2),
				(GLfloat) state.stack->to<LUA_NUMBER>(3),
				(GLfloat) state.stack->to<LUA_NUMBER>(4)
			);
			break;
		case 3:
			if (state.stack->is<LUA_TTABLE>(3)){
				size_t size = 0;
				GLfloat * data = nullptr;
				vector<float> _data;

				size = getArray<float>(state, 3, _data);
				data = _data.data();
				glProgramUniform1fv(
					(GLuint) state.stack->to<int>(1),
					(GLint) state.stack->to<int>(2),
					(GLsizei) size,
					(GLfloat*) data
				);
			}else if (state.stack->is<LUA_TNUMBER>(3)){
				GLfloat value = state.stack->to<LUA_NUMBER>(3);
				glProgramUniform1f(
					(GLuint) state.stack->to<int>(1),
					(GLint) state.stack->to<int>(1),
					(GLfloat) value
				);
			}
			break;
		default:
			break;
		}
		return 0;
	}
	int gl_ProgramUniformi(State& state){
		int argc = state.stack->getTop();
		switch (argc){
		case 6:
			glProgramUniform4i(
				(GLuint) state.stack->to<int>(1),
				(GLint) state.stack->to<int>(2),
				(GLint) state.stack->to<int>(3),
				(GLint) state.stack->to<int>(4),
				(GLint) state.stack->to<int>(5),
				(GLint) state.stack->to<int>(6)
			);
			break;
		case 5:
			glProgramUniform3i(
				(GLuint) state.stack->to<int>(1),
				(GLint) state.stack->to<int>(2),
				(GLint) state.stack->to<int>(3),
				(GLint) state.stack->to<int>(4),
				(GLint) state.stack->to<int>(5)
			);
			break;
		case 4:
			glProgramUniform2i(
				(GLuint) state.stack->to<int>(1),
				(GLint) state.stack->to<int>(2),
				(GLint) state.stack->to<int>(3),
				(GLint) state.stack->to<int>(4)
			);
			break;
		case 3:
			if (state.stack->is<LUA_TTABLE>(3)){
				size_t size = 0;
				GLint * data;
				vector<int> _data;

				size = getArray<int>(state, 3, _data);
				data = _data.data();
				glProgramUniform1iv(
					(GLuint) state.stack->to<int>(1),
					(GLint) state.stack->to<int>(2),
					(GLsizei) size,
					(GLint *) data);
			}else if (state.stack->is<LUA_TNUMBER>(3)){
				glProgramUniform1i(
					(GLuint) state.stack->to<int>(1),
					(GLint) state.stack->to<int>(2),
					(GLint) state.stack->to<int>(3)
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
	int gl_ProgramUniformMatrix(State& state){
		size_t count = 0;
		size_t size = 0;
		GLfloat * data = nullptr;
		vector<float> _data;
		GLuint programID = state.stack->to<int>(1);

		int rows = state.stack->to<int>(4), cols = state.stack->to<int>(5);

		//supported sizes are: 2x2, 3x3, 4x4, 2x3, 3x2, 2x4, 4x2, 3x4, 4x3
		if ((rows >= 2) && (cols >= 2) && (rows <= 4) && (cols <= 4) && state.stack->is<LUA_TTABLE>(3)){
			count = state.stack->objLen(3);
			if (count > 0){
				
				//is this a table of matrices?
				state.stack->push<int>(1);
				state.stack->getTable(3);
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
						state.stack->getTable(3);
						size = getArray<float>(state, 3, _data);
						memcpy(
							data + (rows * cols * sizeof(GLfloat) * i),
							_data.data(),
							size * sizeof(float)
						);
						state.stack->pop(1);
					}
				}

				GLboolean transpose = false;
				if (state.stack->is<LUA_TBOOLEAN>(6)){
					transpose = state.stack->to<bool>(6);
				}

				if (rows == 2){
					if (cols == 2){
						glProgramUniformMatrix2fv(programID, (GLint) state.stack->to<int>(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glProgramUniformMatrix2x3fv(programID, (GLint) state.stack->to<int>(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glProgramUniformMatrix2x4fv(programID, (GLint) state.stack->to<int>(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}else if (rows == 3){
					if (cols == 2){
						glProgramUniformMatrix3x2fv(programID, (GLint) state.stack->to<int>(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glProgramUniformMatrix3fv(programID, (GLint) state.stack->to<int>(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glProgramUniformMatrix3x4fv(programID, (GLint) state.stack->to<int>(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}else{
					if (cols == 2){
						glProgramUniformMatrix4x2fv(programID, (GLint) state.stack->to<int>(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else if (cols == 3){
						glProgramUniformMatrix4x3fv(programID, (GLint) state.stack->to<int>(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}else{
						glProgramUniformMatrix4fv(programID, (GLint) state.stack->to<int>(2), (GLsizei) count, (GLboolean) transpose, (GLfloat *) data);
					}
				}
				delete[] data;
			}
		}
		return 0;
	}

	int gl_ProgramBinary(State& state){
		if (state.stack->is<LUA_TNUMBER>(1) && state.stack->is<LUA_TNUMBER>(2) && state.stack->is<LUA_TSTRING>(3)){
			GLuint program = state.stack->to<int>(1);
			GLenum binaryFormat = state.stack->to<int>(2);
			string binary = state.stack->toLString(3);

			glProgramBinary(program, binaryFormat, binary.c_str(), binary.length());
		}
		return 0;
	}

}