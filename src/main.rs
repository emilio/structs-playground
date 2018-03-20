extern crate cssparser;

mod style;

use style::properties::Style;

#[allow(non_snake_case)]
#[no_mangle]
pub extern "C" fn ComputeStyle() -> *mut Style {
    Box::into_raw(style::properties::compute_a_style())
}

#[allow(non_snake_case)]
#[no_mangle]
pub unsafe extern "C" fn FreeStyle(p: *mut Style) {
    let _ = Box::from_raw(p);
}

extern "C" {
    fn main_cpp() -> ::std::os::raw::c_int;
}

fn main() {
    unsafe { main_cpp() };
}
