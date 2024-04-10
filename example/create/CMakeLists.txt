cmake_minimum_required (VERSION 3.18)
project (HDF5_CPP_EXAMPLES CXX)
add_executable(create.x)
target_sources(create.x PRIVATE create.cpp)

set(HDF5DIR "/hdf5/build")
target_include_directories(create.x PRIVATE ${HDF5DIR}/include)
target_link_directories(create.x PRIVATE ${HDF5DIR}/lib)
target_link_libraries(create.x PRIVATE libhdf5.so libhdf5_cpp.so)
