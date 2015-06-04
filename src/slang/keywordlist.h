#ifndef SLANG_KEY
#define SLANG_KEY(key, str)
#endif

SLANG_KEY(STRUCT,    "struct")
SLANG_KEY(PRECISION, "precision")
SLANG_KEY(DISCARD,   "discard")

// Tokens of type TOK_IDENT can be identifiers or keywords.
// This "Unknown keyword" value is used to describe identifiers.
#ifndef SLANG_KEY_UNKNOWN
#define SLANG_KEY_UNKNOWN(key, str) SLANG_KEY(key, str)
#endif

SLANG_KEY_UNKNOWN(UNKNOWN, "unknown")

#undef SLANG_KEY_UNKNOWN

// Control flow
#ifndef SLANG_KEY_FLOW
#define SLANG_KEY_FLOW(key, str) SLANG_KEY(key, str)
#endif

SLANG_KEY_FLOW(FOR,    "for")
SLANG_KEY_FLOW(WHILE,  "while")
SLANG_KEY_FLOW(DO,     "do")

SLANG_KEY_FLOW(BREAK,    "break")
SLANG_KEY_FLOW(CONTINUE, "continue")
SLANG_KEY_FLOW(RETURN,   "return")

SLANG_KEY_FLOW(SWITCH,  "switch")
SLANG_KEY_FLOW(CASE,    "case")
SLANG_KEY_FLOW(DEFAULT, "default")

SLANG_KEY_FLOW(IF,    "if")
SLANG_KEY_FLOW(ELSE,  "else")

#undef SLANG_KEY_FLOW

// Data types
#ifndef SLANG_KEY_DATA
#define SLANG_KEY_DATA(key, str, rows, cols) SLANG_KEY(key, str)
#endif

SLANG_KEY_DATA(BVEC4, "bvec4", 4, 1)
SLANG_KEY_DATA(BVEC3, "bvec3", 3, 1)
SLANG_KEY_DATA(BVEC2, "bvec2", 2, 1)
SLANG_KEY_DATA(BOOL,  "bool",  1, 1)

SLANG_KEY_DATA(IVEC4, "ivec4", 4, 1)
SLANG_KEY_DATA(IVEC3, "ivec3", 3, 1)
SLANG_KEY_DATA(IVEC2, "ivec2", 2, 1)
SLANG_KEY_DATA(INT,   "int",   1, 1)

SLANG_KEY_DATA(UVEC4, "uvec4", 4, 1)
SLANG_KEY_DATA(UVEC3, "uvec3", 3, 1)
SLANG_KEY_DATA(UVEC2, "uvec2", 2, 1)
SLANG_KEY_DATA(UINT,  "uint",  1, 1)

SLANG_KEY_DATA(VEC4,  "vec4",  4, 1)
SLANG_KEY_DATA(VEC3,  "vec3",  3, 1)
SLANG_KEY_DATA(VEC2,  "vec2",  2, 1)
SLANG_KEY_DATA(FLOAT, "float", 1, 1)

SLANG_KEY_DATA(DVEC4,  "dvec4",  4, 1)
SLANG_KEY_DATA(DVEC3,  "dvec3",  3, 1)
SLANG_KEY_DATA(DVEC2,  "dvec2",  2, 1)
SLANG_KEY_DATA(DOUBLE, "double", 1, 1)

SLANG_KEY_DATA(MAT4, "mat4", 4, 4)
SLANG_KEY_DATA(MAT3, "mat3", 3, 3)
SLANG_KEY_DATA(MAT2, "mat2", 2, 2)

SLANG_KEY_DATA(MAT4X4, "mat4x4", 4, 4)
SLANG_KEY_DATA(MAT4X3, "mat4x3", 4, 3)
SLANG_KEY_DATA(MAT4X2, "mat4x2", 4, 2)
SLANG_KEY_DATA(MAT3X4, "mat3x4", 3, 4)
SLANG_KEY_DATA(MAT3X3, "mat3x3", 3, 3)
SLANG_KEY_DATA(MAT3X2, "mat3x2", 3, 2)
SLANG_KEY_DATA(MAT2X4, "mat2x4", 2, 4)
SLANG_KEY_DATA(MAT2X3, "mat2x3", 2, 3)
SLANG_KEY_DATA(MAT2X2, "mat2x2", 2, 2)

SLANG_KEY_DATA(DMAT4, "dmat4", 4, 4)
SLANG_KEY_DATA(DMAT3, "dmat3", 3, 3)
SLANG_KEY_DATA(DMAT2, "dmat2", 2, 2)

SLANG_KEY_DATA(DMAT4X4, "dmat4x4", 4, 4)
SLANG_KEY_DATA(DMAT4X3, "dmat4x3", 4, 3)
SLANG_KEY_DATA(DMAT4X2, "dmat4x2", 4, 2)
SLANG_KEY_DATA(DMAT3X4, "dmat3x4", 3, 4)
SLANG_KEY_DATA(DMAT3X3, "dmat3x3", 3, 3)
SLANG_KEY_DATA(DMAT3X2, "dmat3x2", 3, 2)
SLANG_KEY_DATA(DMAT2X4, "dmat2x4", 2, 4)
SLANG_KEY_DATA(DMAT2X3, "dmat2x3", 2, 3)
SLANG_KEY_DATA(DMAT2X2, "dmat2x2", 2, 2)

// Void data type
#ifndef SLANG_KEY_DATA_VOID
#define SLANG_KEY_DATA_VOID(key, str) SLANG_KEY_DATA(key, str, 1, 1)
#endif

SLANG_KEY_DATA_VOID(VOID, "void")

#undef SLANG_KEY_DATA_VOID
#undef SLANG_KEY_DATA

// Type qualifiers
#ifndef SLANG_KEY_QUAL
#define SLANG_KEY_QUAL(key, str) SLANG_KEY(key, str)
#endif

SLANG_KEY_QUAL(INVARIANT,  "invariant")
SLANG_KEY_QUAL(LAYOUT,     "layout")
SLANG_KEY_QUAL(SUBROUTINE, "subroutine")

// Precision qualifiers
#ifndef SLANG_KEY_QUAL_PREC
#define SLANG_KEY_QUAL_PREC(key, str) SLANG_KEY_QUAL(key, str)
#endif

SLANG_KEY_QUAL_PREC(LOWP,    "lowp")
SLANG_KEY_QUAL_PREC(MEDIUMP, "mediump")
SLANG_KEY_QUAL_PREC(HIGHP,   "highp")

#undef SLANG_KEY_QUAL_PREC

// Storage qualifiers
#ifndef SLANG_KEY_QUAL_STORAGE
#define SLANG_KEY_QUAL_STORAGE(key, str) SLANG_KEY_QUAL(key, str)
#endif

SLANG_KEY_QUAL_STORAGE(CONST,     "const")
SLANG_KEY_QUAL_STORAGE(INOUT,     "inout")
SLANG_KEY_QUAL_STORAGE(IN,        "in")
SLANG_KEY_QUAL_STORAGE(OUT,       "out")
SLANG_KEY_QUAL_STORAGE(CENTROID,  "centroid")
SLANG_KEY_QUAL_STORAGE(PATCH,     "patch")
SLANG_KEY_QUAL_STORAGE(SAMPLE,    "sample")
SLANG_KEY_QUAL_STORAGE(UNIFORM,   "uniform")
SLANG_KEY_QUAL_STORAGE(BUFFER,    "buffer")
SLANG_KEY_QUAL_STORAGE(SHARED,    "shared")
SLANG_KEY_QUAL_STORAGE(COHERENT,  "coherent")
SLANG_KEY_QUAL_STORAGE(VOLATILE,  "volatile")
SLANG_KEY_QUAL_STORAGE(RESTRICT,  "restrict")
SLANG_KEY_QUAL_STORAGE(READONLY,  "readonly")
SLANG_KEY_QUAL_STORAGE(WRITEONLY, "writeonly")

#undef SLANG_KEY_QUAL_STORAGE

// Interpolation qualifiers
#ifndef SLANG_KEY_QUAL_INTERP
#define SLANG_KEY_QUAL_INTERP(key, str) SLANG_KEY_QUAL(key, str)
#endif

SLANG_KEY_QUAL_INTERP(FLAT,          "flat")
SLANG_KEY_QUAL_INTERP(NOPERSPECTIVE, "noperspective")
SLANG_KEY_QUAL_INTERP(SMOOTH,        "smooth")

#undef SLANG_KEY_QUAL_INTERP

#ifndef SLANG_KEY_QUAL_DEPREC
#define SLANG_KEY_QUAL_DEPREC(key, str) SLANG_KEY_QUAL(key, str)
#endif

SLANG_KEY_QUAL_DEPREC(VARYING,   "varying")
SLANG_KEY_QUAL_DEPREC(ATTRIBUTE, "attribute")

#undef SLANG_KEY_QUAL_DEPREC
#undef SLANG_KEY_QUAL

#undef SLANG_KEY
