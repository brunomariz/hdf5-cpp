# HDF5 for C++

This repo contains the definition file along with other necessary files for creating an Apptainer container with HDF5 built and ready for use with C++.

## Usage

### Building container

    apptainer build hdf5-cpp.sif hdf5-cpp.def

### Viewing help

    apptainer run-help hdf5-cpp.sif

### Running container

- Run container interactively:

  apptainer shell hdf5-cpp.sif

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
