namespace GLex {

template <typename T, typename TGL> int gl_BufferData(lutok::state& state){
	GLenum target = state.to_integer(1);
	GLsizei size = 0;

	TGL * data;
	vector<T> _data;

	if (state.is_number(2)){
		size = (GLsizei) state.to_integer(2);
		data = NULL;
	}else{
		if (state.is_table(2)){
			size = getArray<T>(state, 2, _data);
			data = _data.data();
		}else{
			data = NULL;
		}
	}
	GLenum usage = state.to_integer(3);
	GLsizeiptr data_size = size * sizeof(TGL);
	glBufferData(target, data_size, data, usage);
	return 0;
}

template <typename T, typename TGL> int gl_BufferSubData(lutok::state& state){
	GLenum target = state.to_integer(1);
	GLint offset = state.to_integer(2);
	GLsizei size = 0;
	TGL * data;
	vector<T> _data;

	if (state.is_number(3)){
		data = (TGL *) state.to_integer(3);
	}else{
		if (state.is_table(3)){
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
