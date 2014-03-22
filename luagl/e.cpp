#include "main.h"

namespace GLex {
	int gl_EdgeFlag(lutok::state& state){
		glEdgeFlag((GLboolean)state.to_boolean(1));
		return 0;
	}
	int gl_EdgeFlagPointer(lutok::state& state){
		if (state.is_number(1)){
			GLint size = 0;
			GLint nsize = state.to_integer(1);
			GLboolean * data;
			vector<unsigned char> _data;

			if (state.is_number(2)){
				data = (GLboolean *) state.to_integer(2);
			}else{
				if (state.is_table(2)){
					size = getArray<unsigned char>(state, 2, _data);
					data = static_cast<GLboolean*>(_data.data());
				}else{
					data = NULL;
				}
			}
			if ((data && (nsize<=size)) || (nsize>=1 && nsize <= 4)){
				/* call opengl function */
				glEdgeFlagPointer(0, data);
			}
		}
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
	int gl_EndConditionalRender(lutok::state& state){
		glEndConditionalRender();
		return 0;
	}
	int gl_EndQuery(lutok::state& state){
		glEndQuery(
			(GLenum) state.to_integer(1)
			);
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