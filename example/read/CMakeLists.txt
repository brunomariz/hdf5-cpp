cmake_minimum_required (VERSION 3.18)
project (HDF5_CPP_EXAMPLES CXX)

add_executable(read read.cxx)

set(HDF5DIR "/hdf5/build")
target_include_directories(read PRIVATE ${HDF5DIR}/include)
target_link_directories(read PRIVATE ${HDF5DIR}/lib)
target_link_libraries(read PRIVATE libhdf5.so libhdf5_cpp.so)
