luagl
=============

OpenGL/GLEW wrapper of Lua

Wrapper doesn't wrap all OpenGL functions!
Functions are divided into files: a.cpp, b.cpp, c.cpp... where the file name corresponds to the first letter of OpenGL function.

Dependecies
===========

* Lutok2 - https://github.com/soulik/lutok2
* GLEW - http://glew.sourceforge.net/
* Lua 5.x or LuaJIT 2.x - http://www.lua.org/ or http://luajit.org/

Notes
=====

Before doing anything, you'll need to call InitGLEW() function. This will prepare entry points for GL functions.


Usage
=====

```lua
local gl = require 'luagl'
```

Todo
====

* Write proper documentation so people will know what are the parameters for each function.
* Eventualy write wrappers for more OpenGL functions if needed.
