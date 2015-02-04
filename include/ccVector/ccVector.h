//__________________________________________________________________________________//
//                                                                                  //
//                           __      __       _                                     //
//                           \ \    / /      | |                                    //
//                      ___ __\ \  / /__  ___| |_ ___  _ __                         //
//                     / __/ __\ \/ / _ \/ __| __/ _ \| '__|                        //
//                    | (_| (__ \  /  __/ (__| || (_) | |                           //
//                     \___\___| \/ \___|\___|\__\___/|_| v1.0                      //
//                                                                                  //
//                 Copyright (C) 2015 \ Job Talle (job@ccore.org)                   //
//__________________________________________________________________________________//
//                                                                                  //
//      This program is free software: you can redistribute it and/or modify        //
//      it under the terms of the 3-clause BSD license.                             //
//                                                                                  //
//      You should have received a copy of the 3-clause BSD License along with      //
//      this program. If not, see <http://opensource.org/licenses/>.                //
//__________________________________________________________________________________//

// Vector functions
//
// CCV_DEFINE_VEC(n)                    Defines n-dimensional vector ccvVec<n> and its functions
//
// ccvVec<n>Zero(v)                     Sets all elements in vector v to 0
// ccvVec<n>Add(v, a, b)                Add vectors a and b and stores the result in vector v
// ccvVec<n>Subtract(v, a, b)           Subtracts vector b from vector a and stores the result in vector v
// ccvVec<n>Copy(dest, source)          Copies vector source to vector dest
// ccvVec<n>Crossproduct(v, a, b)       Takes the cross product from vectors a and b and stores it in vector v
// ccvVec<n>Multiply(v, n)              Multiplies vector v with scalar n
// ccvVec<n>DotProduct(a, b)            Returns the dot product from vectors a and b
// ccvVec<n>Length(v)                   Returns the length of vector v
// ccvVec<n>Normalize(v)                Scales vector v to have a length of 1
// ccvVec<n>Reflect(v, n, r)            Reflects vector r by normal n and stores the result in vector v

// Matrix functions
//
// CCV_DEFINE_MAT(n)                    Defines n x n matrix ccvMat<n>x<n> and its functions
//
// ccvMat<n>x<n>Zero(m)                 Sets all elements in matrix m to 0
// ccvMat<n>x<n>Add(m, a, b)            Adds matrices a and b and stores the result in matrix m
// ccvMat<n>x<n>Subtract(m, a, b)       Subtracts matrix b from matrix a and stores the result in matrix m
// ccvMat<n>x<n>Copy(dest, source)      Copies matrix source to matrix dest
// ccvMat<n>x<n>Identity(m)             Sets matrix m to the identity matrix
// ccvMat<n>x<n>MultiplyScalar(m, n)    Multiplies matrix m by scalar n
// ccvMat<n>x<n>MultiplyVector(v, a, b) Multiplies matrix a by vector b and stores the result in vector v
// ccvMat<n>x<n>MultiplyMatrix(m, a, b) Multiplies matrix a by matrix b and stores the result in matrix m

#pragma once

#include <math.h>
#include <string.h>

#ifndef inline
#define inline __inline
#endif

// Type

#define _CCV_TYPE double

// Prefixes

#define _CCV_VEC_TYPENAME(dim) ccvVec##dim

#define _CCV_MAT_TYPENAME(dim) ccvMat##dim##x##dim

// Type definitions

#define _CCV_DEFINE_VEC_TYPE(dim) \
	typedef _CCV_TYPE _CCV_VEC_TYPENAME(dim)[dim];

#define _CCV_DEFINE_MAT_TYPE(dim) \
	typedef _CCV_TYPE _CCV_MAT_TYPENAME(dim)[dim][dim];

// Vector operations

#define _CCV_DEFINE_VEC_ZERO(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Zero(_CCV_VEC_TYPENAME(dim) v) { \
		memset(v, 0, sizeof(_CCV_TYPE)* dim); \
	}

#define _CCV_DEFINE_VEC_ADD(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Add(_CCV_VEC_TYPENAME(dim) v, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v[i] = a[i] + b[i]; \
	}

#define _CCV_DEFINE_VEC_SUBTRACT(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Subtract(_CCV_VEC_TYPENAME(dim) v, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v[i] = a[i] - b[i]; \
	}

#define _CCV_DEFINE_VEC_COPY(dim) \
	static inline _CCV_VEC_TYPENAME(dim)##Copy(_CCV_VEC_TYPENAME(dim) dest, const _CCV_VEC_TYPENAME(dim) source) { \
		memcpy(dest, source, sizeof(_CCV_TYPE) * dim); \
	}

#define _CCV_DEFINE_VEC_CROSSPRODUCT(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##CrossProduct(_CCV_VEC_TYPENAME(dim) v, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v[i] = a[i] * b[i]; \
	}

#define _CCV_DEFINE_VEC_MULTIPLY(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Multiply(_CCV_VEC_TYPENAME(dim) v, const _CCV_TYPE n) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v[i] *= n; \
	}

#define _CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	static inline _CCV_TYPE _CCV_VEC_TYPENAME(dim)##DotProduct(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		_CCV_TYPE result = 0; \
		for(i = 0; i < dim; i++) \
			result += a[i] * b[i]; \
		return result; \
	}

#define _CCV_DEFINE_VEC_LENGTH(dim) \
	static inline _CCV_TYPE _CCV_VEC_TYPENAME(dim)##Length(const _CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		_CCV_TYPE squaredResult = 0; \
		for(i = 0; i < dim; i++) \
			squaredResult += v[i] * v[i]; \
		return (_CCV_TYPE)sqrt(squaredResult); \
	}

#define _CCV_DEFINE_VEC_NORMALIZE(dim) \
	static inline _CCV_VEC_TYPENAME(dim)##Normalize(_CCV_VEC_TYPENAME(dim) v) { \
		_CCV_VEC_TYPENAME(dim)##Multiply(v, 1 / _CCV_VEC_TYPENAME(dim)##Length(v)); \
	}

#define _CCV_DEFINE_VEC_REFLECT(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Reflect(_CCV_VEC_TYPENAME(dim) v, const _CCV_VEC_TYPENAME(dim) n, const _CCV_VEC_TYPENAME(dim) r) { \
		_CCV_VEC_TYPENAME(dim) _v; \
		_CCV_VEC_TYPENAME(dim)##Copy(_v, n); \
		_CCV_VEC_TYPENAME(dim)##Multiply(_v, 2 * _CCV_VEC_TYPENAME(dim)##DotProduct(n, r)); \
		_CCV_VEC_TYPENAME(dim)##Subtract(v, r, _v); \
	}

// Matrix operations

#define _CCV_DEFINE_MAT_ZERO(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Zero(_CCV_MAT_TYPENAME(dim) m) { \
		memset(m, 0, sizeof(_CCV_TYPE)* dim * dim); \
	}

#define _CCV_DEFINE_MAT_ADD(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Add(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(row = 0; row < dim; row++) \
			for(col = 0; col < dim; col++) \
				m[row][col] = a[row][col] + b[row][col]; \
	}

#define _CCV_DEFINE_MAT_SUBTRACT(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Subtract(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(row = 0; row < dim; row++) \
			for(col = 0; col < dim; col++) \
				m[row][col] = a[row][col] - b[row][col]; \
	}

#define _CCV_DEFINE_MAT_COPY(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Copy(_CCV_MAT_TYPENAME(dim) dest, const _CCV_MAT_TYPENAME(dim) source) { \
		memcpy(dest, source, sizeof(_CCV_TYPE) * dim * dim); \
	}

#define _CCV_DEFINE_MAT_IDENTITY(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Identity(_CCV_MAT_TYPENAME(dim) m) { \
		unsigned int i; \
		_CCV_MAT_TYPENAME(dim)##Zero(m); \
		for(i = 0; i < dim; i++) \
			m[i][i] = 1; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##MultiplyScalar(_CCV_MAT_TYPENAME(dim) m, const _CCV_TYPE n) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; col++) \
			for(row = 0; row < dim; row++) m[row][col] *= n; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##MultiplyVector(_CCV_VEC_TYPENAME(dim) v, const _CCV_MAT_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i, j; \
		for(i = 0; i < dim; i++) { \
			v[i] = a[0][i] * b[0]; \
			for(j = 1; j < dim; j++) \
				v[i] += a[j][i] * b[j]; \
		} \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_MATRIX(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##MultiplyMatrix(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int i, j, k; \
		for(i = 0; i < dim; i++) \
			for(j = 0; j < dim; j++) { \
				m[i][j] = a[0][j] * b[i][0]; \
				for(k = 1; k < dim; k++) \
					m[i][j] += a[k][j] * b[i][k]; \
			} \
	}

// Definition calls

#define CCV_DEFINE_VEC(dim) \
	_CCV_DEFINE_VEC_TYPE(dim) \
	_CCV_DEFINE_VEC_ZERO(dim) \
	_CCV_DEFINE_VEC_ADD(dim) \
	_CCV_DEFINE_VEC_SUBTRACT(dim) \
	_CCV_DEFINE_VEC_COPY(dim) \
	_CCV_DEFINE_VEC_CROSSPRODUCT(dim) \
	_CCV_DEFINE_VEC_MULTIPLY(dim) \
	_CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	_CCV_DEFINE_VEC_LENGTH(dim) \
	_CCV_DEFINE_VEC_NORMALIZE(dim) \
	_CCV_DEFINE_VEC_REFLECT(dim)

#define CCV_DEFINE_MAT(dim) \
	_CCV_DEFINE_VEC_TYPE(dim) \
	_CCV_DEFINE_MAT_TYPE(dim) \
	_CCV_DEFINE_MAT_ZERO(dim) \
	_CCV_DEFINE_MAT_ADD(dim) \
	_CCV_DEFINE_MAT_SUBTRACT(dim) \
	_CCV_DEFINE_MAT_COPY(dim) \
	_CCV_DEFINE_MAT_IDENTITY(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_MATRIX(dim)