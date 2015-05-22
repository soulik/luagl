#define	SELECT_BUF_SIZE	512

extern GLuint selectBuffer[SELECT_BUF_SIZE];

#define loadGLFunction(FNAME,WGLPROC)	\
	FNAME			= (WGLPROC) FN_GL_GetProcAddress(#FNAME);	\
	setTableValueb(L,#FNAME,(FNAME)?1:0);

namespace LuaGL {

template<typename T> size_t getArray(State & state, int index, vector<T> & out, size_t offset, size_t count);
template<typename T> size_t getArray(State & state, int index, vector<T> & out);
template<typename T> void setArray(State & state, vector<T> & in);
template<typename T> void setArray(State & state, T * in, size_t length);

GL_DEF_FN(lua_glewInit);
GL_DEF_FN(lua_glewIsSupported);

};
