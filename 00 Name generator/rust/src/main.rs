extern crate rand;

use rand::Rng;

fn main() {
    let names = ["Bob", "Tony", "Nathan", "Billy", "Jim"];

    println!("Your name is {}.", names[rand::thread_rng().gen::<usize>() % names.len()]);
}
