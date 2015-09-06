#include "main.h"

namespace LuaGL {
	int gl_CallList(State& state){
		glCallList((GLuint)state.stack->to<int>(1));
		return 0;
	}
	int gl_CallLists(State& state){
		GLint * data;
		vector<int> _data;
		size_t count=0;

		if (state.stack->is<LUA_TNUMBER>(1)){
			data = (GLint *) state.stack->to<int>(1);
		}else{
			if (state.stack->is<LUA_TTABLE>(1)){
				count = getArray<int>(state, 1, _data);
				data = _data.data();
			}else{
				data = NULL;
			}
		}

		glCallLists((GLsizei)count,GL_UNSIGNED_INT,(const GLvoid*)data);
		return 0;
	}
	int gl_CheckFramebufferStatus(State& state){
		GLenum result = glCheckFramebufferStatus(GL_FRAMEBUFFER);
		state.stack->push<int>(result);
		return 1;
	}
	int gl_Clear(State& state){
		glClear((GLuint)state.stack->to<int>(1));
		return 0;
	}
	int gl_ClearColor(State& state){
		glClearColor((GLclampf)state.stack->to<LUA_NUMBER>(1),(GLclampf)state.stack->to<LUA_NUMBER>(2),(GLclampf)state.stack->to<LUA_NUMBER>(3),(GLclampf)state.stack->to<LUA_NUMBER>(4));
		return 0;
	}
	int gl_ClearAccum(State& state){
		glClearAccum((GLfloat)state.stack->to<LUA_NUMBER>(1),(GLfloat)state.stack->to<LUA_NUMBER>(2),(GLfloat)state.stack->to<LUA_NUMBER>(3),(GLfloat)state.stack->to<LUA_NUMBER>(4));
		return 0;
	}
	int gl_ClearBuffer(State& state){
		Stack * stack = state.stack;
		GLenum buffer = static_cast<GLenum>(state.stack->to<int>(1));
		GLint drawBuffer = static_cast<GLint>(state.stack->to<LUA_NUMBER>(2));
		glClearBufferfi(buffer, drawBuffer, static_cast<GLfloat>(state.stack->to<LUA_NUMBER>(3)), static_cast<GLint>(state.stack->to<int>(4)));
		return 0;
	}

	int gl_ClearBufferi(State& state){
		Stack * stack = state.stack;
		GLenum buffer = static_cast<GLenum>(state.stack->to<int>(1));
		GLint drawBuffer = static_cast<GLint>(state.stack->to<LUA_NUMBER>(2));
		if (stack->is<LUA_TTABLE>(3)){

			GLint values​[4] = { 0, 0, 0, 0 };
			for (int i = 0; i < stack->objLen(3); i++){
				stack->getField(i + 1, 3);
				values​[i] = stack->to<int>(-1);
				stack->pop(1);
			}
			glClearBufferiv(buffer, drawBuffer, values​);
		}
		return 0;
	}

	int gl_ClearBufferf(State& state){
		Stack * stack = state.stack;
		GLenum buffer = static_cast<GLenum>(state.stack->to<int>(1));
		GLint drawBuffer = static_cast<GLint>(state.stack->to<LUA_NUMBER>(2));
		if (stack->is<LUA_TTABLE>(3)){

			GLfloat values​[4] = { 0, 0, 0, 0 };
			for (int i = 0; i < stack->objLen(3); i++){
				stack->getField(i + 1, 3);
				values​[i] = static_cast<GLfloat>(stack->to<LUA_NUMBER>(-1));
				stack->pop(1);
			}
			glClearBufferfv(buffer, drawBuffer, values​);
		}
		return 0;
	}

	int gl_ClearDepth(State& state){
		glClearDepth((GLclampd)state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
	int gl_ClearIndex(State& state){
		glClearIndex((GLfloat)state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
	int gl_ClearStencil(State& state){
		glClearStencil((GLint)state.stack->to<int>(1));
		return 0;
	}
	int gl_ClientActivetexture(State& state){
		glClientActiveTexture((GLenum) state.stack->to<int>(1));
		return 0;
	}
	int gl_Color3f(State& state){
		glColor3f((GLfloat)state.stack->to<LUA_NUMBER>(1),(GLfloat)state.stack->to<LUA_NUMBER>(2),(GLfloat)state.stack->to<LUA_NUMBER>(3));
		return 0;
	}
	int gl_Color4x(State& state){
		unsigned long color = state.stack->to<int>(1);
		GLfloat mult = 1/256.0f;
		glColor4f(((GLfloat)(color >> 24))*mult,((GLfloat)((color & 0xFF0000)>>16))*mult,((GLfloat)((color & 0xFF00)>>8))*mult,((GLfloat)(color & 0xFF))*mult);
		return 0;
	}
	int gl_Color4f(State& state){
		glColor4f((GLfloat)state.stack->to<LUA_NUMBER>(1),(GLfloat)state.stack->to<LUA_NUMBER>(2),(GLfloat)state.stack->to<LUA_NUMBER>(3),(GLfloat)state.stack->to<LUA_NUMBER>(4));
		return 0;
	}
	int gl_ClipPlane(State& state){
		GLdouble eq[4];
		int plane = (int)state.stack->to<int>(1);
		if (state.stack->is<LUA_TTABLE>(2)){
			state.stack->getField(1, 2);
			state.stack->getField(2, 2);
			state.stack->getField(3, 2);
			state.stack->getField(4, 2);

			eq[0] = state.stack->to<LUA_NUMBER>(-4);
			eq[1] = state.stack->to<LUA_NUMBER>(-3);
			eq[2] = state.stack->to<LUA_NUMBER>(-2);
			eq[3] = state.stack->to<LUA_NUMBER>(-1);

			state.stack->pop(4);
		}
		glClipPlane((GLenum)plane,(GLdouble*)eq);
		return 0;
	}
	int gl_Color3d(State& state){
		glColor3d((GLdouble)state.stack->to<LUA_NUMBER>(1),(GLdouble)state.stack->to<LUA_NUMBER>(2),(GLdouble)state.stack->to<LUA_NUMBER>(3));
		return 0;
	}
	int gl_Color3dv(State& state){
		//__RENDER->dprintf("Stub(%s)","glColor3dv()");
		return 0;
	}
	int gl_Color3fv(State& state){
		//__RENDER->dprintf("Stub(%s)","glColor3fv()");
		return 0;
	}
	int gl_Color4d(State& state){
		glColor4d((GLdouble)state.stack->to<LUA_NUMBER>(1),(GLdouble)state.stack->to<LUA_NUMBER>(2),(GLdouble)state.stack->to<LUA_NUMBER>(3),(GLdouble)state.stack->to<LUA_NUMBER>(4));
		return 0;
	}
	int gl_Color4dv(State& state){
		//__RENDER->dprintf("Stub(%s)","glColor3dv()");
		return 0;
	}
	int gl_Color4fv(State& state){
		//__RENDER->dprintf("Stub(%s)","glColor4fv()");
		return 0;
	}

	int gl_Color4b(State& state){
		glColor4ub((GLbyte)state.stack->to<int>(1),(GLbyte)state.stack->to<int>(2),(GLbyte)state.stack->to<int>(3),(GLbyte)state.stack->to<int>(4));
		return 0;
	}

	int gl_ColorMask(State& state){
		glColorMask((GLboolean)state.stack->to<bool>(1),(GLboolean)state.stack->to<bool>(2),(GLboolean)state.stack->to<bool>(3),(GLboolean)state.stack->to<bool>(4));
		return 0;
	}
	int gl_ColorMaterial(State& state){
		glColorMaterial((GLenum)state.stack->to<LUA_NUMBER>(1),(GLenum)state.stack->to<LUA_NUMBER>(2));
		return 0;
	}
	int gl_ColorPointer(State& state){
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
				/* call opengl function */
				glColorPointer(nsize, GL_FLOAT, 0, data);
			}
		}
		return 0;
	}
	int gl_CompileShader(State& state){
		glCompileShader((GLuint) state.stack->to<int>(1));
		return 0;
	}
	int gl_CopyPixels(State& state){
		glCopyPixels((GLint)state.stack->to<int>(1),(GLint)state.stack->to<int>(2),(GLsizei)state.stack->to<int>(3),(GLsizei)state.stack->to<int>(4),(GLenum)state.stack->to<int>(5));
		return 0;
	}
	/*
		CopyTexImage1D(target, level, internalFormat, x, y, width, border)
	*/
	int gl_CopyTexImage1D(State& state){
		glCopyTexImage1D(
			(GLenum)state.stack->to<int>(1),
			(GLint)state.stack->to<int>(2),
			(GLenum)state.stack->to<int>(3),
			(GLint)state.stack->to<int>(4),
			(GLint)state.stack->to<int>(5),
			(GLsizei)state.stack->to<int>(6),
			(GLint)state.stack->to<int>(7)
		);
		return 0;
	}
	/*
		CopyTexImage1D(target, level, internalFormat, x, y, width, height, border)
	*/
	int gl_CopyTexImage2D(State& state){
		glCopyTexImage2D(
			(GLenum)state.stack->to<int>(1),
			(GLint)state.stack->to<int>(2),
			(GLenum)state.stack->to<int>(3),
			(GLint)state.stack->to<int>(4),
			(GLint)state.stack->to<int>(5),
			(GLsizei)state.stack->to<int>(6),
			(GLsizei)state.stack->to<int>(7),
			(GLint)state.stack->to<int>(8)
		);
		return 0;
	}
	/*
		CopyTexSubImage1D(target, level, offset, x, y, width)
	*/
	int gl_CopyTexSubImage1D(State& state){
		glCopyTexSubImage1D(
			(GLenum)state.stack->to<int>(1),
			(GLint)state.stack->to<int>(2),
			(GLint)state.stack->to<int>(3),
			(GLint)state.stack->to<int>(4),
			(GLsizei)state.stack->to<int>(5),
			(GLsizei)state.stack->to<int>(6)
		);
		return 0;
	}
	/*
		CopyTexSubImage2D(target, level, x_offset, y_offset, x, y, width, height)
	*/
	int gl_CopyTexSubImage2D(State& state){
		glCopyTexSubImage2D(
			(GLenum)state.stack->to<int>(1),//target
			(GLuint)state.stack->to<int>(2),//level
			(GLuint)state.stack->to<int>(3),//xoffset
			(GLuint)state.stack->to<int>(4),//yoffset
			(GLuint)state.stack->to<int>(5),//x
			(GLuint)state.stack->to<int>(6),//y
			(GLsizei)state.stack->to<int>(7),//width
			(GLsizei)state.stack->to<int>(8));//height
		return 0;
	}
	/*
		CopyTexSubImage3D(target, level, x_offset, y_offset, z_offset, x, y, width, height)
	*/
	int gl_CopyTexSubImage3D(State& state){
		glCopyTexSubImage3D(
			(GLenum)state.stack->to<int>(1), //target
			(GLuint)state.stack->to<int>(2), //level
			(GLuint)state.stack->to<int>(3), //xoffset
			(GLuint)state.stack->to<int>(4), //yoffset
			(GLuint)state.stack->to<int>(5), //zoffset
			(GLuint)state.stack->to<int>(6), //x
			(GLuint)state.stack->to<int>(7), //y
			(GLuint)state.stack->to<int>(8), //width
			(GLuint)state.stack->to<int>(9)); //height
		return 0;
	}
	/*
		CopyBufferSubData(read_target, write_target, read_offset, write_offset, size)
	*/
	int gl_CopyBufferSubData(State& state){
		glCopyBufferSubData(
			(GLenum)state.stack->to<int>(1),
			(GLenum)state.stack->to<int>(2),
			(GLintptr)state.stack->to<int>(3),
			(GLintptr)state.stack->to<int>(4),
			(GLsizeiptr)state.stack->to<int>(5)
		);
		return 0;
	}
	/*
		CopyImageSubData(src_name, src_target, src_level, src_x, src_y, src_z, dest_nam, dest_target, dest_level, dest_x, dest_y, dest_z, src_width, src_height, src_depth)
	*/
	int gl_CopyImageSubData(State& state){
		glCopyImageSubData(
			(GLuint)state.stack->to<int>(1),
			(GLenum)state.stack->to<int>(2),
			(GLint)state.stack->to<int>(3),
			(GLint)state.stack->to<int>(4),
			(GLint)state.stack->to<int>(5),
			(GLint)state.stack->to<int>(6),
			(GLuint)state.stack->to<int>(7),
			(GLenum)state.stack->to<int>(8),
			(GLint)state.stack->to<int>(9),
			(GLint)state.stack->to<int>(10),
			(GLint)state.stack->to<int>(11),
			(GLint)state.stack->to<int>(12),
			(GLsizei)state.stack->to<int>(13),
			(GLsizei)state.stack->to<int>(14),
			(GLsizei)state.stack->to<int>(15)
		);
		return 0;
	}
	int gl_CreateProgram(State& state){
		int result = glCreateProgram();
		state.stack->push<int>(result);
		return 1;
	}
	int gl_CreateShader(State& state){
		int result = glCreateShader((GLenum)state.stack->to<int>(1));
		state.stack->push<int>(result);
		return 1;
	}
	int gl_CullFace(State& state){
		glCullFace((GLenum)state.stack->to<int>(1));
		return 0;
	}

}