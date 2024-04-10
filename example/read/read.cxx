#include <iostream>

#include "hdf5.h"
#define FILE "data/python_data.h5"

using std::cout;
using std::endl;

int main(void) {
    hid_t file_id, dataset_id; /* identifiers */
    herr_t status;
    int i, j;
    float dset_data[10][10];

    /* Open an existing file. */
    file_id = H5Fopen(FILE, H5F_ACC_RDWR, H5P_DEFAULT);

    /* Open an existing dataset. */
    dataset_id = H5Dopen2(file_id, "/b", H5P_DEFAULT);

    status = H5Dread(dataset_id, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL,
                     H5P_DEFAULT, dset_data);

    // Print data
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10; j++) {
            if (j == 0) {
                cout << endl;
            }

            cout << dset_data[i][j] << " ";
        }
    }
    cout << endl;

    /* Close the dataset. */
    status = H5Dclose(dataset_id);

    /* Close the file. */
    status = H5Fclose(file_id);

    return 0;
}