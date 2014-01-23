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
	int gl_FramebufferTexture2D(lutok::state& state){
		GLint level = 0;
		if (state.is_number(4)){
			level = state.to_integer(4);
		}
		glFramebufferTexture2D(GL_FRAMEBUFFER, (GLenum) state.to_integer(1), (GLenum) state.to_integer(2), (GLuint) state.to_integer(3), (GLint) level);
		return 0;
	}
	int gl_FramebufferTexture3D(lutok::state& state){
		GLint level = 0;
		if (state.is_number(4)){
			level = state.to_integer(4);
		}
		glFramebufferTexture3D(GL_FRAMEBUFFER, (GLenum) state.to_integer(1), (GLenum) state.to_integer(2), (GLuint) state.to_integer(3), (GLint) level, (GLint) state.to_integer(4));
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