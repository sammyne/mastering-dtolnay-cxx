#[cxx::bridge(namespace = "demo")]
mod ffi {
    unsafe extern "C++" {
        include!("hello-world/include/hello-world.h");

        type HelloWorld;

        fn new_hello_world() -> UniquePtr<HelloWorld>;

        fn hello_world(&self);
    }

    extern "Rust" {
        type Hi;

        fn hi(&self);

        fn new_hi() -> Box<Hi>;
    }
}

struct Hi {}

impl Drop for Hi {
    fn drop(&mut self) {
        println!("Hi is garbage collected");
    }
}

impl Hi {
    pub fn hi(&self) {
        println!("hi from Rust");
    }
}

fn new_hi() -> Box<Hi> {
    Box::new(Hi {})
}

fn main() {
    let testbot = ffi::new_hello_world();
    testbot.hello_world();
}
