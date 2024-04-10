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

See each example for running instructions
