#include "main.h"
#include <string.h>

namespace LuaGL {
	int gl_GenBuffers(State& state){
		GLsizei count = (GLsizei)state.stack->to<int>(1);
		if (count > 0){
			GLuint * buffers = new GLuint[count];
			glGenBuffers(count, buffers);
			setArray<unsigned int>(state, buffers, count);
			delete[] buffers;
			return 1;
		}
		return 0;
	}
	int gl_GenFrameBuffers(State& state){
		GLsizei count = (GLsizei)state.stack->to<int>(1);
		if (count > 0){
			GLuint * buffers = new GLuint[count];
			glGenFramebuffers(count, buffers);
			setArray<unsigned int>(state, buffers, count);
			delete[] buffers;
			return 1;
		}
		return 0;
	}
	int gl_GenRenderBuffers(State& state){
		GLsizei count = (GLsizei)state.stack->to<int>(1);
		if (count > 0){
			GLuint * buffers = new GLuint[count];
			glGenRenderbuffers(count, buffers);
			setArray<unsigned int>(state, buffers, count);
			delete[] buffers;
			return 1;
		}
		return 0;
	}
	int gl_GenLists(State& state){
		GLuint ret = glGenLists((GLsizei) state.stack->to<int>(1));
		state.stack->push<int>(ret);
		return 1;
	}
	int gl_GenTextures(State& state){
		GLsizei count = (GLsizei)state.stack->to<int>(1);
		if (count > 0){
			GLuint * tex = new GLuint[count];
			glGenTextures(count, tex);
			setArray<unsigned int>(state, tex, count);
			delete[] tex;
			return 1;
		}
		return 0;
	}
	int gl_GenVertexArrays(State& state){
		GLsizei count = (GLsizei)state.stack->to<int>(1);
		if (count > 0){
			GLuint * buffers = new GLuint[count];
			glGenVertexArrays(count, buffers);
			setArray<unsigned int>(state, buffers, count);
			delete[] buffers;
			return 1;
		}
		return 0;
	}
	/*
		gl.Get(format, enum)
	*/
	int gl_Get(State& state){
		string fmt = state.stack->to<const string>(1);
		GLenum pname = (GLenum) state.stack->to<int>(2);
		unsigned int len = 1;
		char type[4];
		if (sscanf(fmt.c_str(), "%1s(%u)", type, &len) == 2){
			if (!strncmp(type, "s", 1)){
				const char * str = (char *) glGetString(pname);
				if (str){
					state.stack->push<const string &>(str);
					return 1;
				}
			}else
				if (!strncmp(type, "i", 1)){
					GLint * values = new GLint[len];
					if (values){
						glGetIntegerv(pname, values);
						setArray<int>(state, static_cast<int *>(values), len);
						delete[] values;
						return 1;
					}
				}else
					if (!strncmp(type, "f", 1)){	
						GLfloat * values = new GLfloat[len];
						if (values){
							glGetFloatv(pname, values);
							setArray<float>(state, static_cast<float *>(values), len);
							delete[] values;
							return 1;
						}
					}else
						if (!strncmp(type, "d", 1)){
							GLdouble * values = new GLdouble[len];
							if (values){
								glGetDoublev(pname, values);
								setArray<double>(state, static_cast<double *>(values), len);
								delete[] values;
								return 1;
							}	
						}else
							if (!strncmp(type, "b", 1)){
								GLboolean * values = new GLboolean[len];
								if (values){
									glGetBooleanv(pname, values);
									setArray<bool>(state, reinterpret_cast<bool *>(values), len);
									delete[] values;
									return 1;
								}	
							}
		}
		return 0;
	}
	/*
		gl.GetEx(enum, type, count)
	*/
	int gl_GetEx(State& state){
		GLenum pname = (GLenum) state.stack->to<int>(1);
		string _type = state.stack->to<const string>(2);
		unsigned int len = state.stack->to<int>(3);
		char type = 0;
		if (_type.length()>0){
			type = _type[0];
		}

		switch (type){
		case 's':
			{const char * str = (char *) glGetString(pname);
			if (str){
				state.stack->push<const string &>(str);
				return 1;
			}}
			break;
		case 'i':
			{GLint * values = new GLint[len];
			if (values){
				glGetIntegerv(pname, values);
				setArray<int>(state, static_cast<int *>(values), len);
				delete[] values;
				return 1;
			}}
			break;
		case 'f':
			{GLfloat * values = new GLfloat[len];
			if (values){
				glGetFloatv(pname, values);
				setArray<float>(state, static_cast<float *>(values), len);
				delete[] values;
				return 1;
			}}
			break;
		case 'd':
			{GLdouble * values = new GLdouble[len];
			if (values){
				glGetDoublev(pname, values);
				setArray<double>(state, static_cast<double *>(values), len);
				delete[] values;
				return 1;
			}}
			break;
		case 'b':
			{GLboolean * values = new GLboolean[len];
			if (values){
				glGetBooleanv(pname, values);
				setArray<bool>(state, reinterpret_cast<bool *>(values), len);
				delete[] values;
				return 1;
			}}
			break;
		}
		return 0;
	}

	int gl_GetBufferSubData(State& state){
		size_t count = state.stack->to<int>(3);
		unsigned char * buffer = new unsigned char[count];
		glGetBufferSubData((GLenum) state.stack->to<int>(1), (GLintptr) state.stack->to<int>(2), (GLsizeiptr) count*sizeof(unsigned char), buffer);
		setArray<unsigned char>(state, buffer, count);
		return 1;
	}
	int gl_GetBufferParameter(State& state){
		GLint result = 0;
		glGetBufferParameteriv((GLenum) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2), &result);
		state.stack->push<int>(result);
		return 1;
	}
	/*
		GetFramebufferAttachmentParameter(target, attachment, parameter_name)
	*/
	int gl_GetFramebufferAttachmentParameter(State& state){
		GLint parameters;

		glGetFramebufferAttachmentParameteriv(
			(GLenum) state.stack->to<int>(1),
			(GLenum) state.stack->to<int>(2),
			(GLenum) state.stack->to<int>(3),
			&parameters
		);
		state.stack->push<int>(parameters);
		return 1;
	}
	int gl_GetClipPlane(State& state){
		//__RENDER->dprintf("Stub(%s)","glGetClipPlane()");
		return 0;
	}
	int gl_GetError(State& state){
		state.stack->push<int>(glGetError());
		return 1;
	}
	int gl_GetLight(State& state){
		//glGetLight(
		return 0;
	}
	int gl_GetMap(State& state){
		//glGetMapf(
		return 0;
	}
	int gl_GetMaterial(State& state){
		//glGetMateriald(
		return 0;
	}
	int gl_GetPixelMap(State& state){
		return 0;
	}
	int gl_GetPointer(State& state){
		return 0;
	}
	int gl_GetPolygonStipple(State& state){
		return 0;
	}
	int gl_GetSwapInterval(State& state){
#ifdef __WGLEW_H__
		wglSwapIntervalEXT((int) state.stack->to<int>(1));
		state.stack->push<int>(wglGetSwapIntervalEXT());
#else
#ifdef __GLXEW_H__
		glXSwapIntervalMESA((int) state.stack->to<int>(1));
		state.stack->push<int>(glXGetSwapIntervalMESA());
#endif
#endif
		return 1;
	}
	int gl_GetTessProperty(State& state){
		return 0;
	}
	int gl_GetTexEnv(State& state){
		return 0;
	}
	int gl_GetTexGen(State& state){
		return 0;
	}
	int gl_GetTexImage(State& state){
		return 0;
	}
	int gl_GetTexLevelParameter(State& state){
		return 0;
	}
	int gl_GetTexParameter(State& state){
		return 0;
	}
	int gl_GetShaderInfoLog(State& state){
		int len=0;
		char buffer[4096];
		glGetShaderInfoLog((GLuint) state.stack->to<int>(1), (GLsizei) 4096, (GLsizei *) &len, (GLchar*) buffer);
		state.stack->pushLString(string(buffer, len));
		return 1;
	}
	int gl_GetProgramInfoLog(State& state){
		int len=0;
		char buffer[4096];
		glGetProgramInfoLog((GLuint) state.stack->to<int>(1), (GLsizei) 4096, (GLsizei *) &len, (GLchar*) buffer);
		state.stack->pushLString(string(buffer, len));
		return 1;
	}
	int gl_GetProgramiv(State& state){
		GLint value=0;
		glGetProgramiv((GLuint) state.stack->to<int>(1), (GLenum) state.stack->to<int>(2), (GLint *) &value);
		state.stack->push<int>(value);
		return 1;
	}

	int gl_GetShaderiv(State& state){
		GLint value=0;
		glGetShaderiv((GLuint) state.stack->to<int>(1), (GLuint) state.stack->to<int>(2), &value);
		state.stack->push<int>(value);
		return 1;
	}

	int gl_GetShaderSource(State & state){
		GLuint shaderID = (GLuint)state.stack->to<int>(1);
		GLint maxLength;
		GLsizei length;

		glGetShaderiv(shaderID, GL_SHADER_SOURCE_LENGTH, &maxLength);

		GLchar * src = new char[maxLength];
		glGetShaderSource(shaderID, maxLength, &length, src);
		state.stack->pushLString(src, length);
		delete[] src;
		return 1;
	}

	int gl_GetProgramBinary(State & state){
		GLuint program = (GLuint)state.stack->to<int>(1);
		GLint maxLength;
		GLsizei length;

		glGetProgramiv(program, GL_PROGRAM_BINARY_LENGTH, &maxLength);

		GLenum binaryFormat;
		GLchar * binary = new char[maxLength];

		glGetProgramBinary(program, maxLength, &length, &binaryFormat, binary);
		
		state.stack->push<int>(binaryFormat);
		state.stack->pushLString(binary, length);

		delete[] binary;
		return 2;
	}

	int gl_GetUniformLocation(State& state){
		const std::string name = state.stack->to<const string>(2);
		int ret = (int) glGetUniformLocation((GLuint) state.stack->to<int>(1), (const GLchar *) name.c_str());
		state.stack->push<int>(ret);
		return 1;
	}

	int gl_GetUniformf(State & state){
		GLfloat value[4] = {0.0f, 0.0f, 0.0f, 0.0f};
		glGetUniformfv((GLuint) state.stack->to<int>(1), (GLint) state.stack->to<int>(2), value);
		for (int i=0; i<4; i++){
			state.stack->push<LUA_NUMBER>(value[i]);
		}
		return 4;
	}
	int gl_GetUniformi(State & state){
		GLint value[4] = {0, 0, 0, 0};
		glGetUniformiv((GLuint) state.stack->to<int>(1), (GLint) state.stack->to<int>(2), value);
		for (int i=0; i<4; i++){
			state.stack->push<int>(value[i]);
		}
		return 4;
	}
	int gl_GetUniformui(State & state){
		GLuint value[4] = {0, 0, 0, 0};
		glGetUniformuiv((GLuint) state.stack->to<int>(1), (GLint) state.stack->to<int>(2), value);
		for (int i=0; i<4; i++){
			state.stack->push<int>(value[i]);
		}
		return 4;
	}
	int gl_GetUniformd(State & state){
		GLdouble value[4] = {0.0f, 0.0f, 0.0f, 0.0f};
		glGetUniformdv((GLuint) state.stack->to<int>(1), (GLint) state.stack->to<int>(2), value);
		for (int i=0; i<4; i++){
			state.stack->push<LUA_NUMBER>(value[i]);
		}
		return 4;
	}
}