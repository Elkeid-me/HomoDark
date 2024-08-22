// Copyright (C) 2022-2024 Elkeid-me
//
// This file is part of HomoDark.
//
// HomoDark is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// HomoDark is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with HomoDark.  If not, see <http://www.gnu.org/licenses/>.

#if __cplusplus >= 201703L
#ifndef __MD_CONFIG_H
#define __MD_CONFIG_H 1
#include <regex>
#include <string>
using char_t = char;
using string_t = std::basic_string<char_t>;
using regex_t = std::basic_regex<char_t>;
#endif // __MD_CONFIG_H
#else
#error Use a compiler that supports C++ 17.
#endif // C++ 17
