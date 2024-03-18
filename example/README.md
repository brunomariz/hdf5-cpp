Example HDF5 project. This code creates a matrix and outputs an HDF5 file `SDS.h5`.

Running example interactively:

    apptainer shell hdf5-cpp.sif
    cd example
    mkdir build
    cd build
    cmake ..
    make
    ./create.x
