#[cxx::bridge(namespace = "demo")]
mod ffi {
    unsafe extern "C++" {
        include!("call-cc-with-passed-fn/include/hello-world.h");

        type Testbot;

        fn new_testbot() -> UniquePtr<Testbot>;
        fn say_hello_world(&self, hello: fn(&Vec<u32>));
    }
}

fn main() {
    let testbot = ffi::new_testbot();

    let hello = |v: &Vec<u32>| {
        for vv in v {
            println!("hello: {}", vv);
        }
    };
    testbot.say_hello_world(hello);
}
