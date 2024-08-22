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
#ifndef __BLOCK_PARSER_H
#define __BLOCK_PARSER_H 1
#include "__md_config.h"
#include <functional>
#include <locale>
#include <memory>
#include <sstream>

namespace ll_markdown
{
    class BlockParser
    {
    public:
        /**
         * @brief Construct a new Block Parser object
         *
         * @param parse_line_callback
         * @param block_Parser_for_line_callback
         */
        BlockParser(std::function<void(string_t &)> parse_line_callback,
                    std::function<std::shared_ptr<BlockParser>(const string_t &)> block_parser_for_line_callback)
            : m_parse_line_callback{parse_line_callback},
              m_block_parser_for_line_callback{block_parser_for_line_callback} {}

        virtual ~BlockParser() {}

        virtual bool is_finished() const = 0;

        virtual void add_line(string_t &line)
        {
            parse_block(line);
            if (is_inline_block_allowed() && !m_child_parser)
                m_child_parser = get_block_parser_for_line(line);
            if (m_child_parser)
            {
                m_child_parser->add_line(line);
                if (m_child_parser->is_finished())
                {
                    m_result << m_child_parser->get_result().str();
                    m_child_parser = nullptr;
                }
                return;
            }
            if (is_line_parser_allowed())
                parse_line(line);
            m_result << line;
        }
        auto get_result() -> std::basic_stringstream<char_t> & { return m_result; }

        void clear() { m_result.str(u8""); }

    protected:
        std::basic_stringstream<char_t> m_result{u8"", std::ios_base::ate | std::ios_base::in | std::ios_base::out};
        std::shared_ptr<BlockParser> m_child_parser{nullptr};

        virtual bool is_inline_block_allowed() const = 0;
        virtual bool is_line_parser_allowed() const = 0;
        virtual void parse_block(string_t &) = 0;

        void parse_line(string_t &line)
        {
            if (m_parse_line_callback)
                m_parse_line_callback(line);
        }

        int get_indent(const string_t &line) const
        {
            int count{0};
            for (char_t c : line)
            {
                if (!std::isspace(c))
                    return count;
                count++;
            }
            return count;
        }

        auto get_block_parser_for_line(const string_t &line) -> std::shared_ptr<BlockParser>
        {
            if (m_block_parser_for_line_callback)
                return m_block_parser_for_line_callback(line);
            return nullptr;
        }

    private:
        std::function<void(string_t &)> m_parse_line_callback;
        std::function<std::shared_ptr<BlockParser>(const string_t &)> m_block_parser_for_line_callback;
    };
}
#endif // __BLOCK_PARSER_H
#else
#error Use a compiler that supports C++ 17.
#endif // C++ 17
