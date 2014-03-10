#include "main.h"

namespace GLex {
	int gl_GenBuffers(lutok::state& state){
		GLsizei count = (GLsizei)state.to_integer(1);
		if (count > 0){
			GLuint * buffers = new GLuint[count];
			glGenBuffers(count, buffers);
			setArray<unsigned int>(state, buffers, count);
			delete[] buffers;
			return 1;
		}
		return 0;
	}
	int gl_GenFrameBuffers(lutok::state& state){
		GLsizei count = (GLsizei)state.to_integer(1);
		if (count > 0){
			GLuint * buffers = new GLuint[count];
			glGenFramebuffers(count, buffers);
			setArray<unsigned int>(state, buffers, count);
			delete[] buffers;
			return 1;
		}
		return 0;
	}
	int gl_GenRenderBuffers(lutok::state& state){
		GLsizei count = (GLsizei)state.to_integer(1);
		if (count > 0){
			GLuint * buffers = new GLuint[count];
			glGenRenderbuffers(count, buffers);
			setArray<unsigned int>(state, buffers, count);
			delete[] buffers;
			return 1;
		}
		return 0;
	}
	int gl_GenLists(lutok::state& state){
		GLuint ret = glGenLists((GLsizei) state.to_integer(1));
		state.push_integer(ret);
		return 1;
	}
	int gl_GenTextures(lutok::state& state){
		GLsizei count = (GLsizei)state.to_integer(1);
		if (count > 0){
			GLuint * tex = new GLuint[count];
			glGenTextures(count, tex);
			setArray<unsigned int>(state, tex, count);
			delete[] tex;
			return 1;
		}
		return 0;
	}
	int gl_GenVertexArrays(lutok::state& state){
		GLsizei count = (GLsizei)state.to_integer(1);
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
	int gl_Get(lutok::state& state){
		string fmt = state.to_string(1);
		GLenum pname = (GLenum) state.to_integer(2);
		unsigned int len = 1;
		char type[4];
		if (sscanf(fmt.c_str(), "%1s(%u)", type, &len) == 2){
			if (!strncmp(type, "s", 1)){
				const char * str = (char *) glGetString(pname);
				if (str){
					state.push_string(str);
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
	int gl_GetEx(lutok::state& state){
		GLenum pname = (GLenum) state.to_integer(1);
		string _type = state.to_string(2);
		unsigned int len = state.to_integer(3);
		char type = 0;
		if (_type.length()>0){
			type = _type[0];
		}

		switch (type){
		case 's':
			{const char * str = (char *) glGetString(pname);
			if (str){
				state.push_string(str);
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

	int gl_GetBufferSubData(lutok::state& state){
		size_t count = state.to_integer(3);
		unsigned char * buffer = new unsigned char[count];
		glGetBufferSubData((GLenum) state.to_integer(1), (GLintptr) state.to_integer(2), (GLsizeiptr) count*sizeof(unsigned char), buffer);
		setArray<unsigned char>(state, buffer, count);
		return 1;
	}
	int gl_GetBufferParameter(lutok::state& state){
		GLint result = 0;
		glGetBufferParameteriv((GLenum) state.to_integer(1), (GLenum) state.to_integer(2), &result);
		state.push_integer(result);
		return 1;
	}
	/*
		GetFramebufferAttachmentParameter(target, attachment, parameter_name)
	*/
	int gl_GetFramebufferAttachmentParameter(lutok::state& state){
		GLint parameters;

		glGetFramebufferAttachmentParameteriv(
			(GLenum) state.to_integer(1),
			(GLenum) state.to_integer(2),
			(GLenum) state.to_integer(3),
			&parameters
		);
		state.push_integer(parameters);
		return 1;
	}
	int gl_GetClipPlane(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glGetClipPlane()");
		return 0;
	}
	int gl_GetError(lutok::state& state){
		state.push_integer(glGetError());
		return 1;
	}
	int gl_GetLight(lutok::state& state){
		//glGetLight(
		return 0;
	}
	int gl_GetMap(lutok::state& state){
		//glGetMapf(
		return 0;
	}
	int gl_GetMaterial(lutok::state& state){
		//glGetMateriald(
		return 0;
	}
	int gl_GetPixelMap(lutok::state& state){
		return 0;
	}
	int gl_GetPointer(lutok::state& state){
		return 0;
	}
	int gl_GetPolygonStipple(lutok::state& state){
		return 0;
	}
	int gl_GetSwapInterval(lutok::state& state){
#ifdef __WGLEW_H__
		wglSwapIntervalEXT((int) state.to_integer(1));
		state.push_integer(wglGetSwapIntervalEXT());
#else
#ifdef __GLXEW_H__
		glXSwapIntervalEXT((int) state.to_integer(1));
		state.push_integer(glXGetSwapIntervalEXT());
#endif
#endif
		return 1;
	}
	int gl_GetTessProperty(lutok::state& state){
		return 0;
	}
	int gl_GetTexEnv(lutok::state& state){
		return 0;
	}
	int gl_GetTexGen(lutok::state& state){
		return 0;
	}
	int gl_GetTexImage(lutok::state& state){
		return 0;
	}
	int gl_GetTexLevelParameter(lutok::state& state){
		return 0;
	}
	int gl_GetTexParameter(lutok::state& state){
		return 0;
	}
	int gl_GetShaderInfoLog(lutok::state& state){
		int len=0;
		char buffer[4096];
		glGetShaderInfoLog((GLuint) state.to_integer(1), (GLsizei) 4096, (GLsizei *) &len, (GLchar*) buffer);
		state.push_lstring(buffer, len);
		return 1;
	}
	int gl_GetProgramInfoLog(lutok::state& state){
		int len=0;
		char buffer[4096];
		glGetProgramInfoLog((GLuint) state.to_integer(1), (GLsizei) 4096, (GLsizei *) &len, (GLchar*) buffer);
		state.push_lstring(buffer, len);
		return 1;
	}
	int gl_GetProgramiv(lutok::state& state){
		GLint value=0;
		glGetProgramiv((GLuint) state.to_integer(1), (GLenum) state.to_integer(2), (GLint *) &value);
		state.push_integer(value);
		return 1;
	}

	int gl_GetShaderiv(lutok::state& state){
		GLint value=0;
		glGetShaderiv((GLuint) state.to_integer(1), (GLuint) state.to_integer(2), &value);
		state.push_integer(value);
		return 1;
	}

	int gl_GetUniformLocation(lutok::state& state){
		std::string & name = state.to_string(2);
		int ret = (int) glGetUniformLocation((GLuint) state.to_integer(1), (const GLchar *) name.c_str());
		state.push_integer(ret);
		return 1;
	}

	int gl_GetUniformf(lutok::state & state){
		GLfloat value[4] = {0.0f, 0.0f, 0.0f, 0.0f};
		glGetUniformfv((GLuint) state.to_integer(1), (GLint) state.to_integer(2), value);
		for (int i=0; i<4; i++){
			state.push_number(value[i]);
		}
		return 4;
	}
	int gl_GetUniformi(lutok::state & state){
		GLint value[4] = {0, 0, 0, 0};
		glGetUniformiv((GLuint) state.to_integer(1), (GLint) state.to_integer(2), value);
		for (int i=0; i<4; i++){
			state.push_integer(value[i]);
		}
		return 4;
	}
	int gl_GetUniformui(lutok::state & state){
		GLuint value[4] = {0, 0, 0, 0};
		glGetUniformuiv((GLuint) state.to_integer(1), (GLint) state.to_integer(2), value);
		for (int i=0; i<4; i++){
			state.push_integer(value[i]);
		}
		return 4;
	}
	int gl_GetUniformd(lutok::state & state){
		GLdouble value[4] = {0.0f, 0.0f, 0.0f, 0.0f};
		glGetUniformdv((GLuint) state.to_integer(1), (GLint) state.to_integer(2), value);
		for (int i=0; i<4; i++){
			state.push_number(value[i]);
		}
		return 4;
	}
}