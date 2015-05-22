#include "main.h"

namespace LuaGL {
	int gl_EdgeFlag(State& state){
		glEdgeFlag((GLboolean)state.stack->to<bool>(1));
		return 0;
	}
	int gl_EdgeFlagPointer(State& state){
		if (state.stack->is<LUA_TNUMBER>(1)){
			GLint size = 0;
			GLint nsize = state.stack->to<int>(1);
			GLboolean * data;
			vector<unsigned char> _data;

			if (state.stack->is<LUA_TNUMBER>(2)){
				data = (GLboolean *) state.stack->to<int>(2);
			}else{
				if (state.stack->is<LUA_TTABLE>(2)){
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
	int gl_Enable(State& state){
		glEnable((GLuint) state.stack->to<int>(1));
		return 0;
	}
	int gl_EnableClientState(State& state){
		glEnableClientState((GLenum) state.stack->to<int>(1));
		return 0;
	}
	int gl_EnableVertexAttribArray(State& state){
		glEnableVertexAttribArray((GLuint) state.stack->to<int>(1));
		return 0;
	}
	int gl_End(State& state){
		glEnd();
		return 0;
	}
	int gl_EndConditionalRender(State& state){
		glEndConditionalRender();
		return 0;
	}
	int gl_EndQuery(State& state){
		glEndQuery(
			(GLenum) state.stack->to<int>(1)
			);
		return 0;
	}
	int gl_EndList(State& state){
		glEndList();
		return 0;
	}
	int glu_ErrorString(State& state){
		int name = (int) state.stack->to<int>(1);
		const string errorMessage = reinterpret_cast<const char *>(gluErrorString(name));
		state.stack->push<const string &>(errorMessage);
		return 1;
	}
	int gl_EvalCoord(State& state){
		//__RENDER->dprintf("Stub(%s)","glEvalCoord()");
		return 0;
	}
	int gl_EvalMesh(State& state){
		//__RENDER->dprintf("Stub(%s)","glEvalMesh()");
		return 0;
	}
	int gl_EvalPoint(State& state){
		//__RENDER->dprintf("Stub(%s)","glEvalPoint()");
		return 0;
	}

}