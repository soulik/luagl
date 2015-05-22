#include "main.h"

namespace LuaGL {

int lua_glewInit(State& state){
	GLenum err = glewInit();
	if (GLEW_OK != err)	{
		/* Problem: glewInit failed, something is seriously wrong. */
		state.stack->pushNil();
		state.stack->push<const string &>((const char *)glewGetErrorString(err));
	}else{
		state.stack->push<bool>(true);
		state.stack->pushVFString("GLEW %s",glewGetString(GLEW_VERSION));
	}
	return 2;
}

int lua_glewIsSupported(State& state){
	if (state.stack->is<LUA_TSTRING>(1)){
		state.stack->push<bool>(glewIsSupported(state.stack->to<const string>(1).c_str()));
		return 1;
	}else{
		return 0;
	}
}

};