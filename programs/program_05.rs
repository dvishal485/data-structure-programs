struct Stack<T> {
    stack: Vec<T>,
}

impl<T> Stack<T> {
    fn new() -> Self {
        Stack { stack: Vec::new() }
    }
    fn push(&mut self, item: T) {
        self.stack.push(item);
    }
    fn pop(&mut self) -> Option<T> {
        self.stack.pop()
    }
    fn top(&self) -> &T {
        self.stack.last().expect("Stack is empty")
    }
    fn length(&self) -> usize {
        self.stack.len()
    }
    fn is_empty(&self) -> bool {
        self.stack.is_empty()
    }
}

fn main() {
    let mut s: Stack<i32> = Stack::new();
    println!("EMPTY : {}", s.is_empty());
    s.push(6);
    s.push(7);
    println!("{} {} {}", s.top(), s.length(), s.is_empty());
    s.push(8);
    println!("{} {} {}", s.top(), s.length(), s.is_empty());
    s.pop();
    println!("{} {} {}", s.top(), s.length(), s.is_empty());
}
