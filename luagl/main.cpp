#include "main.h"
#include <math.h>
#include "gl_fn.h"

namespace GLex {

static int prepareMisc(lutok::state& state){
	state.new_table();
#ifdef __WGLEW_H__
	state.set_field("swap_control", (bool)WGLEW_EXT_swap_control);
#else
#ifdef __GLXEW_H__
		state.set_field("swap_control", (bool)GLXEW_EXT_swap_control);
#else
	state.set_field("swap_control", (bool)false);
#endif
#endif
	return 1;
}

static int prepareGLSL(lutok::state& state){
	state.new_table();

	/* OPENGL 3.0 */
	state.set_field("opengl20", (bool)GLEW_VERSION_2_0);
	state.set_field("opengl21", (bool)GLEW_VERSION_2_1);
	state.set_field("shaders", (bool) GLEW_ARB_vertex_program && GLEW_ARB_vertex_buffer_object && GLEW_ARB_vertex_shader);
	return 1;
}

static int prepareTextureArray(lutok::state& state){
	state.new_table();
	state.set_field("opengl21", (bool)GLEW_EXT_texture3D && GLEW_EXT_copy_texture);
	return 1;
}

static int prepareMultiTexturing(lutok::state& state){
	state.new_table();
	state.set_field("opengl13", (bool) GLEW_VERSION_1_3);
	state.set_field("multitexture", (bool) GLEW_ARB_multitexture);
	return 1;
}

static int prepareVBO(lutok::state& state){
	state.new_table();
	state.set_field("opengl15", (bool) GLEW_VERSION_1_5);
	state.set_field("vertexbuffer", (bool) GLEW_ARB_vertex_buffer_object);
	return 1;
}

static int prepareFBO(lutok::state& state){
	state.new_table();
	state.set_field("framebuffer", (bool) GLEW_ARB_framebuffer_object);
	return 1;
}

static int internalTest(lutok::state& state){
	const void * data = state.to_lightuserdata(1);
	return 0;
}

static int get_last_error(lutok::state& state){
	DWORD le = GetLastError();
	char buffer[1024];
	DWORD len = FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_MAX_WIDTH_MASK,NULL,le,0,buffer,1024,NULL);
	if (len==0){
		state.push_boolean(false);
		state.push_string("Can't get error message!");
		return 2;
	}else{
		state.push_string(buffer);
		return 1;
	}
}

typedef std::map< std::string, lutok::cxx_function > moduleDef;

LUAGLEX_API int luaopen_gl (lua_State *L) {
	lutok::state state(L);
	GLex::moduleDef module;
	module["Accum"] = gl_Accum;
	module["ActiveTexture"] = gl_ActiveTexture;
	module["AlphaFunc"] = gl_AlphaFunc;
	module["ArrayElement"] = gl_ArrayElement;
	module["AttachShader"] = gl_AttachShader;
	//---------------------------
	module["Begin"] = gl_Begin;
	module["BeginCurve"] = gl_BeginCurve;
	module["BeginPolygon"] = gl_BeginPolygon;
	module["BeginSurface"] = gl_BeginSurface;
	module["BeginTrim"] = gl_BeginTrim;
	module["BindBuffer"] = gl_BindBuffer;
	module["BindFrameBuffer"] = gl_BindFrameBuffer;
	module["BindVertexArray"] = gl_BindVertexArray;
	module["BindTexture"] = gl_BindTexture;
	module["BindAttribLocation"] = gl_BindAttribLocation;
	module["Bitmap"] = gl_Bitmap;
	module["BlendColor"] = gl_BlendColor;
	module["BlendEquation"] = gl_BlendEquation;
	module["BlendFunc"] = gl_BlendFunc;
	module["BlitFramebuffer"] = gl_BlitFramebuffer;
	module["BufferData"] = gl_BufferData;
	module["BufferSubData"] = gl_BufferSubData;
	module["Build1DMipmaps"] = glu_Build1DMipmaps;
	module["Build2DMipmaps"] = glu_Build2DMipmaps;
	//---------------------------
	module["CallList"] = gl_CallList;
	module["CallLists"] = gl_CallLists;
	module["CheckFramebufferStatus"] = gl_CheckFramebufferStatus;
	module["Clear"] = gl_Clear;
	module["ClearAccum"] = gl_ClearAccum;
	module["ClearColor"] = gl_ClearColor;
	module["ClearDepth"] = gl_ClearDepth;
	module["ClearIndex"] = gl_ClearIndex;
	module["ClearStencil"] = gl_ClearStencil;
	module["ClientActiveTexture"] = gl_ClientActivetexture;
	module["ClipPlane"] = gl_ClipPlane;
	module["Color3d"] = gl_Color3d;
	module["Color3dv"] = gl_Color3dv;
	module["Color3f"] = gl_Color3f;
	module["Color3fv"] = gl_Color3fv;
	module["Color4d"] = gl_Color4d;
	module["Color4dv"] = gl_Color4dv;
	module["Color4f"] = gl_Color4f;
	module["Color4fv"] = gl_Color4fv;
	module["Color4b"] = gl_Color4b;
	module["Color4x"] = gl_Color4x;
	module["ColorMask"] = gl_ColorMask;
	module["ColorMaterial"] = gl_ColorMaterial;
	module["ColorPointer"] = gl_ColorPointer;
	module["CompileShader"] = gl_CompileShader;
	module["CopyPixels"] = gl_CopyPixels;
	module["CopyTexImage1D"] = gl_CopyTexImage1D;
	module["CopyTexImage2D"] = gl_CopyTexImage2D;
	module["CopyTexSubImage1D"] = gl_CopyTexSubImage1D;
	module["CopyTexSubImage2D"] = gl_CopyTexSubImage2D;
	module["CopyTexSubImage3D"] = gl_CopyTexSubImage3D;
	module["CreateProgram"] = gl_CreateProgram;
	module["CreateShader"] = gl_CreateShader;
	module["CullFace"] = gl_CullFace;
	//---------------------------
	module["DeleteBuffers"] = gl_DeleteBuffers;
	module["DeleteFrameBuffers"] = gl_DeleteFrameBuffers;
	module["DeleteLists"] = gl_DeleteLists;
	module["DeleteProgram"] = gl_DeleteProgram;
	module["DeleteQuadric"] = glu_DeleteQuadric;
	module["DeleteRenderBuffers"] = gl_DeleteRenderBuffers;
	module["DeleteShader"] = gl_DeleteShader;
	module["DeleteVertexArrays"] = gl_DeleteVertexArrays;
	module["DeleteTextures"] = gl_DeleteTextures;
	module["DepthTextures"] = gl_DepthTextures;
	module["DepthFunc"] = gl_DepthFunc;
	module["DepthMask"] = gl_DepthMask;
	module["DepthRange"] = gl_DepthRange;
	module["DetachShader"] = gl_DetachShader;
	module["Disable"] = gl_Disable;
	module["DisableClientState"] = gl_DisableClientState;
	module["DisableVertexArray"] = gl_DisableVertexArray;
	module["DrawArrays"] = gl_DrawArrays;
	module["DrawBuffer"] = gl_DrawBuffer;
	module["DrawBuffers"] = gl_DrawBuffers;
	module["DrawElements"] = gl_DrawElements;
	module["DrawPixels"] = gl_DrawPixels;
	//---------------------------
	module["EdgeFlag"] = gl_EdgeFlag;
	module["EdgeFlagPointer"] = gl_EdgeFlagPointer;
	module["Enable"] = gl_Enable;
	module["EnableClientState"] = gl_EnableClientState;
	module["EnableVertexAttribArray"] = gl_EnableVertexAttribArray;
	module["End"] = gl_End;
	module["EndList"] = gl_EndList;
	module["ErrorString"] = glu_ErrorString;
	module["EvalCoord"] = gl_EvalCoord;
	module["EvalMesh"] = gl_EvalMesh;
	module["EvalPoint"] = gl_EvalPoint;
	//---------------------------
	module["FeedbackBuffer"] = gl_FeedbackBuffer;
	module["Finish"] = gl_Finish;
	module["Flush"] = gl_Flush;
	module["Fog"] = gl_Fog;
	module["FogCoordPointer"] = gl_FogCoordPointer;
	module["FramebufferParameter"] = gl_FramebufferParameter;
	module["FramebufferRenderbuffer"] = gl_FramebufferRenderbuffer;
	module["FramebufferTexture"] = gl_FramebufferTexture;
	module["FramebufferTexture1D"] = gl_FramebufferTexture1D;
	module["FramebufferTexture2D"] = gl_FramebufferTexture2D;
	module["FramebufferTexture3D"] = gl_FramebufferTexture3D;
	module["FramebufferTextureLayer"] = gl_FramebufferTextureLayer;
	module["FrontFace"] = gl_FrontFace;
	module["Frustum"] = gl_Frustum;
	//---------------------------
	module["GenBuffers"] = gl_GenBuffers;
	module["GetBufferSubData"] = gl_GetBufferSubData;
	module["GenFrameBuffers"] = gl_GenFrameBuffers;
	module["GenLists"] = gl_GenLists;
	module["GenRenderBuffers"] = gl_GenRenderBuffers;
	module["GenVertexArrays"] = gl_GenVertexArrays;
	module["GenTextures"] = gl_GenTextures;
	module["Get"] = gl_Get;
	module["GetEx"] = gl_GetEx;
	module["GetBufferParameter"] = gl_GetBufferParameter;
	module["GetClipPlane"] = gl_GetClipPlane;
	module["GetError"] = gl_GetError;
	module["GetFramebufferAttachmentParameter"] = gl_GetFramebufferAttachmentParameter;
	module["GetLastError"] = get_last_error;
	module["GetLight"] = gl_GetLight;
	module["GetMap"] = gl_GetMap;
	module["GetMaterial"] = gl_GetMaterial;
	module["GetPixelMap"] = gl_GetPixelMap;
	module["GetPointer"] = gl_GetPointer;
	module["GetPolygonStipple"] = gl_GetPolygonStipple;
	module["GetProgramInfoLog"] = gl_GetProgramInfoLog;
	module["GetProgramiv"] = gl_GetProgramiv;
	module["GetShaderInfoLog"] = gl_GetShaderInfoLog;
	module["GetShaderiv"] = gl_GetShaderiv;
	module["GetSwapInterval"] = gl_GetSwapInterval;
	module["GetTessProperty"] = gl_GetTessProperty;
	module["GetTexEnv"] = gl_GetTexEnv;
	module["GetTexGen"] = gl_GetTexGen;
	module["GetTexImage"] = gl_GetTexImage;
	module["GetTexLevelParameter"] = gl_GetTexLevelParameter;
	module["GetTexParameter"] = gl_GetTexParameter;
	module["GetUniformLocation"] = gl_GetUniformLocation;
	//---------------------------
	module["Hint"] = gl_Hint;
	//---------------------------
	module["Index"] = gl_Index;
	module["IndexMask"] = gl_IndexMask;
	module["IndexPointer"] = gl_IndexPointer;
	module["InitNames"] = gl_InitNames;
	module["InitGLEW"] = lua_glewInit;
	module["InterleavedArrays"] = gl_InterleavedArrays;
	module["IsEnabled"] = gl_IsEnabled;
	module["IsList"] = gl_IsList;
	module["IsTexture"] = gl_IsTexture;
	module["IsSupported"] = lua_glewIsSupported;
	//---------------------------
	module["Lighti"] = gl_Lighti;
	module["Lightf"] = gl_Lightf;
	module["Lightfv"] = gl_Lightfv;
	module["LightModelf"] = gl_LightModelf;
	module["LightModelfv"] = gl_LightModelfv;
	module["LineStipple"] = gl_LineStipple;
	module["LineWidth"] = gl_LineWidth;
	module["LinkProgram"] = gl_LinkProgram;
	module["ListBase"] = gl_ListBase;
	module["LoadIdentity"] = gl_LoadIdentity;
	module["LoadMatrix"] = gl_LoadMatrix;
	module["LoadTransposeMatrix"] = gl_LoadTransposeMatrix;
	module["LoadName"] = gl_LoadName;
	module["LoadSamplingMatrices"] = glu_LoadSamplingMatrices;
	module["LookAt"] = glu_LookAt;
	//---------------------------
	module["Map1"] = gl_Map1;
	module["Map2"] = gl_Map2;
	module["MapBuffer"] = gl_MapBuffer;
	module["MapGrid"] = gl_MapGrid;
	module["Materialf"] = gl_Materialf;
	module["Materialfv"] = gl_Materialfv;
	module["MatrixMode"] = gl_MatrixMode;
	module["MultMatrix"] = gl_MultMatrix;
	module["MultTransposeMatrix"] = gl_MultTransposeMatrix;
	module["MultitexCoord2f"] = gl_MultitexCoord2f;
	//---------------------------
	module["NewList"] = gl_NewList;
	module["NewNurbsRenderer"] = glu_NewNurbsRenderer;
	module["NewQuadric"] = glu_NewQuadric;
	module["NewTess"] = glu_NewTess;
	module["NextContour"] = glu_NextContour;
	module["Normal3f"] = gl_Normal3f;
	module["Normal3d"] = gl_Normal3d;
	module["NormalPointer"] = gl_NormalPointer;
	module["NurbsCallback"] = gl_NurbsCallback;
	module["NurbsCurve"] = gl_NurbsCurve;
	module["NurbsProperty"] = gl_NurbsProperty;
	module["NurbsSurface"] = gl_NurbsSurface;
	//---------------------------
	module["Ortho"] = gl_Ortho;
	module["Ortho2D"] = glu_Ortho2D;
	//---------------------------
	module["PartialDisk"] = glu_PartialDisk;
	module["PassThrough"] = gl_PassThrough;
	module["Perspective"] = glu_Perspective;
	module["PickMatrix"] = glu_PickMatrix;
	module["PixelMap"] = gl_PixelMap;
	module["PixelStore"] = gl_PixelStore;
	module["PixelTransfer"] = gl_PixelTransfer;
	module["PixelZoom"] = gl_PixelZoom;
	module["PointSize"] = gl_PointSize;
	module["PolygonMode"] = gl_PolygonMode;
	module["PolygonOffset"] = gl_PolygonOffset;
	module["PolygonStipple"] = gl_PolygonStipple;
	module["PrioritizeTextures"] = gl_PrioritizeTextures;
	module["Project"] = glu_Project;
	module["PopAttrib"] = gl_PopAttrib;
	module["PopClientAttrib"] = gl_PopClientAttrib;
	module["PopMatrix"] = gl_PopMatrix;
	module["PopName"] = gl_PopName;
	module["prepareGLSL"] = prepareGLSL;
	module["prepareMultiTexturing"] = prepareMultiTexturing;
	module["prepareVBO"] = prepareVBO;
	module["prepareFBO"] = prepareFBO;
	module["prepareMisc"] = prepareMisc;
	module["prepareTextureArray"] = prepareTextureArray;
	module["PushAttrib"] = gl_PushAttrib;
	module["PushClientAttrib"] = gl_PushClientAttrib;
	module["PushMatrix"] = gl_PushMatrix;
	module["PushName"] = gl_PushName;
	module["PwlCurve"] = glu_PwlCurve;
	//---------------------------
	module["QuadricCallback"] = glu_QuadricCallback;
	module["QuadricDrawStyle"] = glu_QuadricDrawStyle;
	module["QuadricNormals"] = glu_QuadricNormals;
	module["QuadricOrientation"] = glu_QuadricOrientation;
	module["QuadricTexture"] = glu_QuadricTexture;
	//---------------------------
	module["RasterPos"] = gl_RasterPos;
	module["ReadBuffer"] = gl_ReadBuffer;
	module["ReadPixels"] = gl_ReadPixels;
	module["ReadPixel"] = gl_ReadPixel;
	module["Rect"] = gl_Rect;
	module["RenderMode"] = gl_RenderMode;
	module["RenderBufferStorage"] = gl_RenderBufferStorage;
	module["Rotatef"] = gl_Rotatef;
	//---------------------------
	module["Scalef"] = gl_Scalef;
	module["ScaleImage"] = glu_ScaleImage;
	module["Scissor"] = gl_Scissor;
	module["SelectBuffer"] = gl_SelectBuffer;
	module["ShadeModel"] = gl_ShadeModel;
	module["ShaderSource"] = gl_ShaderSource;
	module["Sphere"] = glu_Sphere;
	module["StencilFunc"] = gl_StencilFunc;
	module["StencilMask"] = gl_StencilMask;
	module["StencilOp"] = gl_StencilOp;
	module["SwapInterval"] = gl_SwapInterval;
	//---------------------------
	module["TessBeginContour"] = glu_TessBeginContour;
	module["TessBeginPolygon"] = glu_TessBeginPolygon;
	module["TessCallback"] = glu_TessCallback;
	module["TessEndPolygon"] = glu_TessEndPolygon;
	module["TessNormal"] = glu_TessNormal;
	module["TessProperty"] = glu_TessProperty;
	module["TessVertex"] = glu_TessVertex;
	module["TexCoord2f"] = gl_TexCoord2f;
	module["TexCoord3f"] = gl_TexCoord3f;
	module["TexCoordPointer"] = gl_TexCoordPointer;
	module["TexParameteri"] = gl_TexParameteri;
	module["TexEnvf"] = gl_TexEnvf;
	module["TexEnvi"] = gl_TexEnvi;
	module["TexGen"] = gl_TexGen;
	module["TexImage1D"] = gl_TexImage1D;
	module["TexImage2D"] = gl_TexImage2D;
	module["TexImage3D"] = gl_TexImage3D;
	module["TexParameter"] = gl_TexParameter;
	module["TexSubImage1D"] = gl_TexSubImage1D;
	module["TexSubImage2D"] = gl_TexSubImage2D;
	module["TexSubImage3D"] = gl_TexSubImage3D;
	module["Translatef"] = gl_Translatef;
	//---------------------------
	module["Uniformf"] = gl_Uniformf;
	module["Uniformi"] = gl_Uniformi;
	module["UniformMatrix"] = gl_UniformMatrix;

	module["UnloadProject"] = glu_UnloadProject;
	module["UnmapBuffer"] = gl_UnmapBuffer;
	module["UseProgram"] = gl_UseProgram;
	//---------------------------
	module["Vertex2f"] = gl_Vertex2f;
	module["Vertex2i"] = gl_Vertex2i;
	module["Vertex3f"] = gl_Vertex3f;
	module["VertexAttribd"] = gl_VertexAttribd;
	module["VertexAttribs"] = gl_VertexAttribs;
	module["VertexAttribPointer"] = gl_VertexAttribPointer;
	module["VertexPointer"] = gl_VertexPointer;
	module["Viewport"] = gl_Viewport;

	module["internalTest"] = internalTest;
	
	state.new_table();
	lutok::registerLib(state, module);
	return 1;
}
}