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

#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

// local includes

#include "backend.hpp"

// readline libary for the core of interpreter;
#include <readline/history.h>
#include <readline/readline.h>

// ANSI Color code definitions;
#define RED_m "\033[31m"
#define GREEN_m "\033[32m"
#define YELLOW_m "\033[33m"
#define RESET_m "\033[0m"

void
print_repl_help()
{
                std::cout << "REPL - help:" << std::endl;
                std::cout
                    << "1- you can do masic math like: 2 + 2 -> will return 4."
                    << std::endl;
                std::cout << "2- you can invoke math functions like sin with "
                             "value: sin(30) "
                             "-> will return 1/2"
                          << std::endl;
}

void
exec_system_function(std::string system_command)
{
                std::unique_ptr<FILE, decltype(&pclose)> pipe(
                    popen(system_command.c_str(), "r"), pclose);

                if (!pipe)
                {
                                std::cout << "Failed to run command.\n";
                                return;
                }

                char buffer[128];
                while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr)
                {
                                std::cout << buffer;
                }
}

bool
eval(std::string &t_user_input)
{
                std::string prefix_system = "sys:";

                if (t_user_input == "exit")
                {
                                return false;
                }

                if (!t_user_input.empty())
                {
                                add_history(t_user_input.c_str());
                }

                if (t_user_input == "clear")
                {
                                std::cout << "\033[2J\033[H";
                }

                if (t_user_input == "help")
                {
                                print_repl_help();
                }

                if (t_user_input.starts_with(prefix_system))
                {
                                t_user_input.erase(0, prefix_system.length());
                                exec_system_function(t_user_input);
                }

                return true;
}

void
repl()
{
                std::string user_input;
                std::cout << "Welcome to the REPL interface. For help, you can "
                             "type string "
                             "literal 'help'."
                          << std::endl;
                while (true)
                {

                                char *line = readline(
                                    "\001\033[1;32m\002>> \001\033[0m\002");

                                if (!line)
                                                break; // Ctrl+D

                                std::string input(line);
                                free(line);
                                if (!eval(input))
                                                break;
                }
}

int
main(int argc, char **argv)
{
                if (argc < 2)
                {
                                std::cout << RED_m
                                          << "No argument found, switching to "
                                             "REPL mode"
                                          << RESET_m << std::endl;

                                repl();
                }
                else
                {

                                // scan_input(argv);
                                rtxt::tokenize_input(argv);
                }

                // rtxt::debug::print_enum_info();

                return 0;
}
