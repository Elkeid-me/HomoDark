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
#ifndef __QUOTATION_PARSER_H
#define __QUOTATION_PARSER_H 1
#include "__block_parser.h"
#include "__md_config.h"
#include <functional>
#include <regex>

namespace ll_markdown
{
    class QuotationParser : public BlockParser
    {
    public:
        QuotationParser(std::function<void(string_t &)> parse_line_callback,
                        std::function<std::shared_ptr<BlockParser>(const string_t &)> block_parser_for_line_callback)
            : BlockParser(parse_line_callback, block_parser_for_line_callback) {}

        static bool is_start_line(const string_t &line)
        {
            static regex_t re{u8R"(^\> .*)"};
            return std::regex_match(line, re);
        }

        void add_line(string_t &line) override
        {
            if (!m_is_started)
            {
                m_result << u8"<blockquote>";
                m_is_started = true;
            }

            bool finish{false};
            if (line.empty() ||
                line.find(u8"</blockquote>") != string_t::npos)
                finish = true;

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

            if (finish)
            {
                m_result << u8"</blockquote>";
                m_is_finished = true;
            }

            m_result << line;
        }

        bool is_finished() const override { return m_is_finished; }

    protected:
        bool is_inline_block_allowed() const override { return true; }

        bool is_line_parser_allowed() const override { return true; }

        void parse_block(string_t &line) override
        {
            static regex_t line_regex_with_space{u8R"(^\> )"};
            line = std::regex_replace(line, line_regex_with_space, u8"");
//            static regex_t line_regex_without_space{u8R"(^\>)"};
//            line = std::regex_replace(line, line_regex_without_space, u8"");
            if (!line.empty())
                line += u8' ';
        }

    private:
        bool m_is_started{false}, m_is_finished{false};
    };
}
#endif
#endif
