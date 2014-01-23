#include "main.h"

namespace GLex {
	int gl_CallList(lutok::state& state){
		glCallList((GLuint)state.to_integer(1));
		return 0;
	}
	int gl_CallLists(lutok::state& state){
		GLint * data;
		vector<int> _data;
		size_t count=0;

		if (state.is_number(1)){
			data = (GLint *) state.to_integer(1);
		}else{
			if (state.is_table(1)){
				count = getArray<int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}

		glCallLists((GLsizei)count,GL_UNSIGNED_INT,(const GLvoid*)data);
		return 0;
	}
	int gl_CheckFramebufferStatus(lutok::state& state){
		GLenum result = glCheckFramebufferStatus(GL_FRAMEBUFFER);
		state.push_integer(result);
		return 1;
	}
	int gl_Clear(lutok::state& state){
		glClear((GLuint)state.to_integer(1));
		return 0;
	}
	int gl_ClearColor(lutok::state& state){
		glClearColor((GLclampf)state.to_number(1),(GLclampf)state.to_number(2),(GLclampf)state.to_number(3),(GLclampf)state.to_number(4));
		return 0;
	}
	int gl_ClearAccum(lutok::state& state){
		glClearAccum((GLfloat)state.to_number(1),(GLfloat)state.to_number(2),(GLfloat)state.to_number(3),(GLfloat)state.to_number(4));
		return 0;
	}
	int gl_ClearDepth(lutok::state& state){
		glClearDepth((GLclampd)state.to_number(1));
		return 0;
	}
	int gl_ClearIndex(lutok::state& state){
		glClearIndex((GLfloat)state.to_number(1));
		return 0;
	}
	int gl_ClearStencil(lutok::state& state){
		glClearStencil((GLint)state.to_integer(1));
		return 0;
	}
	int gl_ClientActivetexture(lutok::state& state){
		glClientActiveTexture((GLenum) state.to_integer(1));
		return 0;
	}
	int gl_Color3f(lutok::state& state){
		glColor3f((GLfloat)state.to_number(1),(GLfloat)state.to_number(2),(GLfloat)state.to_number(3));
		return 0;
	}
	int gl_Color4x(lutok::state& state){
		unsigned long color = state.to_integer(1);
		GLfloat mult = 1/256.0f;
		glColor4f(((GLfloat)(color >> 24))*mult,((GLfloat)((color & 0xFF0000)>>16))*mult,((GLfloat)((color & 0xFF00)>>8))*mult,((GLfloat)(color & 0xFF))*mult);
		return 0;
	}
	int gl_Color4f(lutok::state& state){
		glColor4f((GLfloat)state.to_number(1),(GLfloat)state.to_number(2),(GLfloat)state.to_number(3),(GLfloat)state.to_number(4));
		return 0;
	}
	int gl_ClipPlane(lutok::state& state){
		GLdouble eq[4];
		int plane = (int)state.to_integer(1);
		if (state.is_table(2)){
			eq[0] = state.get_array<double>(2, 1);
			eq[1] = state.get_array<double>(2, 2);
			eq[2] = state.get_array<double>(2, 3);
			eq[3] = state.get_array<double>(2, 4);
		}
		glClipPlane((GLenum)plane,(GLdouble*)eq);
		return 0;
	}
	int gl_Color3d(lutok::state& state){
		glColor3d((GLdouble)state.to_number(1),(GLdouble)state.to_number(2),(GLdouble)state.to_number(3));
		return 0;
	}
	int gl_Color3dv(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glColor3dv()");
		return 0;
	}
	int gl_Color3fv(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glColor3fv()");
		return 0;
	}
	int gl_Color4d(lutok::state& state){
		glColor4d((GLdouble)state.to_number(1),(GLdouble)state.to_number(2),(GLdouble)state.to_number(3),(GLdouble)state.to_number(4));
		return 0;
	}
	int gl_Color4dv(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glColor3dv()");
		return 0;
	}
	int gl_Color4fv(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glColor4fv()");
		return 0;
	}

	int gl_Color4b(lutok::state& state){
		glColor4ub((GLbyte)state.to_integer(1),(GLbyte)state.to_integer(2),(GLbyte)state.to_integer(3),(GLbyte)state.to_integer(4));
		return 0;
	}

	int gl_ColorMask(lutok::state& state){
		glColorMask((GLboolean)state.to_boolean(1),(GLboolean)state.to_boolean(2),(GLboolean)state.to_boolean(3),(GLboolean)state.to_boolean(4));
		return 0;
	}
	int gl_ColorMaterial(lutok::state& state){
		glColorMaterial((GLenum)state.to_number(1),(GLenum)state.to_number(2));
		return 0;
	}
	int gl_ColorPointer(lutok::state& state){
		GLint size = 0;
		GLdouble * data;
		vector<double> _data;

		if (state.is_number(1)){
			data = (GLdouble *) state.to_integer(1);
		}else{
			if (state.is_table(1)){
				size = getArray<double>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}

		/* call opengl function */
		glColorPointer(size, GL_DOUBLE, 0, data);
		return 0;
	}
	int gl_CompileShader(lutok::state& state){
		glCompileShader((GLuint) state.to_integer(1));
		return 0;
	}
	int gl_CopyPixels(lutok::state& state){
		glCopyPixels((GLint)state.to_integer(1),(GLint)state.to_integer(2),(GLsizei)state.to_integer(3),(GLsizei)state.to_integer(4),(GLenum)state.to_integer(5));
		return 0;
	}
	int gl_CopyTexImage1D(lutok::state& state){
		glCopyTexImage1D(GL_TEXTURE_1D,(GLint)state.to_integer(1),(GLenum)state.to_integer(2),(GLint)state.to_integer(3),(GLint)state.to_integer(4),(GLsizei)state.to_integer(5),(GLint)state.to_integer(6));
		return 0;
	}
	int gl_CopyTexImage2D(lutok::state& state){
		glCopyTexImage2D(GL_TEXTURE_2D,(GLint)state.to_integer(1),(GLenum)state.to_integer(2),(GLint)state.to_integer(3),(GLint)state.to_integer(4),(GLsizei)state.to_integer(5),(GLsizei)state.to_integer(6),(GLint)state.to_integer(7));
		return 0;
	}
	int gl_CopyTexSubImage1D(lutok::state& state){
		glCopyTexSubImage1D(GL_TEXTURE_1D,(GLint)state.to_integer(1),(GLint)state.to_integer(2),(GLint)state.to_integer(3),(GLsizei)state.to_integer(4),(GLsizei)state.to_integer(5));
		return 0;
	}
	int gl_CopyTexSubImage2D(lutok::state& state){
		glCopyTexSubImage2D(
			(GLenum)state.to_integer(1),//target
			(GLuint)state.to_integer(2),//level
			(GLuint)state.to_integer(3),//xoffset
			(GLuint)state.to_integer(4),//yoffset
			(GLuint)state.to_integer(5),//x
			(GLuint)state.to_integer(6),//y
			(GLsizei)state.to_integer(7),//width
			(GLsizei)state.to_integer(8));//height
		return 0;
	}
	int gl_CopyTexSubImage3D(lutok::state& state){
		glCopyTexSubImage3D(
			(GLenum)state.to_integer(1), //target
			(GLuint)state.to_integer(2), //level
			(GLuint)state.to_integer(3), //xoffset
			(GLuint)state.to_integer(4), //yoffset
			(GLuint)state.to_integer(5), //zoffset
			(GLuint)state.to_integer(6), //x
			(GLuint)state.to_integer(7), //y
			(GLuint)state.to_integer(8), //width
			(GLuint)state.to_integer(9)); //height
		return 0;
	}
	int gl_CreateProgram(lutok::state& state){
		int result = glCreateProgram();
		state.push_integer(result);
		return 1;
	}
	int gl_CreateShader(lutok::state& state){
		int result = glCreateShader((GLenum)state.to_integer(1));
		state.push_integer(result);
		return 1;
	}
	int gl_CullFace(lutok::state& state){
		glCullFace((GLenum)state.to_integer(1));
		return 0;
	}

}