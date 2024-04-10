# HDF5 Read example

Example HDF5 project. This code reads a matrix from an HDF5 file created in python () and outputs to stdout.

## Sources:

- https://raw.githubusercontent.com/HDFGroup/hdf5/hdf5_1_14/examples/h5_rdwt.c
- https://docs.hdfgroup.org/hdf5/v1_14/_l_b_examples.html
- https://docs.hdfgroup.org/hdf5/v1_14/_l_b_dset_r_w.html
- https://docs.hdfgroup.org/hdf5/v1_14/_learn_basics.html

- https://github.com/brunomariz/h5py-tutorial

## Running example interactively:

### Start the container

```
apptainer shell hdf5-cpp.sif
```

### View data contents and edit the source code accordingly.

In this example, we'll read the file `data/python_data.h5`, which contains 3 datasets, `a`, `b`, and `c`.

```
cd example/read
/hdf5/build/bin/h5dump data/python_data.h5
```

After running the command above, we get the following output:

```
HDF5 "data/python_data.h5" {
GROUP "/" {
   DATASET "a" {
      DATATYPE  H5T_IEEE_F64LE
      DATASPACE  SIMPLE { ( 100 ) / ( 100 ) }
      DATA {
      (0): -0.00132728, 0.468677, -0.560921, 0.547143, -0.65233, 0.264043,
      (6): 0.816935, 0.175387, 1.12398, -0.833512, 0.090992, -0.963421,
      (12): 0.850282, -0.673362, -1.03646, -0.807808, 0.30894, -0.732777,
      (18): 0.270205, -1.81864, -0.03108, 0.91997, 1.27175, -2.39719,
      (24): -0.58883, 0.377784, 0.412845, -0.957379, 1.37816, -0.863832,
      (30): -1.39108, 2.54633, -1.00756, -1.02187, -0.411958, 1.17056,
      (36): 0.991908, -1.13515, 0.520848, -0.341941, -0.167256, -0.492852,
      (42): -0.254385, -0.113964, -0.109039, 0.313046, 0.887246, 0.908059,
      (48): 0.552372, -1.01882, -1.53234, -0.786992, 0.116334, 0.549208,
      (54): -0.433772, -1.80553, -1.22909, 0.0705967, -0.0775282, 0.121833,
      (60): -1.85292, -0.50749, -0.032697, 0.183209, -1.27592, 0.211984,
      (66): -1.10159, 1.43003, 1.12386, 0.984333, 0.825843, 0.781061,
      (72): -1.41778, -0.150318, 1.27109, -1.73928, -1.24584, 0.94704,
      (78): -0.279703, -0.584742, -1.71145, 0.787307, 1.76943, -0.34754,
      (84): 1.06845, 0.557776, 0.127222, -0.434371, 1.02777, -0.674221,
      (90): 0.107162, 0.037814, -1.24882, 2.43483, -0.0610712, 0.709764,
      (96): 1.21849, 0.356315, -1.12731, 0.495923
      }
   }
   DATASET "b" {
      DATATYPE  H5T_IEEE_F64LE
      DATASPACE  SIMPLE { ( 10, 10 ) / ( 10, 10 ) }
      DATA {
      (0,0): 2.10104, -1.45339, -0.315669, -2.35193, 0.191566, -0.474944,
      (0,6): -1.34342, -2.92522, -0.966509, 0.655339,
      (1,0): 0.115955, 0.653942, -0.385831, 1.72778, -0.487643, -1.24622,
      (1,6): 0.299783, 1.89518, -0.2164, -0.0368579,
      (2,0): 1.71394, -0.23479, 1.1942, 0.36042, -0.216333, -0.0903564,
      (2,6): -1.2953, -0.896473, 0.212997, 0.231686,
      (3,0): -1.44919, -0.153628, -0.867629, -1.23658, 0.475187, -1.38872,
      (3,6): -0.554302, 0.283435, 0.648246, -0.0552864,
      (4,0): -0.774658, -0.161686, -0.317284, 1.45616, -1.58963, 0.472345,
      (4,6): 1.07208, -0.381566, 0.654501, -1.8768,
      (5,0): -0.0835703, 0.422272, -0.707092, 1.06186, 0.887497, -0.570835,
      (5,6): 0.610546, 1.30369, -1.02116, -0.496702,
      (6,0): -1.26845, 0.556141, 0.709601, 0.598072, 0.0822077, -1.53819,
      (6,6): -1.86625, 1.13732, 0.0310158, 1.0336,
      (7,0): -0.174742, -0.114531, -1.92458, -0.590291, -0.00561194, -2.4078,
      (7,6): 0.124507, -1.29736, -1.42324, 0.769763,
      (8,0): 0.00901314, 1.39095, -0.115488, -0.293545, 1.05472, -0.187939,
      (8,6): -0.376301, 1.86345, 0.106388, -0.250032,
      (9,0): 0.615323, 1.02953, -1.43519, 0.983914, 0.825113, 0.84438,
      (9,6): -1.00296, -0.243307, 0.547816, 0.547061
      }
   }
   DATASET "c" {
      DATATYPE  H5T_IEEE_F64LE
      DATASPACE  SIMPLE { ( 3 ) / ( 3 ) }
      DATA {
      (0): 4.89247, 1.80155, 0.356585
      }
   }
}
}
```

This shows that dataset `b` has shape (10, 10), (with the same value for max_shape, separated by a forward slash `/`). Therefore, in read.cxx, we'll declare our buffer as

```c
float dset_data[10][10];
```

It is also important to note that, since our dataset values are of type H5T\*IEEE_F64LE (Float 64, little-endian), we should set the mem_type_id (i.e., the variable type in memory after having been read by the API function) to float aswell, with the value H5T_NATIVE_FLOAT:

```c
status = H5Dread(dataset_id, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL,
                     H5P_DEFAULT, dset_data);
```

### Build and run

Create build dir

```
mkdir build
```

Build and run example

````
cmake -S . -B build/```
cmake --build build/ && ./build/read ^C
````

This execution should output the contents of the `b` dataset in the `data/python_data.h5` file:

![image](https://github.com/brunomariz/hdf5-cpp/assets/48870924/5e005397-907f-4cf3-b164-ec5a29d43efd)

HDF5 view screen for comparison:

![Untitled](https://github.com/brunomariz/hdf5-cpp/assets/48870924/a0ada5c0-c2e0-4b4c-932b-706bcd9618b0)

