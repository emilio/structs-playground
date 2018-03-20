# Structs playground

This is a simplified version of the current setup that Firefox uses to read
styles from Servo.

In short, we generate C++ structs, somewhat like:

```rust
let display = Box::new(bindings::StyleDisplay {
    m_float: conversions::convert_float(computed_float),
});
```

Which require expensive conversions from Rust to C++ data structures.

Using cbindgen we should be able to avoid the conversion and make C++ understand
the Rust types.

This crate is intended as a starting point to allow hacking on the problem more
easily than with a Firefox build and show different ways to approach the
problem :)

