#[derive(Debug)]
enum Error {
    KeyNotFound,
}
fn main() {
    println!("Input array size :");
    let mut array_size = String::new();
    std::io::stdin()
        .read_line(&mut array_size)
        .expect("Failed to read line!");
    let array_size: usize = array_size.trim().parse().expect("Expected an usize input!");

    println!("Input elements in sorted order :");
    let mut arr = vec![0; array_size];
    for x in 0..array_size {
        let mut input = String::new();
        std::io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line!");
        arr[x] = input.trim().parse().expect("Expected integer input!");
    }

    // binary search
    println!("Input key to search :");
    let mut key = String::new();
    std::io::stdin()
        .read_line(&mut key)
        .expect("Failed to read line!");
    let key: i32 = key.trim().parse().expect("Expected integer input!");
    let res = binary_search(&arr, key).expect("Key not found!");
    println!("Key found at index {}", res);
}

fn binary_search(arr: &[i32], key: i32) -> Result<usize, Error> {
    let mut low = 0;
    let mut high = arr.len() - 1;
    while low <= high {
        let mid = low + (high - low) / 2;
        if arr[mid] == key {
            return Ok(mid);
        } else if arr[mid] < key {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return Err(Error::KeyNotFound);
}
