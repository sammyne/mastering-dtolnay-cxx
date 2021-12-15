#[cxx::bridge(namespace = "demo")]
mod ffi {
    struct Args {
        who: String,
    }

    unsafe extern "C++" {
        include!("call-cc-with-shared-types/include/hello-world.h");

        type Testbot;

        fn new_testbot() -> UniquePtr<Testbot>;
        fn say_hello_world(&self, args: &Args);
    }
}

fn main() {
    let testbot = ffi::new_testbot();

    let args = ffi::Args {
        who: "sammyne".to_string(),
    };

    testbot.say_hello_world(&args);
}
