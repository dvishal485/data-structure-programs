fn main() {
    println!("Input array size :");
    let mut array_size = String::new();
    std::io::stdin()
        .read_line(&mut array_size)
        .expect("Failed to read line!");
    let array_size: usize = array_size.trim().parse().expect("Expected an usize input!");

    println!("Input array elements :");
    let mut arr = vec![0; array_size];
    for x in 0..array_size {
        let mut input = String::new();
        std::io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line!");
        arr[x] = input.trim().parse().expect("Expected integer input!");
    }

    // linear search
    println!("Input key to search :");
    let mut key = String::new();
    std::io::stdin()
        .read_line(&mut key)
        .expect("Failed to read line!");
    let key: i32 = key.trim().parse().expect("Expected integer input!");
    for x in 0..array_size {
        if key == arr[x] {
            println!("Key found at index {x}");
            return;
        }
    }
    println!("Key not found!");
}
