#[cxx::bridge(namespace = "demo")]
mod ffi {
    unsafe extern "C++" {
        include!("hello-world/include/hello-world.h");

        type Testbot;

        fn new_testbot() -> UniquePtr<Testbot>;

        fn hello_world(&self) -> UniquePtr<CxxString>;
    }
}

fn main() {
    let testbot = ffi::new_testbot();
    let out = testbot.hello_world();

    println!("{}", out);
}
