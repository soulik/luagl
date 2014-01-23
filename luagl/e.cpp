#include "main.h"

namespace GLex {
	int gl_EdgeFlag(lutok::state& state){
		glEdgeFlag((GLboolean)state.to_boolean(1));
		return 0;
	}
	int gl_EdgeFlagPointer(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glEdgeFlagPointer()");
		return 0;
	}
	int gl_Enable(lutok::state& state){
		glEnable((GLuint) state.to_integer(1));
		return 0;
	}
	int gl_EnableClientState(lutok::state& state){
		glEnableClientState((GLenum) state.to_integer(1));
		return 0;
	}
	int gl_EnableVertexAttribArray(lutok::state& state){
		glEnableVertexAttribArray((GLuint) state.to_integer(1));
		return 0;
	}
	int gl_End(lutok::state& state){
		glEnd();
		return 0;
	}
	int gl_EndList(lutok::state& state){
		glEndList();
		return 0;
	}
	int glu_ErrorString(lutok::state& state){
		int name = (int) state.to_integer(1);
		state.push_string(reinterpret_cast<const char *>(gluErrorString(name)));
		return 1;
	}
	int gl_EvalCoord(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glEvalCoord()");
		return 0;
	}
	int gl_EvalMesh(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glEvalMesh()");
		return 0;
	}
	int gl_EvalPoint(lutok::state& state){
		//__RENDER->dprintf("Stub(%s)","glEvalPoint()");
		return 0;
	}

}