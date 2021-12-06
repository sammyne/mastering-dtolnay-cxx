#[cxx::bridge(namespace = "demo")]
mod ffi {
    unsafe extern "C++" {
        include!("call-cc-with-separated-extern-block/include/hello-world.h");

        type Testbot;

        fn new_testbot() -> UniquePtr<Testbot>;
        fn say_hello_world(&self);
    }

    unsafe extern "C++" {
        include!("call-cc-with-separated-extern-block/include/hello-world2.h");

        type Testbot2;

        fn new_testbot2() -> UniquePtr<Testbot2>;
        fn say_hello_world(&self);
    }
}

fn main() {
    let testbot = ffi::new_testbot();
    testbot.say_hello_world();

    let testbot = ffi::new_testbot2();
    testbot.say_hello_world();
}
