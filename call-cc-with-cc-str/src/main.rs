#[cxx::bridge(namespace = "demo")]
mod ffi {
    unsafe extern "C++" {
        include!("hello-world/include/hello-world.h");

        fn say_hello(who: &CxxString);
    }
}

use cxx::let_cxx_string;

fn main() {
    let_cxx_string!(who = "sammy");

    who.as_mut().push_str(" :)");

    ffi::say_hello(&who);
}
