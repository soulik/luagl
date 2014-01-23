#include "main.h"

namespace GLex {

int lua_glewInit(lutok::state& state){
	GLenum err = glewInit();
	if (GLEW_OK != err)	{
		/* Problem: glewInit failed, something is seriously wrong. */
		state.push_nil();
		state.push_string((const char *)glewGetErrorString(err));
	}else{
		state.push_boolean(true);
		state.push_fstring("GLEW %s",glewGetString(GLEW_VERSION));
	}
	return 2;
}

int lua_glewIsSupported(lutok::state& state){
	if (state.is_string(1)){
		state.push_boolean(glewIsSupported(state.to_string(1).c_str()));
		return 1;
	}else{
		return 0;
	}
}

};