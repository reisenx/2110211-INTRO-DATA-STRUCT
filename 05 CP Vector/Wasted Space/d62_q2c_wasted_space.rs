use std::io;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: u64 = input.trim().parse().unwrap();
    println!("{}", 2_u64.pow((n as f64).log2().ceil() as u32) - n);
}