Example HDF5 project. This code reads a matrix and outputs to stdout.

### Running example interactively:

Start container

```
apptainer shell hdf5-cpp.sif
```

View data contents

```
cd example/read
/hdf5/build/bin/h5dump data/SDS.h5
```

Create build dir

```
mkdir build
```

Build example

```
cmake -S . -B build/
cmake --build build/
```

Run example

```
./build/read
```
