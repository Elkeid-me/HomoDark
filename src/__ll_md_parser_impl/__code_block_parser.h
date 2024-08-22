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
#ifndef __CODE_BLOCK_PARSER_H
#define __CODE_BLOCK_PARSER_H 1
#include "__block_parser.h"
#include "__md_config.h"
#include <functional>
#include <regex>

namespace ll_markdown
{
    class CodeBlockParser : public BlockParser
    {
    public:
        CodeBlockParser(std::function<void(string_t &)> parse_line_callback,
                        std::function<std::shared_ptr<BlockParser>(const string_t &)> block_parser_for_line_callback)
            : BlockParser(parse_line_callback, block_parser_for_line_callback) {}

        static bool is_start_line(const string_t &line)
        {
            static regex_t re{u8R"(^(?:`){3}.*$)"};
            return std::regex_match(line, re);
        }

        bool is_finished() const override { return m_is_finished; }

    protected:
        bool is_inline_block_allowed() const override { return false; }

        bool is_line_parser_allowed() const override { return false; }

        void parse_block(string_t &line) override
        {
            if (line == u8"```")
            {
                if (!m_is_started)
                {
                    line = u8"<pre><code>\n";
                    m_is_started = true;
                    m_is_finished = false;
                    return;
                }
                else
                {
                    line = u8"</code></pre>";
                    m_is_finished = true;
                    m_is_started = false;
                    return;
                }
            }
            line += u8'\n';
        }

    private:
        bool m_is_started{false}, m_is_finished{false};
    };
}
#endif // __CODE_BLOCK_PARSER_H
#else
#error Use a compiler that supports C++ 20.
#endif // C++ 201703L
