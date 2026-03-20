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



use std::io::{stdin,stdout,Write};


// a calculator in rust!

fn eval(input : String) -> String
{
    let l = "Just put the fries in the bag bro.";
    return l.to_string();
}

fn interface()
{
    println!("Welcome to the calculator,you can start evaluating expressions like 2 + 2");

    // REPL
    while true
    {
        print!(">> ");
        let mut input = String::new();
        let _=stdout().flush();
        stdin().read_line(&mut input).expect("Did not enter a correct string");
        if let Some('\n')=input.chars().next_back() {
            input.pop();
        }
        if let Some('\r')=input.chars().next_back() {
            input.pop();
        }
        println!("read: {}",input);
        let mut evaluated_input = eval(input);
        println!("eval: {}",evaluated_input); 

    }
}


fn main()
{
    interface();
    println!("Hello world!");
}
