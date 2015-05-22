#include "main.h"

namespace LuaGL {

inline void endian_swap(unsigned long& x){
	x = (x>>24) | 
		((x<<8) & 0x00FF0000) |
		((x>>8) & 0x0000FF00) |
		(x<<24);
}

template<> size_t getArray<double>(State& state, int index, vector<double> & out, size_t offset, size_t count){
	if (state.stack->is<LUA_TTABLE>(index)){
		if (count==0 || (offset > count)){
			count = state.stack->objLen(index);
		}
		out.reserve(count);
		for (size_t i=offset; i<count; i++){
			state.stack->push<int>(i+1);
			state.stack->getTable(index);
			if (state.stack->is<LUA_TNUMBER>()){
				out.push_back((double) state.stack->to<LUA_NUMBER>(-1));
			}
			state.stack->pop(1);
		}
	}
	return out.size();
}
template<> size_t getArray<float>(State& state, int index, vector<float> & out, size_t offset, size_t count){
	if (state.stack->is<LUA_TTABLE>(index)){
		if (count==0 || (offset > count)){
			count = state.stack->objLen(index);
		}
		out.reserve(count);
		for (size_t i=offset; i<count; i++){
			state.stack->push<int>(i+1);
			state.stack->getTable(index);
			if (state.stack->is<LUA_TNUMBER>()){
				out.push_back((float) state.stack->to<LUA_NUMBER>(-1));
			}
			state.stack->pop(1);
		}
	}
	return out.size();
}
template<> size_t getArray<int>(State& state, int index, vector<int> & out, size_t offset, size_t count){
	if (state.stack->is<LUA_TTABLE>(index)){
		if (count==0 || (offset > count)){
			count = state.stack->objLen(index);
		}
		out.reserve(count);
		for (size_t i=offset; i<count; i++){
			state.stack->push<int>(i+1);
			state.stack->getTable(index);
			if (state.stack->is<LUA_TNUMBER>()){
				out.push_back((int) state.stack->to<int>(-1));
			}
			state.stack->pop(1);
		}
	}
	return out.size();
}
template<> size_t getArray<unsigned int>(State& state, int index, vector<unsigned int> & out, size_t offset, size_t count){
	if (state.stack->is<LUA_TTABLE>(index)){
		if (count==0 || (offset > count)){
			count = state.stack->objLen(index);
		}
		out.reserve(count);
		for (size_t i=offset; i<count; i++){
			state.stack->push<int>(i+1);
			state.stack->getTable(index);
			if (state.stack->is<LUA_TNUMBER>()){
				out.push_back((unsigned int) state.stack->to<int>(-1));
			}
			state.stack->pop(1);
		}
	}
	return out.size();
}
template<> size_t getArray<double>(State& state, int index, vector<double> & out){
	if (state.stack->is<LUA_TTABLE>(index)){
		size_t count = state.stack->objLen(index);
		out.reserve(count);
		for (size_t i=0; i<count; i++){
			state.stack->push<int>(i+1);
			state.stack->getTable(index);
			if (state.stack->is<LUA_TNUMBER>()){
				out.push_back((double) state.stack->to<LUA_NUMBER>(-1));
			}
			state.stack->pop(1);
		}
	}
	return out.size();
}
template<> size_t getArray<float>(State& state, int index, vector<float> & out){
	if (state.stack->is<LUA_TTABLE>(index)){
		size_t count = state.stack->objLen(index);
		out.reserve(count);
		for (size_t i=0; i<count; i++){
			state.stack->push<int>(i+1);
			state.stack->getTable(index);
			if (state.stack->is<LUA_TNUMBER>()){
				out.push_back((float) state.stack->to<LUA_NUMBER>(-1));
			}
			state.stack->pop(1);
		}
	}
	return out.size();
}
template<> size_t getArray<int>(State& state, int index, vector<int> & out){
	if (state.stack->is<LUA_TTABLE>(index)){
		size_t count = state.stack->objLen(index);
		out.reserve(count);
		for (size_t i=0; i<count; i++){
			state.stack->push<int>(i+1);
			state.stack->getTable(index);
			if (state.stack->is<LUA_TNUMBER>()){
				out.push_back((int) state.stack->to<int>(-1));
			}
			state.stack->pop(1);
		}
	}
	return out.size();
}
template<> size_t getArray<unsigned int>(State& state, int index, vector<unsigned int> & out){
	if (state.stack->is<LUA_TTABLE>(index)){
		size_t count = state.stack->objLen(index);
		out.reserve(count);
		for (size_t i=0; i<count; i++){
			state.stack->push<int>(i+1);
			state.stack->getTable(index);
			if (state.stack->is<LUA_TNUMBER>()){
				out.push_back((unsigned int)state.stack->to<int>(-1));
			}
			state.stack->pop(1);
		}
	}
	return out.size();
}
template<> size_t getArray<unsigned char>(State& state, int index, vector<unsigned char> & out){
	size_t _count = 0;
	if (state.stack->is<LUA_TTABLE>(index)){
		size_t count = state.stack->objLen(index);
		out.reserve(count);
		for (size_t i=0; i<count; i++){
			state.stack->push<int>(i+1);
			state.stack->getTable(index);
			if (state.stack->is<LUA_TSTRING>()){
				out.push_back((unsigned char)state.stack->to<int>(-1));
			}
			state.stack->pop(1);
		}
	}
	return out.size();
}
template<> size_t getArray<std::string>(State& state, int index, vector<std::string> & out){
	if (state.stack->is<LUA_TTABLE>(index)){
		size_t count = state.stack->objLen(index);
		out.reserve(count);
		for (size_t i=0; i<count; i++){
			state.stack->push<int>(i+1);
			state.stack->getTable(index);
			if (state.stack->is<LUA_TNUMBER>()){
				const string str = state.stack->to<const string>(-1);
				out.push_back(str);
			}
			state.stack->pop(1);
		}
	}
	return out.size();
}
template<> void setArray<double>(State& state, vector<double> & in){
	state.stack->newTable();
	for (size_t i=0; i < in.size(); i++){
		state.stack->push<int>(i+1);
		state.stack->push<LUA_NUMBER>(in[i]);
		state.stack->setTable();
	}
}
template<> void setArray<float>(State& state, vector<float> & in){
	state.stack->newTable();
	for (size_t i=0; i < in.size(); i++){
		state.stack->push<int>(i+1);
		state.stack->push<LUA_NUMBER>(in[i]);
		state.stack->setTable();
	}
}
template<> void setArray<int>(State& state, vector<int> & in){
	state.stack->newTable();
	for (size_t i=0; i < in.size(); i++){
		state.stack->push<int>(i+1);
		state.stack->push<int>(in[i]);
		state.stack->setTable();
	}
}
template<> void setArray<unsigned int>(State& state, vector<unsigned int> & in){
	state.stack->newTable();
	for (size_t i=0; i < in.size(); i++){
		state.stack->push<int>(i+1);
		state.stack->push<int>(in[i]);
		state.stack->setTable();
	}
}

template<> void setArray<bool>(State& state, vector<bool> & in){
	state.stack->newTable();
	for (size_t i=0; i < in.size(); i++){
		state.stack->push<int>(i+1);
		state.stack->push<bool>(in[i]);
		state.stack->setTable();
	}
}
template<> void setArray<char*>(State& state, vector<char *> & in){
	state.stack->newTable();
	for (size_t i=0; i < in.size(); i++){
		state.stack->push<int>(i+1);
		state.stack->push<const string &>(in[i]);
		state.stack->setTable();
	}
}

template<> void setArray<double>(State& state, double * in, size_t length){
	state.stack->newTable();
	for (size_t i=0; i < length; i++){
		state.stack->push<int>(i+1);
		state.stack->push<LUA_NUMBER>(in[i]);
		state.stack->setTable();
	}
}
template<> void setArray<float>(State& state, float * in, size_t length){
	state.stack->newTable();
	for (size_t i=0; i < length; i++){
		state.stack->push<int>(i+1);
		state.stack->push<LUA_NUMBER>(in[i]);
		state.stack->setTable();
	}
}
template<> void setArray<int>(State& state, int * in, size_t length){
	state.stack->newTable();
	for (size_t i=0; i < length; i++){
		state.stack->push<int>(i+1);
		state.stack->push<int>(in[i]);
		state.stack->setTable();
	}
}
template<> void setArray<unsigned int>(State& state, unsigned int * in, size_t length){
	state.stack->newTable();
	for (size_t i=0; i < length; i++){
		state.stack->push<int>(i+1);
		state.stack->push<int>(in[i]);
		state.stack->setTable();
	}
}
template<> void setArray<bool>(State& state, bool * in, size_t length){
	state.stack->newTable();
	for (size_t i=0; i < length; i++){
		state.stack->push<int>(i+1);
		state.stack->push<bool>(in[i]);
		state.stack->setTable();
	}
}
template<> void setArray<char*>(State& state, char ** in, size_t length){
	state.stack->newTable();
	for (size_t i=0; i < length; i++){
		state.stack->push<int>(i+1);
		state.stack->push<const string &>(in[i]);
		state.stack->setTable();
	}
}
template<> void setArray<unsigned char>(State& state, unsigned char * in, size_t length){
	state.stack->newTable();
	for (size_t i=0; i < length; i++){
		state.stack->push<int>(i+1);
		state.stack->push<int>(in[i]);
		state.stack->setTable();
	}
}

};
