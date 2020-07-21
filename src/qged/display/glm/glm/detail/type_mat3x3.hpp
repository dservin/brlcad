/*
 * OpenGL Mathematics (GLM)
 * --------------------------------------------------------------------------------
 * GLM is licensed under The Happy Bunny License or MIT License
 *
 * BRL-CAD will use glm under the standard MIT license
 *
 * ================================================================================
 * The MIT License
 * --------------------------------------------------------------------------------
 * Copyright (c) 2005 - G-Truc Creation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/// @ref core
/// @file glm/detail/type_mat3x3.hpp

#pragma once

#include "type_vec3.hpp"
#include <limits>
#include <cstddef>

namespace glm
{
	template<typename T, qualifier Q>
	struct mat<3, 3, T, Q>
	{
		typedef vec<3, T, Q> col_type;
		typedef vec<3, T, Q> row_type;
		typedef mat<3, 3, T, Q> type;
		typedef mat<3, 3, T, Q> transpose_type;
		typedef T value_type;

	private:
		col_type value[3];

	public:
		// -- Accesses --

		typedef length_t length_type;
		GLM_FUNC_DECL static GLM_CONSTEXPR length_type length() { return 3; }

		GLM_FUNC_DECL col_type & operator[](length_type i);
		GLM_FUNC_DECL GLM_CONSTEXPR col_type const& operator[](length_type i) const;

		// -- Constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR mat() GLM_DEFAULT;
		template<qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR mat(mat<3, 3, T, P> const& m);

		GLM_FUNC_DECL explicit GLM_CONSTEXPR mat(T scalar);
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			T x0, T y0, T z0,
			T x1, T y1, T z1,
			T x2, T y2, T z2);
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			col_type const& v0,
			col_type const& v1,
			col_type const& v2);

		// -- Conversions --

		template<
			typename X1, typename Y1, typename Z1,
			typename X2, typename Y2, typename Z2,
			typename X3, typename Y3, typename Z3>
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			X1 x1, Y1 y1, Z1 z1,
			X2 x2, Y2 y2, Z2 z2,
			X3 x3, Y3 y3, Z3 z3);

		template<typename V1, typename V2, typename V3>
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			vec<3, V1, Q> const& v1,
			vec<3, V2, Q> const& v2,
			vec<3, V3, Q> const& v3);

		// -- Matrix conversions --

		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<3, 3, U, P> const& m);

		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<2, 2, T, Q> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<4, 4, T, Q> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<2, 3, T, Q> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<3, 2, T, Q> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<2, 4, T, Q> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<4, 2, T, Q> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<3, 4, T, Q> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<4, 3, T, Q> const& x);

		// -- Unary arithmetic operators --

		template<typename U>
		GLM_FUNC_DECL mat<3, 3, T, Q> & operator=(mat<3, 3, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DECL mat<3, 3, T, Q> & operator+=(U s);
		template<typename U>
		GLM_FUNC_DECL mat<3, 3, T, Q> & operator+=(mat<3, 3, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DECL mat<3, 3, T, Q> & operator-=(U s);
		template<typename U>
		GLM_FUNC_DECL mat<3, 3, T, Q> & operator-=(mat<3, 3, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DECL mat<3, 3, T, Q> & operator*=(U s);
		template<typename U>
		GLM_FUNC_DECL mat<3, 3, T, Q> & operator*=(mat<3, 3, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DECL mat<3, 3, T, Q> & operator/=(U s);
		template<typename U>
		GLM_FUNC_DECL mat<3, 3, T, Q> & operator/=(mat<3, 3, U, Q> const& m);

		// -- Increment and decrement operators --

		GLM_FUNC_DECL mat<3, 3, T, Q> & operator++();
		GLM_FUNC_DECL mat<3, 3, T, Q> & operator--();
		GLM_FUNC_DECL mat<3, 3, T, Q> operator++(int);
		GLM_FUNC_DECL mat<3, 3, T, Q> operator--(int);
	};

	// -- Unary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator+(mat<3, 3, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator-(mat<3, 3, T, Q> const& m);

	// -- Binary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator+(mat<3, 3, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator+(T scalar, mat<3, 3, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator+(mat<3, 3, T, Q> const& m1, mat<3, 3, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator-(mat<3, 3, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator-(T scalar, mat<3, 3, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator-(mat<3, 3, T, Q> const& m1, mat<3, 3, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator*(mat<3, 3, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator*(T scalar, mat<3, 3, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL typename mat<3, 3, T, Q>::col_type operator*(mat<3, 3, T, Q> const& m, typename mat<3, 3, T, Q>::row_type const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL typename mat<3, 3, T, Q>::row_type operator*(typename mat<3, 3, T, Q>::col_type const& v, mat<3, 3, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator*(mat<3, 3, T, Q> const& m1, mat<3, 3, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<2, 3, T, Q> operator*(mat<3, 3, T, Q> const& m1, mat<2, 3, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator*(mat<3, 3, T, Q> const& m1, mat<4, 3, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator/(mat<3, 3, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator/(T scalar, mat<3, 3, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL typename mat<3, 3, T, Q>::col_type operator/(mat<3, 3, T, Q> const& m, typename mat<3, 3, T, Q>::row_type const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL typename mat<3, 3, T, Q>::row_type operator/(typename mat<3, 3, T, Q>::col_type const& v, mat<3, 3, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator/(mat<3, 3, T, Q> const& m1, mat<3, 3, T, Q> const& m2);

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(mat<3, 3, T, Q> const& m1, mat<3, 3, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL bool operator!=(mat<3, 3, T, Q> const& m1, mat<3, 3, T, Q> const& m2);
}//namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_mat3x3.inl"
#endif