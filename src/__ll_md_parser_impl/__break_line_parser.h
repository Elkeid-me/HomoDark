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
#ifndef __BREAK_LINE_PARSER_H
#define __BREAK_LINE_PARSER_H 1
#include "__md_config.h"
#include <regex>

namespace ll_markdown
{
    /**
     * BreakLineParser
     *
     * @class
     * @brief 解析换行符
     */
    class BreakLineParser
    {
    public:
        void parse(string_t &line)
        {
            // ______________________crlf / cr
            static regex_t re{u8R"((\r\n|\r))"};
            static string_t replacement{u8R"(</br>)"};
            line = std::regex_replace(line, re, replacement);
        }
    };
}
#endif // __BREAK_LINE_PARSER_H
#else
#error Use a compiler that supports C++ 17.
#endif // C++ 17
