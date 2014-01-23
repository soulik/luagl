#include "main.h"

void mem_resize(tMemTable * t, size_t size){
	t->data = (MEM_TYPE*) realloc(t->data,sizeof(MEM_TYPE)*size);
	t->size = size;
}

int mem_set(lua_State * L){
	if (isType(L,1,MEM_TABLE)){
		tMemTable * data = *(tMemTable **)lua_touserdata(L,1);
		if (data){
			if (lua_type(L,2)==LUA_TTABLE){
				size_t n = luaL_getn(L, 2);
				if (n>data->size){
					mem_resize(data,n);
				}
				for(size_t i = 0; i < n; i++){
					lua_rawgeti(L, 2, i + 1);
					data->data[i] = (MEM_TYPE)lua_tonumber(L, -1);
				}
			}
		}
	}
	return 0;
}

int mem_new(lua_State * L){
	size_t size = lua_tointeger(L,1);
	unsigned int flags = lua_tointeger(L,2);
	if (size>=0){
		tMemTable ** data = (tMemTable **)lua_newuserdata(L,sizeof(tMemTable*));
		(*data) = (tMemTable*) malloc(sizeof(tMemTable));
		if (size>0){
			(*data)->data = (MEM_TYPE*) malloc(sizeof(MEM_TYPE)*size);
			(*data)->size = size;
		}else{
			(*data)->data = NULL;
			(*data)->size = size;
		}
		(*data)->flags = flags;
		luaL_getmetatable(L,MEM_TABLE);
		lua_setmetatable(L,-2);
		return 1;
	}
	return 0;
}

static int mem_index(lua_State * L){
	if (isType(L,1,MEM_TABLE)){
		tMemTable * data = *(tMemTable **)lua_touserdata(L,1);
		if (data){
			switch (lua_type(L,2)){
				case LUA_TNUMBER:
					if (data->size>0 ){
						long index = (long)lua_tonumber(L,2);
						if (index< (long)data->size){
							if (index<0){
								index = ((index-1) % data->size);
							}
							lua_pushnumber(L,data->data[index]);
							return 1;
						}
					}
					break;
				case LUA_TSTRING:
					const char * key = lua_tostring(L,2);
					if (!strcmp(key,"size")){
						lua_pushinteger(L,data->size);
						return 1;
					}else
						if (!strcmp(key,"raw")){
							lua_pushlstring(L,(const char *)data->data,data->size*sizeof(MEM_TYPE));
							return 1;
						}
						if (!strcmp(key,"set")){
							lua_pushcfunction(L,mem_set);
							return 1;
						}
						break;
			}
		}
	}
	return 0;
}

static int mem_newindex(lua_State * L){
	if (isType(L,1,MEM_TABLE)){
		tMemTable * data = *(tMemTable **)lua_touserdata(L,1);
		size_t index;
		MEM_TYPE value;

		switch (lua_type(L,2)){

			case LUA_TNUMBER:
				index = lua_tointeger(L,2);
				value = lua_tonumber(L,3);

				if (data->size>0 ){
					if (index < data->size){
						if (index<0){
							index = (index % data->size);
						}
						data->data[index] = value;
						return 0;
					}else{
						if (data->flags & MEM_FLAG_RESIZABLE){
							mem_resize(data,index+1);
							data->data[index] = value;
						}
					}
				}else{
					if (data->flags & MEM_FLAG_RESIZABLE){
						mem_resize(data,index+1);
						data->data[index] = value;
					}
				}
				break;
			case LUA_TSTRING:
				const char * key = lua_tostring(L,2);
				if (!strcmp(key,"size")){
					size_t size = lua_tointeger(L,3);
					if (size!=data->size){
						mem_resize(data,size);
					}
				}
				break;
		}
	}
	return 0;
}

static int mem_len(lua_State * L){
	if (isType(L,1,MEM_TABLE)){
		tMemTable * data = *(tMemTable **)lua_touserdata(L,1);
		if (data){
			lua_pushinteger(L,data->size);
			return 1;
		}
	}
	return 0;
}

static int mem_gc(lua_State * L){
	if (isType(L,1,MEM_TABLE)){
		tMemTable * data = *(tMemTable **)lua_touserdata(L,1);
		if (data){
			if (data->data){
				free(data->data);
				data->size = 0;
			}
			free(data);
		}
	}
	return 0;
}

static luaL_Reg mem_mt[] = {
	{"__index",mem_index},
	{"__newindex",mem_newindex},
	{"__len",mem_len},
	{"__gc",mem_gc},
	{NULL,NULL}
};

int init_mem(lua_State * L){
	luaL_newmetatable(L,MEM_TABLE);
	luaL_openlib(L,NULL,mem_mt,NULL);
	return 0;
}