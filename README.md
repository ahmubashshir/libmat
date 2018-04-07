# libmat [![Build Status](https://travis-ci.org/ahmubashshir/libmat.svg?branch=master)](https://travis-ci.org/ahmubashshir/libmat) ![Downloads](https://img.shields.io/github/downloads/ahmubashshir/libmat/total.svg?link=https://github.com/ahmubashshir/libmat/archive/master.zip&link=https://github.com/ahmubashshir/libmat/releases) [![GitHub issues](https://img.shields.io/github/issues/ahmubashshir/libmat.svg)](https://github.com/ahmubashshir/libmat/issues)  [![GitHub license](https://img.shields.io/github/license/ahmubashshir/libmat.svg)](https://github.com/ahmubashshir/libmat/blob/master/LICENSE)
## A library for calculating matrics

### Currently Supports:
- Dynamic Sized Matrics     :heavy_check_mark:
- Reinitialization:`mat.reinit(column,row,"MatA")`    :heavy_check_mark:
- Book like output: `mat.out()`     :heavy_check_mark:
- intelligent Indentation in output     :heavy_check_mark:
- Add operation : `mat.add(mata,matb);`     :heavy_check_mark:
- Subtract Operation : `mat.sub(mata,matb);`     :heavy_check_mark:
- Multiply Operation:     :heavy_check_mark:
   *  Matrics : `mat.mul(mata,matb);`     :heavy_check_mark:
   *  Scalar  : `mat.add(3);`     :heavy_check_mark:
- Accessable as raw(array): `mat.get_raw()`     :heavy_check_mark:

### Would be Supported:
- Transversing     :heavy_multiplication_x:
- Determinant     :heavy_multiplication_x:
- Identity matrices     :heavy_multiplication_x:
- Inverse matrix     :heavy_multiplication_x:
- Operator overriding     :heavy_multiplication_x:
