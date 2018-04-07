# libmat [![Build Status](https://travis-ci.org/ahmubashshir/libmat.svg?branch=master)](https://travis-ci.org/ahmubashshir/libmat)

## A library for calculating matrics

### Currently Supports:


- [x] Dynamic Sized Matrics
- [x] Reinitialization:`mat.reinit(column,row,"MatA")`
- [x] Book like output: `mat.out()`
- [x] intelligent Indentation in output
- [x] Add operation : `mat.add(mata,matb);`
- [x] Subtract Operation : `mat.sub(mata,matb);`
- [x] Multiply Operation:
  1. Matrics : `mat.mul(mata,matb);`
  2. Scalar  : `mat.add(3);`
- [x] Accessable as raw(array): `mat.get_raw()`

### Would be Supported
- [ ] Transversing
- [ ] Determinant
- [ ] Identity matrices
- [ ] Inverse matrix
- [ ] Operator overriding
