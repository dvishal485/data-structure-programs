fn main() {
    let mut arr = [0; 100];
    println!("Input array size :");
    let mut size = String::new();
    std::io::stdin().read_line(&mut size).unwrap();
    let size: usize = size.trim().parse().unwrap();
    println!("Input array elements :");
    for x in 0..size {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let input: i32 = input.trim().parse().unwrap();
        arr[x] = input;
    }
    let mut i = size;
    let mid = size / 2;
    while i > mid {
        arr[i] = arr[i - 1];
        i -= 1;
    }
    println!("Input element to be inserted :");
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    arr[mid] = input.trim().parse().unwrap();
    println!("Array after insertion :");
    for x in 0..(size + 1) {
        print!("{} ", arr[x]);
    }
    println!("");
}
