#include "main.h"

namespace GLex {
	int gl_FeedbackBuffer(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glFeedbackBuffer()");
		//glFeedbackBuffer((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,1));
		return 0;
	}
	int gl_Finish(lutok::state& state){
		glFinish();
		return 0;
	}
	int gl_Flush(lutok::state& state){
		glFlush();
		return 0;
	}
	int gl_Fog(lutok::state& state){
		glFogf((GLenum) state.to_integer(1), (GLfloat) state.to_number(2));
		return 0;
	}
	int gl_FogCoordPointer(lutok::state& state){
		if (state.is_number(1)){
			GLint size = 0;
			GLint nsize = state.to_integer(1);
			GLfloat * data;
			vector<float> _data;

			if (state.is_number(2)){
				data = (GLfloat *) state.to_integer(2);
			}else{
				if (state.is_table(2)){
					size = getArray<float>(state, 2, _data);
					data = _data.data();
				}else{
					data = NULL;
				}
			}
			if ((data && (nsize<=size)) || (nsize>=1 && nsize <= 4)){
				/* call opengl function */
				glFogCoordPointer(GL_FLOAT, 0, data);
			}
		}
		return 0;
	}
	/*
		FramebufferParameter(target, name, value)
	*/
	int gl_FramebufferParameter(lutok::state& state){
		glFramebufferParameteri(
			(GLenum) state.to_integer(1),
			(GLenum) state.to_integer(2),
			(GLint) state.to_integer(3)
		);
		return 0;
	}
	/*
		FramebufferParameter(target, attachment, renderbuffer_target, renderbuffer)
	*/
	int gl_FramebufferRenderbuffer(lutok::state& state){
		glFramebufferRenderbuffer(
			(GLenum) state.to_integer(1),
			(GLenum) state.to_integer(2),
			(GLenum) state.to_integer(3),
			(GLuint) state.to_integer(4)
		);
		return 0;
	}
	/*
		FramebufferTexture(target, attachment, texture, level)
	*/
	int gl_FramebufferTexture(lutok::state& state){
		glFramebufferTexture(
			(GLenum) state.to_integer(1),
			(GLenum) state.to_integer(2),
			(GLuint) state.to_integer(3),
			(GLint) state.to_integer(4)
		);
		return 0;
	}
	/*
		FramebufferTexture1D(target, attachment, texture_target, texture, level)
	*/
	int gl_FramebufferTexture1D(lutok::state& state){
		glFramebufferTexture1D(
			(GLenum) state.to_integer(1),
			(GLenum) state.to_integer(2),
			(GLenum) state.to_integer(3),
			(GLuint) state.to_integer(4),
			(GLint) state.to_integer(5)
		);
		return 0;
	}
	/*
		FramebufferTexture2D(target, attachment, texture_target, texture, level)
	*/
	int gl_FramebufferTexture2D(lutok::state& state){
		glFramebufferTexture2D(
			(GLenum) state.to_integer(1),
			(GLenum) state.to_integer(2),
			(GLenum) state.to_integer(3),
			(GLuint) state.to_integer(4),
			(GLint) state.to_integer(5)
		);
		return 0;
	}
	/*
		FramebufferTexture3D(target, attachment, texture_target, texture, level, layer)
	*/
	int gl_FramebufferTexture3D(lutok::state& state){
		glFramebufferTexture3D(
			(GLenum) state.to_integer(1),
			(GLenum) state.to_integer(2),
			(GLenum) state.to_integer(3),
			(GLuint) state.to_integer(4),
			(GLint) state.to_integer(5),
			(GLint) state.to_integer(6)
		);
		return 0;
	}
	/*
		FramebufferTextureLayer(target, attachment, texture, level, layer)
	*/
	int gl_FramebufferTextureLayer(lutok::state& state){
		glFramebufferTextureLayer(
			(GLenum) state.to_integer(1),
			(GLenum) state.to_integer(2),
			(GLuint) state.to_integer(3),
			(GLint) state.to_integer(4),
			(GLint) state.to_integer(5)
			);
		return 0;
	}
	int gl_FrontFace(lutok::state& state){
		glFrontFace((GLuint)state.to_integer(1));
		return 0;
	}
	int gl_Frustum(lutok::state& state){
		glFrustum((GLdouble) state.to_number(1), (GLdouble) state.to_number(2), (GLdouble) state.to_number(3), (GLdouble) state.to_number(4), (GLdouble) state.to_number(5), (GLdouble) state.to_number(6));
		return 0;
	}

}