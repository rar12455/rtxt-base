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
#include <cstdint>
#include <iostream>

enum class token_type : uint8_t // var_t means it's a token type
{
        number_t,   // 0
        plus_t,     // 1
        minus_t,    // 2
        divide_t,   // 3
        multiply_t, // 4
        end_t = 255
};

struct token
{
        token_type type;
        char     **value;
};

// initialize tokens;

token_type number_t_var   = token_type::number_t;
token_type plus_t_var     = token_type::plus_t;
token_type minus_t_var    = token_type::minus_t;
token_type divide_t_var   = token_type::divide_t;
token_type multiply_t_var = token_type::multiply_t;
token_type end_t_var      = token_type::end_t;

// helper function to implicitly convert an enum to int;

int
enum_to_int(token_type token)
{
        int int_value = static_cast<int>(token);
        return int_value;
}

// helper functions for debugging;

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
                if (i != '+' && i != '*' && i != '/' && i != '-' &&
                    !std::isdigit(i)) // ignore non-math spesific chars
                {
                        continue;
                }
                std::cout << "argv: " << i << '\n';

                if (std::isdigit(i))
                {
                        //
                }
        }
}

void
parse_input(void)
{
}

} // namespace rtxt

namespace rtxt::debug
{

void
print_enum_info()
{
        std::cout << enum_to_int(number_t_var) << '\n';
        std::cout << enum_to_int(plus_t_var) << '\n';
        std::cout << enum_to_int(minus_t_var) << '\n';
        std::cout << enum_to_int(divide_t_var) << '\n';
        std::cout << enum_to_int(multiply_t_var) << '\n';
        std::cout << enum_to_int(end_t_var) << '\n';
}

} // namespace rtxt::debug
