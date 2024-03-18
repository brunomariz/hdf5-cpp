# HDF5 for C++

This repo contains the definition file along with other necessary files for creating an Apptainer container with HDF5 built and ready for use with C++.

## Usage

Clone this repo

```
git clone https://github.com/brunomariz/hdf5-cpp.git
cd hdf5-cpp
```

### Building container

```
apptainer build hdf5-cpp.sif hdf5-cpp.def
```

> Note: you will be presented with the Copyright Notice and License Terms for HDF5 (Hierarchical Data Format 5) Software Library and Utilities. To continue, press `Q`.

### Viewing help

```
apptainer run-help hdf5-cpp.sif
```

### Running container

- Run container interactively:

```
apptainer shell hdf5-cpp.sif
```

- Running example interactively:

```
apptainer shell hdf5-cpp.sif
cd example
mkdir build
cd build
cmake ..
make
./create.x
```

- Executing commands in container:

```
cd example/build/
apptainer exec ../../hdf5-cpp.sif cmake
apptainer exec ../../hdf5-cpp.sif make
apptainer exec ../../hdf5-cpp.sif ./create.x
```

## Examples

More examples can be found in the `/hdf5/CMake-hdf5-1.14.3/hdf5-1.14.3/c++/examples/` folder.
