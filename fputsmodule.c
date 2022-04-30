#include <python.h>
#include "helpers.c"

/*
 * Entry point of C logic from python call
 */
static PyObject *method_fputs(PyObject *self, PyObject *args) {
    char *str, *filename = NULL;
    int bytes_copied = -1;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "ss", &str, &filename)) {
        return NULL;
    }
    /* core logic */
    FILE *fp = fopen(filename, "w");
    char* str_ = append_date(str);

    //l // need to fail to clear cache of pip install
    bytes_copied = fputs(str_, fp);
    fclose(fp);

    return PyLong_FromLong(bytes_copied);
}

/*
 * Entry point description (array of struct, each element - interface entry point):
 * - Function from python call.
 * - Function from python c interface.
 * - # Number of arguments.
 *   > self
 *   > arguments 
 * - Doc string.
 */
static PyMethodDef FputsMethods[] = {
    {"fputs", method_fputs, METH_VARARGS, "Python interface for fputs C library function"},
    {NULL, NULL, 0, NULL}
};

/*
 * For each entry point.
 * Struct defines entry point meta data.
 */
static struct PyModuleDef fputsmodule = {
    PyModuleDef_HEAD_INIT,
    "fputs",
    "Python interface for the fputs C library function",
    -1,
    FputsMethods
};

/*
 * For entry point.
 * Creating C interface.
 */
PyMODINIT_FUNC PyInit_fputs(void) {
    return PyModule_Create(&fputsmodule);
}

