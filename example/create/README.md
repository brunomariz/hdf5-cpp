Example HDF5 project. This code creates a matrix and outputs an HDF5 file `SDS.h5`.

- Run container interactively:

```
apptainer shell hdf5-cpp.sif
```

- Running example interactively:

```
apptainer shell hdf5-cpp.sif
cd example/create
mkdir build
cd build
cmake ..
make
./create.x
```

- Executing commands in container:

```
cd example/create/build/
apptainer exec ../../../hdf5-cpp.sif cmake
apptainer exec ../../../hdf5-cpp.sif make
apptainer exec ../../../hdf5-cpp.sif ./create.x
```

## Examples

More examples can be found in the `/hdf5/CMake-hdf5-1.14.3/hdf5-1.14.3/c++/examples/` folder.
