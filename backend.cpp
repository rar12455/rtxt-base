/*
 * Copyright (C) 2026 rar <rarSS@proton.me>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * version 2 any later version.
 *
 * This program is distributed in the hope that it will be WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <cctype>
#include <iostream>

enum class token_type // var_t means it's a token type
{
                number_t = 255,
                plus_t,
                minus_t,
                divide_t,
                multiply_t,
                end_t
};

struct token
{
                token_type type;
                char     **value;
};

namespace rtxt
{

void
tokenize_input(char **argv)
{
                // wrap the raw pointer in the string_view, so the for loop
                // knows the boundaries.
                std::string_view arg_view(argv[1]);
                for (const auto &i : arg_view)
                {
                                if (i == ' ') // ignore whitespace
                                {
                                                continue;
                                }
                                if (i != '+' && i != '*' && i != '/' &&
                                    i != '-' &&
                                    !std::isdigit(
                                        i)) // ignore non-math spesific chars
                                {
                                                continue;
                                }
                                std::cout << "argv: " << i << '\n';

                                if (std::isdigit(i))
                                {
                                                token_type n =
                                                    token_type::number_t;
                                                int value_token_number =
                                                    static_cast<int>(
                                                        token_type::number_t);
                                                std::cout << "cast: "
                                                          << value_token_number
                                                          << '\n';
                                }
                }
}

void
parse_input()
{
}

} // namespace rtxt
