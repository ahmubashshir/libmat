# libmat [![Build Status](https://travis-ci.org/ahmubashshir/libmat.svg?branch=master)](https://travis-ci.org/ahmubashshir/libmat) [![Downloads](https://img.shields.io/github/downloads/ahmubashshir/libmat/total.svg)](https://github.com/ahmubashshir/libmat/releases/latest) [![GitHub issues](https://img.shields.io/github/issues/ahmubashshir/libmat.svg)](https://github.com/ahmubashshir/libmat/issues)  [![GitHub license](https://img.shields.io/github/license/ahmubashshir/libmat.svg)](https://github.com/ahmubashshir/libmat/blob/master/LICENSE)
## A library for calculating matrics

### Currently Supports:
- Dynamic Sized Matrics
- Reinitialization:`mat.reinit(column,row,"MatA")`
- Book like output: `mat.out()`
- intelligent Indentation in output
- Add operation : `mat.add(mata,matb);`
- Subtract Operation : `mat.sub(mata,matb);`
- Multiply Operation:
   *  Matrics : `mat.mul(mata,matb);`
   *  Scalar  : `mat.add(3);`
- Accessable as raw(array): `mat.get_raw()`

### Would be Supported:
- Transversing
- Determinant
- Identity matrices
- Inverse matrix
- Operator overriding
- C Linking Support
### Build History
[![Build](https://buildstats.info/travisci/chart/ahmubashshir/libmat?buildCount=7)](https://travis-ci.org/ahmubashshir/libmat/builds)
