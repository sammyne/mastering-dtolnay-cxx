#[cxx::bridge(namespace = "demo")]
mod ffi {
    unsafe extern "C++" {
        include!("call-cc-forward-declaration/include/hello-world.h");

        type Testbot;

        fn new_testbot() -> UniquePtr<Testbot>;
        fn say_hello_world(&self);
    }
}

fn main() {
    let testbot = ffi::new_testbot();
    testbot.say_hello_world();
}
