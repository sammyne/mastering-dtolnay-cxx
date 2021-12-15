#[cxx::bridge(namespace = "demo")]
mod ffi {
    unsafe extern "C++" {
        include!("call-cc-mutable-class-by-pin/include/hello-world.h");

        type Testbot;

        fn new_testbot() -> UniquePtr<Testbot>;
        fn say_hello_world(self: Pin<&mut Testbot>);
    }
}

fn main() {
    let mut testbot = ffi::new_testbot();

    for _ in 0..=2 {
        testbot.pin_mut().say_hello_world();
    }
}
