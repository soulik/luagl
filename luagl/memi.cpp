#include "main.h"

void memi_resize(tMemiTable * t, size_t size){
	t->data = (MEMi_TYPE*) realloc(t->data,sizeof(MEMi_TYPE)*size);
	t->size = size;
	if (t->count>size){
		t->count = size;
	}
}

int memi_set(lua_State * L){
	if (isType(L,1,MEMi_TABLE)){
		tMemiTable * data = *(tMemiTable **)lua_touserdata(L,1);
		if (data){
			if (lua_type(L,2)==LUA_TTABLE){
				size_t n = luaL_getn(L, 2);
				if (n>data->size){
					memi_resize(data,n);
				}
				for(size_t i = 0; i < n; i++){
					lua_rawgeti(L, 2, i + 1);
					data->data[i] = (MEMi_TYPE)lua_tonumber(L, -1);
				}
				data->count = n;
			}
		}
	}
	return 0;
}

int memi_addRange(lua_State * L){
	if (isType(L,1,MEMi_TABLE)){
		tMemiTable * data = *(tMemiTable **)lua_touserdata(L,1);
		if (data){
			if (lua_isnumber(L,2) && lua_isnumber(L,3)){
				int num1 = lua_tointeger(L,2);
				int num2 = lua_tointeger(L,3);
				if (num1>=num2){
					luaL_error(L,"Second argument should be less than the third");
					return 0;
				}
				
				//lua_pushvalue(L,1);
				if (data->count+(num2-num1) > data->size){
					memi_resize(data,data->count+(num2-num1));
				}

				int n=0;
				for (int i=num1; i<num2; i++){
					n = data->count+(i-num1);
					data->data[n] = i;
				}
				data->count = n+1;
			}
		}
	}
	return 0;
}

int memi_new(lua_State * L){
	size_t size = lua_tointeger(L,1);
	unsigned int flags = lua_tointeger(L,2);
	if (size>=0){
		tMemiTable ** data = (tMemiTable **)lua_newuserdata(L,sizeof(tMemiTable*));
		(*data) = (tMemiTable*) malloc(sizeof(tMemiTable));
		if (size>0){
			(*data)->data = (MEMi_TYPE*) malloc(sizeof(MEMi_TYPE)*size);
			(*data)->size = size;
		}else{
			(*data)->data = NULL;
			(*data)->size = size;
		}
		(*data)->flags = flags;
		(*data)->count = 0;
		luaL_getmetatable(L,MEMi_TABLE);
		lua_setmetatable(L,-2);
		return 1;
	}
	return 0;
}

static int memi_index(lua_State * L){
	if (isType(L,1,MEMi_TABLE)){
		tMemiTable * data = *(tMemiTable **)lua_touserdata(L,1);
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
							lua_pushlstring(L,(const char *)data->data,data->size*sizeof(MEMi_TYPE));
							return 1;
						}else
						if (!strcmp(key,"count")){
							lua_pushinteger(L,data->count);
							return 1;
						}else
						if (!strcmp(key,"set")){
							lua_pushcfunction(L,memi_set);
							return 1;
						}else
						if (!strcmp(key,"addRange")){
							lua_pushcfunction(L,memi_addRange);
							return 1;
						}
						break;
			}
		}
	}
	return 0;
}

static int memi_newindex(lua_State * L){
	if (isType(L,1,MEMi_TABLE)){
		tMemiTable * data = *(tMemiTable **)lua_touserdata(L,1);
		size_t index;
		MEMi_TYPE value;

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
						if (index>=data->count){
							data->count = index+1;
						}
						return 0;
					}else{
						if (data->flags & MEMi_FLAG_RESIZABLE){
							memi_resize(data,index+1);
							data->data[index] = value;
							if (index>=data->count){
								data->count = index+1;
							}
						}
						
					}
				}else{
					if (data->flags & MEMi_FLAG_RESIZABLE){
						memi_resize(data,index+1);
						data->data[index] = value;
						if (index>=data->count){
							data->count = index+1;
						}
					}
				}
				break;
			case LUA_TSTRING:
				const char * key = lua_tostring(L,2);
				if (!strcmp(key,"size")){
					size_t size = lua_tointeger(L,3);
					if (size!=data->size){
						memi_resize(data,size);
					}
				}else
				if (!strcmp(key,"count")){
					data->count = lua_tointeger(L,3);
					return 0;
				}
				break;
		}
	}
	return 0;
}

static int memi_len(lua_State * L){
	if (isType(L,1,MEMi_TABLE)){
		tMemiTable * data = *(tMemiTable **)lua_touserdata(L,1);
		if (data){
			lua_pushinteger(L,data->size);
			return 1;
		}
	}
	return 0;
}

static int memi_gc(lua_State * L){
	if (isType(L,1,MEMi_TABLE)){
		tMemiTable * data = *(tMemiTable **)lua_touserdata(L,1);
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

static luaL_Reg memi_mt[] = {
	{"__index",memi_index},
	{"__newindex",memi_newindex},
	{"__len",memi_len},
	{"__gc",memi_gc},
	{NULL,NULL}
};

int init_memi(lua_State * L){
	luaL_newmetatable(L,MEMi_TABLE);
	luaL_openlib(L,NULL,memi_mt,NULL);
	return 0;
}