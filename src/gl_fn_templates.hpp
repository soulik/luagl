namespace LuaGL {

template <typename T, typename TGL> int gl_BufferData(State& state){
	GLenum target = state.stack->to<int>(1);
	GLsizei size = 0;

	TGL * data;
	vector<T> _data;

	if (state.stack->is<LUA_TNUMBER>(2)){
		size = (GLsizei) state.stack->to<int>(2);
		data = NULL;
	}else{
		if (state.stack->is<LUA_TTABLE>(2)){
			size = getArray<T>(state, 2, _data);
			data = _data.data();
		}else{
			data = NULL;
		}
	}
	GLenum usage = state.stack->to<int>(3);
	GLsizeiptr data_size = size * sizeof(TGL);
	glBufferData(target, data_size, data, usage);
	return 0;
}

template <typename T, typename TGL> int gl_BufferSubData(State& state){
	GLenum target = state.stack->to<int>(1);
	GLint offset = state.stack->to<int>(2);
	GLsizei size = 0;
	TGL * data;
	vector<T> _data;

	if (state.stack->is<LUA_TNUMBER>(3)){
		data = (TGL *) state.stack->to<int>(3);
	}else{
		if (state.stack->is<LUA_TTABLE>(3)){
			size = getArray<T>(state, 3, _data);
			data = _data.data();
		}else{
			data = NULL;
		}
	}
	GLintptr data_offset = offset * sizeof(TGL);
	GLsizeiptr data_size = size * sizeof(TGL);
	glBufferSubData(target, data_offset, data_size, data);
	return 0;
}
};
