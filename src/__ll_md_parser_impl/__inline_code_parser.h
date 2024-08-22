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
#ifndef __INLINE_CODE_PARSER
#define __INLINE_CODE_PARSER 1
#include "__md_config.h"
#include <regex>

namespace ll_markdown
{
    /**
     * InlineCodeParser
     *
     * @class
     * @brief 解析行内代码
     */
    class InlineCodeParser
    {
    public:
        void parse(string_t &line)
        {
            // ______________________`([^`]*)`
            static regex_t re{u8R"(`([^`]*)`)"};
            static string_t replacement{u8R"(<code>$1</code>)"};
            line = std::regex_replace(line, re, replacement);
        }
    };
}
#endif // __INLINE_CODE_PARSER
#else
#error Use a compiler that supports C++ 17.
#endif // C++ 17
