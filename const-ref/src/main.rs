use std::ffi::CString;
//use std::os::raw::c_char;

#[cxx::bridge(namespace = "demo")]
mod ffi {
    unsafe extern "C++" {
        include!("hello-world/include/hello-world.h");

        type HelloWorld;

        unsafe fn greet(&self, who: *const c_char);
        fn play();
    }

    extern "Rust" {
        fn hi(h: &HelloWorld);
    }
}

fn hi(h: &ffi::HelloWorld) {
    let s = CString::new("you").unwrap();
    let ss = s.as_c_str();

    unsafe {
        h.greet(ss.as_ptr());
    }
}

fn main() {
    ffi::play();
}
