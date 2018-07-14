# libmat [![Build Status](https://travis-ci.org/Polymath-Team/libmat.svg?branch=master)](https://travis-ci.org/Polymath-Team/libmat) [![Downloads](https://img.shields.io/github/downloads/Polymath-Team/libmat/total.svg)](https://github.com/Polymath-Team/libmat/releases/latest) [![GitHub issues](https://img.shields.io/github/issues/Polymath-Team/libmat.svg)](https://github.com/Polymath-Team/libmat/issues)  [![GitHub license](https://img.shields.io/github/license/Polymath-Team/libmat.svg)](https://github.com/Polymath-Team/libmat/blob/master/LICENSE)
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
[![Build](https://buildstats.info/travisci/chart/Polymath-Team/libmat?buildCount=7)](https://travis-ci.org/Polymath-Team/libmat/builds)
