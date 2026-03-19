#ifndef BACKEND_H
#define BACKEND_H

#include <cstdint>

enum class token_type : uint8_t
{
                number_t,
                plus_t,
                minus_t,
                divide_t,
                multiply_t,
                end_t
}; // var_t means it's a token type

struct token;

int enum_to_int(token_type token);

namespace rtxt
{

void tokenize_input(char **argv);
void parse_input(void);

} // namespace rtxt

namespace rtxt::debug
{

void print_enum_info();

} // namespace rtxt::debug

#endif
