#ifndef SLANG_KEY
#define SLANG_KEY(key, str)
#endif

SLANG_KEY(STRUCT,    "struct")
SLANG_KEY(PRECISION, "precision")
SLANG_KEY(DISCARD,   "discard")

// Special keyword to indicate that it is not recognized as a keyword
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
#define SLANG_KEY_DATA(key, str) SLANG_KEY(key, str)
#endif

SLANG_KEY_DATA(BVEC4, "bvec4")
SLANG_KEY_DATA(BVEC3, "bvec3")
SLANG_KEY_DATA(BVEC2, "bvec2")
SLANG_KEY_DATA(BOOL,  "bool")

SLANG_KEY_DATA(IVEC4, "ivec4")
SLANG_KEY_DATA(IVEC3, "ivec3")
SLANG_KEY_DATA(IVEC2, "ivec2")
SLANG_KEY_DATA(INT,   "int")

SLANG_KEY_DATA(VEC4,  "vec4")
SLANG_KEY_DATA(VEC3,  "vec3")
SLANG_KEY_DATA(VEC2,  "vec2")
SLANG_KEY_DATA(FLOAT, "float")

SLANG_KEY_DATA(DVEC4,  "dvec4")
SLANG_KEY_DATA(DVEC3,  "dvec3")
SLANG_KEY_DATA(DVEC2,  "dvec2")
SLANG_KEY_DATA(DOUBLE, "double")

SLANG_KEY_DATA(MAT4, "mat4")
SLANG_KEY_DATA(MAT3, "mat3")
SLANG_KEY_DATA(MAT2, "mat2")

SLANG_KEY_DATA(DMAT4, "dmat4")
SLANG_KEY_DATA(DMAT3, "dmat3")
SLANG_KEY_DATA(DMAT2, "dmat2")

// Void data type
#ifndef SLANG_KEY_DATA_VOID
#define SLANG_KEY_DATA_VOID(key, str) SLANG_KEY_DATA(key, str)
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
