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

#include <fstream>
#include <iostream>
#include <string>

void
bytecode_parse(std::string line)
{
                for (const auto &i : line)
                {

                                if (i == ' ')
                                {
                                                continue; // ignore whitespace
                                }
                                std::cout << "test: " << i << '\n';
                }
}

int
bytecode_read(auto data_path)
{
                std::ifstream file(data_path);
                std::string   line;

                if (file.is_open())
                {
                                while (std::getline(file, line))
                                {
                                                bytecode_parse(line);
                                }
                                file.close();
                }
                else
                {
                                std::cerr << "unable to open file, exiting.";
                                return -1;
                }
                return 0;
}

int
main()
{
                auto file_path = "/home/rar/notes.txt";
                bytecode_read(file_path);
                return 0;
}
