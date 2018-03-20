extern crate bindgen;
extern crate gcc;

fn main() {
    use bindgen;
    use std::path::PathBuf;
    use std::env;

    let src_dir = PathBuf::from(env::var_os("CARGO_MANIFEST_DIR").unwrap());
    let out_dir = PathBuf::from(env::var_os("OUT_DIR").unwrap());

    let bindings = bindgen::builder()
        .header(src_dir.join("cpp").join("StyleStructs.h").to_string_lossy())
        .clang_arg("-xc++")
        .clang_arg("-std=c++11")
        .rustified_enum("StyleFloat")
        .generate()
        .expect("Couldn't generate bindings");

    bindings.write_to_file(out_dir.join("bindings.rs"))
        .expect("Failed to write bindings");

    // This is really the other way around (the Rust code is compiled as a
    // static lib). But this doesn't matter much in practice.
    gcc::Build::new()
        .cpp(true)
        .file("cpp/Consumer.cpp")
        .compile("libgecko.a");
}
