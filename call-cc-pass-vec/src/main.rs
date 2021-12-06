#[cxx::bridge(namespace = "demo")]
mod ffi {
    unsafe extern "C++" {
        include!("call-cc-pass-vec/include/hello-world.h");

        type Testbot;

        fn new_testbot() -> UniquePtr<Testbot>;

        fn increment(&self, v: &Vec<u32>) -> Vec<u32>;
        fn say_hello_world(&self);
    }
}

fn main() {
    let testbot = ffi::new_testbot();
    testbot.say_hello_world();

    let vv = vec![1, 2, 3];
    let out = testbot.increment(&vv);
    for v in out {
        println!("v = {}", v);
    }
}
