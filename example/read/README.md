Example HDF5 project. This code reads a matrix and outputs to stdout.

Running example interactively:

    apptainer shell hdf5-cpp.sif
    cd example/read
    mkdir build
    cd build
    cmake ..
    make
    cd ..
    ./read
